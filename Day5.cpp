#include <iostream>
#include <vector>
#include <algorithm> // for reverse
using namespace std;

vector<int> findLeaders(vector<int>& arr) {
    int n = arr.size();
    vector<int> leaders;

    int maxFromRight = arr[n - 1]; // last element is always a leader
    leaders.push_back(maxFromRight);

    // Traverse from right to left
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= maxFromRight) {
            maxFromRight = arr[i];
            leaders.push_back(arr[i]);
        }
    }

    // Leaders are collected in reverse order, so reverse them
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main() {
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    
    vector<int> leaders = findLeaders(arr);

    cout << "Leaders: ";
    for (int num : leaders) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
