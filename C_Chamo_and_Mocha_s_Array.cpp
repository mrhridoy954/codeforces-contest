#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMaxPossibleValue(vector<int>& a) {
    sort(a.begin(), a.end());
    int n = a.size();
    return a[(n - 1) / 2];
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int maxValue = findMaxPossibleValue(a);
        cout << maxValue << endl;
    }
    
    return 0;
}
