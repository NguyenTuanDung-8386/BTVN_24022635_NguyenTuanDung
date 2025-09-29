#include <iostream>
#include "List.h"
using namespace std;

class QueueList
{
private:
    List list;

public:
    bool isEmpty()
    {
        return list.size() == 0;
    }

    bool isFull()
    {
        return list.isFull();
    }

    int size()
    {
        return list.size();
    }

    // Thêm phần tử vào cuối Queue
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue day!\n";
            return;
        }
        list.insertTail(x);
    }

    // Lấy phần tử đầu ra khỏi Queue
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue rong!\n";
            return -1;
        }
        int val = list.get(0);
        list.removeHead();
        return val;
    }

    // Xem phần tử đầu tiên
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue rong!\n";
            return -1;
        }
        return list.get(0);
    }

    // In ra toàn bộ Queue
    void printQueue()
    {
        cout << "Queue: ";
        list.traverseForward();
    }
};

// Test
int main()
{
    QueueList q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.printQueue();

    cout << "Front = " << q.peek() << endl;

    cout << "Dequeue = " << q.dequeue() << endl;
    q.printQueue();

    cout << "Dequeue = " << q.dequeue() << endl;
    q.printQueue();

    cout << "Is empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
