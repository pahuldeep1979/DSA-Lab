// 5. Implement Heapsort (Increasing/Decreasing order).
#include <iostream>
#include <vector>
using namespace std;

// -------------------------
// Helpers: heapify for max-heap and min-heap
// -------------------------
// heapifyMax: ensures subtree rooted at i is a max-heap (for size 'n')
void heapifyMax(vector<int> &a, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapifyMax(a, n, largest);
    }
}

// heapifyMin: ensures subtree rooted at i is a min-heap (for size 'n')
void heapifyMin(vector<int> &a, int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && a[l] < a[smallest]) smallest = l;
    if (r < n && a[r] < a[smallest]) smallest = r;

    if (smallest != i) {
        swap(a[i], a[smallest]);
        heapifyMin(a, n, smallest);
    }
}

// -------------------------
// Heapsort for ascending order (increasing)
// Build a max-heap, repeatedly swap root with last and reduce heap size.
// Resulting array will be in ascending order.
// -------------------------
void heapSortAscending(vector<int> &a) {
    int n = (int)a.size();
    // Build max heap
    for (int i = n/2 - 1; i >= 0; --i)
        heapifyMax(a, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; --i) {
        swap(a[0], a[i]);      // move current max to end
        heapifyMax(a, i, 0);   // heapify reduced heap
    }
}

// -------------------------
// Heapsort for descending order (decreasing)
// Build a min-heap, repeatedly swap root with last and reduce heap size.
// Resulting array will be in descending order.
// -------------------------
void heapSortDescending(vector<int> &a) {
    int n = (int)a.size();
    // Build min heap
    for (int i = n/2 - 1; i >= 0; --i)
        heapifyMin(a, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; --i) {
        swap(a[0], a[i]);      // move current min to end
        heapifyMin(a, i, 0);   // heapify reduced heap
    }
}

// Utility: print array
void printArray(const vector<int> &a) {
    for (int x : a) cout << x << " ";
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid size\n";
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) cin >> arr[i];

    cout << "\nChoose Heapsort option:\n";
    cout << "1. Sort in Increasing (Ascending) order\n";
    cout << "2. Sort in Decreasing (Descending) order\n";
    cout << "Enter choice: ";
    int choice; cin >> choice;

    vector<int> work = arr; // copy input so both options possible independently

    if (choice == 1) {
        heapSortAscending(work);
        cout << "\nSorted array (Ascending): ";
        printArray(work);
    } else if (choice == 2) {
        heapSortDescending(work);
        cout << "\nSorted array (Descending): ";
        printArray(work);
    } else {
        cout << "Invalid choice\n";
    }

    return 0;
}

/*
sample input for all examples:
Enter number of elements: 6
Enter 6 elements: 5 2 9 1 7 3
Output — Increasing (Ascending) order (choice 1)
Choose Heapsort option:
1. Sort in Increasing (Ascending) order
2. Sort in Decreasing (Descending) order
Enter choice: 1

Sorted array (Ascending): 1 2 3 5 7 9
Output — Decreasing (Descending) order (choice 2)
Choose Heapsort option:
1. Sort in Increasing (Ascending) order
2. Sort in Decreasing (Descending) order
Enter choice: 2

Sorted array (Descending): 9 7 5 3 2 1

*/