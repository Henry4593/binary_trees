#include "binary_trees.h"

/**
 * bst_insert - inserts a value into a Binary Search Tree (BST)
 * @tree: double pointer to the root node of the BST
 * @value: the value to insert
 *
 * Description: This function inserts a value into a Binary Search Tree (BST).
 *              It maintains the BST property that each node has a valuegreater
 *              than all values in its left subtree and less than all values in
 *              its right subtree.
 *
 * Return: pointer to the newly created node, NULL on failure
 *         (e.g., memory allocation error)
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp = NULL;
	bst_t *second = NULL;
	bst_t *new = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	temp = *tree;
	while (temp)
	{
		second = temp;
		if (value < temp->n)
			temp = temp->left;
		else if (value > temp->n)
			temp = temp->right;
		else if (value == temp->n)
			return (NULL);
	}

	new = binary_tree_node(NULL, value);
	if (second == NULL)
		second = new;
	else if (value < second->n)
	{
		second->left = new;
		new->parent = second;
	}
	else
	{
		second->right = new;
		new->parent = second;
	}

	return (new);
}
