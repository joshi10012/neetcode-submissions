class Solution {
    struct data{
        int val;
        int count;
    };
    struct cmpdata{
        bool operator()(const data& a, const data& b)
        {
            return a.count>b.count;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> arr(2001,0);
        for(auto num: nums){
            auto i = num + 1000;
            arr[i]+=1;
        }
        std::priority_queue<data, vector<data>, cmpdata> pq;
        for(auto i=0; i<arr.size(); i++){
            if(arr[i]==0)continue;
            auto count = arr[i];
            auto val = i-1000;
            //cout<<val<<" "<<count<<endl;
            if(pq.size()>k) {
                auto top = pq.top();
                cout<<"top: "<<top.val<<" "<<top.count<<endl;
                pq.pop();
            }
            pq.push({val,count});
        }
        if(pq.size()!=k)pq.pop();
        vector<int> ret;
        while(pq.size()!=0){
            auto top = pq.top();
            pq.pop();
            ret.push_back(top.val);
        }
        return ret;
    }
};
