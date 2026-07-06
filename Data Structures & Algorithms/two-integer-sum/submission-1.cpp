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
            auto num = target - nums[j];
            if(uMap.find(num)!=uMap.end() && uMap[num][0]!=j){
                return {uMap[num][0], j};
            }
            j++;
        }
        return {};
    }
};
