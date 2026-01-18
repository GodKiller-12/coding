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

int dp[20][2][11];

int rec(int pos , int tight , int prev , string &s){
    if(pos == s.size()){
        return 1;
    }
    int ans = 0;
    if(dp[pos][tight][prev]!=-1) return dp[pos][tight][prev];
    int limit = tight ? s[pos]-'0': 9 ;
    for(int d = 0;d<=limit;d++){
        int nextight = tight && (d==limit);
        if(d==prev) continue;
        int next = (d==0 && prev == 10) ? 10 : d;
        ans += rec(pos+1,nextight,next,s);
    }
    return dp[pos][tight][prev] = ans ;
}


void solve(){
  
 int a , b;
 cin>>a>>b;
 
 string s1 = to_string(a-1);
 string s2 = to_string(b);
 
 memset(dp,-1,sizeof(dp));
 
 int num2 = rec(0,1,10,s2);
 memset(dp,-1,sizeof(dp));
 int num1 = rec(0,1,10,s1);
  
  cout<<num2-num1<<endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t=1;
    while (t--) solve();
}
 
// Golden Rules
/*
    Solutions are simple.
 
    Proofs are simple.
 
    Implementations are simple.
*/
