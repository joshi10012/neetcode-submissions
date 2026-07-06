class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::map<int, bool> mp;
        for(auto i : nums){
            if(mp.find(i)==mp.end())
            {
                mp[i]=true;
                continue;
            }
            return true;
        }
        return false;
    }
};