#include "binary_trees.h"

/**
* binary_tree_insert_right - inserts a node as the right child of another node
* @parent: pointer to the node to insert the right child under
* @value: value to store in the new node
*
* Return: a pointer to the created new node, or NULL on failure
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
binary_tree_t *new;
if (parent == NULL)
return (NULL);
new = malloc(sizeof(binary_tree_t));
if (new == NULL)
return (NULL);
new->n = value;
new->parent = parent;
new->left = NULL;
new->right = parent->right;
parent->right = new;
if (new->right)
new->right->parent = new;

return (new);
}
