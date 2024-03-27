#include "binary_trees.h"

/**
 * binary_tree_size - calculates the size of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: the number of nodes in the tree, 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
if (!tree)
return (0);
return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
