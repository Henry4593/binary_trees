#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a valid binary search tree
 *                      (BST)
 * @tree: pointer to the root node of the tree
 *
 * Description: This function checks if a binary tree is a valid Binary Search
 *              Tree (BST). A BST has the following properties:
 *              - The left subtree of a node contains only values less than the
 *                node's value.
 *              - The right subtree of a node contains only values greater than
 *                the node's value.
 *              - Both the left and right subtrees are also BSTs.
 *
 * Return: 1 if the tree is a BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btib_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btib_helper - helper function to check if a binary tree is a binary search
 *               tree (BST)
 * @tree: pointer to the root node of the tree
 * @min: minimum allowed value for nodes in the current subtree
 * @max: maximum allowed value for nodes in the current subtree
 *
 * Description: Recursively checks if a binary tree is a BST. A BST has the
 *              property that the value of each node is greater than all values
 *              in its left subtree and less than all values in its right
 *              subtree.
 *
 * Return: 1 if the tree is a BST, 0 otherwise
 */

int btib_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (btib_helper(tree->left, min, tree->n - 1) &&
		btib_helper(tree->right, tree->n + 1, max));
}
