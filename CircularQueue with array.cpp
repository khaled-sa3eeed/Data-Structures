#include <iostream>
using namespace std;

const int Size = 5;

class CircularQueue
{
private:
    int front, rear;
    int items[Size];

public:
    CircularQueue()
    {
        front = rear = -1;
    }

    bool isFull()
    {
        return rear == front - 1 || (front == 0 && rear == Size - 1);
    }

    bool isEmpty()
    {
        return front == -1;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "The queue is full" << endl;
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            /*if (rear == Size - 1) { rear = -1; }
            items[++rear] = value;*/

            rear = (rear + 1) % Size;
        }
        items[rear] = value;
        cout << "enqueued : " << value << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }


        if (front == rear)
        {
            // there is only one number
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % Size;
        }
        cout << "dequeued" << endl;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "front item is: " << items[front] << endl;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue: ";
        int i = front;
        while (true)
        {
            cout << items[i] << ' ';
            if (i == rear)
            {
                break;
            }
            i = (i + 1) % Size;
        }
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
    q.enqueue(33);
    q.dequeue();
    q.enqueue(88);
    q.display();
    q.peek();
    q.dequeue();
    q.display();
    return 0;
}
