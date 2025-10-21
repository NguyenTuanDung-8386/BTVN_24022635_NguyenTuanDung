#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// ========================== MAX HEAP ==========================
class MaxHeap {
private:
    vector<int> heap;

    void swim(int k) {
        while (k > 0 && heap[k] > heap[(k - 1) / 2]) {
            swap(heap[k], heap[(k - 1) / 2]);
            k = (k - 1) / 2;
        }
    }

    void sink(int k) {
        int n = heap.size();
        while (2 * k + 1 < n) {
            int j = 2 * k + 1;
            if (j + 1 < n && heap[j + 1] > heap[j]) j++;
            if (heap[k] >= heap[j]) break;
            swap(heap[k], heap[j]);
            k = j;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        swim(heap.size() - 1);
    }

    int delMax() {
        if (heap.empty()) return -1;
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) sink(0);
        return maxVal;
    }

    int max() const {
        return heap.empty() ? -1 : heap[0];
    }

    bool isEmpty() const {
        return heap.empty();
    }

    int size() const {
        return heap.size();
    }
};

// ========================== MIN HEAP ==========================
class MinHeap {
private:
    vector<int> heap;

    void swim(int k) {
        while (k > 0 && heap[k] < heap[(k - 1) / 2]) {
            swap(heap[k], heap[(k - 1) / 2]);
            k = (k - 1) / 2;
        }
    }

    void sink(int k) {
        int n = heap.size();
        while (2 * k + 1 < n) {
            int j = 2 * k + 1;
            if (j + 1 < n && heap[j + 1] < heap[j]) j++;
            if (heap[k] <= heap[j]) break;
            swap(heap[k], heap[j]);
            k = j;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        swim(heap.size() - 1);
    }

    int delMin() {
        if (heap.empty()) return -1;
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) sink(0);
        return minVal;
    }

    int min() const {
        return heap.empty() ? -1 : heap[0];
    }

    bool isEmpty() const {
        return heap.empty();
    }

    int size() const {
        return heap.size();
    }
};

// ==================== TÍNH TRUNG VỊ ====================
void processMedian(const vector<int>& nums) {
    MaxHeap left;  // nửa nhỏ hơn (max heap)
    MinHeap right; // nửa lớn hơn (min heap)

    cout << fixed << setprecision(1);

    for (int x : nums) {
        // Chèn phần tử mới vào heap thích hợp
        if (left.isEmpty() || x <= left.max())
            left.insert(x);
        else
            right.insert(x);

        // Cân bằng kích thước 2 heap
        if (left.size() > right.size() + 1) {
            right.insert(left.delMax());
        } else if (right.size() > left.size() + 1) {
            left.insert(right.delMin());
        }

        // Tính trung vị
        double median;
        if (left.size() == right.size())
            median = (left.max() + right.min()) / 2.0;
        else if (left.size() > right.size())
            median = left.max();
        else
            median = right.min();

        cout << median << endl;
    }
}

// ========================== MAIN ==========================
int main() {
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    vector<int> a(n);
    cout << "Nhap " << n << " so nguyen: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << "\nTrung vi sau moi lan chen:\n";
    processMedian(a);

    return 0;
}
