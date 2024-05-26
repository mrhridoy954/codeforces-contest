#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isBeautiful(vector<int>& a) {
    int n = a.size();
    sort(a.begin(), a.end());
    
    int first = a[0];
    int second = -1;
    for (int i = 1; i < n; i++) {
        if (a[i] != first) {
            second = a[i];
            break;
        }
    }
    
    if (second == -1) {
        return false; 
    }
    
    for (int i = 0; i < n; i++) {
        if (a[i] % first != 0 && a[i] % second != 0) {
            return false;
        }
    }
    
    return true;
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
        
        if (isBeautiful(a)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
