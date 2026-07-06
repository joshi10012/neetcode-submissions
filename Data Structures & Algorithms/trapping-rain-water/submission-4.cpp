class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;
        vector<int> fwd(height.size(),0);
        int fmax = height[0];
        for(int i=1; i<height.size(); i++){
            fwd[i] = fmax - height[i];
            if(fwd[i]<0){
                fmax = height[i];
                fwd[i] = 0;
            }
        }

        int bmax = height[height.size()-1];
        int bwd = 0;
        for(int i = height.size()-2; i>=0; i--){
            bwd = bmax - height[i];
            if(bwd<0){
                bmax = height[i];
                bwd = 0;
            }
            total+=min(fwd[i],bwd);
        }
        return total;
    }
};
