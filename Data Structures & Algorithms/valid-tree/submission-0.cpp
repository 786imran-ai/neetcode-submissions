class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        vector<vector<int>> graph(n);
        vector<int> visited(n,0);
        for(auto &e: edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);

        }
        int count=1;
        queue<int> q;
        q.push(0);
        visited[0]=1;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            for(auto nie: graph[node]){
                if(!visited[nie]){
                    visited[nie]=1;
                    count++;
                    q.push(nie);
                }
            }
        }
        return n==count;
    }
};
