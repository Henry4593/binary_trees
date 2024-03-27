#include "binary_trees.h"

/**
 * binary_tree_is_avl - checks if a binary tree is an AVL tree
 * @tree: pointer to the root node of the tree
 *
 * Description: This function checks if a binary tree is an AVL tree. An AVL
 *              tree is a self-balancing Binary Search Tree (BST) where the
 *              difference in heights of the left and right subtrees for any
 *              node is at most 1.
 *              The function utilizes a helper function (`btia_helper`) to
 *              perform the recursive checks on the tree structure.
 *
 * Return: 0 if the tree is not an AVL tree, 1 if it is
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (btia_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btia_helper - recursive helper function for binary_tree_is_avl
 * @tree: pointer to the current node in the tree
 * @min: minimum allowed value in the subtree
 * @max: maximum allowed value in the subtree
 *
 * Description: This function is a helper function for `binary_tree_is_avl`.
 *              It recursively checks if a subtree rooted at the current node
 *              is an AVL tree. It ensures:
 *              - Node value is within allowed range (min <= value <= max).
 *              - The difference in heights of left and right subtrees is at
 *                most 1
 *              - Left subtree values are less than the current node's value.
 *              - Right subtree values are greater than the current node's
 *                value.
 *              - Both left and right subtrees are also AVL trees.
 *
 * Return: 0 if the subtree is not an AVL tree, 1 if it is
 */
int btia_helper(const binary_tree_t *tree, int min, int max)
{
	int path_l, path_r;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	path_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	path_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(path_l - path_r) > 1)
		return (0);

	return (btia_helper(tree->left, min, tree->n - 1) &&
		btia_helper(tree->right, tree->n + 1, max));

}

/**
 * binary_tree_height - calculates the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Description: This function calculates the height of a binary tree. Theheight
 *              of a tree is defined as the maximum number of nodes along any
 *              longest path from the root node down to a leaf node.
 *              The function utilizes recursion to traverse the tree and keep
 *              track of the maximum height found so far.
 *
 * Return: height of the binary tree, 0 if the tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
