class Solution {
public:
int dp[105][105];
// int rec(int i , int j , vector<int>& cuts){
  
// }

int minCost(int n, vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(),cuts.end());
    int N = cuts.size();
    // return rec(1,N-2, cuts);
    for(int i  = N-2;i>=1;i--){
        for(int j = 1;j<=N-2;j++){
 if(i>j){
    dp[i][j]= 0;
    continue ;
   }
  
   int ans = INT_MAX;
   for(int k = i ;k<=j;k++){
    ans = min(ans , cuts[j+1]-cuts[i-1] +dp[i][k-1] + dp[k+1][j]);
   }
    dp[i][j] = ans ;
        }
    }

    return dp[1][N-2];

}
};
