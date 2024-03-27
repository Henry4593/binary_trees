#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle node of a given node
 * @node: pointer to the node to find the uncle for
 *
 * Return: pointer to the uncle node, or NULL if no uncle or error
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	return (binary_tree_sibling(node->parent));
}

/**
 * binary_tree_sibling - finds the sibling node of a given node in a binarytree
 * @node: pointer to the node for which to find the sibling
 *
 * Return: pointer to the sibling node, or NULL if no sibling or error
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}
