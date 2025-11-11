#include <iostream>
#include <string>
using namespace std;

class LinearProbingHashST {
private:
    static const int M = 10;        
    string keys[M];                 
    int vals[M];                    

    // ham bam
    int hash(string key) {
        int h = 0;
        for (char c : key)
            h = 31 * h + c;
        if (h < 0) h = -h;
        return h % M;
    }

public:
    // constructor
    LinearProbingHashST() {
        for (int i = 0; i < M; i++) {
            keys[i] = "";           
            vals[i] = 0;
        }
    }

    // them key moi hoac cap nhat gia tri key cu
    void put(string key, int val) {
        int i;
        for (i = hash(key); keys[i] != ""; i = (i + 1) % M) {
            if (keys[i] == key) {   
                vals[i] = val;      
                return;
            }
        }
        keys[i] = key;
        vals[i] = val;
    }

    // tim gia tri theo key
    int get(string key) {
        for (int i = hash(key); keys[i] != ""; i = (i + 1) % M) {
            if (keys[i] == key)
                return vals[i];
        }
        cout << "Khong tim thay khoa!\n";
        return -1;
    }

    // in bang bam
    void display() {
        cout << "\nIndex | Key -> Value\n";
        for (int i = 0; i < M; i++) {
            if (keys[i] != "")
                cout << i << " | " << keys[i] << " -> " << vals[i] << endl;
            else
                cout << i << " | (trong)\n";
        }
    }
};

// test
int main() {
    LinearProbingHashST table;
    table.put("A", 1);
    table.put("B", 2);
    table.put("C", 3);
    table.put("D", 4);
    table.put("K", 5);

    cout << "Gia tri cua D: " << table.get("D") << endl;
    table.display();
}
