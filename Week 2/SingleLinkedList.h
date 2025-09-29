#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

class SingleLinkedList
{
private:
    Node *head;
    Node *tail;
    int n; // số phần tử

public:
    // Constructor: khoi tao danh sach rong
    SingleLinkedList()
    {
        head = tail = NULL;
        n = 0;
    }
    // Destructor: giai phong bo nho
    ~SingleLinkedList()
    {
        Node *p;
        while (head)
        {
            p = head;
            head = head->next;
            delete p;
        }
    }

    // Trả về kích thước
    int size() { return n; }

    // Kiểm tra rỗng
    bool isEmpty() { return n == 0; }

    // 1. Truy cập phần tử tại vị trí i O(n)
    int get(int i)
    {
        if (i < 0 || i >= n)
        {
            cout << "Vi tri khong hop le!\n";
            return -1;
        }
        Node *p = head;
        for (int k = 0; k < i; k++)
            p = p->next;
        return p->data;
    }

    // 2. Chèn vào đầu O(1)
    void insertHead(int x)
    {
        Node *p = new Node(x);
        if (!head)
            head = tail = p;
        else
        {
            p->next = head;
            head = p;
        }
        n++;
    }

    // 3. Chèn vào cuối O(1)
    void insertTail(int x)
    {
        Node *p = new Node(x);
        if (!head)
            head = tail = p;
        else
        {
            tail->next = p;
            tail = p;
        }
        n++;
    }

    // 4. Chèn vào vị trí i O(n)
    void insertAt(int i, int x)
    {
        if (i < 0 || i > n)
        {
            cout << "Vi tri khong hop le!\n";
            return;
        }
        if (i == 0)
        {
            insertHead(x);
            return;
        }
        if (i == n)
        {
            insertTail(x);
            return;
        }

        Node *p = head;
        for (int k = 0; k < i - 1; k++)
            p = p->next;
        Node *q = new Node(x);
        q->next = p->next;
        p->next = q;
        n++;
    }

    // 5. Xóa đầu O(1)
    void removeHead()
    {
        if (!head)
            return;
        Node *p = head;
        head = head->next;
        if (!head)
            tail = NULL;
        delete p;
        n--;
    }

    // 6. Xóa cuối O(n)
    void removeTail()
    {
        if (!head)
            return;
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *p = head;
            while (p->next != tail)
                p = p->next;
            delete tail;
            tail = p;
            tail->next = NULL;
        }
        n--;
    }

    // 7. Xóa tại vị trí i O(n)
    void removeAt(int i)
    {
        if (i < 0 || i >= n)
        {
            cout << "Vi tri khong hop le!\n";
            return;
        }
        if (i == 0)
        {
            removeHead();
            return;
        }
        if (i == n - 1)
        {
            removeTail();
            return;
        }

        Node *p = head;
        for (int k = 0; k < i - 1; k++)
            p = p->next;
        Node *q = p->next;
        p->next = q->next;
        delete q;
        n--;
    }

    // 8. Duyệt xuôi O(n)
    void traverseForward()
    {

        Node *p = head;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << "\n";
    }

    // 9. Duyệt ngược (dùng đệ quy) O(n)
    void traverseBackward(Node *p)
    {

        if (!p)
            return;
        traverseBackward(p->next);
        cout << p->data << " ";
    }

    void traverseBackward()
    {
        traverseBackward(head);
        cout << "\n";
    }
};


