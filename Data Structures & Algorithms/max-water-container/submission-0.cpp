class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n= heights.size();
        int area=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int prod = min(heights[i], heights[j]) * (j - i);
                area= max(area,prod);

            }
        }
        return area;
    }
};
