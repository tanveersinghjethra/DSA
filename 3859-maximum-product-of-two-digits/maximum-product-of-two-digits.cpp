class Solution {
public:
    int maxProduct(int n) {
        vector<int>arr;
        while(n>0){
            int lastd=n%10;
            n=n/10;
            arr.push_back(lastd);
        }

        int maxi=0;
        int x=arr.size();
        for(int i=0;i<x;i++){
            for(int j=i+1;j<x;j++){
                int mul=arr[i]*arr[j];
                maxi=max(maxi,mul);
            }
        }
        return maxi;
    }
};