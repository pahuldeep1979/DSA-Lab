// Q2. Improved Selection Sort (Bidirectional Selection Sort)

// Question:
// A slightly improved selection sort – We know that selection sort algorithm takes the minimum on every pass on the array, and places it at its correct position.
// The idea is to also take the maximum on every pass and place it at its correct position.
// So in every pass, we keep track of both maximum and minimum, and array becomes sorted from both ends.
// Implement this logic.

#include <iostream>
using namespace std;

void improvedSelectionSort(int a[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int minIndex = left;
        int maxIndex = left;

        // Find min and max in the current range
        for (int i = left; i <= right; i++) {
            if (a[i] < a[minIndex])
                minIndex = i;
            if (a[i] > a[maxIndex])
                maxIndex = i;
        }

        // Swap minimum to the left
        int temp = a[left];
        a[left] = a[minIndex];
        a[minIndex] = temp;

        // If maxIndex was at left, after swapping min, maxIndex shifts to minIndex
        if (maxIndex == left)
            maxIndex = minIndex;

        // Swap maximum to the right
        temp = a[right];
        a[right] = a[maxIndex];
        a[maxIndex] = temp;

        left++;
        right--;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    improvedSelectionSort(arr, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
