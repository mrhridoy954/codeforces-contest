#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        
        vector<int> result;
        while (x != 0) {
            if (x % 2 != 0) {
                // If x is odd, set the current bit to 1 or -1
                result.push_back((x % 2 == 1) ? 1 : -1);
                x -= result.back(); // Subtract the value we just added
            } else {
                // If x is even, set the current bit to 0
                result.push_back(0);
            }
            x /= 2;
        }
        
        // Output the result
        cout << result.size() << endl;
        for (int v : result) {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}
