class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> visited(n,0);
        for(auto &e: edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                queue<int> q;
                q.push(i);
                visited[i]=1;
                while(!q.empty()){
                    int node= q.front();
                    q.pop();
                    for(auto nie: graph[node]){
                        if(!visited[nie]){
                            visited[nie]=1;
                            q.push(nie);
                        }
                    }
                }
            }
        }
        return count;
    }
};
