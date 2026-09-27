class Solution {
public:
    vector<vector<int>> result;
    void dfs(int idx, vector<int>& nums, int target,vector<int> &curr){
        if(target==0) {
            result.push_back(curr);
            return;
        }
        if(target<0 || idx== nums.size()) return;

        curr.push_back(nums[idx]);
        dfs(idx, nums, target-nums[idx],curr);
        curr.pop_back();

        dfs(idx+1, nums, target, curr);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        // going to use dfs
        vector<int> curr;
        dfs(0, nums, target,curr);
        return result;
    }
};
