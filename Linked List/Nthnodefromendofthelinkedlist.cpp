// C++ program to find N'th node from end
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

void printNthFromLast(struct Node* head, int N)
{
	int len = 0, i;
	struct Node* temp = head;

	while (temp != NULL) {
		temp = temp->next;
		len++;
	}

	if (len < N)
		return;

	temp = head;

	// Get the (len-N+1)th node from the beginning
	for (i = 1; i < len - N + 1; i++)
		temp = temp->next;

	cout << temp->data;

	return;
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = new Node();

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

int main()
{
	struct Node* head = NULL;

	// create linked 35->15->4->20
	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 35);
	
	// Function call
	printNthFromLast(head, 4);
	return 0;
}
