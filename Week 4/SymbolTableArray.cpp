#include <iostream>
using namespace std;

struct Symbol {
    string key;   // tên biến (identifier)
    int value;    // giá trị của biến
};

class SymbolTableArray {
private:
    Symbol table[100];  // dùng mảng tĩnh
    int size;           // số lượng phần tử hiện có

public:
    SymbolTableArray() {
        size = 0;
    }

    // Thêm hoặc cập nhật giá trị cho key
    void put(string key, int value) {
        // Nếu key đã tồn tại, cập nhật giá trị
        for (int i = 0; i < size; i++) {
            if (table[i].key == key) {
                table[i].value = value;
                return;
            }
        }
        // Nếu chưa có, thêm mới
        table[size].key = key;
        table[size].value = value;
        size++;
    }

    // Tìm giá trị theo key
    int get(string key) {
        for (int i = 0; i < size; i++) {
            if (table[i].key == key)
                return table[i].value;
        }
        cout << "Không tìm thấy key!\n";
        return -1;
    }

    // Hiển thị toàn bộ bảng
    void display() {
        cout << "Symbol Table (Array):\n";
        for (int i = 0; i < size; i++)
            cout << table[i].key << " : " << table[i].value << endl;
    }
};
int main() {
    SymbolTableArray sta;
    sta.put("x", 10);
    sta.put("y", 20);
    sta.put("x", 30); // cập nhật giá trị x
    sta.display();
    cout << "Giá trị y = " << sta.get("y") << endl;

    cout << "\n";
    return 0;
}

