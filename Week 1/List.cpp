#include <iostream>
using namespace std;

const int MAX = 1000;

class List
{
private:
    int a[MAX];
    int n;

public:
    List() { n = 0; }

    // 1. Truy cập phần tử tại i (O(1))
    int get(int i)
    {
        if (i < 0 || i >= n)
        {
            cout << "Loi: vi tri khong hop le!\n";
            return -1;
        }
        return a[i];
    }

    // 2. Chèn phần tử vào đầu (O(n))
    void insertHead(int x)
    {
        if (n == MAX)
        {
            cout << "Loi: List day!\n";
            return;
        }
        for (int i = n; i > 0; i--)
            a[i] = a[i - 1];
        a[0] = x;
        n++;
    }

    // 3. Chèn phần tử vào cuối O(1)
    void insertTail(int x)
    {
        if (n == MAX)
        {
            cout << "Loi: List day!\n";
            return;
        }
        a[n++] = x; 
    }

    // 4. Chèn phần tử vào vị trí i O(n)
    void insertAt(int i, int x)
    {
        if (n == MAX)
        {
            cout << "Loi: List day!\n";
            return;
        }
        if (i < 0 || i > n)
        {
            cout << "Loi: vi tri khong hop le!\n";
            return;
        }
        for (int j = n; j > i; j--)
            a[j] = a[j - 1]; 
        a[i] = x;
        n++;
    }

    // 5. Xóa phần tử đầu O(n)
    void removeHead()
    {
        if (n == 0)
        {
            cout << "Loi: List rong!\n";
            return;
        }
        for (int i = 0; i < n - 1; i++)
            a[i] = a[i + 1]; 
        n--;
    }

    // 6. Xóa phần tử cuối O(1)
    void removeTail()
    {
        if (n == 0)
        {
            cout << "Loi: List rong!\n";
            return;
        }
        n--; 
    }

    // 7. Xóa phần tử tại vị trí i O(n)
    void removeAt(int i)
    {
        if (i < 0 || i >= n)
        {
            cout << "Loi: vi tri khong hop le!\n";
            return;
        }
        for (int j = i; j < n - 1; j++)
            a[j] = a[j + 1]; 
        n--;
    }

    // 8. Duyệt xuôi O(n)
    void traverseForward()
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }

    // 9. Duyệt ngược O(n)
    void traverseBackward()
    {
        for (int i = n - 1; i >= 0; i--)
            cout << a[i] << " ";
        cout << "\n";
    }
};

int main()
{
    List lst;

    lst.insertTail(10);
    lst.insertTail(20);
    lst.insertTail(30);
    lst.insertHead(5);
    lst.insertAt(2, 15);

    cout << "Duyet xuoi: ";
    lst.traverseForward();

    cout << "Duyet nguoc: ";
    lst.traverseBackward();

    lst.removeHead();
    lst.removeTail();
    lst.removeAt(1);

    cout << "Sau khi xoa: ";
    lst.traverseForward();

    return 0;
}
