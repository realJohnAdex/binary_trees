#include "binary_trees.h"


/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 *
 * @tree: A pointer to the node of the tree to count leaves.
 *
 * Return: The number of leaves in the tree, or 0 if tree is NULL.
 *
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t result;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	result = binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);

	return (result);
}
