class Solution {
public:
int dp[305][305];
    // int rec(int i , int j , vector<int>&a){
    //     int n = a.size();
    //     if(i>j) return 0;
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }

    // }
    int maxCoins(vector<int>&arr) {
        int n = arr.size();
        vector<int>a ;
        memset(dp,-1,sizeof(dp));
        a.push_back(1);
        for(int i = 0;i<n;i++){
            a.push_back(arr[i]);
        }
        a.push_back(1);
    //   return rec(1,n,a);  


    for(int i = n;i>=1;i--){
        for(int j = 1;j<=n;j++){
           if(i>j){
            dp[i][j] = 0; 
           }
           else{
  int ans = INT_MIN;
        for (int k = i; k <= j; k++) {
            int left = (k > i) ? dp[i][k - 1] : 0;
            int right = (k < j) ? dp[k + 1][j] : 0;
            ans = max(ans, a[i - 1] * a[k] * a[j + 1] + left + right);
        }
        dp[i][j] = ans;
           }
        }
    }



return dp[1][n];

    }
};