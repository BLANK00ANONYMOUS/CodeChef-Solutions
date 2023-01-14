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
    int n;
    cin >> n;
    
    int a[2 * n];
    for (int i = 0; i < 2 * n; ++i) cin >> a[i];

    int ans = 0;
    int fc = n - 1;
    int ext = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] > n) {
            ans++;
            ext += fc - i;
            fc--;
        }
    }

    int bc = n;
    for (int i = n; i < 2 * n; ++i) {
        if (a[i] <= n) {
            ext += i - bc;
            bc++;
        }
    }
    
    cout << ans * ans + ext << endl;
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