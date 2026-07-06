class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.size()==0) return {};
        int i =0, j = numbers.size()-1;
        while(i!=j){
            auto sum = numbers[i]+numbers[j];
            // return 1 indexed. => focus on the return values. 
            if(sum==target) return {i +1, j + 1};
            if(sum>target) {j--; continue;}
            if(sum<target) {i++; continue;}
        }
        return {};
    }
};
