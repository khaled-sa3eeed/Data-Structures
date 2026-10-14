#include <iostream>
using namespace std;

const int Size = 5;

class Queue
{
private:
    int front, rear;
    int items[Size];

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        return rear == Size - 1;
    }

    bool isEmpty()
    {
        return (front > rear || front == -1);
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "queue is full!" << endl;
        }
        else
        {
            if (front == -1) { front = 0; }
            items[++rear] = value;
            cout << "enqueue: " << value << endl;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            cout << "dequeue: " << items[front] << endl;
            front++;
        }
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            cout << "front is: " << items[front] << endl;
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
            for (int i = front; i <= rear; i++)
            {
                cout << items[i] << ' ';
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
    q.enqueue(6);
    q.enqueue(1);
    q.enqueue(3);
    q.peek();
    q.display();
    q.dequeue();
    q.peek();
    q.display();
    q.enqueue(66);

    return 0;
}
