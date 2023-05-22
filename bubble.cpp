#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void bubble(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
        }
    }
}

void pBubble(int array[], int n) {
    // Sort odd indexed numbers
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; j += 2) {
            if (array[j] < array[j - 1]) {
                swap(array[j], array[j - 1]);
            }
        }

        // Synchronize
        for (int j = 2; j < n; j += 2) {
            if (array[j] < array[j - 1]) {
                swap(array[j], array[j - 1]);
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    // Set up variables
    int n = 10000;
    int arr[n];
    int brr[n];

    // Create an array with numbers starting from n to 1
    for (int i = 0, j = n; i < n; i++, j--)
        arr[i] = j;

    // Sequential version
    auto start_time = high_resolution_clock::now();
    bubble(arr, n);
    auto end_time = high_resolution_clock::now();
    chrono::duration<double, milli> duration = end_time - start_time;
    cout << "Sequential Execution Time: " << duration.count() << " milliseconds" << endl;

    // Reset the array
    for (int i = 0, j = n; i < n; i++, j--)
        arr[i] = j;

    // Parallel version
    start_time = high_resolution_clock::now();
    pBubble(arr, n);
    end_time = high_resolution_clock::now();
    duration = end_time - start_time;
    cout << "Parallel Execution Time: " << duration.count() << " milliseconds" << endl;

    return 0;
}
