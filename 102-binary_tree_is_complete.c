#include "binary_trees.h"



/**
 * binary_tree_size - Measures the size of a binary tree
 *
 * @tree: A pointer to the root node of the tree to measure
 *
 * Return: The size of the tree, or 0 if tree is NULL
 */


size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}


/**
 * binary_tree_is_complete_helper - Checks if a binary tree is complete
 *
 * @tree: A pointer to the root node of the tree
 * @size: The size of the tree
 * @index: The index of the current node
 * @complete: Pointer to a variable to store completeness status
 *
 */
void binary_tree_is_complete_helper(const binary_tree_t *tree, size_t size,/
												size_t index, size_t *complete)
{
	if (tree == NULL)
		return;

	if (index >= size)
	{
		*complete = 0;
		return;
	}

	binary_tree_is_complete_helper(tree->left, size, 2 * index + 1, complete);
	binary_tree_is_complete_helper(tree->right, size, 2 * index + 2, complete);
}



/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 *
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */


int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size, index = 0;
	int complete = 1;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);

	binary_tree_is_complete_helper(tree, size, 0, &index, &complete);

	return (complete);
}
