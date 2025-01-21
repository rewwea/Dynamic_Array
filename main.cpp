#include <iostream>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time()

using namespace std;

void srt(int* p, int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i] > p[j]) {
                swap(p[i], p[j]);
            }
        }
    }
}

int main()
{
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int* a = new int[n];
    srand(time(0));

    cout << "Случайный массив: ";
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100; 
        cout << a[i] << " ";
    }
    cout << endl;

    srt(a, n); 

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    delete[] a; 

    return 0;
}