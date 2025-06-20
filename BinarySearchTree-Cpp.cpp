#include<iostream>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;

    node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Tree {
public:
    node *root;

    Tree() {
        root = NULL;
    }

    // Insert a node recursively
    node* insert(node *temp, int val) {
        if (temp == NULL) {
            return new node(val);
        }
        if (val < temp->data) {
            temp->left = insert(temp->left, val);
        } else if (val > temp->data) {
            temp->right = insert(temp->right, val);
        } else {
            cout << "Repeated element not allowed.\n";
        }
        return temp;
    }

    // Find minimum node in right subtree
    node* findMin(node* temp) {
        while (temp->left != NULL)
            temp = temp->left;
        return temp;
    }

    // Delete a node recursively
    node* deleteNode(node* temp, int key) {
        if (temp == NULL) return NULL;

        if (key < temp->data) {
            temp->left = deleteNode(temp->left, key);
        } else if (key > temp->data) {
            temp->right = deleteNode(temp->right, key);
        } else {
            // Node found
            if (temp->left == NULL) {
                node *rightChild = temp->right;
                delete temp;
                return rightChild;
            } else if (temp->right == NULL) {
                node *leftChild = temp->left;
                delete temp;
                return leftChild;
            } else {
                // Node with two children
                node *minNode = findMin(temp->right);
                temp->data = minNode->data;
                temp->right = deleteNode(temp->right, minNode->data);
            }
        }
        return temp;
    }

    // Inorder traversal
    void inorder(node *temp) {
        if (temp == NULL) return;
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
};

int main() {
    Tree Obj;
    int choice, val;

    do {
        cout << "\n1) Insert\n2) Delete\n3) Display (Inorder)\n0) Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                Obj.root = Obj.insert(Obj.root, val);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                Obj.root = Obj.deleteNode(Obj.root, val);
                break;
            case 3:
                cout << "Inorder Traversal: ";
                Obj.inorder(Obj.root);
                cout << endl;
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}

