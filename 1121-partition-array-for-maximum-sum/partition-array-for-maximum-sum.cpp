class Solution {
public:
int k ;
int dp[501];
    // int rec(int level, vector<int>& a) {
    //     int n = a.size();
   
    // }

    int maxSumAfterPartitioning(vector<int>& a, int tar) {
        k = tar;
        int n = a.size();
    //     memset(dp,-1,sizeof(dp));
    //   return rec(0,a);
    for(int level = n ;level>=0;level--){
  if(level==n){
        dp[level] =  0;
     }else{
     int ans = INT_MIN ;
     int maxi = INT_MIN ;
     for(int i = level ;i<min(level+k,n);i++){
        maxi = max(maxi,a[i]);
        ans = max(ans,maxi *(i + 1 - level) + dp[i+1]);
     }
     dp[level] = max(ans,dp[level]) ;

     }
    }
    return dp[0];
    }
};
