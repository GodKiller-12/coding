class Solution {
public:
int dp[101][101];
int rec(int i , int j , vector<int>& cuts){
   if(i>j){
    return 0;
   }
   if(dp[i][j]!=-1){
    return dp[i][j];
   }
   int ans = INT_MAX;
   for(int k = i ;k<=j;k++){
    ans = min(ans , cuts[j+1]-cuts[i-1] + rec(i,k-1,cuts) + rec(k+1,j,cuts));
   }
   return dp[i][j] = ans ;
}

int minCost(int n, vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(),cuts.end());
    memset(dp,-1,sizeof(dp));
    int N = cuts.size();
    return rec(1,N-2, cuts);
    
}
};
