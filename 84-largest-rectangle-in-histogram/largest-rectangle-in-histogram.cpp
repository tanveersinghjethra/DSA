class Solution {
public:

    vector<int> previousSmaller(vector<int>& heights){
        int n=heights.size();
        stack<int> st;
        vector<int> left(n);

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();

            left[i]=st.empty()?-1:st.top();
            st.push(i);
        }

        return left;
    }

    vector<int> nextSmaller(vector<int>& heights){
        int n=heights.size();
        stack<int> st;
        vector<int> right(n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();

            right[i]=st.empty()?n:st.top();
            st.push(i);
        }

        return right;
    }

    int largestRectangleArea(vector<int>& heights) {

        vector<int> left=previousSmaller(heights);
        vector<int> right=nextSmaller(heights);

        int ans=0;

        for(int i=0;i<heights.size();i++){
            int width=right[i]-left[i]-1;
            ans=max(ans,width*heights[i]);
        }

        return ans;
    }
};