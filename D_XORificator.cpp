#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<string> matrix(n);
        for (int i = 0; i < n; ++i) {
            cin >> matrix[i];
        }

        vector<int> columnCount(m, 0);
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                if (matrix[i][j] == '1') {
                    ++columnCount[j];
                }
            }
        }

        int maxSpecial = 0;
        vector<int> bestConfig(n, 0);

        for (int mask = 0; mask < (1 << n); ++mask) {
            vector<int> currentCount = columnCount;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    for (int j = 0; j < m; ++j) {
                        currentCount[j] += (matrix[i][j] == '0') ? 1 : -1;
                    }
                }
            }

            int specialCount = 0;
            for (int j = 0; j < m; ++j) {
                if (currentCount[j] == 1) {
                    ++specialCount;
                }
            }

            if (specialCount > maxSpecial) {
                maxSpecial = specialCount;
                for (int i = 0; i < n; ++i) {
                    bestConfig[i] = (mask & (1 << i)) ? 1 : 0;
                }
            }
        }

        cout << maxSpecial << endl;
        for (int i = 0; i < n; ++i) {
            cout << bestConfig[i];
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
