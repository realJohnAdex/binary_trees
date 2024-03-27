#include "binary_trees.h"



/**
 * Heightfunc - Measures the height of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree, or 0 if tree is NULL.
 */

size_t Heightfunc(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = Heightfunc(tree->left);
	right_height = Heightfunc(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * SizeFunc - Measures the size of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the size.
 *
 * Return: The size of the tree, or 0 if tree is NULL.
 *
 */

size_t SizeFunc(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + SizeFunc(tree->left) + SizeFunc(tree->right));
}



/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 *
 */


int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, size, perfect_size;

	if (tree == NULL)
		return (0);

	height = Heightfunc(tree);
	size = SizeFunc(tree);
	perfect_size = (1 << height) - 1;

	return (size == perfect_size);
}
