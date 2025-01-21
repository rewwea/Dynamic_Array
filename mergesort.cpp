#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void merge(unsigned int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    unsigned int* L = new unsigned int[n1];
    unsigned int* R = new unsigned int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(unsigned int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    unsigned int n = 1000;
    unsigned int* arr = new unsigned int[n];
    srand(time(0));

    for (unsigned int i = 0; i < n; i++)
        arr[i] = rand() % 100;

    clock_t start = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end = clock();

    cout << "Merge sort time: " << ((double)end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    delete[] arr;
    return 0;
}