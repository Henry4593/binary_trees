#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling node of a given node
 * @node: pointer to the node to find the sibling for
 *
 * Return: pointer to the sibling node, or NULL if no sibling or error
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
if (!(node) || !(node->parent))
{
return (NULL);
}
if (node == node->parent->left)
{
return (node->parent->right);
}
return (node->parent->left);
}
