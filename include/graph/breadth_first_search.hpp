#pragma once

#include "graph_concept.hpp"
#include <functional>
#include <unordered_set>
#include <stack>
#include <ranges>
#include <vector>
#include <algorithm>

namespace algorithms {
namespace graph {
    /**
     * @defgroup bfs Breadth-First Search (BFS)
     * @brief Breadth-First Search traversal algorithms for graphs
     * @ingroup graph
     * @{
     */

    /**
     * @brief Performs iterative breadth-first search starting from a given node.
     * @tparam GraphType Graph type satisfying the Graph concept.
     * @tparam VisitFunc Callable type for node visitation.
     * @param graph The graph to traverse.
     * @param start The starting node.
     * @param visit Function called for each visited node.
     *
     * Time Complexity: O(V + E) where V is reachable vertices, E is reachable edges.
     * Space Complexity: O(V) for visited set + queue
     *
     * @ingroup bfs
     */
    template<Graph GraphType, typename VisitFunc>
    void bfs_iterative(const GraphType& graph, typename GraphType::NodeType start, VisitFunc visit) {
        std::unordered_set<typename GraphType::NodeType> visited;
        std::vector<typename GraphType::NodeType> queue;

        queue.push_back(start);
        visited.insert(start);

        while (!queue.empty()) {
            auto node = queue.front();
            queue.erase(queue.begin());
            visit(node);

            for (const auto& neighbor : graph.get_neighbors(node)) {
                if (!visited.contains(neighbor)) {
                    visited.insert(neighbor);
                    queue.push_back(neighbor);
                }
            }
        }
    }

    /**
     * @brief Performs BFS on all connected components of the graph.
     * @tparam GraphType Graph type satisfying the Graph concept.
     * @tparam VisitFunc Callable type for node visitation.
     * @param graph The graph to traverse.
     * @param visit Function called for each visited node.
     *
     * Time Complexity: O(V + E) where V is all vertices, E is all edges.
     * Space Complexity: O(V) for visited set + queue
     *
     * @ingroup bfs
     */
    template<Graph GraphType, typename VisitFunc>
    void bfs_complete(const GraphType& graph, VisitFunc visit) {
        std::unordered_set<typename GraphType::NodeType> visited;

        for (const auto& start : graph.get_all_nodes()) {
            if (visited.contains(start)) continue;

            std::vector<typename GraphType::NodeType> queue;
            queue.push_back(start);
            visited.insert(start);

            while (!queue.empty()) {
                auto node = queue.front();
                queue.erase(queue.begin());
                visit(node);

                for (const auto& neighbor : graph.get_neighbors(node)) {
                    if (!visited.contains(neighbor)) {
                        visited.insert(neighbor);
                        queue.push_back(neighbor);
                    }
                }
            }
        }
    }

    /** @} */ // end of bfs group
    /** @} */ // end of graph group

} // namespace graph
} // namespace algorithms