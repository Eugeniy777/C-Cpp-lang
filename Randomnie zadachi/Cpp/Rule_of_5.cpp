#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Array
{
private:
    int *data;
    int size;

public:
    Array(int _size) : size(_size) { data = new int[size]; }

    int &operator[](const int &i) { return data[i]; }
    const int &operator[](const int &i) const { return data[i]; }

    // The Rule of "Three" - pravilo treh
    ~Array()
    {
        cout << "destroy" << endl;
        delete[] data;
    }
    Array(const Array &arr)
    {
        size = arr.size;
        data = new int[size];
        memcpy(data, arr.data, sizeof(int) * size);
    }
    Array &operator=(const Array &arr)
    {
        if (this == &arr)
            return *this;

        delete[] data;
        size = arr.size;
        data = new int[size];
        memcpy(data, arr.data, sizeof(int) * size);

        return *this;
    }

    // The Rule of Five
    Array(Array &&arr)
    {
        size = arr.size;
        data = arr.data;
        arr.data = nullptr;
    }
    Array &operator=(Array &&arr)
    {
        if (this == &arr)
        {
            return *this;
        }
        delete[] data;
        size = arr.size;
        data = arr.data;
        arr.data = nullptr;

        return *this;
    }
};

Array createBigArray(int size)
{
    Array a(size);
    for (int i = 0; i < size; ++i)
    {
        a[i] = rand();
    }
    return a; // -> Array temp(&&a); -> a = temp(&&) 
    //a = temp(&&) <- peremeschayuschee prisvaivanie
}

int main()
{
    Array a = createBigArray(1000000);
    std::cin.get();
    return 0;
}