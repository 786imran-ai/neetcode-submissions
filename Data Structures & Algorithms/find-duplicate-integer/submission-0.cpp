class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int count=1;
        sort(nums.begin(), nums.end());
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(i>0 &&nums[i]==nums[i-1]){
                count++;
            }
            if(count>=2) return nums[i];
        }
        return 1;
    }
};
