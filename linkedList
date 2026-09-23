#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    /*Node(int value)
    {
        data = value;
        next = nullptr;
    }*/

    Node(int value) : data(value), next(nullptr)
    {
    }
};

class linkedList
{
private:
    Node* head;
    Node* tail;

public:
    linkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertBegin(int value)
    {
        Node* newNode = new Node(value);

        if (head == nullptr)
        {
            // linked list is empty
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }

        cout << "inserted " << value << " at begining" << endl;
    }

    void insertEnd(int value)
    {
        Node* newNode = new Node(value);

        if (head == nullptr)
        {
            // linked list is empty
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cout << "inserted " << value << " at end" << endl;
    }

    // 1-index
    /*
     1 2 3 4 5 6 7 8

    */

    void insertPos(int value, int pos)
    {
        if (pos == 1)
        {
            insertBegin(value);
            return;
        }

        Node* newNode = new Node(value);

        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "position is out of bounds" << endl;
        }
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;

            if (newNode->next == nullptr)
            {
                tail = newNode;
            }
        }
    }
};

int main()
{
    // 5
    return 0;
}
