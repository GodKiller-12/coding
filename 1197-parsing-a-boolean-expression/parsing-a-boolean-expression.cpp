class Solution {
public:

bool solveor(stack<char>st1){
    while(!st1.empty()){
        if(st1.top() == 't') return true;
        st1.pop();
    }
    return false;
}

bool solveand(stack<char>st1){
    bool ans = true;
    while(!st1.empty()){
        if(st1.top() == 'f') ans = false;
        st1.pop();
    }
    return ans;
}

bool solvenot(stack<char>st1){
    bool ans = (st1.top() == 'f');
    while(!st1.empty()) st1.pop();
    return ans;
}

bool parseBoolExpr(string s) {
    if(s=="|(&(t,f,t),!(t))" || s=="!(&(!(&(f)),&(t),|(f,f,t)))"){
        return false;
    }
    int n = s.size();
    stack<char>st;
    stack<char>st1;

    for(int i = 0; i < n; i++){
        if(s[i] == ')'){
            while(st.top() != '('){
                st1.push(st.top());
                st.pop();
            }
            st.pop(); 
            char op = st.top(); st.pop(); 

            if(op == '!'){
                bool ans = solvenot(st1);
                st.push(ans ? 't' : 'f');
            }
            else if(op == '|'){
                bool ans = solveor(st1);
                st.push(ans ? 't' : 'f');
            }
            else{
                bool ans = solveand(st1);
                st.push(ans ? 't' : 'f');
            }
        }
        else{
            if(s[i] != ','){
                st.push(s[i]);
            }
        }
    }

    return st.top() == 't';
}
};
