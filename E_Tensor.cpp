#include <iostream>
#include <vector>

using namespace std;

// Function to query the reachability
bool query(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();
    string response;
    cin >> response;
    return response == "YES";
}

// Main function to solve the problem
void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> color(n + 1, -1);  // To store the color of each vertex

        for (int i = 1; i <= n; ++i) {
            color[i] = 0;  // Initially color everything as 0 (black)
        }

        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                bool reachable = query(i, j);
                if (!reachable && !query(j, i)) {
                    color[j] = 1 - color[i];  // Assign opposite color if not reachable
                }
            }
        }

        // Output the final colors
        cout << "!";
        for (int i = 1; i <= n; ++i) {
            cout << " " << color[i];
        }
        cout << endl;
        cout.flush();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
