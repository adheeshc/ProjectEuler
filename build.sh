#!/bin/bash
# Build script for Project Euler C++ solutions

CXX="g++"
CXXFLAGS="-std=c++17 -O2 -Wall -Wextra"
SRC_DIR="cpp_solutions"
BUILD_DIR="build"

# Create build directory
mkdir -p "$BUILD_DIR"

# Build single file
build_file() {
    local src_file="$1"
    local base_name=$(basename "$src_file" .cpp)
    local output="$BUILD_DIR/$base_name"

    echo "Building: $src_file -> $output"
    $CXX $CXXFLAGS "$src_file" -o "$output"

    if [ $? -eq 0 ]; then
        echo "Successfully built: $output"
        return 0
    else
        echo "Failed: $src_file"
        return 1
    fi
}

# Run a built file
run_file() {
    local arg="$1"

    # Determine source file and executable name
    if [[ "$arg" == *.cpp ]]; then
        src_file="$arg"
        base_name=$(basename "$src_file" .cpp)
    else
        src_file="$SRC_DIR/${arg}.cpp"
        base_name="$arg"
    fi

    local exe="$BUILD_DIR/$base_name"

    # Always rebuild when running
    echo "Building $base_name..."
    build_file "$src_file" || return 1

    echo ""
    echo "=== Running $base_name ==="
    "$exe"
}

# Main script logic
if [ $# -eq 0 ]; then
    # Build all
    echo "Building all C++ solutions..."
    for src_file in "$SRC_DIR"/*.cpp; do
        if [ -f "$src_file" ]; then
            build_file "$src_file"
        fi
    done
elif [ "$1" == "run" ]; then
    # Run a specific problem
    if [ -z "$2" ]; then
        echo "Usage: ./build.sh run <problem_name or path>"
        echo "Examples:"
        echo "  ./build.sh run 1_multiplesof3or5"
        echo "  ./build.sh run cpp_solutions/1_multiplesof3or5.cpp"
        exit 1
    fi
    run_file "$2"
elif [ "$1" == "clean" ]; then
    # Clean build directory
    echo "Cleaning build directory..."
    rm -rf "$BUILD_DIR"
    echo "✓ Cleaned"
else
    # Build specific problem
    # Check if argument is a .cpp file path
    if [[ "$1" == *.cpp ]]; then
        src_file="$1"
    else
        src_file="$SRC_DIR/${1}.cpp"
    fi

    if [ ! -f "$src_file" ]; then
        echo "Error: $src_file not found"
        exit 1
    fi
    build_file "$src_file"
fi
