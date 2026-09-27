class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> result;
        unordered_map<int , int>   mp;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<pair<int, int>> freq;
        for(auto &it : mp){
            freq.push_back({it.second, it.first});
        }
        sort(freq.rbegin(),freq.rend());
        for(int i=0;i<k;i++){
            result.push_back(freq[i].second);
        }
        return result;

    }
};
