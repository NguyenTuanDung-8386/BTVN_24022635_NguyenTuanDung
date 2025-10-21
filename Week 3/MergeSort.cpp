#include <iostream>
#include <vector>
using namespace std;

// Hàm trộn hai nửa mảng đã sắp xếp
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;     // Số phần tử của nửa trái
    int n2 = right - mid;        // Số phần tử của nửa phải

    // Tạo mảng tạm để chứa hai nửa
    vector<int> L(n1), R(n2);

    // Copy dữ liệu vào hai mảng tạm
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Trộn hai mảng L và R lại theo thứ tự tăng dần
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Sao chép phần còn lại (nếu có) của L vào arr
    while (i < n1)
        arr[k++] = L[i++];

    // Sao chép phần còn lại (nếu có) của R vào arr
    while (j < n2)
        arr[k++] = R[j++];
}

// Hàm chính của Merge Sort (đệ quy)
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Chia đôi mảng

        // Gọi đệ quy sắp xếp hai nửa
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Trộn hai nửa đã sắp xếp
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Mang truoc khi sap xep: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Mang sau khi Merge Sort: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
