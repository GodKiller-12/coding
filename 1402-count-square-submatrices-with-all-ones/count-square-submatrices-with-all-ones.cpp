class Solution {
public:
int dp[301][301];
    int countSquares(vector<vector<int>>&a) {
        int m = a.size();
        int n = a[0].size();
        int sum = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(a[i][j]==1){
                    if(i==0 || j==0){
                        dp[i][j] = 1;
                    }
                    else{
                    dp[i][j] = min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]}) + 1 ;
                    }
                }
                sum += dp[i][j];
            }
        }
        return sum ;
    }
};