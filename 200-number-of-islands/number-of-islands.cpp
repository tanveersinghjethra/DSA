class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &visted,vector<vector<char>>& grid,int n,int m){
        if(i<0||j<0||i>=n||j>=m||visted[i][j]==1||grid[i][j]!='1'){
            return;
        }

        visted[i][j]=1;

        dfs(i-1,j,visted,grid,n,m);
        dfs(i+1,j,visted,grid,n,m);
        dfs(i,j-1,visted,grid,n,m);
        dfs(i,j+1,visted,grid,n,m);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();//row
        int m=grid[0].size();//col

        //this will create a m x n visted matrix 
        vector<vector<int>> visted(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visted[i][j]==0){
                    dfs(i,j,visted,grid,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};