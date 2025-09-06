#include <bits/stdc++.h>
using namespace std;
vector<int> slidingWindowMax(vector<int>& arr, int k) {
    deque<int> dq; elements
    vector<int> result;
    for (int i = 0; i < arr.size(); i++) {
      window
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
 current element from back
        while (!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();
        dq.push_back(i);
 window
        if (i >= k - 1)
            result.push_back(arr[dq.front()]);
    }
    return result;
}
int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = slidingWindowMax(arr, k);
    cout << "Output: [";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    return 0;
}
