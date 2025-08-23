# Algorithms

A collection of fundamental algorithms implemented in C++ from scratch, part of the Weekly-Projects series.

## Project Overview

This project is part of the Weekly-Projects series. The goal is to implement classic algorithms in C++ with a focus on understanding the underlying mechanics, time/space complexity analysis, and clean, readable code. Each algorithm is implemented independently with comprehensive documentation and test cases.

## Learning Objectives

- Algorithm design patterns and problem-solving techniques
- Time and space complexity analysis (Big O notation)
- C++ standard library usage and modern C++ features (C++20/23)
- Template programming and generic algorithm design
- Data structure implementation and optimization
- Performance benchmarking and profiling
- Unit testing with modern C++ testing frameworks

## Design Philosophy

- Clarity over cleverness: readable, well-documented implementations explaining the why behind every decision
- Performance awareness: complexity analysis and benchmarking included
- Modern C++: leverage C++20/23 features where appropriate
- Testability: comprehensive unit tests for correctness and edge cases
- Modularity: each algorithm is self-contained and reusable

## Technical Approach

### Implementation Strategy

- Header-only libraries for easy inclusion and template instantiation
- STL-compatible interfaces where applicable (iterators, functors)
- Generic implementations using templates for type flexibility
- Separate test files with comprehensive coverage
- Benchmark utilities for performance measurement
- Documentation with complexity analysis and usage examples

### Code Organization

- One algorithm per header file with implementation
- Consistent naming conventions and code style
- Template specializations for common types when beneficial
- Exception safety and RAII principles
- Modern C++ idioms (auto, range-based loops, smart pointers)

## Algorithms Implemented

Some ideas of algorithms to be implemented (not all of them will be implemented in the one-week period)

### Sorting Algorithms
- [X] Bubble Sort - O(n²) comparison-based sorting
- [ ] Selection Sort - O(n²) in-place sorting algorithm
- [ ] Insertion Sort - O(n²) adaptive sorting algorithm
- [X] Merge Sort - O(n log n) divide-and-conquer stable sort
- [ ] Quick Sort - O(n log n) average case in-place sort
- [ ] Heap Sort - O(n log n) in-place sorting using binary heap
- [ ] Radix Sort - O(nk) non-comparison integer sorting
- [ ] Counting Sort - O(n+k) stable integer sorting algorithm

### Search Algorithms
- [X] Linear Search - O(n) sequential search
- [X] Binary Search - O(log n) divide-and-conquer search
- [ ] Interpolation Search - O(log log n) for uniformly distributed data
- [ ] Exponential Search - O(log n) for unbounded/infinite arrays
- [ ] Jump Search - O(√n) block-based search algorithm
- [ ] Ternary Search - O(log₃ n) divide-and-conquer variant

### Graph Algorithms
- [X] Depth-First Search (DFS) - O(V+E) graph traversal
- [X] Breadth-First Search (BFS) - O(V+E) level-order traversal
- [ ] Dijkstra's Algorithm - O((V+E) log V) shortest path
- [ ] Bellman-Ford Algorithm - O(VE) shortest path with negative weights
- [ ] Floyd-Warshall Algorithm - O(V³) all-pairs shortest path
- [ ] Kruskal's Algorithm - O(E log E) minimum spanning tree
- [ ] Prim's Algorithm - O(E log V) minimum spanning tree
- [ ] Topological Sort - O(V+E) DAG ordering
- [ ] Disjoint Set Union (DSU) - More of a data structure, but serves the same purpose as other algorithms in many situations

### Dynamic Programming
- [ ] Fibonacci Sequence - O(n) bottom-up and memoization
- [ ] Longest Common Subsequence - O(mn) sequence alignment
- [ ] Knapsack Problem - O(nW) 0/1 and unbounded variants
- [ ] Edit Distance - O(mn) string transformation
- [ ] Coin Change - O(nW) minimum coins and counting solutions
- [ ] Maximum Subarray - O(n) Kadane's algorithm

### String Algorithms
- [ ] KMP String Matching - O(n+m) pattern searching
- [ ] Rabin-Karp Algorithm - O(n+m) rolling hash matching
- [ ] Boyer-Moore Algorithm - O(n/m) efficient string search
- [ ] Z Algorithm - O(n) pattern preprocessing
- [ ] Manacher's Algorithm - O(n) palindrome detection
- [ ] Suffix Array - O(n log n) string indexing structure

### Tree Algorithms
- [ ] Binary Search Tree Operations - O(log n) average case
- [ ] AVL Tree - O(log n) self-balancing BST
- [ ] Red-Black Tree - O(log n) balanced binary search tree
- [ ] B-Tree - O(log n) multi-way search tree
- [ ] Trie (Prefix Tree) - O(m) string prefix operations
- [ ] Segment Tree - O(log n) range query data structure
- [ ] Fenwick Tree - O(log n) cumulative frequency queries

### Mathematical Algorithms
- [ ] Euclidean Algorithm - O(log min(a,b)) GCD computation
- [ ] Sieve of Eratosthenes - O(n log log n) prime generation
- [ ] Fast Exponentiation - O(log n) modular exponentiation
- [ ] Matrix Multiplication - O(n³) and Strassen's O(n^2.81)
- [ ] Fast Fourier Transform - O(n log n) signal processing
- [ ] Miller-Rabin Primality Test - O(k log³ n) probabilistic

## Project Structure

Planned structure for the algorithms collection:

```
Algorithms/
├── include/
│   ├── sorting/
│   │   ├── bubble_sort.hpp
│   │   ├── merge_sort.hpp
│   │   ├── quick_sort.hpp
│   │   └── ...
│   ├── searching/
│   │   ├── binary_search.hpp
│   │   ├── linear_search.hpp
│   │   └── ...
│   ├── graph/
│   │   ├── dfs.hpp
│   │   ├── bfs.hpp
│   │   ├── dijkstra.hpp
│   │   └── ...
│   ├── dynamic_programming/
│   │   ├── fibonacci.hpp
│   │   ├── knapsack.hpp
│   │   └── ...
│   ├── string/
│   │   ├── kmp.hpp
│   │   ├── rabin_karp.hpp
│   │   └── ...
│   ├── tree/
│   │   ├── bst.hpp
│   │   ├── avl_tree.hpp
│   │   └── ...
│   ├── math/
│   │   ├── gcd.hpp
│   │   ├── sieve.hpp
│   │   └── ...
│   └── utils/
│       ├── benchmark.hpp       # Performance measurement utilities
│       ├── test_utils.hpp      # Common testing utilities
│       └── concepts.hpp        # C++20 concepts for type constraints
├── tests/
│   ├── sorting/
│   │   ├── test_bubble_sort.cpp
│   │   ├── test_merge_sort.cpp
│   │   └── ...
│   ├── searching/
│   ├── graph/
│   ├── dynamic_programming/
│   ├── string/
│   ├── tree/
│   └── math/
├── examples/
│   ├── sorting_demo.cpp        # Demonstrates various sorting algorithms
│   ├── graph_demo.cpp          # Graph algorithm examples
│   └── benchmark_demo.cpp      # Performance comparison examples
├── docs/
│   ├── complexity_analysis.md  # Big O analysis for all algorithms
│   ├── implementation_notes.md # Design decisions and trade-offs
│   └── usage_examples.md       # Code examples and best practices
├── CMakeLists.txt              # CMake build configuration
├── Doxyfile                    # Doxygen configuration
├── LICENSE
└── README.md                   # This file
```

## Technology Stack

- Language: C++20/23
- Build System: CMake 3.20+
- Testing Framework: Catch2 or Google Test
- Compiler Support: GCC 9+, Clang 10+, MSVC 2019+
- Documentation: Doxygen for API docs
- Benchmarking: Custom utilities + std::chrono
- Static Analysis: clang-tidy, cppcheck

## Getting Started

### Prerequisites

- Modern C++ compiler (C++20/23 support)
- CMake 3.20 or higher
- Git for version control

### Building the Project

```bash
# Clone the repository
git clone <repository-url>
cd Algorithms

# Create build directory
mkdir build && cd build

# Configure with CMake
cmake .. -DCMAKE_BUILD_TYPE=Release

# Build all algorithms and tests
cmake --build .

# Run tests
ctest --output-on-failure
```

### Using Individual Algorithms

```cpp
#include "sorting/merge_sort.hpp"
#include "searching/binary_search.hpp"
#include <vector>
#include <iostream>

int main() {
    std::vector<int> data = {64, 34, 25, 12, 22, 11, 90};
    
    // Sort the data
    algorithms::merge_sort(data.begin(), data.end());
    
    // Search for an element
    auto it = algorithms::binary_search(data.begin(), data.end(), 25);
    if (it != data.end()) {
        std::cout << "Found 25 at position: " 
                  << std::distance(data.begin(), it) << std::endl;
    }
    
    return 0;
}
```

## Success Criteria

### Implementation Goals
- [ ] At least 10 fundamental algorithms implemented
- [ ] Comprehensive test suite
- [ ] Performance benchmarks for complexity verification
- [ ] Documentation with examples and complexity analysis
- [ ] Modern C++ best practices throughout
- [ ] Cross-platform compatibility

### Educational Objectives
- [ ] Deep understanding of algorithmic complexity
- [ ] Proficiency with advanced C++ template programming
- [ ] Experience with performance optimization techniques
- [ ] Knowledge of when to use each algorithm type
- [ ] Ability to analyze and improve existing implementations

## Learning Outcomes

This project will demonstrate:

- **Algorithm Analysis**: Understanding time/space complexity and choosing appropriate algorithms for different scenarios
- **Template Metaprogramming**: Advanced C++ techniques for generic, reusable code
- **Performance Engineering**: Benchmarking, profiling, and optimization techniques
- **Software Architecture**: Organizing complex codebases with clear module boundaries
- **Testing Strategies**: Comprehensive testing including edge cases and performance tests
- **Documentation**: Technical writing and API documentation for complex systems

## Design Decisions

### Architecture Choices

**Header-Only Implementation**: Chose header-only libraries for algorithms to enable template instantiation at compile time and avoid linking complexities. This provides better optimization opportunities and easier distribution.

**Template-First Design**: Prioritized generic implementations using templates over concrete type implementations to maximize code reuse and type flexibility while maintaining performance.

**STL Compatibility**: Designed interfaces to be compatible with STL conventions (iterator-based, predicate functors) to ensure familiarity and interoperability with existing C++ code.

**Namespace Organization**: Will organize algorithms in nested namespaces (`algorithms::sorting::`, `algorithms::graph::`) to prevent naming conflicts and provide logical grouping.

### Implementation Strategy

**Complexity Over Features**: Focused on implementing fewer algorithms with thorough complexity analysis and benchmarking rather than many algorithms without proper analysis.

**Modern C++ Features**: Leveraged C++20/23 features like concepts, ranges, and constexpr where appropriate while maintaining compatibility with C++20 for broader adoption.

**Testing Strategy**: Planned comprehensive unit testing with property-based tests for mathematical correctness and performance regression testing for complexity verification.

**Documentation First**: Emphasized extensive inline documentation explaining algorithm mechanics, complexity analysis, and usage examples over just working code.

### Performance Considerations

**Compile-Time Optimization**: Extensive use of `constexpr` and template metaprogramming to move computations to compile time where possible.

**Cache-Friendly Patterns**: Considered memory access patterns and cache locality in implementations, particularly for sorting and graph algorithms.

**Benchmark-Driven Development**: Planned to validate theoretical complexity with actual performance measurements using custom benchmarking utilities.

**Template Specializations**: Will provide optimized specializations for common types (integers, strings) while maintaining generic implementations.

## Algorithm Complexity Reference

### Implemented Algorithms

| Algorithm     | Best Case | Average Case  | Worst Case    | Space Complexity  | Properties                |
|---------------|-----------|---------------|---------------|-------------------|---------------------------|
| **Searching** |           |               |               |                   |                           |
| Linear Search | O(1)      | O(n)          | O(n)          | O(1)              | Works on unsorted data    |
| Binary Search | O(1)      | O(log n)      | O(log n)      | O(1)              | Requires sorted data      |
| **Sorting**   |           |               |               |                   |                           |
| Bubble Sort   | O(n)      | O(n²)         | O(n²)         | O(1)              | Stable, adaptive          |
| Merge Sort    | O(n log n)| O(n log n)    | O(n log n)    | O(n)              | Stable, not adaptive      |
| Quick Sort    | O(n log n)| O(n log n)    | O(n²)         | O(log n)          | Not stable, in-place      |
| **Graph**     |           |               |               |                   |                           |
| DFS           | O(V + E)  | O(V + E)      | O(V + E)      | O(V)              | Stack-based traversal     |
| BFS           | O(V + E)  | O(V + E)      | O(V + E)      | O(V)              | Queue-based traversal     |

### Algorithm Properties Explained

**Stable**: Equal elements maintain their relative order after sorting  
**Adaptive**: Performance improves on nearly sorted data  
**In-place**: Requires only O(1) or O(log n) extra memory  
**Comparison-based**: Uses element comparisons for ordering decisions

### When to Use Each Algorithm

**Linear Search**: Small datasets, unsorted data, simple implementation needed  
**Binary Search**: Large sorted datasets, repeated searches, logarithmic performance required  
**Bubble Sort**: Educational purposes, small datasets, stability required  
**Merge Sort**: Large datasets, stability required, predictable performance needed  
**Quick Sort**: Large datasets, average case performance, in-place sorting preferred  
**DFS**: Graph connectivity, pathfinding, topological ordering

## Notes and Reflections

**August 18, 2025 - Project Planning**
Decided the project structure and philosophy. It could have been planned in many other ways, but this approach gives a more scalable structure so that it can be expanded later, little by little, with many more algorithms.

## Resources

- [Introduction to Algorithms (CLRS)](https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/) — Comprehensive algorithmic reference
- [The Algorithm Design Manual (Skiena)](https://www.algorist.com/) — Practical algorithm implementation guide
- [C++ Templates: The Complete Guide](https://www.josuttis.com/tmplbook/) — Advanced template programming
- [Effective Modern C++ (Scott Meyers)](https://www.oreilly.com/library/view/effective-modern-c/9781491908419/) — Modern C++ best practices
- [CodeForces](https://codeforces.com/) & [LeetCode](https://leetcode.com/) — Algorithm practice problems
- [Big O Cheat Sheet](https://www.bigocheatsheet.com/) — Complexity reference

---

**Started:** August 18, 2025  
**Developer:** Boris Mladenov Beslimov  
**Project:** Weekly-Projects — Algorithms