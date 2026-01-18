#include<bits/stdc++.h>
using namespace std;
#define int long long

int MOD = 1e9+7;

int dp[100005][2][105];

int rec(int pos, int tight, int mod, string &s, int D){
    if(pos == s.size()){
        return (mod == 0);
    }

    int &ans = dp[pos][tight][mod];
    if(ans != -1) return ans;

    ans = 0;
    int limit = tight ? s[pos]-'0' : 9;

    for(int d = 0; d <= limit; d++){
        int ntight = tight && (d == limit);
        int nmod = (mod + d) % D;
        ans = (ans + rec(pos+1, ntight, nmod, s, D)) % MOD;
    }

    return ans;
}

void solve(){
    string k;
    int d;
    cin >> k >> d;

    memset(dp, -1, sizeof(dp));
    int res = rec(0, 1, 0, k, d);

    cout << (res - 1 + MOD) % MOD;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
