class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n= heights.size();
        int l=0;
        int r= n-1;
        int area=0;
        while(l<r){
            int h= min(heights[l],heights[r]);
             area= max(area,h*(r-l));

            if(heights[l]<heights[r]) l++;
            else r--;
        }
        return area;
    }
};
