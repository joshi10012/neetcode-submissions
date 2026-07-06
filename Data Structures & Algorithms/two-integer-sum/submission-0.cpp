class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, std::vector<int>> uMap;
        int j = 0;
        for(auto i : nums){
            if(uMap.find(i)!=uMap.end()){
                uMap[i].push_back(j);
            }else{
                uMap[i] = {j};
            }
            j++;
        }
        for(int i = 0; i<nums.size(); i++){
            auto num = target - nums[i];
            if(uMap.find(num)!=uMap.end()){
                for(auto k : uMap[num]){
                    if(k>i){
                        return {i,k};
                    }
                }
            }
        }
        return {};
    }
};
