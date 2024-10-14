#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> stack1, stack2;

public:
    void enqueue(int x) {
        stack1.push(x);
    }

    int dequeue() {
        if (stack2.empty()) {
            if (stack1.empty()) {
                cout << "Queue is empty" << endl;
                return -1;
            }
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int topVal = stack2.top();
        stack2.pop();
        return topVal;
    }

    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }

    int front() {
        if (stack2.empty()) {
            if (stack1.empty()) {
                cout << "Queue is empty" << endl;
                return -1;
            }
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front element: " << q.front() << endl;  
    cout << "Dequeued: " << q.dequeue() << endl; 
    cout << "Front element: " << q.front() << endl; 
    cout << "Dequeued: " << q.dequeue() << endl;   
    cout << "Dequeued: " << q.dequeue() << endl;    
    cout << "Dequeued: " << q.dequeue() << endl; 

    return 0;
}
