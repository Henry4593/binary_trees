#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int balance(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * height - calculates the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Description: This function calculates the height of a binary tree. Theheight
 *              of a tree is defined as the maximum number of nodes along any
 *              longest path from the root node down to a leaf node.
 *              The function utilizes recursion to traverse the tree and keep
 *              track of the maximum height found so far. Empty child nodes are
 *              considered to have a height of 0.
 *
 * Return: height of the binary tree, 0 if the tree is NULL
 */

size_t height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * balance - calculates the balance factor of a binary tree node
 * @tree: pointer to the binary tree node
 *
 * Return: The balance factor of the node, or 0 if the tree is NULL
 */

int balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * avl_insert_recursive - recursively inserts a value into an AVL tree
 * @tree: double pointer to the root node of the AVL tree
 * @parent: pointer to the parent node of the current node
 * @new: double pointer to store the newly created node (output)
 * @value: the value to insert
 *
 * Description: This function recursively inserts a new node with the specified
 *              value into an AVL tree. It maintains the AVL tree property by
 *              performing rotations if the balance factor becomes unbalanced
 *              after insertion.
 *
 * Return: pointer to the new root node after insertion, NULL on failure
 */

avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int bfactor;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	bfactor = balance(*tree);
	if (bfactor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (bfactor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (bfactor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bfactor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - inserts a value into an AVL tree
 * @tree: double pointer to the root node of the AVL tree
 * @value: the value to insert
 *
 * Description: This function inserts a new node with the specified value into
 *              an AVL tree. It utilizes the `avl_insert_recursive` function to
 *              perform the actual insertion and maintain the AVL tree property
 *
 * Return: pointer to the newly created node, NULL on memory allocation failure
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new, value);
	return (new);
}
