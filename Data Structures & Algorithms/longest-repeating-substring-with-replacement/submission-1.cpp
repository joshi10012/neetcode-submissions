class Solution {
    //checking the total - maxFreq <= k
    bool check(vector<int>& vec, int k){
        int maxv = 0, total = 0;
        for(auto v: vec){
            maxv = max(maxv, v);
            total+=v;
        }
        if((total-maxv)<=k) return true;
        return false;
    }
public:
    int characterReplacement(string s, int k) {
        if(s.size()<=k) return s.size();
        vector<int> vec(26,0);
        for(int i =0; i<=k; i++){
            vec[s[i]-'A']+=1;
        }
        int i = 0, j=k;
        int count = 0;
        for(;j<s.size();){
            if(check(vec, k)==false){
                //freq is not within k then shorten the window. 
                vec[s[i]-'A']--;
                i++;
            }
            else
            {
                //expand the window.
                count = max(count,j-i+1);
                j++;
                if(j<s.size()) vec[s[j]-'A']++;
            }
        }
        return count;
    }
};
