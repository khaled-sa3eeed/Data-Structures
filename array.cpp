#include <iostream>
using namespace std;

template <typename T>
class Array
{
private:
    T* arr;
    int capacity;
    int length;

    void ensureCapacity()
    {
        if (length == capacity)
        {
            int newCapacity = (capacity == 0) ? 2 : capacity * 2;
            T* newArr = new T[newCapacity];
            for (int i = 0; i < length; i++) { newArr[i] = arr[i]; }
            delete[] arr;
            arr = newArr;
            capacity = newCapacity;
        }
    }

public:
    Array(int initialCapacity = 10)
    {
        length = 0;
        capacity = initialCapacity;
        if (capacity < 0) capacity = 10;
        arr = new T[capacity];
    }

    ~Array() { delete[] arr; }

    void Append(T element)
    {
        ensureCapacity();
        arr[length++] = element;
    }

    void Insert(int index, T element)
    {
        if (index < 0 || index > length)
        {
            cout << "Index out of bounds for insertion.";
            return;
        }
        ensureCapacity();

        for (int i = length; i > index; i--) { arr[i] = arr[i - 1]; }
        arr[index] = element;
        length++;
    }

    void Remove()
    {
        if (length == 0)
        {
            cout << "Array is empty, cannot remove element.";
            return;
        }
        length--;
    }

    void Delete(int index)
    {
        if (index < 0 || index >= length)
        {
            cout << "Index out of bounds for deletion.";
            return;
        }

        for (int i = index; i < length - 1; i++) { arr[i] = arr[i + 1]; }
        length--;
    }

    T Get(int index)
    {
        if (index < 0 || index >= length)
        {
            cout << "Index out of bounds.";
            return -1;
        }
        return arr[index];
    }

    int GetSize() { return length; }

    void Reverse()
    {
        int left = 0, right = length - 1;
        while (left < right)
        {
            swap(arr[left], arr[right]);
            left++, right--;
        }
    }

    int Search(T element)
    {
        for (int i = 0; i < length; ++i)
        {
            if (arr[i] == element) { return i; }
        }
        return -1;
    }

    void Display()
    {
        cout << "the Array: ";

        for (int i = 0; i < length; ++i)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
};

int main()
{
    Array<int> arr;

    arr.Append(10);
    arr.Append(20);
    arr.Append(30);
    arr.Insert(1, 15);

    arr.Display();

    cout << "Size: " << arr.GetSize() << "\n";
    cout << "Element at index 2: " << arr.Get(2) << "\n";
    cout << "Index of 20: " << arr.Search(20) << "\n";

    arr.Reverse();

    arr.Display();

    arr.Delete(1);
    arr.Remove();
    cout << "After Delete(1) and Remove(): ";
    arr.Display();

    return 0;
}
