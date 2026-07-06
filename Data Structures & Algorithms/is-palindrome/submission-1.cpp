class Solution {
    bool IsAlphaNumeric(char ch){
        auto capL = ch>='A'&& ch<='Z'? true:false;
        auto smallL = ch>='a'&& ch<='z'? true:false;
        auto num = ch>='0' && ch <='9'?true :false;
        return capL || smallL || num;
    }
public:
    bool isPalindrome(string s) {
        if(s.size()==0)return true;
        int i=0, j=s.size()-1;
        while(i<=j){
            auto a = s[i], b = s[j];
            if(!IsAlphaNumeric(a)){i++; continue;}
            if(!IsAlphaNumeric(b)){j--; continue;}
            if (a>='A' && a<='Z'){ a = a -'A' + 'a';}
            if(b>='A' && b<='Z'){b=b-'A'+'a';}
            //cout<<a<<" "<<b<<endl;
            if(a!=b) return false;
            i++; j--;
        }
        return true;
    }
};
