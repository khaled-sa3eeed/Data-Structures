#include <iostream>
using namespace std;

template <class T>

class Node
{
public:
    T data;
    Node* next;

    Node(T value)
    {
        data = value;
        next = nullptr;
    }
};

template <class T>

// T =  T data  next

class Stack
{
private:
    Node<T>* top;

public:
    Stack()
    {
        top = nullptr;
    }

    bool isEmpty()
    {
        return (top == nullptr);
    }

    void push(T value)
    {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
        cout << value << " pushed into stack" << endl;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow! cannot pop" << endl;
        }
        else
        {
            cout << top->data << " popped from the stack" << endl;
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "The top is " << top->data << endl;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "The elements are : ";
            Node<T>* temp = top;
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
    /*Stack<int> st;

    st.push(4);
    st.push(7);
    st.push(6);
    st.push(1);
    st.push(3);
    st.push(8); // overflow
    st.display();
    st.pop();
    st.push(15);
    st.peek();
    st.display();
    */


    Stack<string> st2;
    st2.push("khaled");
    st2.push("kareem");
    st2.display();
    st2.pop();
    st2.push("saeed");
    st2.peek();
    st2.display();


    return 0;
}
