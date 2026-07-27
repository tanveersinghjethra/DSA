class Solution {
public:
    int maxProduct(vector<int>& nums) {
       // find first largest and second largest 
       int max1=1,max2=1;
       for(int val:nums){
        if(max1<=val){
            max2=max1;
            max1=val;
        }
        else if(val> max2 && val!=max1){
            max2=val;
        }
       }
       return (max1-1)*(max2-1);
    }
};