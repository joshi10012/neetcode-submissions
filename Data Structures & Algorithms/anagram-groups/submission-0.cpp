class Solution {
    vector<int> transformStr(string s){
        vector<int> tmp(26,0);
        for(auto ch : s){
            auto i = (int)(ch - 'a');
            tmp[i]++;
        }
        return tmp;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<vector<int>, vector<int>> mp;
        for(int i=0; i<strs.size(); i++){
            auto s = transformStr(strs[i]);
            if(mp.find(s)!=mp.end()){
                //std::cout<<strs[i]<<std::endl;
                mp[s].push_back(i);
            }else{
                //std::cout<<strs[i]<<std::endl;
                mp[s]={i};
            }
        }
        vector<vector<string>> ret;
        for(auto mpair : mp){
            ret.push_back({});
            for(auto j : mpair.second){
                ret[ret.size()-1].push_back(strs[j]);
            }
        }
        return ret;
    }
};
