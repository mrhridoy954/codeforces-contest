#include <iostream>
#include <vector>
using namespace std;

bool canBeSortedWithSwaps(const vector<int>& arr) {
    int n = arr.size();
    int countBreaks = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[(i + 1) % n]) {
            countBreaks++;
        }
    }
    
    return countBreaks <= 1;
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
        
        if (canBeSortedWithSwaps(a)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
