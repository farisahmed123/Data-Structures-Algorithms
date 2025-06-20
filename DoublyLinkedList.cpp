#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* pre;
    bool Result;

    node() {
        next = pre = NULL;
        Result = false;
    }
};

class DoubleList {
private:
    node* head;

public:
    DoubleList() {
        head = NULL;
    }

    ~DoubleList() {
        node* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert() {
        int dataa;
        cout << "Enter Data: ";
        cin >> dataa;

        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert After a Value\n";
        cout << "Enter Option: ";
        int n;
        cin >> n;

        if (n == 1) {
            node* newNode = new node;
            newNode->data = dataa;
            newNode->next = head;
            if (head != NULL) head->pre = newNode;
            head = newNode;
        }
        else if (n == 2) {
            node* newNode = new node;
            newNode->data = dataa;
            if (head == NULL) {
                head = newNode;
                return;
            }
            node* temp = head;
            while (temp->next != NULL) temp = temp->next;
            temp->next = newNode;
            newNode->pre = temp;
        }
        else if (n == 3) {
            int key;
            cout << "Enter key to insert after: ";
            cin >> key;
            node* temp = head;
            while (temp != NULL) {
                if (temp->data == key) {
                    node* newNode = new node;
                    newNode->data = dataa;
                    newNode->next = temp->next;
                    newNode->pre = temp;
                    if (temp->next != NULL)
                        temp->next->pre = newNode;
                    temp->next = newNode;
                    break; // insert after first match
                }
                temp = temp->next;
            }
        }
    }

    void Completed() {
        int pos;
        cout << "Enter Task to mark as Completed: ";
        cin >> pos;
        node* temp = head;
        while (temp != NULL) {
            if (temp->data == pos) {
                temp->Result = true;
                cout << "Marked as completed.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Task not found.\n";
    }

    void displayCompletedTasks() {
        node* temp = head;
        cout << "Completed Tasks: ";
        while (temp != NULL) {
            if (temp->Result)
                cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteNode() {
        int value;
        cout << "Enter task to delete: ";
        cin >> value;

        node* temp = head;
        while (temp != NULL) {
            if (temp->data == value) {
                if (temp == head) {
                    head = head->next;
                    if (head != NULL)
                        head->pre = NULL;
                }
                else {
                    if (temp->pre != NULL)
                        temp->pre->next = temp->next;
                    if (temp->next != NULL)
                        temp->next->pre = temp->pre;
                }
                delete temp;
                cout << "Deleted.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Task not found.\n";
    }

    void display() {
        cout << "1. From Start\n2. From End\nChoose Option: ";
        int n;
        cin >> n;

        if (head == NULL) {
            cout << "No tasks to display.\n";
            return;
        }

        if (n == 1) {
            node* temp = head;
            cout << "Tasks (Start to End): ";
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else if (n == 2) {
            node* temp = head;
            while (temp->next != NULL) temp = temp->next;
            cout << "Tasks (End to Start): ";
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->pre;
            }
            cout << endl;
        }
    }
};

int main() {
    DoubleList obj;
    int n;
    do {
        cout << "\n1. Insert Task\n2. Display Tasks\n3. Delete Task\n4. Mark Completed\n5. Show Completed\n0. Exit\n";
        cout << "Enter Option: ";
        cin >> n;

        switch (n) {
            case 1: obj.insert(); break;
            case 2: obj.display(); break;
            case 3: obj.deleteNode(); break;
            case 4: obj.Completed(); break;
            case 5: obj.displayCompletedTasks(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid Option.\n";
        }
    } while (n != 0);

    return 0;
}

