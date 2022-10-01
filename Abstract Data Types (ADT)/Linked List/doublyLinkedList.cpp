#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Node class

class Node
{

public:
    int data;
    Node *nextNode;
    Node *previousNode;

    Node(int data)
    {
        this->data = data;
        nextNode = NULL;
        previousNode = NULL;
    }
    Node()
    {
        nextNode = NULL;
        previousNode = NULL;
    }
};

// Function for entering data in DoublyLinkedList
Node *takeInput()
{

    Node *head = NULL;
    cout << "DO YOU WANT TO ADD DATA" << endl;
    cout << "'y' for YES or 'n' for NO" << endl;
    char responseUser;
    cin >> responseUser;
    if (responseUser == 'y')
    {
        cout << "Enter data"
             << ":" << endl;
        int data1;
        cin >> data1;
        head = new Node(data1);
        Node *tail = head;

        cout << "DO YOU WANT TO ADD MORE DATA" << endl;
        char response;
        cin >> response;

        while (response == 'y')
        {
            cout << "Enter data :" << endl;
            int data;
            cin >> data;
            Node *newNode = new Node(data);
            tail->nextNode = newNode;
            tail->nextNode->previousNode = tail;
            tail = tail->nextNode;
            cout << "DO YOU WANT TO ADD MORE DATA" << endl;
            cin >> response;
        }
    }
    return head;
}

// Function to traverse the DoublyLinked list and Displaying all its node elements.

void printLinkedlist(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->nextNode;
    }
    cout << endl;
}

// Function for calculating Length of DoublyLinkedlist

int lengthLinkedlist(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->nextNode;
        count++;
    }

    return count;
}

// Function for Inserting node at index provided by User.
Node *insertNode(Node *head, int data, int index)
{
    Node *newNode = new Node(data);
    Node *temp = head;

    if (index == 0)
    {
        newNode->nextNode = head;
        head->previousNode = newNode;
        head = newNode;
    }
    else
    {
        int i = 0;
        while (i < index - 1 && temp != NULL)
        {
            temp = temp->nextNode;
            i++;
        }
        if (temp != NULL)
        {
            newNode->nextNode = temp->nextNode;
            temp->nextNode = newNode;
            newNode->previousNode = temp;
            newNode->nextNode->previousNode = newNode;
        }
    }
    return head;
}

// Function for Deleting node at index provided by User.

Node *deleteNode(Node *head, int index)
{

    Node *temp = head;

    if (index == 0)
    {
        Node *a = head;
        head = head->nextNode;
        head->previousNode = NULL;
        delete a;
    }
    else
    {
        int i = 0;
        while (i < index - 1 && temp != NULL)
        {

            temp = temp->nextNode;
            i++;
        }

        if (temp != NULL)
        {

            Node *a = temp->nextNode;
            temp->nextNode = temp->nextNode->nextNode;
            temp->nextNode->nextNode->previousNode = temp;
            delete a;
        }
    }

    return head;
}

// Function to remove Duplicates from Doubly LinkedList

Node *removeDuplicates(Node *head)
{
    unordered_set<int> dataset;
    Node *temp1 = head;
    Node *temp2 = NULL;
    while (temp1 != NULL)
    {
        if (dataset.find(temp1->data) != dataset.end())
        {
            temp2->nextNode = temp1->nextNode;
            temp2->nextNode->previousNode = temp2;
            delete temp1;
            temp1 = temp2->nextNode;
        }
        else
        {
            dataset.insert(temp1->data);
            temp2 = temp1;
            temp1 = temp1->nextNode;
        }
    }
    return head;
}

// Function to find Largest Node and Deleting it from Doublylinkedlist

Node *largestNodeAndDelete(Node *head)
{
    Node *temp = head;
    int maxData = 0;

    while (temp != NULL)
    {
        if (temp->data > maxData)
        {
            maxData = temp->data;
        }
        temp = temp->nextNode;
    }

    temp = head;

    while (temp != NULL)
    {
        if (temp->data == maxData)
        {
            if (temp->previousNode == NULL)
            {
                Node *a = temp;
                temp = temp->nextNode;
                head = temp;
                temp->previousNode = NULL;
                delete a;
            }
            else if (temp->nextNode == NULL)
            {
                Node *a = temp;
                temp = temp->previousNode;
                temp->nextNode = NULL;
                temp = temp->nextNode;
                delete a;
            }
            else
            {
                temp->previousNode->nextNode = temp->nextNode;
                temp->nextNode->previousNode = temp->previousNode;
                Node *a = temp;
                temp = temp->nextNode;
                delete a;
            }
        }
        else
        {
            temp = temp->nextNode;
        }
    }

    return head;
}

// Function for getting Tail pointer

Node *Tail(Node *head)
{
    Node *temp = head;
    while (temp->nextNode != NULL)
    {
        temp = temp->nextNode;
    }
    return temp;
}

// Function for rotating Doublylinkedlist counter-clockwise by N nodes and then clockwise by M nodes.

Node *rotate(Node *head, int N, int M)
{
    Node *tail = Tail(head);
    if (N > M)
    {
        for (int i = 0; i < (N - M); i++)
        {
            tail->nextNode = head;
            head->previousNode = tail;
            head = head->nextNode;
            head->previousNode->nextNode = NULL;
            head->previousNode = NULL;
            tail = tail->nextNode;
        }
    }
    else if (N < M)
    {
        for (int i = 0; i < (M - N); i++)
        {
            head->previousNode = tail;
            tail->nextNode = head;
            tail = tail->previousNode;
            tail->nextNode->previousNode = NULL;
            tail->nextNode = NULL;
            head = head->previousNode;
        }
    }
    return head;
}

