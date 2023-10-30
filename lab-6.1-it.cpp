#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateArray(int a[], int size, const int low, const int high) {
    for (int i = 0; i < size; i++) {
        a[i] = low + rand() % (high - low + 1);
    }
}

void calculateSumAndChangeToZero(int a[], int size, int &count, int &sum) {
    count = 0;
    sum = 0;
    for (int i = 0; i < size; ++i) {
        if (a[i] > 0 && i % 5 != 0) {
            count++;
            sum += a[i];

            a[i] = 0;
        }
    }
}

void printArray(int a[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    srand((unsigned)time(NULL));

    const int LOW = -20;
    const int HIGH = 50;
    const int SIZE = 20;
    int a[SIZE];
    int count, sum;

    generateArray(a, SIZE, LOW, HIGH);
    cout << "Початковий масив:" << endl;
    printArray(a, SIZE);

    calculateSumAndChangeToZero(a, SIZE, count, sum);
    cout << "Модифікований масив:" << endl;
    printArray(a, SIZE);

    cout << "Кількість елементів, які задовольняють критерії: " << count << endl;
    cout << "Сума елементів, які задовольняють критерії: " << sum << endl;

    return 0;
}