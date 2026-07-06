class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //find row index
        int l=0,r=matrix.size()-1;
        auto mid = 0;
        while(l<=r){
            mid = (l+r)/2;
            if(matrix[mid][0]==target) return true;
            if(matrix[mid][0]>target) {r = mid -1; mid = r;}
            else l = mid + 1;
        }
        if(mid < 0) return false;
        l = 0; r = matrix[0].size()-1;
        auto count = 0;
        while(l<=r){
            auto m = (l+r)/2;
            if(matrix[mid][m]==target) return true;
            if(matrix[mid][m]>target) r = m -1;
            else l = m + 1;
        }
        return false;
    }
};
