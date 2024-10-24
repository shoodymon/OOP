#pragma once
#include <iostream>

template <typename T>
class ListElement {
private:
    T m_data;                
    ListElement<T>* m_next;  
    static int m_count;      

public:
    ListElement(T value) : m_data(value), m_next(nullptr) {
        m_count++;
    }

    ~ListElement() {
        m_count--;
    }

    ListElement<T>* addToStart(T value) {
        ListElement<T>* newElement = new ListElement<T>(value);
        newElement->m_next = this;
        return newElement;
    }

    ListElement<T>* removeFromStart() {
        if (m_next) {
            ListElement<T>* newHead = m_next;
            m_next = nullptr;  // Отсоединяем текущий элемент
            delete this;
            return newHead;
        }
        return this;
    }

    ListElement<T>* find(T value) {
        ListElement<T>* current = this;
        while (current) {
            if (current->m_data == value) {
                return current;
            }
            current = current->m_next;
        }
        return nullptr;
    }

    static void deleteList(ListElement<T>*& head) {
        while (head) {
            ListElement<T>* temp = head;
            head = head->m_next;
            delete temp;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const ListElement<T>* head) {
        const ListElement<T>* current = head;
        while (current) {
            os << current->m_data << " ";
            current = current->m_next;
        }
        return os;
    }

    bool operator==(const ListElement<T>& other) const {
        int thisSize = 0;
        int otherSize = 0;
        const ListElement<T>* current = this;
        while (current) {
            thisSize++;
            current = current->m_next;
        }
        current = &other;
        while (current) {
            otherSize++;
            current = current->m_next;
        }
        return thisSize == otherSize;
    }

    static int getCount() {
        return m_count;
    }
};

template <typename T>
int ListElement<T>::m_count = 0;
