#include <iostream>
using namespace std;

class Node {
	
public:
	int data;
	Node* left;
	Node* right;
	int height;
};

class Avl {
	
public:
	Node* root;
	//To get max height
	int maxheight(int left, int right) {
		if (left > right)
			return left;
		else
			return right;
	}
	//To get tree height
	int TreeHeight(Node* root) {
		if (root == NULL)
			return 0;
		return root->height;
	}

	//To get the balance
	int getDifference(Node* root) {
		if (root == NULL)
			return 0;
		else
			return TreeHeight(root->left) - TreeHeight(root->right);
	}

	//Insertion of Node
	Node* newNode(int data) {
		Node* node = new Node();
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		node->height = 1;

		return node;
	}

	//Right Rotation
	Node* rotateRight(Node* y) {
		Node* x = y->left;
		Node* t2 = x->right;
		//Perform rotation
		x->right = y;
		y->left = t2;
		y->height = maxheight(TreeHeight(y->left), TreeHeight(y->right)) + 1;
		x->height = maxheight(TreeHeight(x->left), TreeHeight(x->right)) + 1;

		return x;
	}

	//Left Rotation 
	Node* rotateLeft(Node* x) {
		Node* y = x->right;
		Node* t2 = y->left;
		//Perform Rotation
		y->left = x;
		x->right = t2;
		x->height = maxheight(TreeHeight(x->left), TreeHeight(x->right)) + 1;
		y->height = maxheight(TreeHeight(y->left), TreeHeight(y->right)) + 1;

		return y;
	}

	//Insertion and balance
	Node* insertion(Node* root, int data) {
		if (root == NULL) {
			return newNode(data);
		}
		if (data < root->data) {
			root->left = insertion(root->left, data);
		}
		else if (data > root->data) {
			root->right = insertion(root->right, data);
		}
		else {
			return root;
		}

		root->height = 1 + maxheight(TreeHeight(root->left), TreeHeight(root->right));

		int balance = getDifference(root);

		// Cases
		//LL case
		if (balance > 1 && data < root->left->data)
			return rotateRight(root);

		//RR case
		if (balance < -1 && data > root->right->data)
			return rotateLeft(root);

		//LR case
		if (balance > 1 && data > root->left->data) {
			root->left = rotateLeft(root->left);
			return rotateRight(root);
		}

		//RL case 
		if (balance < -1 && data < root->right->data) {
			root->right = rotateRight(root->right);
			return rotateLeft(root);
		}
		return root;
	}

	//Traverse
	void inorder(Node* root) {
		if (root == NULL) {
			return;
		}
		else {
			inorder(root->left);
			cout << root->data << " ";
			inorder(root->right);
		}
	}

	//To find the minimum value of the right subtree
	Node* minValue(Node* root) {
		Node* temp = root;
		while (temp->left != NULL) {
			temp = temp->left;
		}
		return temp;
	}
	
	//Delete Node
	Node* delNode(Node* root, int data) {
		if (root == NULL)
			return root;

		if (data < root->data)
			root->left = delNode(root->left, data);
		else if (data > root->data)
			root->right = delNode(root->right, data);

		else {

			if (root->left == NULL) {
				Node* temp = root->right;
				delete root;

				return temp;
			}

			else if (root->right == NULL) {
				Node* temp = root->left;
				delete root;

				return temp;
			}

			else {
				Node* temp = minValue(root->right);
				root->data = temp->data;
				root->right = delNode(root->right, temp->data);
			}
		}

		if (root == NULL)
			return root;

		root->height = 1 + maxheight(TreeHeight(root->left), TreeHeight(root->right));

		int balance = getDifference(root);

		if (balance > 1 && data < root->left->data)
			return rotateRight(root);

		//RR case
		if (balance < -1 && data > root->right->data)
			return rotateLeft(root);

		//LR case 
		if (balance > 1 && data > root->left->data) {
			root->left = rotateLeft(root->left);
			return rotateRight(root);
		}

		//RL case 
		if (balance < -1 && data < root->right->data) {
			root->right = rotateRight(root->right);
			return rotateLeft(root);
		}
		return root;
	}
};

int main() {
	
	Avl a1;
	Node* root = NULL;
	root = a1.insertion(root, 7);
	root = a1.insertion(root, 1);
	root = a1.insertion(root, 5);
	root = a1.insertion(root, 2);
	root = a1.insertion(root, 6);
	
	a1.delNode(root, 5);     
	
	cout << endl << "Tree = ";
	a1.inorder(root);

	return 0;
}

