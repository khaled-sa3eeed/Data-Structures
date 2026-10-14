#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class Queue
{
private:
    Node* front;
    Node* rear;

public:
    Queue()
    {
        front = rear = nullptr;
    }

    bool isEmpty()
    {
        return front == nullptr;
        // return rear == nullptr;
    }

    void enqueue(int value)
    {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << value << endl;
    }


    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;

        cout << "Dequeue: " << front->data << endl;

        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            cout << "front is: " << front->data << endl;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            cout << "Queue is : ";

            Node* temp = front;
            while (temp != nullptr)
            {
                cout << temp->data << ' ';
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue q;
    q.enqueue(7);
    q.enqueue(9);
    q.enqueue(5);
    q.enqueue(9);
    q.enqueue(10);
    q.enqueue(6);
    q.enqueue(1);
    q.enqueue(3);
    q.peek();
    q.display();
    q.dequeue();
    q.peek();
    q.display();
    q.enqueue(66);
    q.display();

    return 0;
}
