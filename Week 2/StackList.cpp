#include <iostream>
#include "List.h"
using namespace std;

class StackList {
private:
    List list;

public:
    // Kiểm tra rỗng
    bool isEmpty() {
        return list.isEmpty();
    }

    // Kiểm tra đầy
    bool isFull() {
        return list.isFull();
    }

    // Số phần tử
    int size() {
        return list.size();
    }

    // Thêm phần tử vào stack (push)
    void push(int x) {
        if (isFull()) {
            cout << "Stack day!\n";
            return;
        }
        list.insertTail(x);
    }

    // Lấy phần tử ra khỏi stack (pop)
    int pop() {
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return -1;
        }
        int val = list.get(list.size() - 1);
        list.removeTail();
        return val;
    }

    // Xem phần tử trên cùng (top)
    int top() {
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return -1;
        }
        return list.get(list.size() - 1);
    }

    // In ra toàn bộ stack
    void printStack() {
        cout << "Stack (bottom -> top): ";
        list.traverseForward();
    }
};

// Test
int main() {
    StackList st;

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
