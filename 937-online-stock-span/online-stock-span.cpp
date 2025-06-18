class StockSpanner {
public:
 stack<pair<int,int>>st;
   int ind;
    StockSpanner() {
    ind = -1;
     while (!st.empty()) st.pop();
    }
   
    int next(int val) {
        ind = ind + 1;
        while(!st.empty() && st.top().first<=val){
            st.pop();
        }
        if(st.empty()){
            st.push({val,ind});
            return ind+1;
        }
        else{
           int ans = ind - st.top().second ;
           st.push({val,ind});
           return ans ;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */