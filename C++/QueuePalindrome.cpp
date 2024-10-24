//To check if a queue is palindrome or not
#include<iostream>
using namespace std;
#define size 30
class queue 
{
public:
    int rear, front;
    int items[size];

    queue() 
    {
        rear = -1;
        front = -1;
    }

    int empty() 
    {
        if ((rear == -1 && front == -1) || front > rear)
            return 1;
        else 
            return 0;
    }

    int full() 
    {
        if (rear == size - 1)
            return 1;
        else 
            return 0;
    }

    void insert(int x) 
    {
        if (full()) 
        {
            cout << "Queue is full. Cannot insert\n";
            exit(1);
        }
        else 
        {
            rear = rear + 1;
            items[rear] = x;
            if (rear == 0)
                front = 0;
        }
    }

    int deletes() 
    {
        if (empty()) 
        {
            cout << "Queue is empty. Cannot delete\n";
            exit(1);
        }
        else
            return items[front++];
    }
  
    bool isPalin()
    {
        while(!empty() && rear>=front)
        {
            int STop=deletes();
            if(STop!=items[rear])
            return false;
            rear--;
        }
        return true;
    }
};
int main()
{
    queue q;
    q.insert(0);
    q.insert(0);
    q.insert(0);
    q.insert(0);
    q.insert(0);
    if(q.isPalin())
    cout<<"Is palindrome\n";
    else
    cout<<"not palindrome\n";
    return 0;
}
