#include <initializer_list>

namespace bst 
{
template <typename T>
struct bst_node {
    T value;
    bst_node* left;
    bst_node* right;
    bst_node* parent;

    bst_node(T value_ = 0, bst_node* left_ = nullptr, 
             bst_node* right_ = nullptr, bst_node* parent_ = nullptr) : 
             value(value_), left(left_), right(right_), parent(parent_) {}
}; 

template <typename T>
class BSTSimple {
public:
    using node_ptr = bst_node<T>*;

    // Insert value given initial BT root, return root of new BT
    node_ptr insert(node_ptr root, T val)
    {
        if (!root) return new bst_node<T>(val);
        
        node_ptr temp;
        if (root->value == val) 
        {
            return root;
        }
        // Val less than root, put left
        else if (val < root->value)
        {
            temp = insert(root->left, val);
            root->left = temp;
        // Val greater than root, put right
        } else {
            temp = insert(root->right, val);
            root->right = temp;
        }
        // Assign temp parent = root
        temp->parent = root;
        return root;
    }

    // Insert entirety of initList, return root of new BT
    node_ptr insert(const std::initializer_list<T>& initList)
    {
        if (!initList.size()) return nullptr;
        // Create root of tree = no root, beginning of initList
        auto root = insert(nullptr, *(initList.begin()));
        // Populate BT with rest of list
        for (auto elem = initList.begin() + 1; elem < initList.end(); ++elem)
        {
            insert(root, *elem);
        }
        return root;
    }

    node_ptr delete_node(node_ptr node, T val)
    {
        if (!node) return node;
        
        // Node to delete in left subtree
        if (val < node->value)
        {
            node->left = delete_node(node->left, val);
        } 
        // Node to delete in right subtree
        else if (val > node->value)
        {
            node->right = delete_node(node->right, val);
        }
        // If val == node->value, delete this node
        else
        {
            // One child or no child
            if (!node->left)
            {
                auto temp = node->right;
                delete node;
                return temp;
            } 
            else if (!node->right)
            {
                auto temp = node->left;
                delete node;
                return temp;
            }

            // Two children, get inorder successor (rightmost min = min of larger elems)
            auto temp = min_tree(node->right);
        
            // Copy successor to node
            node->value = temp->value;

            // Delete sucessor
            node->right = delete_node(node->right, temp->value);
        }
        return node;
    }

    // Return node pointer to minimum node in BT given initial node pointer in BT
    // Max O(h) where h is height of tree
    node_ptr min_tree(node_ptr node)
    {
        while (node->left)
        {
            node = node->left;
        }
        return node;
    }

    bool is_left_child(node_ptr node)
    {
        if (!(node->parent)) return true;
        return node->parent->left == node;
    }

    // Find the "next" node (in-order successor) of given node in BT
    node_ptr successor(node_ptr node)
    {
        if (!node) return nullptr;
        
        // If node has a right predeccessor, return the rightmost
        if (node->right) return min_tree(node->right);

        // Move upwards, check if given node is a left child of the parent above it
        // When found node where is left child of parent, return parent, 
        while (!is_left_child(node))
        {
            node = node->parent;
        }
        return node->parent;
    }

    // Least common ancestor of two input values (assumed to be in tree)
    // O(h)
    node_ptr LCA(node_ptr root, T val1, T val2)
    {
        while (root)
        {
            if (root->value > val1 && root->value < val2)
                root = root->left;
            else if (root->value < val1 && root->value < val2)
                root = root->right;
            else    
                break;
        }
        return root;
    }

    // Returns depth of node to root of BST
    int depth(node_ptr node)
    {
        int d = -1;
        while (node)
        {
            ++d;
            node = node->parent;
        }
        return d;
    }

    // LCA with parent node, O(h) time, O(1) space
    node_ptr LCA_withparent(node_ptr node1, node_ptr node2)
    {
        int d1 = depth(node1);
        int d2 = depth(node2);
        int diff = d1 - d2;

        // If node2 deeper in BST, swap node1 and node2
        if (diff < 0)
        {
            auto temp = node1;
            node1 = node2;
            node2 = temp;
            diff *= -1;
        }

        // Move node1 up until same level as node2
        while (diff--)
        {
            node1 = node1->parent;
        }

        while (node1 && node2)
        {
            if (node2 == node1) return node1;
            node1 = node1->parent;
            node2 = node2->parent;
        }
    }

    // Searches for searchVal in root subtrees
    node_ptr search(node_ptr root, T searchVal)
    {
        if (!root) return nullptr;
        if (root->value == searchVal) return root;
        (searchVal < root->value) ? search(root->left, searchVal) : search(root->right, searchVal); 
    }

    // Print contents of BT with postorder traversal 
    // DF
    void postorder_print(node_ptr node)
    {
        if (!node) return;
        // Recurse left
        postorder_print(node->left);
        // Recurse right
        postorder_print(node->right);
        std::cout << node->value << " ";
    }

    // Print contents of BT with preorder traversal
    // DF
    void preorder_print(node_ptr node)
    {
        if (!node) return;
        std::cout << node->value << " ";
        // Recurse left
        preorder_print(node->left);
        // Recurse right
        preorder_print(node->right);
        
    }

    // Print contents of BT with inorder traversal
    // DF
    void inorder_print(node_ptr node)
    {
        if (!node) return;
        // Recurse left
        inorder_print(node->left);
        std::cout << node->value << " ";
        // Recurse right
        inorder_print(node->right);
        
    }

    // Print contents of DF traversal
    void depth_first_print(node_ptr node)
    {
        int height = get_max_depth(node);
        // TODO
    }

    // Get maximum depth of tree given node to consider root
    // Complexity = O(h) 
    int get_max_depth(node_ptr node)
    {
        if (!node) return 0;
        auto lDepth = get_max_depth(node->left);
        auto rDepth = get_max_depth(node->right);
        return (lDepth > rDepth ? lDepth + 1 : rDepth + 1);
    }

    // Get minimum depth of tree
    int get_min_depth(node_ptr node)
    {
        if (!node) return 0;
        // TODO
        return 0;
    }

    // Delete node
    // COmpl

};  // class BSTSimple

}   // namespace bst