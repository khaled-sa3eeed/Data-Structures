#include <iostream>
using namespace std;

struct Node
{
    int data, priority;
    Node* next;
};

class priorityQueue
{
private:
    Node* front;

public:
    priorityQueue()
    {
        front = nullptr;
    }

    void enqueue(int data, int prio)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->priority = prio;
        newNode->next = nullptr;

        if (front == nullptr || prio > front->priority)
        {
            newNode->next = front;
            front = newNode;
        }
        else
        {
            Node* temp = front;
            while (temp->next != nullptr && temp->next->priority >= prio)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void dequeue()
    {
        if (front == nullptr)
        {
            cout << "Priority queue is empty" << endl;
        }
        else
        {
            cout << "dequeued: " << front->data << endl;
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void peek()
    {
        if (front == nullptr)
        {
            cout << "Priority queue is empty" << endl;
        }
        else
        {
            cout << "peek: " << front->data << ',' << front->priority << endl;
        }
    }

    void display()
    {
        if (front == nullptr)
        {
            cout << "Priority queue is empty" << endl;
            return;
        }

        Node* temp = front;
        while (temp != nullptr)
        {
            cout << temp->data << ',' << temp->priority << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    priorityQueue pq;
    pq.enqueue(8, 2);
    pq.enqueue(7, 1);
    pq.enqueue(2, 5);
    pq.enqueue(99, 4);
    pq.enqueue(3, 4);
    pq.enqueue(88, 4);
    pq.enqueue(1, 3);
    pq.display();
    pq.peek();
    pq.dequeue();
    pq.display();

    return 0;
}
