#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    long long N, M;
    cin >> N >> M;
   long long gcd = __gcd(N, M);
    long long lcm = (N / gcd) * M;
    cout << lcm << endl;
    return 0;
}
