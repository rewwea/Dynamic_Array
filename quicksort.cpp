#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;

void quickSort(unsigned int* arr, int low, int high) {
    stack<int> s;
    s.push(low);
    s.push(high);

    while (!s.empty()) {
        high = s.top(); s.pop();
        low = s.top(); s.pop();

        if (low < high) {
            unsigned int pivot = arr[high];
            int i = (low - 1);
            for (int j = low; j <= high - 1; j++) {
                if (arr[j] < pivot) {
                    i++;
                    unsigned int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            unsigned int temp = arr[i + 1];
            arr[i + 1] = arr[high];
            arr[high] = temp;
            int pi = i + 1;

            // Push left side to stack
            s.push(low);
            s.push(pi - 1);
            
            // Push right side to stack
            s.push(pi + 1);
            s.push(high);
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
    quickSort(arr, 0, n - 1);
    clock_t end = clock();

    cout << "Quick sort time: " << ((double)end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    delete[] arr;
    return 0;
}
