class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(prices[i]< prices[j]){
                    int diff= prices[j]-prices[i];
                    ans= max(ans, diff);
                }
            }
        }
        return ans;
    }
};
