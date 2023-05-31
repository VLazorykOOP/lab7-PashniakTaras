
#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
T minElement(T* arr, int size)
{
    T minElem = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] < minElem)
            minElem = arr[i];

    return minElem;
}

template <>
char* minElement<char*>(char** arr, int size) {
    char* minElem = arr[0];
    size_t minElemLen = strlen(minElem);
    for (int i = 1; i < size; i++) {
        size_t curLen = strlen(arr[i]);
        if (curLen < minElemLen) {
            minElem = arr[i];
            minElemLen = curLen;
        }
    }
    return minElem;
}


void Task1Char()
{
    int size = 0;
    cout << "Input size: ";
    cin >> size;
    char** arr{ new char* [size] };

    cout << "Input array:" << endl;
    for (int i = 0; i < size; i++)
    {
        arr[i] = new char[100];
        cout << "Input [ " << i + 1 << " ] element: ";
        cin >> arr[i];
    }

    char* minElem = minElement<char*>(arr, size);
    cout << "Minimum element: " << minElem << endl;

    for (int i = 0; i < size; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

void Task1AllType()
{
    int size = 0;
    cout << "Input size: ";
    cin >> size;
    double* arr{ new double[size] };

    cout << "Input array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Input [ " << i + 1 << " ] element: ";
        cin >> arr[i];
    }

    double minElem = minElement(arr, size);
    cout << "Minimum element: " << minElem << endl;
}
void Ex1()
{
    int select;
    cout << endl;
    cout << "Select type of search: " << endl;
    cout << "1. Another type " << endl;
    cout << "2. Char " << endl;
    cin >> select;


    switch (select)
    {
    case 1:

        Task1AllType();
        break;
    case 2:

        Task1Char();
        break;
    default:

        break;
    }

}




template <typename T>
class ListNode
{
public:
    T data;
    ListNode* next;

    ListNode(T val) : data(val), next(nullptr) {}
};

template <typename T>
class List
{
private:
    ListNode<T>* head;
    ListNode<T>* tail;
    int size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    void add(T val)
    {
        ListNode<T>* node = new ListNode<T>(val);

        if (head == nullptr) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }

        size++;
    }

    T get(int index)
    {
        if (index < 0 || index >= size)
            return 0;

        ListNode<T>* current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    int getSize()
    {
        return size;
    }

    class Iterator
    {
    private:
        ListNode<T>* current; //поточний вказівник на вузол

    public:
        Iterator(ListNode<T>* node) : current(node) {}

        Iterator& operator++()
        {
            current = current->next;
            return *this;
        }

        bool operator!=(const Iterator& other) const
        {
            return current != other.current;
        }

        T& operator*()
        {
            return current->data;
        }
    };

    Iterator begin()
    {
        return Iterator(head);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }
};
void Ex4()
{
    int sz, l;
    cout << "Input number of lists: "; cin >> sz;
    List<int> lst;
    for (int i = 0; i < sz; i++) {
        cout << "Input list [" << i + 1 << "]: "; cin >> l;
        lst.add(l);

    }



    for (auto it = lst.begin(); it != lst.end(); ++it)
        cout << *it << "\t";
    cout << endl;
}

template <class T>
class Matrix {
private:
    T** matrix;
    int rows, cols;

public:
    Matrix(int r = 0, int c = 0) : rows(r), cols(c) {
        matrix = new T * [rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new T[cols];
        }
    }

    Matrix(const Matrix& m) : rows(m.rows), cols(m.cols) {
        matrix = new T * [rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new T[cols];
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = m.matrix[i][j];
            }
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    Matrix& operator=(const Matrix& m) {
        if (this != &m) {
            for (int i = 0; i < rows; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;

            rows = m.rows;
            cols = m.cols;

            matrix = new T * [rows];
            for (int i = 0; i < rows; i++) {
                matrix[i] = new T[cols];
                for (int j = 0; j < cols; j++) {
                    matrix[i][j] = m.matrix[i][j];
                }
            }
        }

        return *this;
    }

    T* operator[](int index) const {
        return matrix[index];
    }

    Matrix operator+(const Matrix& m) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
            }
        }
        return result;
    }

    Matrix& operator+=(const Matrix& m) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] += m.matrix[i][j];
            }
        }
        return *this;
    }
};
void Ex3() {
    Matrix<int> a(2, 2);
    Matrix<int> b(2, 2);

    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;

    b[0][0] = 5;
    b[0][1] = 6;
    b[1][0] = 7;
    b[1][1] = 8;

    Matrix<int> c = a + b;

    cout << "a:\n";
    cout << a[0][0] << " " << a[0][1] << "\n";
    cout << a[1][0] << " " << a[1][1] << "\n\n";

    cout << "b:\n";
    cout << b[0][0] << " " << b[0][1] << "\n";
    cout << b[1][0] << " " << b[1][1] << "\n\n";

    cout << "a + b:\n";
    cout << c[0][0] << " " << c[0][1] << "\n";
    cout << c[1][0] << " " << c[1][1] << "\n\n";

    cout << "a += b:\n";
    cout << a[0][0] << " " << a[0][1] << "\n";
    cout << a[1][0] << " " << a[1][1] << "\n\n";
}



template <typename T>
void sort(T array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[i]) {
                T temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

template <typename T>
int binarySearch(T array[], int size, T key) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int middle = (low + high) / 2;
        if (array[middle] == key) {
            return middle;
        }
        else if (key < array[middle]) {
            high = middle - 1;
        }
        else {
            low = middle + 1;
        }
    }
    return -1;
}

template <>
void sort<char*>(char* array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(array[j], array[i]) < 0) {
                char* temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void Ex2() {
    cout << "Test: " << "\n";
    int intArray[] = { 4, 2, 5, 1, 3 };
    sort(intArray, 5);
    cout << "Index of number 5 in intArray: " << binarySearch(intArray, 5, 5) << "\n";

    double doubleArray[] = { 1.5, 3.2, 2.0, 4.6, 0.9 };
    sort(doubleArray, 5);
    cout << "Index of number 2.0 in doubleArray: " << binarySearch(doubleArray, 5, 2.0) << "\n";

    /*char* stringArray[] = {"hello", "world", "apple", "orange", "banana"};
    sort(stringArray, 5);
    cout << "Index of string 'apple' in stringArray: " << binarySearch(stringArray, 5, "apple") << "\n";*/

}

int main() {
    cout << " Lab #7  !\n";
    //  Код виконання завдань
    //  Головне меню завдань
    //  Функції та класи можуть знаходитись в інших файлах проекту
    int a, flag = 0;
    cout << "Menu:\n 1) MinElement search\n 2) Binary search\n 3) Matrix class\n 4) List class\n 5) Exit\n";

    do {
        cout << "\nChoose the exercise: ";
        cin >> a;
        switch (a) {
        case 1: Ex1(); break;
        case 2: Ex2(); break;
        case 3: Ex3(); break;
        case 4: Ex4(); break;
        case 5: flag = 1; break;
        }
    } while (flag != 1);
    return 0;

}