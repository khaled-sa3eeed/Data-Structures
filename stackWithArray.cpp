#include <iostream>
using namespace std;

const int Max = 5;

class Stack
{
private:
    int arr[Max];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty()
    {
        return (top == -1);

        /*if (top == -1) { return 1; }
        else { return 0; }*/
    }

    bool isFull()
    {
        return (top == Max - 1);
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack overflow! cannot push" << endl;
        }
        else
        {
            arr[++top] = value;
            cout << value << " pushed into stack" << endl;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow! cannot pop" << endl;
        }
        else
        {
            cout << arr[top--] << " popped from stack" << endl;
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
            cout << "The top is " << arr[top] << endl;
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
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << ' ';
            }
            cout << endl;
        }
    }
};

int main()
{
    Stack st;

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
    return 0;
}
