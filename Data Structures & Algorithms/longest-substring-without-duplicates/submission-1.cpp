class Solution {

public:
    int lengthOfLongestSubstring(string s) {
        set<char> tracker;
        int i = 0, count = 0; 
        for(int j = 0; j<s.size(); j++){
            if(tracker.find(s[j])!=tracker.end()){
                while(s[i]!=s[j]){
                    tracker.erase(s[i]);
                    i++;
                }
                i++;
            }
            count = max(count,j-i+1);
            tracker.insert(s[j]);
        }
        return count;
    }
};
