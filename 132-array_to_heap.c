#include "binary_trees.h"

/**
 * array_to_heap - Converts an array into a heap
 * @array: Pointer to the integer array
 * @size: Size of the array
 *
 * Return: Pointer to the root node of the created heap, or NULL on failure.
 */

heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int idx;
	heap_t *root = NULL;

	for (idx = 0; idx < size; idx++)
		heap_insert(&root, array[idx]);

	return (root);
}
