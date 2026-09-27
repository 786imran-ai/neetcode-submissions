class Solution {
public:
    int m, n;
    void dfs(vector<vector<int>>& h,vector<vector<int>> &vis, int i, int j, int prev){
        if(i<0 || j<0|| i>=m|| j>=n|| vis[i][j]==1) return;
        if(h[i][j] < prev) return;
        vis[i][j]=1;
        
        dfs(h,vis, i+1,j,h[i][j]);
        dfs(h,vis,i-1,j,h[i][j]);
        dfs(h,vis,i,j-1,h[i][j]);
        dfs(h,vis,i,j+1,h[i][j]);
    }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m= heights.size();
        n= heights[0].size();
        vector<vector<int>> pac(m, vector<int>(n,0));
        vector<vector<int>> atl(m, vector<int>(n, 0));
        vector<vector<int>> ans;
        for(int i=0;i<m;i++) dfs(heights, pac, i,0,-1);
        for(int j=0;j<n;j++) dfs(heights,pac,0,j,-1);
        for(int i=0;i<m;i++) dfs(heights,atl,i,n-1,-1);
        for(int j=0;j<n;j++) dfs(heights, atl,m-1,j,-1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
 
    }
};
