#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Solution
{
    public:
	//Approach 1: Using stack
    void rev1(queue<int> &q)
    {
        stack<int>s;
        while(!q.empty()){
            s.push(q.front());
            q.pop();
        }
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
    }

	//Approach 2: Using recursion
	void rev2(queue<int> &q)
    {
        if (q.empty())
		return;

		long long int data = q.front();
		q.pop();

		rev2(q);

		q.push(data);
    }

	void printQueue(queue<int> Queue)
	{
		while (!Queue.empty()) {
			cout << Queue.front() << " ";
			Queue.pop();
		}
	}
};

int main(){
	Solution s;
	queue<int> Queue;
	Queue.push(56);
	Queue.push(27);
	Queue.push(30);
	Queue.push(45);
	Queue.push(85);
	Queue.push(92);
	Queue.push(58);
	Queue.push(80);
	Queue.push(90);
	Queue.push(100);

	cout << "Original Queue: ";
	s.printQueue(Queue);
	cout << endl;

	cout << "Queue reversal using stack: ";
	s.rev1(Queue);
	s.printQueue(Queue);
	cout << endl;

	cout << "Queue reversal using recursion: ";
	s.rev2(Queue);
	s.printQueue(Queue);
	cout << endl;
	return 0;
}
