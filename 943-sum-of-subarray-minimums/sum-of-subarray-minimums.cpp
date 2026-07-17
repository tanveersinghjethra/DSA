class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // const int MOD = 1e9 + 7;
        // long long ans = 0;
        // int n = arr.size();

        // for (int i = 0; i < n; i++) {
        //     int mini = arr[i];
        //     for (int j = i; j < n; j++) {
        //         mini = min(mini, arr[j]);
        //         ans = (ans + mini) % MOD;
        //     }
        // }

        // return ans;

        //optimal
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> left(n), right(n);
        stack<int> st;

        // Previous Less Element (strictly less)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            if (st.empty())
                left[i] = -1;
            else
                left[i] = st.top();

            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Less Element (less than or equal)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if (st.empty())
                right[i] = n;
            else
                right[i] = st.top();

            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;

            ans = (ans + (1LL * arr[i] * leftCount % MOD) * rightCount) % MOD;
        }

        return ans;
    }
};