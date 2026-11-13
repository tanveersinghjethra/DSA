class Solution {
public:
    void dfs(int node,vector<vector<int>> &Adjlist,vector<int> & visted){

        visted[node]=1;
        for(auto it:Adjlist[node]){
            if(!visted[it]){
                dfs(it,Adjlist,visted);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int m=isConnected.size();

        vector<vector<int>>Adjlist(m);

        
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j]==1 && i!=j){
                    Adjlist[i].push_back(j);
                }
            }
        }

        vector<int>visted(m,0);
        int cnt=0;
        for(int i=0;i<m;i++){
            if(visted[i]==0){
                cnt++;
                dfs(i,Adjlist,visted);
            }
        }
        return cnt;
    }
};