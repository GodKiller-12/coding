class Solution {
public:


map<pair<int,int>,int> mp;

int rec(int i , int j , vector<int>& cuts){
    if((j-i)==1) return 0;
    bool found = false;
    for(int k = 0; k < cuts.size(); k++){
        if(cuts[k] > i && cuts[k] < j){
            found = true;
            break;
        }
    }
    if(!found){
        return 0;
    }

    if(mp.count({i,j})) return mp[{i,j}];

    int ans = INT_MAX;
    for(int k = 0; k < cuts.size(); k++){
        if(cuts[k] > i && cuts[k] < j){
            ans = min(ans, (j - i) + rec(i, cuts[k], cuts) + rec(cuts[k], j, cuts));
        }
        
    }

    return mp[{i,j}] = ans;
}

int minCost(int n, vector<int>& cuts) {
    sort(cuts.begin(),cuts.end());
    return rec(0, n, cuts);
}
};
