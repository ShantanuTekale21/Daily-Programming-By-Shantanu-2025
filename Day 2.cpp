#include <iostream>
#include <vector>
#include <numeric> // for accumulate
using namespace std;

int find_missing_number(const vector<int>& arr) {
    int n = arr.size() + 1;
    long long expected_sum = (long long)n * (n + 1) / 2;
    long long actual_sum = accumulate(arr.begin(), arr.end(), 0LL);
    return expected_sum - actual_sum;
}

int main() {
    vector<pair<vector<int>, int>> test_cases = {
        {{1, 2, 4, 5}, 3},
        {{2, 3, 4, 5}, 1},
        {{1, 2, 3, 4}, 5},
        {{1}, 2},
        // generating large test case
        {[](){
            vector<int> v;
            for (int i = 1; i < 1000000; i++) {
                v.push_back(i);
            }
            return v;
        }(), 1000000}
    };

    cout << "Running Test Cases :-" << endl;
    for (size_t i = 0; i < test_cases.size(); i++) {
        const vector<int>& input_arr = test_cases[i].first;
        int expected_output = test_cases[i].second;
        int actual_output = find_missing_number(input_arr);
        string status = (actual_output == expected_output) ? "Pass" : "Fail";

        cout << "\nTest Case " << i + 1 << ":" << endl;
        if (input_arr.size() > 20) {
            cout << "Input: A list from 1 to " << input_arr.size() << endl;
        } else {
            cout << "Input: ";
            for (int num : input_arr) cout << num << " ";
            cout << endl;
        }
        cout << "Expected: " << expected_output
             << ", Actual: " << actual_output << endl;
        cout << "Status: " << status << endl;
    }

    cout << "\n**** Testing Complete ****" << endl;
    return 0;
}
