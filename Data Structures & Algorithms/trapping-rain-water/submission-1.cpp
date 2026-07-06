class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;
        vector<int> fwd(height.size(),0);
        for(int i=1; i<height.size(); i++){
            fwd[i] = (height[i-1] + fwd[i-1]) - height[i];
            fwd[i] = fwd[i]>=0?fwd[i]:0;
        }
        //int sum = 0;
        vector<int> bwd (height.size(), 0);
        for(int i = height.size()-2; i>=0; i--){
            bwd[i] = height[i+1] + bwd[i+1] - height[i];
            //cout<< i << " " << bwd[i] <<endl;
            bwd[i] = bwd[i]>=0?bwd[i]:0;
        }
        //auto sum =0;
        for(int i =0; i<height.size(); i++)
        {
            cout<<fwd[i]<<" "<<bwd[i]<<endl;
            total +=min(fwd[i], bwd[i]);
        }
        return total;
    }
};
