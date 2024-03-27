#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left rotation on a binary tree node
 * @tree: pointer to the node to perform the left rotation on
 *
 * Description: Performs a left rotation on the provided binary tree node.
 *              This rearranges the node's structure such that its right child
 *              becomes the new root node, and the original node becomes the
 *              left child of the new root.
 *
 * Return: pointer to the new root node after the left rotation,
 *         NULL on error (e.g., if the node has no right child)
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp = NULL, *parent;

	if (!tree || !tree->right)
		return (NULL);
	temp = tree;
	parent = tree->parent;
	tree = tree->right;
	tree->parent = NULL;
	if (tree->left)
	{
		temp->right = tree->left;
		tree->left->parent = temp;
	}
	else
		temp->right = NULL;
	temp->parent = tree;
	tree->left = temp;
	if (parent)
		parent->right = tree;
	tree->parent = parent;
	return (tree);
}
