#include<iostream>
using namespace std;

struct node {
    string data;
    node* rear;
    node() {
        data = "N/A";
        rear = NULL;
    }
};

class Q {
    node* head;
    node* tail;
    int size;
    int length;

    node* rollerHead;
    node* rollerTail;
    node* motionHead;
    node* motionTail;
    node* wheelHead;
    node* wheelTail;

public:
    Q(int size) {
        this->size = size;
        length = 0;
        head = tail = NULL;
        rollerHead = rollerTail = NULL;
        motionHead = motionTail = NULL;
        wheelHead = wheelTail = NULL;
    }

    void enque() {
        string val;
        cout << "Enter visitor name: ";
        cin >> val;

        if (length == size) {
            cout << "Queue is Full\n";
            return;
        }

        node* newNode = new node;
        newNode->data = val;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->rear = newNode;
            tail = newNode;
        }
        length++;
        cout << "Visitor added to the queue.\n";
    }

    void deque() {
        if (head == NULL) {
            cout << "Queue is empty.\n";
            return;
        }

        int n;
        cout << "1) Roller Coaster\n";
        cout << "2) Motion Ride\n";
        cout << "3) Round Wheel\n";
        cout << "Choose ride for front visitor: ";
        cin >> n;

        node* temp = head;
        head = head->rear;
        if (head == NULL) tail = NULL;

        temp->rear = NULL; // detach

        if (n == 1) {
            appendToRide(rollerHead, rollerTail, temp);
            cout << "Roller Coaster Ticket Sold to: " << temp->data << endl;
        } else if (n == 2) {
            appendToRide(motionHead, motionTail, temp);
            cout << "Motion Ride Ticket Sold to: " << temp->data << endl;
        } else if (n == 3) {
            appendToRide(wheelHead, wheelTail, temp);
            cout << "Round Wheel Ticket Sold to: " << temp->data << endl;
        } else {
            cout << "Invalid ride selection.\n";
            delete temp;
            return;
        }

        length--;
    }

    void appendToRide(node*& rideHead, node*& rideTail, node* newNode) {
        if (rideHead == NULL) {
            rideHead = rideTail = newNode;
        } else {
            rideTail->rear = newNode;
            rideTail = newNode;
        }
    }

    void display() {
        cout << "\n--- Visitors Enjoying Roller Coaster ---\n";
        printRideList(rollerHead);

        cout << "\n--- Visitors Enjoying Motion Ride ---\n";
        printRideList(motionHead);

        cout << "\n--- Visitors Enjoying Round Wheel ---\n";
        printRideList(wheelHead);
    }

    void printRideList(node* rideHead) {
        if (rideHead == NULL) {
            cout << "No visitors.\n";
            return;
        }
        node* temp = rideHead;
        while (temp != NULL) {
            cout << temp->data << " is enjoying the ride.\n";
            temp = temp->rear;
        }
    }
};

int main() {
    Q obj(5);
    int n;
    do {
        cout << "\n1) Enter a visitor to purchase queue\n";
        cout << "2) Process all queues (Display rides)\n";
        cout << "3) Sell a ticket (assign to ride)\n";
        cout << "0) Exit\n";
        cout << "Enter your option: ";
        cin >> n;

        switch (n) {
            case 1:
                obj.enque();
                break;
            case 2:
                obj.display();
                break;
            case 3:
                obj.deque();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (n != 0);

    return 0;
}

