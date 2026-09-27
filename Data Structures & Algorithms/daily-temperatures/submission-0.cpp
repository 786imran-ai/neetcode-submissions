class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> res;
        for(int i=0;i<n-1;i++){
            int maxel=INT_MIN;
            for(int j=i+1;j<n;j++){
                if(temperatures[i]< temperatures[j]){
                    maxel=j;
                    res.push_back(maxel-i);
                    break;
                }
            }
            if(maxel==INT_MIN) res.push_back(0);
        }
        res.push_back(0);
        return res;
    }
};
