class Solution {
    vector<int> getCount(string s){
        vector<int> tmp (26,0);
        for(auto ch : s){
            auto i = (int)(ch - 'a');
            tmp[i]++;
        }
        return tmp;
    }
public:
    bool isAnagram(string s, string t) {
       vector<int> sv =  getCount(s);
       vector<int> tv = getCount(t);
       for(int i=0; i<26; i++){
        if(sv[i]!=tv[i]) return false;
       }
       return true;
    }
};
