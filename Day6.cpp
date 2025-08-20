#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> findZeroSumSubarrays(vector<int>& arr) {
    vector<pair<int,int>> result;
    unordered_map<int, vector<int>> prefixMap; // prefix sum -> list of indices
    int prefixSum = 0;

    for(int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        // If prefix sum is zero, subarray from 0 to i has sum 0
        if(prefixSum == 0) {
            result.push_back({0, i});
        }

        // If prefix sum seen before, then subarray between indices has sum 0
        if(prefixMap.find(prefixSum) != prefixMap.end()) {
            for(int startIndex : prefixMap[prefixSum]) {
                result.push_back({startIndex + 1, i});
            }
        }

        // Store current index for this prefix sum
        prefixMap[prefixSum].push_back(i);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, -3, 3, -1, 2};
    vector<pair<int,int>> subarrays = findZeroSumSubarrays(arr);

    if(subarrays.empty()) {
        cout << "No subarrays found\n";
    } else {
        cout << "Subarrays with zero sum:\n";
        for(auto &p : subarrays) {
            cout << "(" << p.first << ", " << p.second << ")\n";
        }
    }
    return 0;
}
