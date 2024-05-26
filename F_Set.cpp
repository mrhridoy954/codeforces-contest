#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int numSets = (1 << n) - 1;
    vector<int> v(numSets);
    for (int i = 0; i < numSets; ++i) {
        cin >> v[i];
    }

       vector<int> validSubsets;

         for (int s = 0; s < (1 << n); ++s) {
        bool valid = true;

        for (int t = 1; t < (1 << n); ++t) {
            int intersectionSize = 0;
            for (int i = 0; i < n; ++i) {
                if ((s & (1 << i)) && (t & (1 << i))) {
                    intersectionSize++;
                }
            }
            if (!(v[t - 1] & (1 << intersectionSize))) {
                valid = false;
                break;
            }
        }

        if (valid) {
            validSubsets.push_back(s);
        }
    }

    sort(validSubsets.begin(), validSubsets.end());
    cout << validSubsets.size() << endl;
    for (int subset : validSubsets) {
        cout << subset << endl;
    }

    return 0;
}
