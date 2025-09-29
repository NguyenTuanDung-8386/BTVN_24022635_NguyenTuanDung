#include <iostream>
#include "SingleLinkedList.h"
using namespace std;

class StackLinkedList {
private:
    SingleLinkedList list;

public:
    // Kiểm tra rỗng
    bool isEmpty() {
        return list.isEmpty();
    }

    // Số phần tử
    int size() {
        return list.size();
    }

    // Thêm phần tử vào stack (push): O(1)
    void push(int x) {
        list.insertHead(x);
    }

    // Lấy phần tử ra khỏi stack (pop): O(1)
    int pop() {
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return -1;
        }
        int val = list.get(0);
        list.removeHead();
        return val;
    }

    // Xem phần tử trên cùng (top/peek): O(1)
    int top() {
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return -1;
        }
        return list.get(0);
    }

    // In toàn bộ stack (từ top xuống bottom)
    void printStack() {
        cout << "Stack (top -> bottom): ";
        list.traverseForward();
    }
};

// Test
int main() {
    StackLinkedList st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.printStack();

    cout << "Top = " << st.top() << endl;

    cout << "Pop = " << st.pop() << endl;
    st.printStack();

    cout << "Pop = " << st.pop() << endl;
    st.printStack();

    cout << "Is empty? " << (st.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
