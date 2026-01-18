#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

pair<ull, ull> dp[20][2];
bool vis[20][2];

pair<ull, ull> rec(int pos, int tight, const string &s){
    if(pos == (int)s.size()){
        return {1, 0};
    }
    if(vis[pos][tight]) return dp[pos][tight];
    vis[pos][tight] = true;
    ull cnt = 0, sum = 0;
    int limit = tight ? s[pos] - '0' : 9;
    for(int d = 0; d <= limit; d++){
        auto p = rec(pos + 1, tight && (d == limit), s);
        cnt += p.first;
        sum += p.second + (ull)d * p.first;
    }
    return dp[pos][tight] = {cnt, sum};
}

ull solve_upto(long long x){
    if(x < 0) return 0;
    string s = to_string(x);
    memset(vis, false, sizeof(vis));
    return rec(0, 1, s).second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    while(cin >> a >> b){
        if(a == -1 && b == -1) break;
        cout << solve_upto(b) - solve_upto(a - 1) << '\n';
    }
    return 0;
}
