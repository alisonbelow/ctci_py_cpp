#include "bst_simple.h"

namespace bst 
{
template <typename T>
class BSTtoDLL {
public:
    using node_ptr = bst_node<T>*;

    void to_dll(node_ptr root, node_ptr* head)
    {
        if (!root) return;

        // Recurse right subtree
        to_dll(root->right, head);

        // Insert root into CDLL
        root->right = *head;
        // Change left pointer of previos head
        if (*head != nullptr) (*head)->left = root;
        // Change left
        *head = root;

        // Recurse left subtree
        to_dll(root->left, head);
    }

};  // class BSTtoDLL
}   // namespace bst