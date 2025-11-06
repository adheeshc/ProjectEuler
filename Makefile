# Makefile for Project Euler C++ Solutions

CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra
SRC_DIR = CPP
BUILD_DIR = build

# Get all .cpp files in CPP directory
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
# Generate executable names (remove .cpp extension and path)
TARGETS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%,$(SOURCES))

.PHONY: all clean run

# Default target: build all
all: $(BUILD_DIR) $(TARGETS)

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Pattern rule to build executables
$(BUILD_DIR)/%: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@
	@echo "Built: $@"

# Build and run a specific problem (e.g., make run PROBLEM=1_multiplesof3or5)
run:
ifdef PROBLEM
	@$(MAKE) $(BUILD_DIR)/$(PROBLEM)
	@echo "\n=== Running $(PROBLEM) ==="
	@$(BUILD_DIR)/$(PROBLEM)
else
	@echo "Usage: make run PROBLEM=<problem_name>"
	@echo "Example: make run PROBLEM=1_multiplesof3or5"
endif

# Build a specific problem (e.g., make build PROBLEM=1_multiplesof3or5)
build:
ifdef PROBLEM
	@$(MAKE) $(BUILD_DIR)/$(PROBLEM)
else
	@echo "Usage: make build PROBLEM=<problem_name>"
	@echo "Example: make build PROBLEM=1_multiplesof3or5"
endif

# Clean all built executables
clean:
	rm -rf $(BUILD_DIR)
	@echo "Cleaned build directory"

# Help target
help:
	@echo "Project Euler C++ Build System"
	@echo ""
	@echo "Available targets:"
	@echo "  make all                    - Build all C++ solutions"
	@echo "  make build PROBLEM=<name>   - Build a specific problem"
	@echo "  make run PROBLEM=<name>     - Build and run a specific problem"
	@echo "  make clean                  - Remove all built executables"
	@echo "  make help                   - Show this help message"
	@echo ""
	@echo "Examples:"
	@echo "  make run PROBLEM=1_multiplesof3or5"
	@echo "  make build PROBLEM=10_primeSummation"
