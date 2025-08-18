#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int i, int j) {
    if (arr1[i] > arr2[j]) {
        swap(arr1[i], arr2[j]);
    }
}

void merge(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int len = m + n;
    int gap = (len / 2) + (len % 2); // initial gap (ceil)
    
    while (gap > 0) {
        int left = 0;
        int right = left + gap;

        while (right < len) {
            // Case 1: both pointers in arr1
            if (left < m && right < m) {
                if (arr1[left] > arr1[right]) {
                    swap(arr1[left], arr1[right]);
                }
            }
            // Case 2: left in arr1, right in arr2
            else if (left < m && right >= m) {
                if (arr1[left] > arr2[right - m]) {
                    swap(arr1[left], arr2[right - m]);
                }
            }
            // Case 3: both in arr2
            else {
                if (arr2[left - m] > arr2[right - m]) {
                    swap(arr2[left - m], arr2[right - m]);
                }
            }
            left++, right++;
        }

        if (gap == 1) break;
        gap = (gap / 2) + (gap % 2); // reduce gap (ceil)
    }
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};

    merge(arr1, arr2, arr1.size(), arr2.size());

    cout << "arr1: ";
    for (int x : arr1) cout << x << " ";
    cout << endl;

    cout << "arr2: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    return 0;
}
