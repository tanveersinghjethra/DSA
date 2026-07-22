class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n=num.size();
        string res="";
        for(int i=0;i<n;i++){
            while(!st.empty()&& k>0 &&  (st.top()-'0') >(num[i]-'0') ){
                st.pop();
                k--;
            }
            st.push(num[i]);

            if(st.size() == 1 && num[i] == '0') st.pop();
        }
        while(k && !st.empty()){
            k--;
            st.pop();
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        if(res.length()==0) return "0";
        return res;
    }
};