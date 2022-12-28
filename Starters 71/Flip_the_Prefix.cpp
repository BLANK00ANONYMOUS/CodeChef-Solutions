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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int res = n;
    int seg = 1;

    for (int i = 1; i < k; ++i) {
        seg += s[i] != s[i - 1];
    }

    if (s[k - 1] == '1') res = seg - 1;
    else res = seg;

    for (int i = k; i < n; ++i) {
        seg += s[i] != s[i - 1];
        seg -= s[i - k] != s[i - k + 1];
        if (s[i] == '1') res = min(res, seg - 1);
        else res = min(res, seg);
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