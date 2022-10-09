// Creating an empty queue

#include <bits/stdc++.h>
using namespace std;

// A structure to represent a queue
class Queue {
public:
	int front, rear, size;
	unsigned cap;
	int* arr;
};

// Function to create a queue of given capacity
// It initializes size of queue as 0
Queue* createQueue(unsigned cap)
{
	Queue* queue = new Queue();
	queue->cap = cap;
	queue->front = queue->size = 0;

	queue->rear = cap - 1;
	queue->arr = new int[(queue->cap * sizeof(int))];
	return queue;
}
