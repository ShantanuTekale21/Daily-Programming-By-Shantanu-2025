#include <bits/stdc++.h>
using namespace std;
int countDivisors(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            if (i != n / i) {
                count++;
            }
        }
    }
    return count;
}
int main() {
    int N;
    cin >> N;
    cout << countDivisors(N) << endl;
    return 0;
}
