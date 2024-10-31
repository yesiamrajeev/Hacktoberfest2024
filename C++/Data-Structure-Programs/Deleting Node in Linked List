#include <bits/stdc++.h>
using namespace std;

struct Node {
	int number;
	Node* next;
};

void Push(Node** head, int A)
{
	Node* n = (Node*)malloc(sizeof(Node));
	n->number = A;
	n->next = *head;
	*head = n;
}

void deleteN(Node** head, int position)
{
	Node* temp;
	Node* prev;
	temp = *head;
	prev = *head;
	for (int i = 0; i < position; i++) {
		if (i == 0 && position == 1) {
			*head = (*head)->next;
			free(temp);
		}
		else {
			if (i == position - 1 && temp) {
				prev->next = temp->next;
				free(temp);
			}
			else {
				prev = temp;

				// Position was greater than
				// number of nodes in the list
				if (prev == NULL)
					break;
				temp = temp->next;
			}
		}
	}
}

void printList(Node* head)
{
	while (head) {
		if (head->next == NULL)
			cout << "[" << head->number << "] "
				<< "[" << head << "]->"
				<< "(nil)" << endl;
		else
			cout << "[" << head->number << "] "
				<< "[" << head << "]->" << head->next
				<< endl;
		head = head->next;
	}
	cout << endl << endl;
}

// Driver code
int main()
{
	Node* list = (Node*)malloc(sizeof(Node));
	list->next = NULL;
	Push(&list, 1);
	Push(&list, 2);
	Push(&list, 3);

	printList(list);

	// Delete any position from list
	deleteN(&list, 1);
	printList(list);
	return 0;
}
