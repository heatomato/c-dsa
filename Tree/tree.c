#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NODE {
	int item;
	struct NODE *left;
	struct NODE *right;
}NODE;

struct NODE * createNode( int value ) {
	NODE *node = malloc(sizeof(NODE));
	node->item = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

struct NODE * insertLeft( NODE *root, int value ) {
	root->left = createNode(value);
	return root->left;
}

struct NODE * insertRight( NODE *root, int value ) {
	root->right = createNode(value);
	return root->right;
}

void inorderTraversal( NODE * root ) {
	if (root == NULL) return;
	inorderTraversal(root->left);
	printf("%d -> ", root->item);
	inorderTraversal(root->right);
}


void preorderTraversal( NODE * root ) {
	if (root == NULL) return;
	printf("%d -> ", root->item);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

void postorderTraversal( NODE *root ) {
	if (root == NULL) return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%d -> ", root->item);

}

bool isFullBinaryTree( NODE *root ) {
	// Checking tree emptiness
	if (root == NULL) return true;

	// Checking the presence of childeren
	if (root->left == NULL && root->right == NULL) {
		return true;
	}

	// Recursive check of treee
	if ((root->left) && (root->right)) {
		return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));
	}

	return false;
};

int depth ( NODE *node ) {
	int d = 0;
	while (node != NULL) {
		d++;
		node = node->left;
	}
	return d;
}

bool checkPerfectBinaryTree ( NODE *root, int d, int level ) {
	// If the tree is empty
	if (root == NULL) return true;

	// Check the presence of children
	if (root->left == NULL  && root->right == NULL) return (d == level + 1);

    if (root->left == NULL || root->right == NULL) return false;

    return checkPerfectBinaryTree(root->left, d, level + 1) && checkPerfectBinaryTree(root->right, d, level + 1);
}

bool isPerfectBinaryTree ( NODE *root) {
	int d = depth(root);
	return checkPerfectBinaryTree(root, d, 0);
}

int countNumNodes ( NODE *root ) {
	if (root == NULL) return 0;

	return (1 + countNumNodes(root->left) + countNumNodes(root->right));
}

bool isCompleteTree ( NODE *root, int index, int numberNodes ) {
	// Check if the tree is complete
	if (root == NULL) return true;

	if (index >= numberNodes) return false;

	return (isCompleteTree(root->left, 2 * index + 1, numberNodes) && isCompleteTree(root->right, 2 * index + 2, numberNodes));
}

bool checkHeightBalance ( NODE *root, int *height ) {
	// Check for emptieness
	int leftHeight = 0;
	int rightHeight = 0;
	int l = 0;
	int r = 0;

	if (root == NULL) {
		*height = 0;
		return 1;
	}

	l = checkHeightBalance(root->left, &leftHeight);
	r = checkHeightBalance(root->right, &rightHeight);

	*height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

	if ((leftHeight - rightHeight) || (rightHeight - leftHeight >= 2))
		return 0;
	else
		return 1 && r;
}


// Binary Search Tree Operations
NODE * insert ( NODE *node, int value ) {
	if (node == NULL) return createNode(value);

	// Traverse to the right place and insert the node
 	if (value < node->item) {
 		node->left = insert(node->left, value);
 	} else {
 		node->right = insert(node->right, value);
 	}
 	return node;
}

NODE *minValueNode ( NODE * node ) {
	NODE *current = node;

	// Find the leftmost leaf
	while (current && current->left != NULL) {
		current = current->left;
	}

	return current;
}

NODE *deleteNode ( NODE *root, int value ) {
	if (root == NULL) return root;

	// Find the node to be deleted
	if (value < root->item) {
		root->left = deleteNode(root->left, value);
	} else if (value > root->item) {
		root->right = deleteNode(root->right, value);
	} else {
		// If the is with only one child or no child
		if (root->left == NULL) {
			NODE *temp = root->right;
			free(root);
			return temp;
		} else if (root->right == NULL) {
			NODE *temp = root->left;
			free(root);
			return temp;
		}

		// if the node has two children
		NODE *temp = minValueNode(root->right);

		// Place the inorder successor in position of the node to be deleted
		root->item = temp->item;

		// Delete the inorder sucessor
		root->right = deleteNode(root->right, temp->item);

	}

	return root;
}



void treeTask(){
	NODE *root = createNode(1);
	insertLeft(root, 12);
	insertRight(root, 9);

	insertLeft(root->left, 5);
	insertRight(root->right, 6);

	printf("InOrderTraversal\n");
	inorderTraversal(root);

	printf("PreOrderTraversal\n");
	preorderTraversal(root);

	printf("PostOrderTraversal\n");
	postorderTraversal(root);

	if (isFullBinaryTree(root)) {
		printf("The tree is a full binary tree\n");
	} else {
		printf("The tree is not a full binary tree\n");
	}

	if (isPerfectBinaryTree(root)) {
		printf("The tree is a perfect binary tree\n");
	} else {
		printf("The tree is not a perfect binary tree\n");
	}

	int count = countNumNodes(root);
	int index = 0;
	if (isCompleteTree(root, index, count)) {
		printf("The tree is a complete binary tree\n");
	} else {
		printf("The tree is not a complete binary tree\n");
	}

	int height = 0;
	if (checkHeightBalance(root, &height)) {
		printf("The tree is balanced");
	} else {
		printf("The tree is not balanced");
	}


}

