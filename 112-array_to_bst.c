#include "binary_trees.h"

/**
 * array_to_bst - converts a sorted array to a Binary Search Tree (BST)
 * @array: pointer to the first element of the sorted array
 * @size: number of elements in the array
 *
 * Description: This function converts a sorted array to a Binary Search Tree
 *              (BST). The BST will have the same elements as the array, and
 *              it will maintain the BST property: each node has a valuegreater
 *              than all values in its left subtree and less than all values in
 *              its right subtree.
 *
 * Return: pointer to the root node of the BST, NULL on failure
 *         (e.g., memory allocation error)
 */

bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int idx;
	bst_t *root = NULL;

	for (idx = 0; idx < size; idx++)
		bst_insert(&root, array[idx]);

	return (root);
}
