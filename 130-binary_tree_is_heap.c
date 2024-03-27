#include "binary_trees.h"

/**
 * binary_tree_is_heap - checks if a binary tree is a max-heap
 * @tree: pointer to the root node of the binary tree
 *
 * Description: This function checks if a given binary tree is a max-heap.
 *              It utilizes a helper function `btih_helper` to recursively
 *              traverse the tree and verify the heap property at each node.
 *              The heap property states that a parent node should be greater
 *              than or equal to its children.
 *
 * Return: 1 if the tree is a max-heap, 0 otherwise
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btih_helper(tree));
}

/**
 * btih_helper - helper function for binary_tree_is_heap
 * @tree: pointer to the root node of the binary tree
 *
 * Return: 1 if the tree rooted at 'tree' is a max-heap, 0 otherwise
 */

int btih_helper(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (!binary_tree_is_complete(tree))
		return (0);

	if (tree->left)
		if (tree->left->n > tree->n)
			return (0);
	if (tree->right)
		if (tree->right->n > tree->n)
			return (0);

	return (btih_helper(tree->left) &&
		btih_helper(tree->right));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node
 *
 * Return: 1 if complete, 0 otherwise
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
 * btic_helper - helper function for binary_tree_is_complete
 * @tree: pointer to the current node in the tree traversal
 * @index: index of the current node in an in-order traversal
 * @size: total number of nodes in the tree
 *
 * Return: 1 if the tree is complete up to the current node, 0 otherwise
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
 * binary_tree_size - calculates the size of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: size of the binary tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
