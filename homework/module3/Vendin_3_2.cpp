#include <iostream>

using namespace std;

template <typename X> struct CBinaryNode {
	int data;
	CBinaryNode <X> *left;
	CBinaryNode <X> *right;
	CBinaryNode () {
		left = NULL;
		right = NULL;
	}
};

template <typename V> void insert (CBinaryNode <V> *root, CBinaryNode <V> *inserted) {
 	if (root->data <= inserted->data) {
 		if (root->right == NULL) {
 			root->right = inserted;
 		} else {
 			insert (root->right, inserted);
 		}
 	} else {
 		if (root->left == NULL) {
 			root->left = inserted;
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
		cin >> Bin[i]->data;
		insert (Bin[0], Bin[i]);
	}

	inOrderTravers (Bin[0]);
	return 0;
}
