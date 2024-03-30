#include "binary_trees.h"

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	long int height_diff;

	if (!tree)
		return (0);

	if (!binary_tree_is_bst(tree))
		return (0);

	height_diff = binary_tree_height(tree->left) -
						binary_tree_height(tree->right);
	if (height_diff > 1 || height_diff < -1)
		return (0);

	return (1);
}


/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left != NULL && tree->left->n > tree->n)
		return (0);

	if (tree->right != NULL && tree->right->n < tree->n)
		return (0);

	if (tree->left != NULL && binary_tree_is_bst(tree->left))
		return (0);

	if (tree->right != NULL && binary_tree_is_bst(tree->right))
		return (0);

	return (1);
}


/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: A pointer to the root node of the tree to measure the height
 *
 * Return: If tree is NULL, your function must return 0
 *
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);
	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}
