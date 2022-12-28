#include <bits/stdc++.h>
    
using namespace std;
    
#define endl                       '\n'
#define mod                        1000000007
#define span(a)                    begin(a), end(a)
#define ps(x)                      fixed << setprecision(8) << (x);
#define int                        long long
#define ll                         long long
#define inf                        1e18
    
template<class T>
ostream &operator<<(ostream &out, const vector<T> &v) {
    for (int i = 0, n = (int) v.size(); i < n; ++i) {
        if (i) out << ' ';
        out << v[i];
    }
    return out << "\n";
}
    
template<class T>
ostream &operator<<(ostream &out, const vector<vector<T>> &M) {
    for (int i = 0, n = (int) M.size(); i < n; ++i) {
        for (int j = 0, m = (int) M[i].size(); j < m; ++j) {
            if (j) out << " ";
            out << M[i][j];
        }
        out << "\n";
    }
    return out;
}
    
int ceil_div(int a, int b) {
    return a / b + ((a ^ b) > 0 && a % b != 0);
}
    
    
void solve() {
    int len;
    cin >> len;

    string s;
    cin >> s;

    string temp = s;
    reverse(temp.begin(), temp.end());

    int m = s.length(), n = temp.length();
 
    int lookup[m + 1][n + 1];
 
 
    for (int i = 0; i <= m; i++) {
        lookup[i][0] = 0;
    }
 
 
    for (int j = 0; j <= n; j++) {
        lookup[0][j] = 0;
    }
 
 
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == temp[j - 1]) {
                lookup[i][j] = lookup[i - 1][j - 1] + 1;
            } else  {
                lookup[i][j] = max(lookup[i - 1][j], lookup[i][j - 1]);
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i + j == len) {
                res = max(res, lookup[i][j]);
            }
        }
    }
    cout << res << endl;
}
    
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    cout << '\n';
    cout << "Output\n";
#endif
   
    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    cout << endl;
    return 0;
}