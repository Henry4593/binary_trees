#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right rotation on a binary tree node
 * @tree: pointer to the node to perform the right rotation on
 *
 * Description: Performs a right rotation on the provided binary tree node.
 *              This rearranges the node's structure such that its left child
 *              becomes the new root node, and the original node becomes the
 *              right child of the new root.
 *
 * Return: pointer to the new root node after the right rotation,
 *         NULL on error (e.g., if the node has no left child)
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp = NULL, *parent;

	if (!tree || !tree->left)
		return (NULL);
	temp = tree;
	parent = tree->parent;
	tree = tree->left;
	tree->parent = NULL;
	if (tree->right)
	{
		temp->left = tree->right;
		tree->right->parent = temp;
	}
	else
		temp->left = NULL;
	temp->parent = tree;
	tree->right = temp;
	if (parent)
		parent->left = tree;
	tree->parent = parent;
	return (tree);
}
