class Solution {
public:
int k ;
int dp[501];
    int rec(int level, vector<int>& a) {
        int n = a.size();
     if(level==n){
        return 0;
     }
     if(dp[level]!=-1){
        return dp[level];
     }
     int ans = INT_MIN ;
     int maxi = INT_MIN ;
     for(int i = level ;i<min(level+k,n);i++){
        maxi = max(maxi,a[i]);
        ans = max(ans,maxi *(i + 1 - level) + rec(i+1,a));
     }

     return dp[level] = max(ans,dp[level]) ;
    }

    int maxSumAfterPartitioning(vector<int>& a, int tar) {
        k = tar;
        int n = a.size();
        memset(dp,-1,sizeof(dp));
      return rec(0,a);
    }
};
