#include "binary_trees.h"


/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 *
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: The balance factor of the tree, or 0 if tree is NULL.
 *
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);
	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);
	return (left_height - right_height);
}
