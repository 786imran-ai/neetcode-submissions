class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> maxheap;
        for(auto &p: points){
            int dist= p[0]*p[0]+ p[1]*p[1];
            maxheap.push({dist, {p[0],p[1]}});

            if(maxheap.size()>k) maxheap.pop();
        }
        vector<vector<int>> result;
        while(!maxheap.empty()){
            auto top= maxheap.top();
            maxheap.pop();
            result.push_back({top.second.first, top.second.second});
        }
        return result;
    }
};
