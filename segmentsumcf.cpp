#include<bits/stdc++.h>
using namespace std;
#define int long long

// Problem Statement
/*

*/
 
// Small Observatins
/* 
*/
 
// Claims on algo 
/*  
    
 
*/
int MOD = 998244353;
#define INF 1e18

pair<int,int> dp[20][2][1<<11][11];
bool vis[20][2][1<<11][12];
int p10[20];

pair<int,int> rec(int pos , int tight, int b , int count , string &s,int k ){
    if(pos == s.size()){
        return {1,0};
    }
    if(vis[pos][tight][b][count]) return dp[pos][tight][b][count];
    vis[pos][tight][b][count] = true;

    int ans = 0;
    int cnt = 0;
    int limit = tight ? s[pos]-'0': 9 ;

    for(int d = 0; d <= limit; d++){
        int nextcount = count;
        int nextb = b;

        if(((1<<d)&(b))!=(1<<d)){
            if(count < k){
                nextb |= (1<<d);
                nextcount++;
            }else{
                continue;
            }
        }

        int nextight = tight && (d == limit);
        pair<int,int> p = rec(pos+1, nextight, nextb, nextcount, s, k);

        int cur = (d * p10[s.size() - pos - 1]) % MOD;

        cnt = (cnt + p.first) % MOD;
        ans = (ans + p.second + (cur * (p.first % MOD)) % MOD) % MOD;
    }

    return dp[pos][tight][b][count] = {cnt, ans};
}


int sumDigits(int x,int k){
    if(x < 0) return 0;
    string s = to_string(x);
    memset(vis, false, sizeof(vis));
    return rec(0, 1,0,0, s,k).second;
}

void solve(){
    int a , b,k;
    cin >> a >> b>>k;

    int ans = (sumDigits(b,k) - sumDigits(a-1,k)+MOD)%MOD;
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 p10[0] = 1;
    for(int i = 1; i < 20; i++) p10[i] = (p10[i-1] * 10) % MOD;
    int t=1;
    while (t--) solve();
}
 
// Golden Rules
/*
    Solutions are simple.
 
    Proofs are simple.
 
    Implementations are simple.
*/
