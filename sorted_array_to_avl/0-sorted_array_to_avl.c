#include "binary_trees.h"
#include <stdlib.h>
#include <stddef.h>

/**
* sorted_array_to_avl - a function that builds an AVL tree
* from a sorted array
*
* @array: pointer to array containing elements
* @size: size of the array
*
* Return: pointer to the root node of the created AVL tree,
* or NULL on failure or if array is NULL or size is 0
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
if (array == NULL || size == 0)
	return (NULL);
return (helper_array_to_avl(array, 0, size - 1, NULL));
}

/**
* helper_array_to_avl - a helper function that builds an AVL tree
* from a sorted array
*
* @array: pointer to array containing elements
* @beginning: starting index of the subarray
* @end: ending index of the subarray
* @root: pointer to the parent node of the current subtree
*
* Return: pointer to the root node of the created AVL tree,
* or NULL on failure
*/
avl_t *helper_array_to_avl(int *array, int beginning, int end, avl_t *root)
{
	int middle;
	avl_t *tree;

	if (beginning > end)
		return (NULL);

	middle = (beginning + end) / 2;

	tree = calloc(1, sizeof(avl_t));
	if (tree == NULL)
		return (NULL);

	tree->parent = root;
	tree->left = helper_array_to_avl(array, beginning, middle - 1, tree);
	tree->right = helper_array_to_avl(array, middle + 1, end, tree);
	tree->n = array[middle];

	return (tree);
}
