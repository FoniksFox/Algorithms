#include <iostream>

#include "graph/depth_first_search.hpp"
#include <vector>
#include <algorithm>
#include <cassert>

void test_depth_first_search() {
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

    std::vector<int> expected_order = {0, 1, 3, 4, 2};
    std::vector<int> dfs_order;
    algorithms::graph::dfs_recursive(g, 0, [&dfs_order](int node) {
        dfs_order.push_back(node);
    });
    assert(dfs_order == expected_order);
    std::cout << "DFS-recursive test passed!" << std::endl;
    dfs_order.clear();

    algorithms::graph::dfs_iterative(g, 0, [&dfs_order](int node) {
        dfs_order.push_back(node);
    });
    assert(dfs_order == expected_order);
    std::cout << "DFS-iterative test passed!" << std::endl;
    dfs_order.clear();

    // Test complete DFS on disconnected graph
    graph g2(6);
    g2.add_edge(0, 1);
    g2.add_edge(0, 2);
    g2.add_edge(3, 4);
    g2.add_edge(4, 5);

    std::vector<int> expected_order2 = {0, 1, 2};
    std::vector<int> dfs_order2;
    algorithms::graph::dfs_recursive(g2, 0, [&dfs_order2](int node) {
        dfs_order2.push_back(node);
    });
    assert(dfs_order2 == expected_order2);
    std::cout << "DFS-recursive test passed!" << std::endl;
    dfs_order2.clear();

    algorithms::graph::dfs_iterative(g2, 0, [&dfs_order2](int node) {
        dfs_order2.push_back(node);
    });
    assert(dfs_order2 == expected_order2);
    std::cout << "DFS-iterative test passed!" << std::endl;
    dfs_order2.clear();

    std::vector<int> expected_complete_order = {0, 1, 2, 3, 4, 5};
    algorithms::graph::dfs_complete(g2, [&dfs_order2](int node) {
        dfs_order2.push_back(node);
    });
    assert(dfs_order2 == expected_complete_order);
    std::cout << "DFS-complete test passed!" << std::endl;

}

int main() {
    test_depth_first_search();
    std::cout << "All tests passed." << std::endl;
    return 0;
}