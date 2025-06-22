class Solution {
public:
int dp[301][301];
    int rec(int i , int j , vector<int>&a){
        int n = a.size();
        if(i>j) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
int ans = INT_MIN;
for(int k = i;k<=j;k++){
    ans = max(ans,a[i-1]*a[k]*a[j+1] + rec(i,k-1,a) + rec(k+1,j,a));
}
return dp[i][j] = ans ;
    }
    int maxCoins(vector<int>&arr) {
        int n = arr.size();
        vector<int>a ;
        memset(dp,-1,sizeof(dp));
        a.push_back(1);
        for(int i = 0;i<n;i++){
            a.push_back(arr[i]);
        }
        a.push_back(1);
      return rec(1,n,a);  
    }
};