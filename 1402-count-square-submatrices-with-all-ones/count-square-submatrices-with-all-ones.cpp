class Solution {
public:
    int countSquares(vector<vector<int>>&a) {
        int m = a.size();
        int n = a[0].size();
        int sum = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(a[i][j]==1){
                    if(i==0 || j==0){
                        // dp[i][j] = 1;
                    }
                    else{
                    a[i][j] = min({a[i-1][j],a[i-1][j-1],a[i][j-1]}) + 1 ;
                    }
                }
                sum += a[i][j];
            }
        }
        return sum ;
    }
};