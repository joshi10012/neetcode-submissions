class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        std::unordered_map<int, pair<int,bool>> umap;
        for(auto i=0; i<nums.size(); i++){
            umap[nums[i]]={i,false};
        }
        int max_count = 0;
        for(int i =0; i<nums.size(); i++)
        {            
            if(umap.find(nums[i] - 1) != umap.end()) continue;
            if(umap[nums[i]].second == true) continue;
            
            auto local_count = 0;
            auto next = nums[i];
            while(umap.find(next) != umap.end() && umap[next].second != true)
            {
                umap[next].second = true;
                local_count +=1;
                next=next+1;
            }
            max_count = max(max_count, local_count);
        }
        return max_count;
    }
};