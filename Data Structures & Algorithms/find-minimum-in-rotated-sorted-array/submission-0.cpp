class Solution {
public:
    int findMin(vector<int> &nums) {
        int n= nums.size();
        int minval=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<minval) minval= nums[i];
        }
        return minval;
    }
};
