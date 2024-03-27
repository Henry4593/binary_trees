#include "binary_trees.h"

bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * inorder_successor - finds the inorder successor of a node in a BST
 * @root: pointer to the node whose successor is to be found
 *
 * Description: This function finds the inorder successor of a node in a Binary
 *              Search Tree (BST). The inorder successor is the next node that
 *              would be visited during an in-order traversal of the BST
 *              starting from the root.
 *
 * Return: pointer to the inorder successor node, NULL if no successor exists
 *         (e.g., the node is the rightmost node in the BST)
 */

bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - deletes a node from a Binary Search Tree (BST)
 * @root: pointer to the root node of the BST
 * @node: pointer to the node to be deleted
 *
 * Description: This function deletes a node from a Binary Search Tree (BST).
 *              It handles three cases:
 *              - Node has no children or only a right child.
 *              - Node has only a left child.
 *              - Node has two children.
 *              The function maintains the BST property after deletion.
 *
 * Return: pointer to the new root node after deletion, NULL on failure
 *         (e.g., node not found in the BST)
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/* No children or right-child only */
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	/* Left-child only */
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	/* Two children */
	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * bst_remove_recursive - recursively removes a node from a BST
 * (helper function for bst_remove)
 * @root: pointer to the root node of the BST
 * @node: pointer to the current node in the search
 * @value: the value to remove
 *
 * Description: This function recursively removes a node with the specified
 *              value from a Binary Search Tree (BST). It utilizes a helper
 *              function for bst_remove, which makes the main function cleaner.
 *              The function handles the following cases:
 *              - Node not found (NULL)
 *              - Node with the value is found
 *              - Value is less than the current node's value (search left
 *                subtree)
 *              - Value is greater than the current node's value (search right
 *                subtree)
 *
 * Return: pointer to the new root node after deletion, NULL on error
 */

bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - removes a node from a Binary Search Tree (BST)
 * @root: pointer to the root node of the BST
 * @value: the value to remove
 *
 * Description: This function removes a node with the specified value from a
 *              Binary Search Tree (BST). It utilizes the`bst_remove_recursive`
 *              function to perform the actual removal.
 *
 * Return: pointer to the new root node after deletion, NULL on error
 */

bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
