#include "binary_trees.h"

/**
 * binary_tree_levelorder - performs a level-order traversal of a binary tree
 * @tree: pointer to the root node of the tree
 * @func: pointer to a function to call for each node
 *
 * Description: This function performs a level-order traversal of a binarytree.
 *              For each node encountered, it calls the provided function
 *              (`func`) passing the node's value (`n`).
 *
 * Return: nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, maxlevel;

	if (!tree || !func)
		return;

	maxlevel = binary_tree_height(tree) + 1;

	for (level = 1; level <= maxlevel; level++)
		btlo_helper(tree, func, level);
}

/**
 * btlo_helper - performs a level-order traversal and calls a function on each
 *               node
 * @tree: pointer to the root node of the tree
 * @func: pointer to a function to call for each node
 * @level: current level in the traversal
 *
 * Description: This function performs a level-order traversal of a binary
 *              tree. For each node encountered at a specific level, it calls
 *              the provided function (`func`) passing the node's value (`n`).
 *
 * Return: nothing (void function)
 */


void btlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		btlo_helper(tree->left, func, level - 1);
		btlo_helper(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_height - calculates the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Description: This function calculates the height of a binary tree.The height
 *              of a tree is defined as the maximum number of levels (excluding
 *              the root level) from the root node to the farthest leaf node.
 *
 * Return: the height of the tree, 0 if the tree is NULL
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
