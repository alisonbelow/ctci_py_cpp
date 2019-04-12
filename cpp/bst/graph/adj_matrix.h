#include <vector>

namespace graph
{
template <typename T, bool directed = true>
class AdjMatrix
{
public:
    using value_type = T;
    using cell_type = typename std::pair<size_t, size_t>;
    using matrix_type = typename std::vector<std::vector<T>>;
    using const_reference = std::vector<T>&;

    AdjMatrix (size_t num_vertices = 0) : num_vertices_(num_vertices), num_edges_(0), grid_(num_vertices_, std::vector<T>(num_vertices_, value_type{})) {}

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

    void add_edge(size_t to, size_t from, T cost)
    {
        grid_.at(to).at(from) = cost;
        // If not directed, add corresponding edge
        if (!directed) { vertices_.at(from).at(to) = cost; }
        ++num_edges_;
    }

    const_reference adjacent_vertices(size_t vertex) const
    {
        return grid_.at(vertex);
    }

private:
    size_t num_edges_;
    size_t num_vertices_;
    std::vector<std::vector<T>> grid_;

};  // class AdjMatrix
} // namespace graph