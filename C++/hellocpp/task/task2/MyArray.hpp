//
// Created by mac on 2020/9/18.
//

#pragma once
#include <iostream>
using namespace std;

template <class T>
class MyArray {
public:
    MyArray(int capacity) {
        cout << "MyArray 有参构造函数" << endl;
        this->m_capacity = capacity;
        this->m_size = 0;
        this->p_address = new T[this->m_capacity];
    }

    // 拷贝构造函数
    MyArray(const MyArray &arr) {
        cout << "MyArray 拷贝构造" << endl;
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->p_address = new T[arr.m_capacity];
        for (int i = 0; i < arr.m_size; i++) {
            this->p_address[i] = arr.p_address[i];
        }
    }

    // 重载 = 运算符，防止浅拷贝问题
    MyArray & operator=(const MyArray &arr) {
        cout << "MyArray =运算符重载" << endl;
        // 先判断原来堆区是否有数据
        if (this->p_address) {
            delete[] this->p_address;
            this->p_address = NULL;
            this->m_capacity = 0;
            this->m_size = 0;
        }
        // 深拷贝
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->p_address = new T[arr.m_capacity];
        for (int i = 0; i < arr.m_size; i++) {
            this->p_address[i] = arr.p_address[i];
        }

        return *this;
    }

    // 尾插法
    void push_back(const T &val) {
        // 判断容量
        if (m_size == m_capacity) {
            cout << "array is full." << endl;
            return;
        }
        this->p_address[m_size] = val;
        m_size++;
    }

    // 尾删法
    void pop_back() {
        if (m_size == 0) {
            return;
        }
        this->m_size--;
    }

    // 通过下标访问元素
    T& operator[](int index) {
        return this->p_address[index];
    }

    int get_size() {
        return this->m_size;
    }

    int get_capacity() {
        return this->m_capacity;
    }

    void show_elems() {
        for(int i = 0; i < this->m_size; i++) {
            cout << this->p_address[i] << " ";
        }
        cout << endl;
    }

    ~MyArray() {
        cout << "MyArray 析构函数" << endl;
        if (this->p_address) {
            delete[] this->p_address;
            this->p_address = NULL;
            this->m_capacity = 0;
            this->m_size = 0;
        }
    }
private:
    T *p_address;
    int m_capacity;
    int m_size;
};
