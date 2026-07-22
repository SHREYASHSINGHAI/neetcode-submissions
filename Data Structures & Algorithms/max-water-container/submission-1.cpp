class Solution {
public:
    int maxArea(vector<int>& heights) {
        int right = heights.size()-1;
        int left = 0;
        int max_vol = 0;
        while(right>left){
            int width = right - left;
            int h = min(heights[left], heights[right]);
            int area = width * h;

            max_vol = max(max_vol, area);

            if(heights[left]< heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return max_vol;
    }
};
