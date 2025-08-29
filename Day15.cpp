#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s) {
    vector<int> lastIndex(256, -1);
    int n = s.size();
    int left = 0, maxLen = 0;
    for (int right = 0; right < n; right++) {
        if (lastIndex[s[right]] >= left) {
            left = lastIndex[s[right]] + 1;
        }
        lastIndex[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
