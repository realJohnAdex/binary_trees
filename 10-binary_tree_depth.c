#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 *
 * @tree: A pointer to the node to measure the depth
 *
 * Return: If tree is NULL, your function must return 0
 *
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t node_depth = 0;

	if (tree == NULL)
		return (0);
	
	if (tree->parent)
	node_depth = binary_tree_depth(tree->parent) + 1;

	return (node_depth);
}
