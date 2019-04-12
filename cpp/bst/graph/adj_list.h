#include <vector>
#include <list>

namespace graph
{
template <typename T, bool directed = true>
class AdjList
{
public:
    using value_type = T;
    using list_type = typename std::forward_list<T>;
    using graph_type = typename std::vector<std::forward_list<T>;
    using const_reference = std::forward_list<T>&;
    using iterator = graph_type::iterator;

    AdjList(size_t num_vertices) : vertices_{num_vertices}, num_vertices_(num_vertices), num_edges(0) {}

    size_t num_vertices() const noexcept
    {
        return num_vertices_;
    }

    size_t num_edges() const noexcept
    {
        return num_edges_;
    }

    bool empty() const noexcept
    {
        return (num_vertices_ == 0);
    }

    void add_edge(size_t to, size_t from)
    {
        // TODO check to < num_vertices_, from < num_vertices_
        vertices_.at(to).push_front(from);
        // If not directed, add corresponding edge
        if (!directed) { vertices_.at(from).push_front(to); }
        ++num_edges;
    }

    const_reference adjacent_vertices(size_t vertex) const 
    {
        return vertices_.at(vertex);
    }

    iterator begin() { return vertices_.begin(); }
    iterator end() { return vertices_.end(); }

private:
    std::vector<std::forward_list<T> vertices_;
    const size_t num_vertices_;
    size_t num_edges;

};  // class AdjList
} // namespace graph