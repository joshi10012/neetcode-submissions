class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
            int mul = 1;
            //signle 0 in array. => other than index having 0 has value 0
            //more than one 0 in array. => all values are 0
            int zcount = 0;
            int zindex = 0;
            auto index = 0;
            for(auto num:nums){
                if(num==0){
                    zcount++;
                    zindex = index;
                    continue;
                }
                mul*=num;
                index++;
            }
            vector<int> ret (nums.size(),0);
            if (zcount>1) return ret;
            if(zcount == 1){
                ret[zindex] = mul;
                return ret;
            }
            for(auto i=0; i<nums.size(); i++)
            {
                ret[i] = mul/nums[i];
            }
            return ret;
    }
};
