#include <iostream>
using namespace std;

struct Node {
    string key;
    int value;
    Node* next;
    Node(string k, int v) : key(k), value(v), next(nullptr) {}
};

class SymbolTableLinkedList {
private:
    Node* head;

public:
    SymbolTableLinkedList() {
        head = nullptr;
    }

    // Thêm hoặc cập nhật
    void put(string key, int value) {
        Node* temp = head;
        while (temp) {
            if (temp->key == key) {
                temp->value = value; // cập nhật nếu đã tồn tại
                return;
            }
            temp = temp->next;
        }
        // Thêm mới vào đầu danh sách
        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
    }

    // Tìm kiếm
    int get(string key) {
        Node* temp = head;
        while (temp) {
            if (temp->key == key)
                return temp->value;
            temp = temp->next;
        }
        cout << "Không tìm thấy key!\n";
        return -1;
    }

    // Hiển thị
    void display() {
        cout << "Symbol Table (Linked List):\n";
        Node* temp = head;
        while (temp) {
            cout << temp->key << " : " << temp->value << endl;
            temp = temp->next;
        }
    }
};
int main() {
    SymbolTableLinkedList stl;
    stl.put("a", 5);
    stl.put("b", 15);
    stl.put("a", 50); // cập nhật
    stl.display();
    cout << "Giá trị b = " << stl.get("b") << endl;
    cout << "\n";
    return 0;
}
