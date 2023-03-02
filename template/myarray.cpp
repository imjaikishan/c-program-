#include <algorithm>

#include <iostream>

template<typename T>
class MyArray {
    T* m_arr;
    int m_len;
public:
    MyArray() : m_arr(nullptr), m_len(0) {} // default constructor
    MyArray(int len) : m_arr(new T[len]), m_len(len) {} // constructor
    ~MyArray() { delete[] m_arr; } // destructor

    void append(T val) {
        T* temp = new T[m_len + 1];
        for (int i = 0; i < m_len; i++) {
            temp[i] = m_arr[i];
        }
        temp[m_len] = val;
        delete[] m_arr;
        m_arr = temp;
        m_len++;
    }

    T at(int index) {
        if (index >= 0 && index < m_len) {
            return m_arr[index];
        }
        else {
            throw std::out_of_range("Index out of range.");
        }
    }

    bool search(T key) const {
        for (int i = 0; i < m_len; i++) {
            if (m_arr[i] == key) {
                return true;
            }
        }
        return false;
    }

    T sum() const {
        T result = 0;
        for (int i = 0; i < m_len; i++) {
            result += m_arr[i];
        }
        return result;
    }

    T min() const {
        T result = m_arr[0];
        for (int i = 1; i < m_len; i++) {
            if (m_arr[i] < result) {
                result = m_arr[i];
            }
        }
        return result;
    }

    T max() const {
        T result = m_arr[0];
        for (int i = 1; i < m_len; i++) {
            if (m_arr[i] > result) {
                result = m_arr[i];
            }
        }
        return result;
    }

    void reverse() {
        for (int i = 0; i < m_len / 2; i++) {
            std::swap(m_arr[i], m_arr[m_len - 1 - i]);
        }
    }

    void sort() {
        std::sort(m_arr, m_arr + m_len);
    }
};


int main() {
    MyArray<int> arr(5);

    arr.append(1);
    arr.append(3);
    arr.append(5);
    arr.append(2);
    arr.append(4);

    std::cout << "Array elements: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Search 3: " << arr.search(3) << std::endl;
    std::cout << "Sum: " << arr.sum() << std::endl;
    std::cout << "Min: " << arr.min() << std::endl;
    std::cout << "Max: " << arr.max() << std::endl;

    arr.reverse();

    std::cout << "Reversed array elements: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr.at(i) << " ";
    }
    std::cout << std::endl;

    arr.sort();

    std::cout << "Sorted array elements: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr.at(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
