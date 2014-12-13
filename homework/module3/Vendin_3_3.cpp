#include <iostream>

using namespace std;

template <typename X> class TreeNode {
public:
	X *left;
	X *right;
	X *parent;
	TreeNode () {
		left = right = parent = NULL;
	}
};

class DescartesTree : public TreeNode<DescartesTree> {
private:
	int x, y;
public:
	DescartesTree (int X=0, int Y=0):x(X), y(Y) {}
	friend void split (DescartesTree *cuurret , int key, DescartesTree *& left, DescartesTree *& right);
	friend DescartesTree* merge (DescartesTree *left, DescartesTree *right);
	template <typename X> friend void insert_descartes (X *root, X *inserted);
};



template <typename X> void insert_descartes (X *root, X *inserted) {
	/*if (root->y > inserted->y) {
		if (root->x <= inserted->x) {
	 		if (root->right == NULL) {
	 			root->right = inserted;
	 			inserted->parent = root;
	 		} else {
	 			insert_descartes (root->right, inserted);
	 		}
	 	} else {
	 		if (root->left == NULL) {
	 			root->left = inserted;
	 			inserted->parent = root;
	 		} else {
	 			insert_descartes (root->left, inserted);
	 		}
	 	}
	} else {
		DescartesTree *l = new DescartesTree();
		DescartesTree *r = new DescartesTree();
		split (root, root->x, l, r);
		inserted->left = l;
		l->parent = inserted;
		inserted->right = r;
		r->parent = inserted;
	}*/
	DescartesTree *l = new DescartesTree();
	DescartesTree *r = new DescartesTree();
	split(root, inserted->x, l, r);
	merge(merge(inserted,r), l);
}

void split (DescartesTree *cuurret , int key, DescartesTree *& left, DescartesTree *& right) {
	if (cuurret == NULL) {
		left = right = NULL;
	} else {
		if ( key >= cuurret->x) {
			split (cuurret->right, key, cuurret->right, right);
			left = cuurret;
		} else {
			split (cuurret->left, key, left, cuurret->left);
			right = cuurret;
		}
	}
}

DescartesTree* merge (DescartesTree *left, DescartesTree *right) {
	if (left == 0 || right == 0) {
		return left == 0 ? right : left;
	}
	if (left->y > right->y) {
		left->right = merge (left->right, right);
		return left;
	}
	right->left = merge(left, right->left);
	return right;
}



class BinaryTree : public TreeNode<BinaryTree> {
private:
	int x;
public:
	BinaryTree (int X=0): x(X) {}
	template <typename X>	friend void insert_binary (X *root, X *inserted);

};

template <typename X> void insert_binary (X *root, X *inserted) {
 	if (root->x <= inserted->x) {
 		if (root->right == NULL) {
 			root->right = inserted;
 			inserted->parent = root;
 		} else {
 			insert_binary (root->right, inserted);
 		}
 	} else {
 		if (root->left == NULL) {
 			root->left = inserted;
 			inserted->parent = root;
 		} else {
 			insert_binary (root->left, inserted);
 		}
 	}
 }

template <typename X> int HeightOfTree(X * node) {
    if(node == 0)
        return 0;
    int left, right;
    if (node->leftChild != NULL) {
        left = HeightOfTree(node->leftChild);
    }else 
        left = -1;
    if (node->rightChild != NULL) {
        right = HeightOfTree(node->rightChild);
    }else 
        right = -1;
    int max = left > right ? left : right;
    return max+1;

}

template <typename X> int height(X *p)
{
        X *temp=p;
        int h1=0,h2=0;
        if(p==NULL)return(0);
        if(p->left){h1=height(p->left);}
        if(p->right){h2=height(p->right);}
        return(max(h1,h2)+1);
}

int main (void) {
	int N, Xi, Yi;
	cin >> N;
	DescartesTree **treap;
	BinaryTree **binary;
	treap = new  DescartesTree*[N];
	binary = new BinaryTree*[N];

	for (int i = 0; i < N; ++i) {
		cin >> Xi >> Yi;
		treap[i] = new DescartesTree(Xi, Yi);
		binary[i] = new BinaryTree(Xi);
	}

	for (int i = 1; i < N; ++i) {
		insert_descartes (treap[0],treap[i]);
		insert_binary (binary[0], binary[i]);
	}
	cout << height(binary[0]) << "\n ||||| " << endl;
	for (int i = 0; i < N; ++i) {
	
	cout << height(treap[i]) << endl;
	}
	return 0;
}