#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void selectionSort(unsigned int* arr, unsigned int n) {
    for (unsigned int i = 0; i < n - 1; i++) {
        unsigned int minIndex = i;
        for (unsigned int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            unsigned int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    unsigned int n = 1000;
    unsigned int* arr = new unsigned int[n];
    srand(time(0));

    for (unsigned int i = 0; i < n; i++)
        arr[i] = rand() % 100;

    clock_t start = clock();
    selectionSort(arr, n);
    clock_t end = clock();

    cout << "Selection sort time: " << ((double)end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    delete[] arr;
    return 0;
}