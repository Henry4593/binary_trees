#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree
 *
 * Description: This function checks if a binary tree is complete. A complete
 *              binary tree is one where all levels except possibly the last
 *              are completely filled, and all nodes are as far left as
 *              possible.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = binary_tree_size(tree);

	return (btic_helper(tree, 0, size));
}

/**
 * btic_helper - helper function to check if a binary tree is complete
 * @tree: pointer to the root node of the tree
 * @index: current index in the level-order traversal
 * @size: maximum number of nodes in the complete binary tree
 *
 * Description: This function assists in checking if a binary tree is complete.
 *              It performs a level-order traversal and checks if nodes exist
 *              only at specific indices based on the tree's size. If anon-null
 *              node is encountered at an unexpected index (indicating a gap),
 *              the tree is not complete.
 *
 * Return: 1 if the tree is (so far) complete, 0 otherwise.
 */

int btic_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (btic_helper(tree->left, 2 * index + 1, size) &&
		btic_helper(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - calculates the number of nodes in a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Description: recursively traverses the tree, counting nodes at each level
 *
 * Return: the number of nodes in the tree, otherwise NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
