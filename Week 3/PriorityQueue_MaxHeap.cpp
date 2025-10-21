#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap; // dùng vector để lưu cấu trúc heap (max-heap)

    // Hàm helper: hoán đổi phần tử cha - con khi chèn
    void swim(int k) {
        // Khi phần tử mới thêm lớn hơn cha => đổi chỗ để duy trì max-heap
        while (k > 0 && heap[k] > heap[(k - 1) / 2]) {
            swap(heap[k], heap[(k - 1) / 2]);
            k = (k - 1) / 2; // lên cha
        }
    }

    // Hàm helper: đẩy phần tử xuống dưới khi xóa phần tử lớn nhất
    void sink(int k) {
        int n = heap.size();
        while (2 * k + 1 < n) { // khi còn con bên trái
            int j = 2 * k + 1; // con trái
            if (j + 1 < n && heap[j + 1] > heap[j]) // nếu có con phải và con phải lớn hơn
                j++; // chọn con lớn hơn
            if (heap[k] >= heap[j]) break; // nếu cha >= con => đúng vị trí
            swap(heap[k], heap[j]); // đổi chỗ cha - con
            k = j; // đi xuống tiếp
        }
    }

public:
    // Chèn giá trị vào hàng đợi
    void insert(int value) {
        heap.push_back(value);  // thêm vào cuối vector
        swim(heap.size() - 1);  // đưa lên đúng vị trí trong heap
    }

    // Xóa và trả về giá trị lớn nhất
    int delMax() {
        if (isEmpty()) {
            cout << "Priority Queue rong!" << endl;
            return -1;
        }

        int maxVal = heap[0]; // phần tử lớn nhất luôn ở gốc
        heap[0] = heap.back(); // thay thế bằng phần tử cuối
        heap.pop_back();       // xóa phần tử cuối
        sink(0);               // đẩy phần tử mới ở gốc xuống đúng chỗ
        return maxVal;
    }

    // Trả về giá trị lớn nhất (không xóa)
    int max() {
        if (isEmpty()) {
            cout << "Priority Queue rong!" << endl;
            return -1;
        }
        return heap[0];
    }

    // Kiểm tra rỗng
    bool isEmpty() {
        return heap.empty();
    }

    // Trả về số phần tử
    int size() {
        return heap.size();
    }

    // In heap ra màn hình (để kiểm tra)
    void printHeap() {
        cout << "Heap: ";
        for (int v : heap)
            cout << v << " ";
        cout << endl;
    }
};

// --- Chương trình kiểm thử ---
int main() {
    PriorityQueue pq;

    pq.insert(10);
    pq.insert(40);
    pq.insert(30);
    pq.insert(5);
    pq.insert(20);

    pq.printHeap();

    cout << "Gia tri lon nhat hien tai: " << pq.max() << endl;

    cout << "Xoa gia tri lon nhat: " << pq.delMax() << endl;
    pq.printHeap();

    cout << "So phan tu con lai: " << pq.size() << endl;
    cout << "Priority Queue rong? " << (pq.isEmpty() ? "Co" : "Khong") << endl;

    return 0;
}
