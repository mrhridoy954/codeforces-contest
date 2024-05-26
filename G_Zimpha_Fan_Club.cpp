#include <iostream>
#include <string>

using namespace std;

bool canTransform(const string& s, const string& t) {
    int n = s.length();
    int m = t.length();
    
    size_t star_pos = s.find('*');
    
    // No '*' in s
    if (star_pos == string::npos) {
        if (n != m) return false;
        for (int i = 0; i < n; ++i) {
            if (s[i] != '-' && s[i] != t[i]) return false;
        }
        return true;
    }
    
    // Check prefix before '*'
    for (int i = 0; i < star_pos; ++i) {
        if (i >= m || (s[i] != '-' && s[i] != t[i])) return false;
    }
    
    // Check suffix after '*'
    int suffix_start_s = star_pos + 1;
    int suffix_start_t = m - (n - suffix_start_s);
    
    if (suffix_start_t < 0) return false;
    
    for (int i = suffix_start_s; i < n; ++i) {
        int t_index = suffix_start_t + (i - suffix_start_s);
        if (t_index >= m || (s[i] != '-' && s[i] != t[t_index])) return false;
    }
    
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    
    if (canTransform(s, t)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}
