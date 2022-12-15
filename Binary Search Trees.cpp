#include <iostream>
using namespace std;

class Node {
	
public:
	int data;
	Node* left;
	Node* right;

	Node() {
		
		left = NULL;
		right = NULL;
	}
};

class BST {
	
public:
	Node* root;

	BST() {
		
		root = NULL;
	}
	
	//creating a new Node
	Node* newNode(Node* root, int data) {
		
		Node* node = new Node;
		node->data = data;
		node->left = NULL;
		node->right = NULL;

		return node;
	}

	Node* insertion(Node* root, int data) {

		//checking if the node to be inserted is on the right or left
		if (root == NULL) {
			return newNode(root, data);
		}
		
		if (data < root->data) {
			root->left = insertion(root->left, data);
		}
		
		else if (data > root->data) {
			root->right = insertion(root->right, data);
		}
		
		else
			return root;
	}
	
	//PreOrder Traversal
	void PreOrder(Node* root) {
		
		if (root == NULL) {
			return;
		}
		
		else {
			cout << "Data: " << root->data << endl;
			PreOrder(root->left);
			PreOrder(root->right);
		}
	}

	//InOrder Traversal
	void InOrder(Node* root) {
		
		if (root == NULL) {
			return;
		}
		
		else {
			InOrder(root->left);
			cout << "Data: " << root->data << endl;
			InOrder(root->right);
		}
	}

	//PostOrder Traversal
	void PostOrder(Node* root) {
		
		if (root == NULL) {
			return;
		}
		
		else {
			PostOrder(root->left);
			PostOrder(root->right);
			cout << "Data: " << root->data << endl;
		}
	}
	
	//To find the minimum value of the right subtree
	Node* minVal(Node* root) {
		
		Node* current = root;
		while(current->left != NULL) {
			current = current->left;
		}
		
		return current;
	}
	
	Node* deleteNode(Node* root, int data) {
		//checking if the node to be deleted is on the right or left
		
		if (root == NULL) {
			return NULL;
		}
		
		if (data < root->data) {
			root->left = deleteNode(root->left, data);
		}
		
		else if (data > root->data) {
			root->right = deleteNode(root->right, data);
		}
		
		else {
			//node with only one or no child
			
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
				//node with 2 children
				//getting the inorder successor(smallest in the right sub tree
				
				Node* temp = minVal(root->right);
				root->data = temp->data;
				root->right = deleteNode(root->right, temp->data);
			}
			
			return root;
		}
		
	}

};

int main() {
	
	Node* root = NULL;
	BST b1;
	root = b1.insertion(root, 7);
	b1.insertion(root, 1);
	b1.insertion(root, 5);
	b1.insertion(root, 2);
	b1.insertion(root, 6);
	
	cout << "InOrder Traversal: " << endl;
	b1.InOrder(root);
	
	cout << endl << "PreOrder Traversal: " << endl;
	b1.PreOrder(root);
	
	cout << endl << "PostOrder Traversal: " << endl;
	b1.PostOrder(root);
	
	cout << endl << "Deleting Node: " << endl;
	cout << "InOrder Traversal: " << endl;
	b1.deleteNode(root,5);
	b1.InOrder(root);

	return 0;
}
