#include <concepts>
#include <functional>

namespace algorithms {
namespace graph {    
    /**
     * @concept Graph
     * @brief Graph interface requirements for BFS algorithms.
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
     * 
     * @ingroup graph
     */
    template<typename GraphType>
    concept Graph = requires(const GraphType& graph, typename GraphType::NodeType node) {
        typename GraphType::NodeType;
        { graph.get_neighbors(node) } -> std::ranges::range;
        { graph.get_all_nodes() } -> std::ranges::range;
        requires std::regular<typename GraphType::NodeType>;
    };

    /** @} */ // end of graph group

} // namespace graph
} // namespace algorithms