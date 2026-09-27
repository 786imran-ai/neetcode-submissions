class Solution {
public:
    int m, n;
    void dfs(vector<vector<int>>& grid, int i, int j, int idx){
        if(i<0 || j<0 || i>=m||j>=n|| grid[i][j] <idx) return;
        grid[i][j]= idx;
        dfs(grid,i+1,j,idx+1);
        dfs(grid,i-1,j,idx+1);
        dfs(grid,i,j+1,idx+1);
        dfs(grid,i,j-1,idx+1);
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        m= grid.size();
        n= grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    dfs(grid, i, j, 0);
                }
            }
        }       
    }
};
