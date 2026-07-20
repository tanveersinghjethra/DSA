class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        //brute -> convert into 1d then rotate 3times as *(0,n-1),*(0,k-1),*(k,n-1)


        int row=grid.size();
        int col=grid[0].size();

        int n=row*col;
        k=k%n;
        if(k==0){
            return grid;
        }


        auto reverse=[&](int i,int j){
            while(i< j){
                swap(grid[i/col][i%col],grid[j/col][j%col]);
                i++;
                j--;
            }
        };

        reverse(0,n-1);
        reverse(0,k-1);
        reverse(k,n-1);
        return grid;
    }
};