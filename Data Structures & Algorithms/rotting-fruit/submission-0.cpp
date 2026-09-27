class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r= grid.size();
        int c= grid[0].size();
        queue<pair<int,int>> que;
        int fresh=0,time=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2) que.push({i,j});
            }
        }
        // direction ke liye simple array
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        // bfs
        while(!que.empty() && fresh>0){
            int size=que.size();
            while(size--){
                int x= que.front().first;
                int y= que.front().second;
                que.pop();

                for(int k=0;k<4;k++){
                    int newx= x+dx[k];
                    int newy= y+dy[k];

                    if(newx>=0 && newy>=0 && newx<r && newy<c  && grid[newx][newy]==1){
                        grid[newx][newy]=2;
                        fresh--;
                        que.push({newx,newy});
                    }
                }
                
            }

            time++;
        }
        return fresh==0? time:-1;

    }
};
