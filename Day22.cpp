#include <bits/stdc++.h>
using namespace std;
int firstElementKTimes(vector<int>& arr, int k) {
    unordered_map<int, int> freq;
    for (int num : arr) {
        freq[num]++;
        if (freq[num] == k) {
            return num;
        }
    }
    return -1;
}
int main() {
    vector<int> arr = {3, 1, 4, 4, 5, 2, 6, 1, 4};
    int k = 2;
    cout << firstElementKTimes(arr, k) << endl;
    return 0;
}
