#include "binary_trees.h"

/**
 * array_to_avl - converts a sorted array to a balanced AVL tree
 * @array: pointer to the sorted integer array
 * @size: size of the array
 *
 * Description: This function converts a sorted integer array into a balanced
 *              AVL tree. It iterates through the array and inserts eachelement
 *              into the AVL tree using `avl_insert`. The function assumes the
 *              input array is already sorted in ascending order.
 *
 * Return: pointer to the root node of the newly created AVL tree, NULL on
 *         failure
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t idx, idx_j;

	if (array == NULL)
		return (NULL);

	for (idx = 0; idx < size; idx++)
	{
		for (idx_j = 0; idx_j < idx; idx_j++)
		{
			if (array[idx_j] == array[idx])
				break;
		}
		if (idx_j == idx)
		{
			if (avl_insert(&tree, array[idx]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
