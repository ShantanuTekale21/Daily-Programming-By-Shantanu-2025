#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> res;
void backtrack(string &s, int index) {
        if (index == s.size()) {
            res.push_back(s);
            return;
        }
        unordered_set<char> used;
        for (int i = index; i < s.size(); i++) {
            if (used.find(s[i]) != used.end()) continue; 
            used.insert(s[i]);
            swap(s[index], s[i]);
            backtrack(s, index + 1);
            swap(s[index], s[i]);
        }
    }
    vector<string> getPermutations(string s) {
        backtrack(s, 0);
        return res;
    }
};
int main() {
    string s = "abc";
    Solution sol;
    vector<string> ans = sol.getPermutations(s);
    for (auto &p : ans) {
        cout << p << "\n";
    }
    return 0;
}
