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

#define INF 1e18

int dp[50005][505];

int n , k ;

vector<vector<int>>adj;

int ans = 0;

void dfs(int node , int parent){
    dp[node][0] = 1;
    
    for(auto child :adj[node]){
    if(child == parent) continue ;
    dfs(child, node);
    
    for(int i = 0;i<k;i++){
        ans += 1ll*dp[node][k-i-1] * dp[child][i] ;
    }
    
    for(int i = 0;i<k;i++){
        dp[node][i+1] += dp[child][i];
    }
    
    }
}
void solve(){
cin>>n >>k ;
adj.resize(n+1);
for(int i  = 0;i<n-1;i++){
    int a , b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    
}
dfs(1,0);
cout<<ans<<endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1;
    while (t--) solve();
}
 
// Golden Rules
/*
    Solutions are simple.
 
    Proofs are simple.
 
    Implementations are simple.
*/
