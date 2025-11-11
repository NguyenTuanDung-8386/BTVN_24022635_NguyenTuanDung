#include <iostream>
#include <string>
using namespace std;

class SeparateChainingHashST {
private:
    static const int M = 7;

    struct Node {
        string key;
        int val;
        Node* next;
        Node(string k, int v, Node* n = nullptr) {
            key = k;
            val = v;
            next = n;
        }
    };
    Node* st[M];            

    // ham bam
    int hash(string key) {
        int h = 0;
        for (char c : key)
            h = 31 * h + c;
        if (h < 0) h = -h;
        return h % M;
    }

public:
    // Constructor
    SeparateChainingHashST() {
        for (int i = 0; i < M; i++)
            st[i] = nullptr;  
    }

    // them key moi hoac cap nhat gia tri key cu 
    void put(string key, int val) {
        int i = hash(key);
        for (Node* x = st[i]; x != nullptr; x = x->next) {
            if (x->key == key) {
                x->val = val;
                return;
            }
        }
        st[i] = new Node(key, val, st[i]);  // them ky moi vao dau danh sach
    }

    // tim gia tri cua key
    int get(string key) {
        int i = hash(key);
        for (Node* x = st[i]; x != nullptr; x = x->next) {
            if (x->key == key)
                return x->val;
        }
        cout << "Khong tim thay khoa!\n";
        return -1;
    }

    // in toan bo bang bam
    void display() {
        for (int i = 0; i < M; i++) {
            cout << "[" << i << "]: ";
            for (Node* x = st[i]; x != nullptr; x = x->next)
                cout << "(" << x->key << "," << x->val << ") ";
            cout << "\n";
        }
    }
};

// test
int main() {
    SeparateChainingHashST table;
    table.put("A", 1);
    table.put("B", 2);
    table.put("C", 3);
    table.put("D", 4);
    table.put("K", 5);

    cout << "Gia tri cua C: " << table.get("C") << endl;

    cout << "\nNoi dung bang bam:\n";
    table.display();
}
