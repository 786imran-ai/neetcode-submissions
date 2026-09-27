class Solution {
public:
    vector<vector<int>> result;
    void dfs(int idx, vector<int> &nums, vector<int> &current){
        result.push_back(current);
        for(int i=idx;i<nums.size();i++){
            current.push_back(nums[i]);
            dfs(i+1, nums, current);
            current.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // we ll be using dfs
        vector<int> current;
        dfs(0, nums,current);
        return result;
    }
};
