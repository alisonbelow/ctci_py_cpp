#include "bst_simple.h"

namespace bst 
{
template <typename T>
class BSTSelfBalancing {
public:
    using node_ptr = bst_node<T>*;

    // Inorder storage of subtrees of root into nodes
    // O(n), populates nodes
    void store_nodes(node_ptr root, std::vector& nodes)
    {
        if (root == nullptr) return;
        store_nodes(root->left, nodes);
        nodes.push_back(root);
        store_nodes(root->right, nodes);
    }

    // O(n), rebuilds tree
    node_ptr build_tree_util(std::vector& nodes, int start, int end)
    {
        if (start > end) return nullptr;
        int midIdx = (start + end)/2;
        auto root = nodes[midIdx];      // Get new root, in middle of tree
        root->left = build_tree_util(nodes, start, mid - 1);
        root->right = build_tree_util(nodes, mid + 1, end);
    }

    node_ptr bst_to_self_balancing(node_ptr root)
    {
        std::vector nodes;
        store_nodes(root, nodes);
        return build_tree_util(nodes, 0, nodes.size() - 1);
    }

};  // class BSTSelfBalancing

}   // namespace bst