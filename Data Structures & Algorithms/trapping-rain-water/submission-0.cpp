class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        int water=0;
        for(int i=0;i<n;i++){
            int leftmax=0;
            for(int l=0;l<=i;l++){
                leftmax= max(leftmax, height[l]);
            }
            int rightmax=0;
            for(int r=i;r<n;r++){
                rightmax= max(rightmax, height[r]);
            }
            water+= min(leftmax, rightmax)- height[i];
        }
        return water;
    }
};
