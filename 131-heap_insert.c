#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a min-heap
 * @root: double pointer to the root node of the min-heap
 * @value: the value to insert
 *
 * Return: pointer to the newly created leaf node, NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *flip;
	int leaves, size, temp, bit, sub, level;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;
	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;

	new = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new) : (tree->left = new);

	flip = new;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		temp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = temp;
		new = new->parent;
	}
	return (new);
}

/**
 * binary_tree_size - Calculates the size of a binary tree
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: The size of the binary tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
