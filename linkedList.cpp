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

    void deleteFromBegin()
    {
        if (head == nullptr)
        {
            cout << "list is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        cout << temp->data << " was deleted from begin" << endl;
        delete temp;
    }

    void deleteFromEnd()
    {
        if (head == nullptr)
        {
            cout << "list is empty" << endl;
            return;
        }

        if (head->next == nullptr)
        {
            // one node
            delete head;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
        tail = temp;
    }

    void deleteAtpos(int pos)
    {
        if (head == nullptr)
        {
            cout << "list is empty" << endl;
            return;
        }

        if (pos == 1)
        {
            deleteFromBegin();
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr)
        {
            cout << "invalid position" << endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        if (temp->next == nullptr)
        {
            tail = temp;
        }
        delete toDelete;
    }

    void traverse()
    {
        // display

        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    void search(int val)
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                cout << "the value was found" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "the value was not found" << endl;
    }
};

int main()
{
    linkedList li;
    li.deleteFromBegin();
    li.deleteFromEnd();
    li.insertBegin(5);
    li.insertBegin(7);
    li.insertEnd(9);
    li.insertPos(8, 2);
    li.insertPos(10, 1);
    li.search(8);

    li.traverse();
    cout << "==============\n";

    li.deleteFromBegin();
    li.deleteFromEnd();
    li.deleteAtpos(2);
    li.traverse();

    li.search(7);
    li.search(8);

    return 0;
}
