class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_vol=0;
        for(int i = 0; i < height.size();i++){
            for(int j = height.size()-1; j>0;j--){
                int width = j-i;
                int max_height = min(height[i],height[j]);
                int area = max_height * width;
                if(area > max_vol){
                    max_vol = area;
                }
            }
        }
        return max_vol;
    }
};
