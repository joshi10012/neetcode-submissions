class Solution {
    // flag is required in case if pile is not factor or k. 
    int timeelapsed(vector<int>& piles, int k, bool& flag){
        auto time = 0;
        flag = false;
        for(auto pile: piles){
            if(pile<k) time++;
            else if(pile%k==0) {time+=pile/k; flag = true;}
            else time+=pile/k +1;
        }
        return time;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mb = 0;
        //compute the max size of pile, i.e. boundary (max)
        for(auto pile:piles){
            mb = max(mb,pile);
        }
        //loop between 1 and mb
        auto l = 1, r = mb;
        auto mid = 0;
        auto flag = false;
        while(l<=r){
            mid = (l+r)/2;
            auto time = timeelapsed(piles, mid, flag);
            //cout<< l<<" "<< r <<" "<<mid<<" " <<flag<< " "<<time<<endl;
            if(time==h && flag == true) return mid;
            if(time>h) {l = mid + 1; mid = l;}
            else r = mid -1;
        }
        return mid;
    }
};
