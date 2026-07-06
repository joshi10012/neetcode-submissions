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

        vector<int> bwd (height.size(), 0);
        int bmax = height[height.size()-1];
        for(int i = height.size()-2; i>=0; i--){
            bwd[i] = bmax - height[i];
            if(bwd[i]<0){
                bmax = height[i];
                bwd[i] = 0;
            }
            total+=min(fwd[i],bwd[i]);
        }
        return total;
    }
};
