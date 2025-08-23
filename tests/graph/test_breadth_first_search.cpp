#include <iostream>

#include "graph/breadth_first_search.hpp"
#include <vector>
#include <algorithm>
#include <cassert>

void test_breadth_first_search() {
    struct graph {
        using NodeType = int;
        std::vector<std::vector<int>> adj_list;
        graph(int n) : adj_list(n) {}
        void add_edge(int u, int v) {
            adj_list[u].push_back(v);
        }
        std::vector<int> get_neighbors(int u) const {
            return adj_list[u];
        }
        std::vector<int> get_all_nodes() const {
            std::vector<int> nodes;
            for (std::size_t i = 0; i < adj_list.size(); ++i) {
                nodes.push_back(i);
            }
            return nodes;
        }
    };
    graph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);

    std::vector<int> expected_order = {0, 1, 2, 3, 4};
    std::vector<int> bfs_order;
    algorithms::graph::bfs_iterative(g, 0, [&bfs_order](int node) {
        bfs_order.push_back(node);
    });
    assert(bfs_order == expected_order);
    std::cout << "BFS-iterative test passed!" << std::endl;
    bfs_order.clear();

    graph g2(6);
    g2.add_edge(0, 1);
    g2.add_edge(0, 2);
    g2.add_edge(3, 4);
    g2.add_edge(4, 5);

    std::vector<int> expected_order2 = {0, 1, 2, 3, 4, 5};
    algorithms::graph::bfs_complete(g2, [&bfs_order](int node) {
        bfs_order.push_back(node);
    });
    assert(bfs_order == expected_order2);
    std::cout << "BFS-complete test passed!" << std::endl;
}

int main() {
    test_breadth_first_search();
    std::cout << "All tests passed." << std::endl;
    return 0;
}