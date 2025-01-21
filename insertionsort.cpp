#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void insertionSort(unsigned int* arr, unsigned int n) {
    for (unsigned int i = 1; i < n; i++) {
        unsigned int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    unsigned int n = 1000;
    unsigned int* arr = new unsigned int[n];
    srand(time(0));

    for (unsigned int i = 0; i < n; i++)
        arr[i] = rand() % 100;

    clock_t start = clock();
    insertionSort(arr, n);
    clock_t end = clock();

    cout << "Insertion sort time: " << ((double)end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    delete[] arr;
    return 0;
}