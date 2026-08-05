class Solution {
public:
    int mySqrt(int x) {
        int lb = 1;
        int ub = x;
        int mid;
        int ans = 0;
        while(lb <= ub){
            int mid = lb + (ub - lb)/2;
            if(mid <= x/mid){
                ans = mid;
                lb = mid+1;
            }
            else if (mid > x/mid){
                ub = mid-1;
            }
        }
        return ans;

    }
};