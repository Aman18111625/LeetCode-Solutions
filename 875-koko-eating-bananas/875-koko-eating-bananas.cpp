class Solution {
    bool is_enough(vector<int>&piles,int mid,int h)
    {
        // req is hours required to finish all the bananas
        int req=0;
        for(auto &it : piles) 
        {
            req+=ceil(it*1.0/mid);
        }
        //if req<=h it means she can it all the bananas in less than or equal to h hours
        return req<=h;
    }
public:
    /*
     Idea is behind apply binary search here is that we know h>=sizeofpiles ,if we take max of piles array than we're able to finish all the bananas in h hourse but we have minimize the k.Now got our search we'll take low=1,high=max of piles and check for every mid 
    */
    int minEatingSpeed(vector<int>& piles, int h) {
         int maxi=0;
        for(auto &it : piles)
        {
            maxi=max(maxi,it);
        }
        int low=1,high=maxi;
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(is_enough(piles,mid,h))
            {
                ans=mid;
                high=mid-1;
            }else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};