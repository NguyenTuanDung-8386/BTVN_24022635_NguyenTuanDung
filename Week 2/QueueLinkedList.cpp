#include <iostream>
#include "SingleLinkedList.h"
using namespace std;

class QueueLinkedList
{
private:
    SingleLinkedList list;

public:
    // Thêm phần tử (enqueue)
    void enqueue(int x)
    {
        list.insertTail(x);
    }

    // Xóa phần tử (dequeue)
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue rong!\n";
            return;
        }
        list.removeHead();
    }

    // Xem phần tử đầu
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue rong!\n";
            return -1;
        }
        return list.get(0);
    }

    // Kiểm tra rỗng
    bool isEmpty()
    {
        return list.size() == 0;
    }

    // Lấy kích thước
    int size()
    {
        return list.size();
    }

    // Hiển thị hàng đợi
    void display()
    {
        cout << "Queue: ";
        list.traverseForward();
    }
};

// Test QueueLinkedList
int main()
{
    QueueLinkedList q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << "Peek: " << q.peek() << endl;

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    return 0;
}
