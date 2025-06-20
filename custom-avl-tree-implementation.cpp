#include <iostream>
using namespace std;
struct TreeNode {
    TreeNode *left, *right;
    int data, height;
};

class CustomAVLTree {
    TreeNode *temp, *current;

public:
    CustomAVLTree() 
	{
        temp = NULL;
        current = NULL;
    }
    TreeNode *createNode(int value)
	 {
        temp = new TreeNode;
        temp->left = NULL;
        temp->right = NULL;
        temp->data = value;
        return temp;
    }

    int getHeight(TreeNode *node) {
        if (node == NULL) 
		{
            return 0;
        }
        return node->height;
    }

    int max(int a, int b) 
	{
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }

    void inOrderTraversal(TreeNode *node) 
	{
        if (node == NULL) 
		{
            cout << "Tree is empty." << endl;
            return;
        }
        if (node->left != NULL) 
		{
            inOrderTraversal(node->left);
        }
        cout << node->data << " ";
        if (node->right != NULL) 
		{
            inOrderTraversal(node->right);
        }
        return;
    }

    void searchValue(TreeNode *node, int value)
	 {
        if (value == node->data) 
		{
            cout << "Value found!" << endl;
            return;
        } 
		else if (value < node->data) 
		{
            return searchValue(node->left, value);
        } 
		else if (value > node->data) 
		{
            return searchValue(node->right, value);
        }
    }

    TreeNode *insertNode(TreeNode *node, int value) 
	{
        if (node == NULL)
		 {
            node = createNode(value);
            return node;
        }
		 else 
		{
            if (value == node->data) 
			{
                cout << "Value already in the tree!" << endl;
                return node;
            }
			 else if (value < node->data) 
			{
                node->left = insertNode(node->left, value);
            } 
			else 
			{
                node->right = insertNode(node->right, value);
            }
        }
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balanceFactor = getBalanceFactor(node);
        if (balanceFactor > 1)
		 {
            if (value < node->left->data) 
			{
                return rightRotation(node);
            } 
			else if (value > node->left->data) 
			{
                node->left = leftRotation(node->left);
                return rightRotation(node);
            }
        }
        if (balanceFactor < -1) 
		{
            if (value > node->right->data) 
			{
                return leftRotation(node);
            } 
			else if (value < node->right->data) 
			{
                node->right = rightRotation(node->right);
                return leftRotation(node);
            }
        }
        return node;
    }

    TreeNode *leftRotation(TreeNode *node) 
	{
        TreeNode *parent, *child;
        parent = node->right;
        child = parent->left;
        parent->left = node;
        node->right = child;
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        parent->height = 1 + max(getHeight(parent->left), getHeight(parent->right));
        return parent;
    }

    TreeNode *rightRotation(TreeNode *node) 
	{
        TreeNode *parent, *child;
        parent = node->left;
        child = parent->right;
        parent->right = node;
        node->left = child;
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        parent->height = 1 + max(getHeight(parent->left), getHeight(parent->right));
        return parent;
    }

    int getBalanceFactor(TreeNode *node) 
	{
        return (getHeight(node->left) - getHeight(node->right));
    }

    TreeNode *deleteNode(TreeNode *node, int value) {
        if (node == NULL) {
            cout << "Tree is empty." << endl;
            return node;
        }

        if (value < node->data) 
		{
            node->left = deleteNode(node->left, value);
        }
		 else if (value > node->data) 
		 {
            node->right = deleteNode(node->right, value);
        } 
		else
		 {
            if (node->left == NULL || node->right == NULL) 
			{
                TreeNode *nodeChild = (node->left) ? node->left : node->right;
                if (nodeChild == NULL) 
				{
                    nodeChild = node;
                    node = NULL;
                } 
				else 
				{
                    *node = *nodeChild;
                }
                delete nodeChild;
            } 
			else 
			{
                TreeNode *successor = findMinValue(node->right);
                node->data = successor->data;
                node->right = deleteNode(node->right, successor->data);
            }
        }

        if (node == NULL) 
		{
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0) 
		{
            return rightRotation(node);
        }
        if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) 
		{
            node->left = leftRotation(node->left);
            return rightRotation(node);
        }
        if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0) 
		{
            return leftRotation(node);
        }
        if (balanceFactor < -1 && getBalanceFactor(node->right) > 0) 
		{
            node->right = rightRotation(node->right);
            return leftRotation(node);
        }

        return node;
    }

    TreeNode *findMinValue(TreeNode *node) 
	{
        while (node->left != NULL) 
		{
            node = node->left;
        }
        return node;
    }
    TreeNode *findMaxValue(TreeNode *node) 
	{
        while (node->right != NULL) 
		{
            node = node->right;
        }
        return node;
    }
};

int main() 
{
    CustomAVLTree avlTree;
    TreeNode *root = NULL;
    int choice;
    do {
        cout<<"1) Insertion\n";
        cout<<"2) Deletion\n";
        cout<<"3) Display\n";
        cout<<"4) Search\n";
        cout<<"5) Maximum\n";
        cout<<"6) Minimum\n";
        cout<<"0) Exit\n";
        cout << "Enter Option : ";
        cin >> choice;
        if (choice == 1) 
		{
            int value;
            cout << "Enter value to insert: ";
            cin >> value;
            root = avlTree.insertNode(root, value);
        } else if (choice == 2) 
		{
            int value;
            cout << "Enter value to delete: ";
            cin >> value;
            root = avlTree.deleteNode(root, value);
        }
		else if (choice == 3) 
		{
            cout << "In-order Traversal: ";
            avlTree.inOrderTraversal(root);
            cout << endl;
        } 
        else if (choice == 4) 
		{
            int value;
            cout << "Enter value to search: ";
            cin >> value;
            avlTree.searchValue(root, value);
        } 
		else if (choice == 5)
		 {
            TreeNode *maxNode = avlTree.findMaxValue(root);
            if (maxNode != NULL) 
			{
                cout << "Maximum value in AVL: " << maxNode->data << endl;
            } 
			else 
			{
                cout << "Tree is empty." << endl;
            }
        } 
		else if (choice == 6) 
		{
            TreeNode *minNode = avlTree.findMinValue(root);
            if (minNode != NULL) 
			{
                cout << "Minimum value in AVL: " << minNode->data << endl;
            } 
			else
			{
                cout << "Tree is empty." << endl;
            }
        }
    } while (choice != 0);
}
