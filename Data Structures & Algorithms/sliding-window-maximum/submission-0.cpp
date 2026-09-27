class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n= nums.size();
        for(int i=0;i<=n-k;i++){
            int maxel=INT_MIN;
            for(int j=i;j<k+i;j++){
                maxel= max(maxel, nums[j]); 
            }
            ans.push_back(maxel);
        }
        return ans;
    }
};
