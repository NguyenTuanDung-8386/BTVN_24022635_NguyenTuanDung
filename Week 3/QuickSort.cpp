#include <iostream>
#include <vector>
using namespace std;

// Hàm chia mảng theo pivot
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Chọn phần tử cuối làm pivot
    int i = low - 1;       // i là vị trí của phần tử nhỏ hơn pivot

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // Nếu phần tử nhỏ hơn pivot
            i++;              // Tăng vị trí i
            swap(arr[i], arr[j]); // Đưa phần tử nhỏ về bên trái
        }
    }

    // Đưa pivot về đúng vị trí (sau phần tử nhỏ nhất)
    swap(arr[i + 1], arr[high]);
    return i + 1; // Trả về vị trí mới của pivot
}

// Hàm QuickSort (đệ quy)
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Tìm vị trí pivot sau khi chia mảng
        int pi = partition(arr, low, high);

        // Gọi đệ quy cho hai nửa mảng
        quickSort(arr, low, pi - 1);  // Bên trái pivot
        quickSort(arr, pi + 1, high); // Bên phải pivot
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Mang truoc khi sap xep: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "Mang sau khi Quick Sort: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
