#include "binary_trees.h"

/**
 * sorted_array_to_avl - converts a sorted array to a balanced AVL tree
 * @array: pointer to the sorted integer array
 * @size: size of the array
 *
 * Description: This function converts a sorted integer array into a balanced
 *              AVL tree. It recursively builds the AVL tree by inserting
 *              elements from the array in their sorted order, maintaining the
 *              AVL property at each insertion.
 *
 * Return: pointer to the root node of the newly created AVL tree, NULL on
 *         failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t middle;

	if (!array)
		return (NULL);
	middle = (size - 1) / 2;
	tree = binary_tree_node(NULL, array[middle]);

	sata_helper(&tree, array, -1, middle);
	sata_helper(&tree, array, middle, size);

	return (tree);
}

/**
 * sata_helper - (deprecated) helper function for sorted_array_to_avl
 * @root: double pointer to the root node of the (supposed) AVL tree beingbuilt
 * @array: pointer to the sorted integer array
 * @lo: starting index in the array for the current subtree
 * @hi: ending index in the array for the current subtree
 *
 * Description: This function (deprecated) attempts to recursively build an AVL
 *              tree from a sorted array. However, it has several issues:
 *              - It doesn't maintain the AVL property during insertion,
 *                potentially leading to an unbalanced tree.
 *              - It modifies the `*root` pointer directly, which can be
 *                confusing and lead to unexpected behavior depending on how
 *                it's called.
 *
 */

void sata_helper(avl_t **root, int *array, size_t lo, size_t hi)
{
	avl_t *new = NULL;
	size_t middle;

	if (hi - lo > 1)
	{
		middle = (hi - lo) / 2 + lo;
		new = binary_tree_node(*root, array[middle]);
		if (array[middle] > (*root)->n)
			(*root)->right = new;
		else if (array[middle] < (*root)->n)
			(*root)->left = new;
		sata_helper(&new, array, lo, middle);
		sata_helper(&new, array, middle, hi);
	}
}
