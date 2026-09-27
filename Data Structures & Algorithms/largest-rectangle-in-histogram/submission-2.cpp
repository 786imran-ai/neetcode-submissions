class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        int area=0;
        for(int i=0;i<n;i++){
            int h= heights[i];
            int left=i, right=i;
            while(left>0 && heights[left-1]>=h) left--;
            while(right<n-1 && heights[right+1]>=h) right++;
            int width= right-left+1;
            area= max(area, h*width);
        }
        return area;
    }
};
