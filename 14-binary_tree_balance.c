#include "binary_trees.h"

/**
 * binary_tree_balance - calculates the balance factor of a binary tree node
 * @tree: pointer to the node to calculate the balance factor for
 *
 * Return: the balance factor (left height - right height), 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - calculates the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: the height of the tree, 0 if the tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}
