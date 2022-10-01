#include <iostream>
using namespace std;
template <typename T>
//Node Class for implementing Linked List.
class Node
{

public:
    T data;
    Node<T> *nextNode;
    

    Node(T data)
    {
        this->data = data;
        nextNode = NULL;
        
    }
    Node()
    {
        nextNode = NULL;
        
    }
};

// Queue class for implementing Queue using Linked List.
template <typename T>
class Queue
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            size++;
        }
        else
        {
            tail->nextNode = newNode;
            tail = tail->nextNode;
            size++;
        }
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Empty Queue" << endl;
            return 0;
        }
        Node<T> *temp = head;
        head = head->nextNode;
        size--;
        T ans = temp->data;
        delete temp;
        return ans;
    }
    T front()
    {
        if (isEmpty())
        {
            cout << "Empty Queue" << endl;
            return 0;
        }
        return head->data;
    }
};