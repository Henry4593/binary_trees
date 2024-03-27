#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree (BST)
 * @tree: pointer to the root node of the BST to search
 * @value: the value to search for
 *
 * Description: This function searches for a value in a Binary SearchTree(BST).
 *              It starts at the root node and traverses the tree based on the
 *              value comparisons. If the value is found, a pointer to the node
 *              containing the value is returned.
 *
 * Return: pointer to the node containing the value, NULL if not found or tree
 *         is NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node = (bst_t *)tree;

	if (!tree)
		return (NULL);

	while (node)
	{
		if (value == node->n)
			return (node);
		if (value < node->n)
			node = node->left;
		else if (value > node->n)
			node = node->right;
	}

	return (NULL);
}
