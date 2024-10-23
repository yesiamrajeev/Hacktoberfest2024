#include <iostream>
using namespace std;
#define null 0

// Define struct for nodes in Linked List
struct node {
    int data;
    struct node *next;
};

struct node *start = null;  // Initialize start as null

// Insert a node at the beginning
void insert_at_begin(int d) {
    struct node *p = new node;
    p->data = d;
    p->next = start;
    start = p;
}

// Insert a node at the end
void insert_at_end(int d) {
    struct node *p = new node;
    p->data = d;
    p->next = null;
    if (start != null) {
        struct node *temp = start;
        while (temp->next != null) {
            temp = temp->next;
        }
        temp->next = p;
    } else {
        start = p;
    }
}

// Insert a node after a given value
void insert_after_value(int d, int key) {
    struct node *p = new node;
    p->data = d;
    p->next = null;
    if (start != null) {
        struct node *temp = start;
        while ((temp->data != key) && (temp->next != null)) {
            temp = temp->next;
        }
        if (temp->data == key) {
            p->next = temp->next;
            temp->next = p;
        } else {
            temp->next = p;  // This handles the case when the key is at the end
        }
    } else {
        start = p;
    }
}

// Delete an element from the beginning
int delete_at_begin() {
    if (start != null) {
        struct node *p = start;
        start = p->next;
        int x = p->data;
        delete p;
        return x;
    } else {
        cout << "List is Empty" << endl;
        return 0;
    }
}

// Display the linked list (queue)
void display() {
    struct node *temp = start;
    if (start != null) {
        while (temp != null) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    } else {
        cout << "Queue is empty" << endl;
    }
}

// Insert into the queue while maintaining sorted order
void enqueue(int d) {
    if (start == null || start->data > d) {
        insert_at_begin(d);
    } else {
        struct node *temp = start;
        struct node *q = null;
        while (temp != null && temp->data < d) {
            q = temp;
            temp = temp->next;
        }
        if (temp == null) {
            insert_at_end(d);
        } else {
            insert_after_value(d, q->data);
        }
    }
}

// Remove the minimum element from the queue (which is the first element)
int mindequeue() {
    return delete_at_begin();
}

// Peek at the first element
int minpeek() {
    if (start != null) {
        return start->data;
    } else {
        cout << "Queue is empty" << endl;
        return -1;  // Return an error code for empty queue
    }
}

// Check if the queue is empty
bool isEmpty() {
    return start == null;
}

int main() {
    int t = 1;
    while (t) {
        cout << "\nSelect the action you want to do:" << endl;
        cout << "1. Enter an Element" << endl;
        cout << "2. Delete an Element" << endl;
        cout << "3. Peek at the minimum element" << endl;
        cout << "4. Exit" << endl;

        int v;
        cin >> v;

        if (v == 1) {
            int element;
            cout << "Enter an element: ";
            cin >> element;
            enqueue(element);
            cout << "Queue after insertion: ";
            display();
        } else if (v == 2) {
            int element = mindequeue();
            cout << "The dequeued minimum element is: " << element << endl;
            cout << "The queue now looks like: ";
            display();
        } else if (v == 3) {
            int element = minpeek();
            if (element != -1) {
                cout << "The minimum element is: " << element << endl;
            }
        } else {
            break;
        }
    }
    return 0;
}
