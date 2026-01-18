#include<bits/stdc++.h>
using namespace std;
#define int long long

// Problem Statement
/*
*/
// Small Observatins
/* 
 transition is that distance to all the child will increase by 
 
 
 maan lo mere ko root ka answer pata hai 
 
 so i think it will be a top down approach 
 
 
 dp[child] = dp[parent]  - (1 + no of childrens of child) + (n-((1 + no of childrens of child))) ;
 
 so i need two dp one for children 
 and one for storing distance 
 
*/
 
 
// Claims on algo 
/*  
    
 
*/

int MOD = 1e9 + 7;


#define INF 1e18

int n ;
int dp[200005];
int ans[200005];

vector<vector<int>>adj;

void dfs2(int node , int parent){
    for(auto i :adj[node]){
        if(i == parent) continue ;

        ans[i] = ans[node] - (1 + dp[i]) + (n - (1 + dp[i]));
                // cout<<i<<" "<<dp[i]<<" "<<ans[i];
        dfs2(i,node);
    }
}
int fuck = 0;

int dfs(int node , int parent){
    if(adj[node].size()==1 && node!=1){
        dp[node] = 0;
        return 1;
    }
    int ans = 0;
    for(auto i :adj[node]){
        if(i==parent) continue;
        ans += dfs(i,node);
    }
    dp[node] = ans ;
    fuck += ans ;
    return 1 + ans ;
}


void solve(){
cin>>n;
adj.resize(n+1);
adj.clear();

for(int i  = 0;i<n-1;i++){
    int a , b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
}
dfs(1,-1);
ans[1] = fuck ;
dfs2(1,-1);
// for(int i = 1;i<=n;i++){
//     cout<<dp[i]<<" ";
// }
// cout<<endl;

for(int i = 1;i<=n;i++){
    cout<<ans[i]<<" ";
}

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
