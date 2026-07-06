class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j=heights.size()-1;
        int maxH = 0;
        while(i<j){
            int minH = min(heights[i],heights[j]);
            maxH = max(maxH, (j-i)*minH);
            if(minH == heights[i]){i++; continue;}
            j--;
        }
        return maxH;
    }
};
