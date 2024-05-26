#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        set<long long> elements;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            elements.insert(a[i]);
        }

        int max_special_length = 0;

        for (int i = 0; i < (1 << n); ++i) {
            long long current_lcm = 1;
            bool is_empty = true;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    is_empty = false;
                    current_lcm = lcm(current_lcm, a[j]);
                    if (current_lcm > 1e9) break;
                }
            }
            if (!is_empty && elements.find(current_lcm) == elements.end()) {
                int subset_size = __builtin_popcount(i);
                max_special_length = max(max_special_length, subset_size);
            }
        }

        cout << max_special_length << endl;
    }

    return 0;
}
