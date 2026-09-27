class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size()>1){
            sort(stones.begin(), stones.end());
            int n= stones.size();
            int y= stones[n-1];
            int x= stones[n-2];
            stones.pop_back();  // pop y
            stones.pop_back(); // pop x
            if(y!=x) stones.push_back(y-x);

        }
        return stones.empty()? 0: stones[0];
    }
};
