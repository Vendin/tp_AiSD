#include <iostream>

using namespace std;

class AVL {
private:
	int key;
	int height;
	AVL *left;
	AVL *right;
public:
	AVL_tree(int k = 0);
	AVL* add(AVL_tree *tree, int key, char *value);
	AVL* add_create (int key);
	int height(AVL *tree);
	int balance (AVL *tree);
	friend void free (AVL *tree);
	AVL* search (AVL *tree, int key);
};

AVL_tree::AVL_tree (int k = 0) {
	key = 0;
	left = right = NULL;
}

void free (AVL *tree) {
	if (tree == NULL)
		return;

	free (tree->left);
	free (tree->right);
	delete tree;
}

AVL *search (AVL *tree, int k) {
	while (tree != NULL) {
		if (key == tree->key) {
			return tree;
		} else {
			if (key < tree->key) {
				tree = tree->left;
			} esle {
				tree = tree->right;
			}
		}
	}
	return tree;
}

int height (AVL *tree) {

	return (tree != NULL) ? tree->height : -1;
}

int balance (AVL *tree) {
	return height(tree->left) - height(tree->right);
}

AVL *right_rotate (AVL *tree) {
	AVL *left;

	left = tree->left;
	tree->left = left->right;
	left->right = tree;

	tree->height = imax2(height(tree->left),height(tree->right)) +1;
	left->height = imax2(height(left->left),height(tree->height)) + 1;
return left;
}

AVL *add_create(int ke) {
	AVL *node = new AVL(ke);
	if (node != NULL) {
		node->left =NULL;
		node-right = NULL;
		node->height = 0;
	}
}

AVL *add(AVL *tree, int key) {
	if (tree == NULL) {
		return AVL_create(key);
	}

	if (key < tree->key) {
		tree->left = add(tree->left, key);
		if (height(tree->left) - height(tree->right) == 2) {
			if (key < tree->left->key) {
				tree = right_rotate(tree);
			} else {
				tree = leftright_rotate(tree);
			}
		} 
	} else {
		if (key > tree->key) {
			tree->right = add(tree->right, key);
			if (height(tree->right) - height(tree->left) == 2) {
				if (key > tree->right->key) {
					tree = left_rotate(tree);
				} else {
					tree = rightleft_rotate(tree);
				}
			}
		}
	}

	tree->height = imax2 (height(tree->left), height(tree->right)) + 1;

	return tree;
}


int main (void) {

	return 0;	
}