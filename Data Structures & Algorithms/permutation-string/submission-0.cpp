class Solution {
    bool comp(vector<int> a, vector<int> b)
    {
        for(int i =0; i<26; i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;
        vector<int> vs1(26,0), vs2(26,0);
        for(auto ch: s1){
            vs1[ch-'a']++;
        }
        for(int i =0; i<s1.size(); i++){
            vs2[s2[i]-'a']++;
        }
        int i =0, j=s1.size()-1;
        for(;j<s2.size();)
        {
            if(comp(vs1, vs2)) return true;
            vs2[s2[i]-'a']--;
            i++; j++;
            if(j<s2.size()) vs2[s2[j]-'a']++;
        }
        return false;
    }
};
