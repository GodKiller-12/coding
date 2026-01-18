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

#define INF 1e18

int dp[200005];

int n ;

vector<vector<int>>adj;

int dia = 0;

void dfs(int node , int parent){
    int max1 = 0,max2 = 0;
    for(auto child :adj[node]){
    if(child == parent) continue ;
    dfs(child, node);
    int depth = dp[child];
    if(depth > max1){
        max2 = max1 ;
        max1 = depth ;
    }
    else if(depth > max2){
        max2 = depth ;
    }
    
    dia = max(dia , max1 + max2);
    }
    dp[node] = max1 +1;
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


cout<<dia<<endl;

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
