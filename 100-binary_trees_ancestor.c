#include "binary_trees.h"

/**
 * binary_tree_is_descendant - Checks if a node is
 * a descendant of another node
 *
 * @node: A pointer to the potential descendant node
 * @ancestor: A pointer to the potential ancestor node
 *
 * Return: 1 if node is a descendant of ancestor, 0 otherwise
 */
int binary_tree_is_descendant(const binary_tree_t *ancestor,
										const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	while (node != NULL)
	{
		if (node == ancestor)
			return (1);
		node = node->parent;
	}

	return (0);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 *
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 *
 * Return: A pointer to the lowest common
 *ancestor node, or NULL if none found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
										const binary_tree_t *second)
{
	const binary_tree_t *temp;

	if (first == NULL || second == NULL)
		return (NULL);

	temp = first;
	while (temp != NULL)
	{
		if (binary_tree_is_descendant(temp, second))
			return ((binary_tree_t *)temp);
		temp = temp->parent;
	}

	return (NULL);
}
