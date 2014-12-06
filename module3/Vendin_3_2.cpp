#include <iostream>

using namespace std;

template <typename X> struct CBinaryNode {
	int data;
	CBinaryNode <X> *left;
	CBinaryNode <X> *right;
	CBinaryNode <X> *parent;
	CBinaryNode () {
		left = right = parent = NULL;
	}
};

template <typename V> void insert (CBinaryNode <V> *root, CBinaryNode <V> *inserted) {
 	if (root->data <= inserted->data) {
 		if (root->right == NULL) {
 			root->right = inserted;
 			inserted->parent = root;
 		} else {
 			insert (root->right, inserted);
 		}
 	} else {
 		if (root->left == NULL) {
 			root->left = inserted;
 			inserted->parent = root;
 		} else {
 			insert (root->left, inserted);
 		}
 	}
 }

template <typename Y> void inOrderTravers(CBinaryNode <Y> *root) {
    if (root) {
        inOrderTravers(root->left);
        cout << root->data << endl;
        inOrderTravers(root->right);

    }
}

int main (void) {
	int N;
	cin >> N;

	CBinaryNode <int> **Bin;
	Bin = new CBinaryNode<int>*[N];
	for (int i = 0; i < N; ++i) {
		Bin[i] = new CBinaryNode<int>();
	}
	for (int i = 0; i < N; ++i) {
		cin >> Bin[i]->data;
	}
	for (int i = 1; i < N; ++i) {
		insert (Bin[0], Bin[i]);
	}

	inOrderTravers (Bin[0]);
	return 0;
}