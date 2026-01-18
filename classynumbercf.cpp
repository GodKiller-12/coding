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
int MOD = 1e9+7;

#define INF 1e18

int dp[20][2][5];

int rec(int pos , int tight,int count , string &s){
    if(pos == s.size()){
        return 1;
    }
    int ans = 0;
    if(dp[pos][tight][count]!=-1) return dp[pos][tight][count];
    if(count == 3){
        int nextight = tight && (s[pos]=='0');
        ans = rec(pos+1,nextight,3,s);
        return dp[pos][tight][count] = ans;
    }
    int limit = tight ? s[pos]-'0': 9 ;
    for(int d = 0;d<=limit;d++){
        int nextight = tight && (d==limit);
        int nextcount = count + (d!=0);
        ans = ans + rec(pos+1,nextight,nextcount,s);
    }
    return dp[pos][tight][count] = ans;
}


void solve(){
    int a , b;
    cin>>a>>b;
string s1,s2;
s1 = to_string(a-1);
s2 = to_string(b);
memset(dp,-1,sizeof(dp));
int ans1 = rec(0,1,0,s1);
memset(dp,-1,sizeof(dp));
int ans2 = rec(0,1,0,s2);

cout<<ans2-ans1<<endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t=1;
    cin>>t;
    while (t--) solve();
}
 
// Golden Rules
/*
    Solutions are simple.
 
    Proofs are simple.
 
    Implementations are simple.
*/
