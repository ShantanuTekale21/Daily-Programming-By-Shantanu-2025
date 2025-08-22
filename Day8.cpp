#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    stringstream ss(s);
    string word;
    vector<string> words;
    while (ss >> word) {
        words.push_back(word);
    }
    reverse(words.begin(), words.end());

    string result;
    for (int i = 0; i < words.size(); i++) {
        if (i > 0) result += " ";
        result += words[i];
    }

    return result;
}

int main() {
    string s = "the sky is blue";
    cout << reverseWords(s) << endl;
    s = "  hello   world  ";
    cout << reverseWords(s) << endl;

    s = "a good   example";
    cout << reverseWords(s) << endl;

    return 0;
}
