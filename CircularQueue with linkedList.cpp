#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class CircularQueue
{
private:
    Node* rear;

public:
    CircularQueue()
    {
        rear = nullptr;
    }

    bool isEmpty()
    {
        return rear == nullptr;
    }

    void enqueue(int value)
    {
        Node* newNode = new Node();
        newNode->data = value;

        if (isEmpty())
        {
            newNode->next = newNode;
            rear = newNode;
        }
        else
        {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
        cout << "enqueued : " << value << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        Node* front = rear->next;

        if (front == rear)
        {
            rear = nullptr;
        }
        else
        {
            rear->next = front->next;
        }

        cout << "dequeued : " << front->data << endl;

        delete front;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            cout << "front is : " << rear->next->data << endl;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Queue is : ";
        Node* temp = rear->next;
        do
        {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        while (temp != rear->next);
        cout << endl;
    }
};

int main()
{
    CircularQueue q;
    q.enqueue(7);
    q.enqueue(9);
    q.enqueue(6);
    q.enqueue(1);
    q.enqueue(3);
    q.enqueue(88);
    q.display();
    q.peek();
    q.dequeue();
    q.display();

    return 0;
}
