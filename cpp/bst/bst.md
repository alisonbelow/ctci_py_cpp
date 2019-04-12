# Binary Search Tree

Flavor of binary tree (elem has at most two child nodes) where the key of the node is greater than all nodes in its left subtree and the key of the node is less than all the nodes in its right subtree.

## Complexity

* **Insert** - *O*(log(n)), space *O*(node)
* **Delete** - *O*(log(n)), space *O*(node)
    Three cases: (1) node is leaf, simply delete
                 (2) node has one child, assign to parent
                 (3) node has two children, find inorder successor of node, copy inorder sucessor to node position and delete inorder sucessor. Inorder predecessor can also be used. Inorder sucessor is needed when **right child is not empty**. Inorder sucessor = min val of right child of the node
* **Search** - *O*(log(n)), no space
* **LCA** - *O*(h), no space
    Find common parent between two input values and root

## Traversal

**Preorder** - Root node of tree processed first, then left subtree, then right subtree
**Postorder** - Left subtree traversed, then right subtree, then root node
**Inorder** - Left subtree traversed, then root node processed, then right subtree --> outputs tree items sorted min --> max

## Self-Balancing BST

BST, not self-balancing, can result skewed if all elements inserted in sorted order. E.g. [1,2,3,4,5] input into `bst_simple` would result in:

```
1
 \
  2
   \
    3
     \
      4
       \
        5
```

Efficient solution for converting BST into self-balancing can be done in *O*(n) time with *O*(n) space. See `bst_self_balancing.h`

## BST to DLL or CDLL

Convert BST to doubly linked list, assume no parent in BST. Use inorder traversal. See `bst_to_cdll.h`
Alg: create function that accepts `node_ptr` root, and pointer to `node_ptr` head, beginning of DLL
    If root is null return
    Recursively convert right subtree 
    Insert root into DLL (`root->right = *head; if *head != NULL, *head->left = root`)
    Change head to root (*head = root)
    Recursively convert left subtree

To convert DLL to  CDLL, root->left = last elem, last_elem->right = root

See `bst_to_dll.h`.

## Why BST?

Over hash table, that has O(1) search, insert, and delete.

* all keys in sorted order with inorder traversal
* Successor/predecessor, minimum, maximum elem search is easy
* Can create custom BST easily, not use library impl
* Self-balancing = all operations in *O*(log(n)) time