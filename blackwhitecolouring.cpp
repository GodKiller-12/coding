#include<bits/stdc++.h>
using namespace std;
#define int long long

// Problem Statement
/*
*/
// Small Observatins
/* 
 now first we are performing the count operation before merging because it will count the pairs which are passing from the same sub child thus making subchild the lca and 
 decreasing the answer 
 
 and also even if one of them is not calculated once it will surely be calculated
 
 we are just counting that at i distance from node i downside not any other dirn  how many nodes exist so that will result 
 
 
//   considering the current node as lca and calculating the answer is also pretty nice 
*/
 
 
// Claims on algo 
/*  
    
 
*/

int MOD = 1e9 + 7;


#define INF 1e18

int dp[200005][2];
int n ;
vector<vector<int>>adj;

int ans = 0;

void dfs(int node , int parent){
//   dp[node][1] = node has been taken 
//   dp[node][0] = node has not been taken 

dp[node][0] = 1;
dp[node][1] = 1;

for(auto child : adj[node]){
    if(child == parent ) continue ;
    dfs(child, node);
    dp[node][0] = (dp[node][0] * (dp[child][0] + dp[child][1]) % MOD) % MOD;
dp[node][1] = (dp[node][1] * dp[child][0]) % MOD;

}


}

void solve(){
  
cin>>n ;
adj.resize(n+1);

for(int i  = 0;i<n-1;i++){
    int a , b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    
}

dfs(1,0);
cout<<((dp[1][0]+dp[1][1]))%MOD<<endl;

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
