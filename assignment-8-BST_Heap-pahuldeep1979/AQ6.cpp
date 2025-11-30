//6. Implement priority queues using heaps.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class MaxHeap {
    vector<int> h;
    static inline int parent(int i){ return (i-1)/2; }
    static inline int left(int i){ return 2*i + 1; }
    static inline int right(int i){ return 2*i + 2; }

    void siftUp(int i) {
        while (i > 0 && h[parent(i)] < h[i]) {
            swap(h[parent(i)], h[i]);
            i = parent(i);
        }
    }

    void siftDown(int i) {
        int n = (int)h.size();
        while (true) {
            int l = left(i), r = right(i);
            int largest = i;
            if (l < n && h[l] > h[largest]) largest = l;
            if (r < n && h[r] > h[largest]) largest = r;
            if (largest == i) break;
            swap(h[i], h[largest]);
            i = largest;
        }
    }

public:
    MaxHeap() = default;
    MaxHeap(const vector<int>& arr) { buildHeap(arr); }

    void buildHeap(const vector<int>& arr) {
        h = arr;
        for (int i = (int)h.size()/2 - 1; i >= 0; --i)
            siftDown(i);
    }

    void push(int val) {
        h.push_back(val);
        siftUp((int)h.size()-1);
    }

    bool isEmpty() const { return h.empty(); }
    int size() const { return (int)h.size(); }

    int top() const {
        if (h.empty()) throw runtime_error("Heap is empty");
        return h[0];
    }

    int pop() {
        if (h.empty()) throw runtime_error("Heap is empty");
        int ret = h[0];
        h[0] = h.back();
        h.pop_back();
        if (!h.empty()) siftDown(0);
        return ret;
    }

    // Find first index of value (linear). Returns -1 if not found.
    int findIndex(int value) const {
        for (int i = 0; i < (int)h.size(); ++i)
            if (h[i] == value) return i;
        return -1;
    }

    // Change key: replace first occurrence of oldVal with newVal and fix heap.
    // Returns true if changed, false if oldVal not found.
    bool changeKey(int oldVal, int newVal) {
        int idx = findIndex(oldVal);
        if (idx == -1) return false;
        h[idx] = newVal;
        // newVal might be greater -> siftUp, or smaller -> siftDown
        siftUp(idx);
        siftDown(idx);
        return true;
    }

    // Return heap array (useful for debug / printing)
    vector<int> asVector() const { return h; }
};

// --------------------
// Min-Heap (Min Priority Queue)
// --------------------
class MinHeap {
    vector<int> h;
    static inline int parent(int i){ return (i-1)/2; }
    static inline int left(int i){ return 2*i + 1; }
    static inline int right(int i){ return 2*i + 2; }

    void siftUp(int i) {
        while (i > 0 && h[parent(i)] > h[i]) {
            swap(h[parent(i)], h[i]);
            i = parent(i);
        }
    }

    void siftDown(int i) {
        int n = (int)h.size();
        while (true) {
            int l = left(i), r = right(i);
            int smallest = i;
            if (l < n && h[l] < h[smallest]) smallest = l;
            if (r < n && h[r] < h[smallest]) smallest = r;
            if (smallest == i) break;
            swap(h[i], h[smallest]);
            i = smallest;
        }
    }

public:
    MinHeap() = default;
    MinHeap(const vector<int>& arr) { buildHeap(arr); }

    void buildHeap(const vector<int>& arr) {
        h = arr;
        for (int i = (int)h.size()/2 - 1; i >= 0; --i)
            siftDown(i);
    }

    void push(int val) {
        h.push_back(val);
        siftUp((int)h.size()-1);
    }

    bool isEmpty() const { return h.empty(); }
    int size() const { return (int)h.size(); }

    int top() const {
        if (h.empty()) throw runtime_error("Heap is empty");
        return h[0];
    }

    int pop() {
        if (h.empty()) throw runtime_error("Heap is empty");
        int ret = h[0];
        h[0] = h.back();
        h.pop_back();
        if (!h.empty()) siftDown(0);
        return ret;
    }

    int findIndex(int value) const {
        for (int i = 0; i < (int)h.size(); ++i)
            if (h[i] == value) return i;
        return -1;
    }

    bool changeKey(int oldVal, int newVal) {
        int idx = findIndex(oldVal);
        if (idx == -1) return false;
        h[idx] = newVal;
        siftUp(idx);
        siftDown(idx);
        return true;
    }

    vector<int> asVector() const { return h; }
};

// --------------------
// Utility to print heap vector in array (level-order) form
// --------------------
void printHeapArray(const vector<int>& arr) {
    cout << "[ ";
    for (int x : arr) cout << x << " ";
    cout << "]\n";
}

// --------------------
// Demo main to show usage and sample output
// --------------------
int main() {
    cout << "=== MaxHeap (Priority Queue: max-priority) Demo ===\n";
    vector<int> data = {5, 2, 9, 1, 7, 3};
    MaxHeap maxpq;
    maxpq.buildHeap(data);
    cout << "Built max-heap from {5,2,9,1,7,3}: ";
    printHeapArray(maxpq.asVector());

    cout << "Insert 8\n";
    maxpq.push(8);
    printHeapArray(maxpq.asVector());

    cout << "Top (max): " << maxpq.top() << "\n";

    cout << "Change key: 2 -> 10\n";
    if (maxpq.changeKey(2, 10)) printHeapArray(maxpq.asVector());
    else cout << "Value 2 not found\n";

    cout << "Pop elements (extract max) until empty: ";
    while (!maxpq.isEmpty()) {
        cout << maxpq.pop() << " ";
    }
    cout << "\n\n";

    cout << "=== MinHeap (Priority Queue: min-priority) Demo ===\n";
    MinHeap minpq(data);
    cout << "Built min-heap from {5,2,9,1,7,3}: ";
    printHeapArray(minpq.asVector());

    cout << "Insert 0\n";
    minpq.push(0);
    printHeapArray(minpq.asVector());

    cout << "Top (min): " << minpq.top() << "\n";

    cout << "Change key: 9 -> -1\n";
    if (minpq.changeKey(9, -1)) printHeapArray(minpq.asVector());
    else cout << "Value 9 not found\n";

    cout << "Pop elements (extract min) until empty: ";
    while (!minpq.isEmpty()) {
        cout << minpq.pop() << " ";
    }
    cout << "\n";

    return 0;
}

/*
=== MaxHeap (Priority Queue: max-priority) Demo ===
Built max-heap from {5,2,9,1,7,3}: [ 9 7 5 1 2 3 ]
Insert 8
[ 9 8 5 1 2 3 7 ]
Top (max): 9
Change key: 2 -> 10
[ 10 9 5 1 8 3 7 ]
Pop elements (extract max) until empty: 10 9 7 5 3 1 8 

=== MinHeap (Priority Queue: min-priority) Demo ===
Built min-heap from {5,2,9,1,7,3}: [ 1 2 3 5 7 9 ]
Insert 0
[ 0 1 3 2 7 9 5 ]
Top (min): 0
Change key: 9 -> -1
[ -1 0 3 2 7 1 5 ]
Pop elements (extract min) until empty: -1 0 1 2 3 5 7 

*/