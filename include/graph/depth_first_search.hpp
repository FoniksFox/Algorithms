#pragma once

#include <concepts>
#include <functional>
#include <unordered_set>
#include <stack>
#include <ranges>
#include <vector>
#include <algorithm>

namespace algorithms {
namespace graph {
    /**
     * @defgroup algorithms Algorithms Library
     * @brief Modern C++ implementation of fundamental algorithms
     */
    /**
     * @defgroup graph Graph Algorithms
     * @brief Algorithms for graph traversal and analysis
     * @ingroup algorithms
     * @{
     */
    /**
     * @defgroup dfs Depth-First Search (DFS)
     * @brief Depth-First Search traversal algorithms for graphs
     * @ingroup graph
     * @{
     */
    /**
     * @concept Graph
     * @brief Graph interface requirements for DFS algorithms.
     *
     * A graph type must provide:
     * - `using NodeType = node_type;` - Type representing graph nodes
     * - `auto get_neighbors(NodeType node) const -> range` - Returns neighbors of a node
     * - `auto get_all_nodes() const -> range` - Returns all nodes in the graph
     *
     * The NodeType must be regular (copyable, assignable, equality comparable) for use in hash sets.
     *
     * @code{.cpp}
     * struct AdjacencyListGraph {
     *     using NodeType = int;
     *     std::vector<int> get_neighbors(int node) const;
     *     std::vector<int> get_all_nodes() const;
     * };
     * @endcode
     */
    template<typename GraphType>
    concept Graph = requires(const GraphType& graph, typename GraphType::NodeType node) {
        typename GraphType::NodeType;
        { graph.get_neighbors(node) } -> std::ranges::range;
        { graph.get_all_nodes() } -> std::ranges::range;
        requires std::regular<typename GraphType::NodeType>;
    };

    /** @} */ // end of graph_concepts group

    /**
     * @brief Performs depth-first search starting from a given node.
     * @tparam GraphType Graph type satisfying the Graph concept.
     * @tparam VisitFunc Callable type for node visitation.
     * @param graph The graph to traverse.
     * @param start The starting node.
     * @param visit Function called for each visited node.
     * 
     * Time Complexity: O(V + E) where V is reachable vertices, E is reachable edges.
     * Space Complexity: O(V) for visited set + O(h) for recursion depth.
     * 
     * @ingroup dfs
     */
    template<Graph GraphType, typename VisitFunc>
    void dfs_recursive(const GraphType& graph, typename GraphType::NodeType start, VisitFunc visit) {
        std::unordered_set<typename GraphType::NodeType> visited;
        
        std::function<void(typename GraphType::NodeType)> dfs_impl = [&](typename GraphType::NodeType node) {
            if (visited.contains(node)) return;
            
            visited.insert(node);
            visit(node);
            
            for (const auto& neighbor : graph.get_neighbors(node)) {
                dfs_impl(neighbor);
            }
        };
        
        dfs_impl(start);
    }

    /**
     * @brief Performs iterative depth-first search starting from a given node.
     * @tparam GraphType Graph type satisfying the Graph concept.
     * @tparam VisitFunc Callable type for node visitation.
     * @param graph The graph to traverse.
     * @param start The starting node.
     * @param visit Function called for each visited node.
     * 
     * Time Complexity: O(V + E) where V is reachable vertices, E is reachable edges.
     * Space Complexity: O(V) for visited set + stack
     * 
     * @ingroup dfs
     */
    template<Graph GraphType, typename VisitFunc>
    void dfs_iterative(const GraphType& graph, typename GraphType::NodeType start, VisitFunc visit) {
        std::unordered_set<typename GraphType::NodeType> visited;
        std::stack<typename GraphType::NodeType> stack;
        
        stack.push(start);
        
        while (!stack.empty()) {
            auto node = stack.top();
            stack.pop();
            
            if (visited.contains(node)) continue;
            
            visited.insert(node);
            visit(node);
            
            // Convert to vector for reverse iteration (consistent traversal order)
            auto neighbors = graph.get_neighbors(node);
            std::vector<typename GraphType::NodeType> neighbor_vec(neighbors.begin(), neighbors.end());
            
            // Add neighbors in reverse order for consistent left-to-right traversal
            for (auto it = neighbor_vec.rbegin(); it != neighbor_vec.rend(); ++it) {
                if (!visited.contains(*it)) {
                    stack.push(*it);
                }
            }
        }
    }

    /**
     * @brief Performs DFS on all connected components of the graph.
     * @tparam GraphType Graph type satisfying the Graph concept.
     * @tparam VisitFunc Callable type for node visitation.
     * @param graph The graph to traverse.
     * @param visit Function called for each visited node.
     * 
     * Time Complexity: O(V + E) where V is all vertices, E is all edges.
     * Space Complexity: O(V) for visited set + recursion depth.
     * 
     * @ingroup dfs
     */
    template<Graph GraphType, typename VisitFunc>
    void dfs_complete(const GraphType& graph, VisitFunc visit) {
        std::unordered_set<typename GraphType::NodeType> visited;
        
        // Reuse the same lambda pattern for consistency
        std::function<void(typename GraphType::NodeType)> dfs_impl = [&](typename GraphType::NodeType node) {
            if (visited.contains(node)) return;
            
            visited.insert(node);
            visit(node);
            
            for (const auto& neighbor : graph.get_neighbors(node)) {
                dfs_impl(neighbor);
            }
        };
        
        for (const auto& node : graph.get_all_nodes()) {
            if (!visited.contains(node)) {
                dfs_impl(node);
            }
        }
    }

    /** @} */ // end of dfs group
    /** @} */ // end of graph group

} // namespace graph
} // namespace algorithms