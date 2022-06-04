class Solution {
public:
    /* 
    //Brute-Force Approach
    //TC:=>O(N) && SC:=>O(N)
    //insert all the number into set and find kth missing number.
    int findKthPositive(vector<int>& arr, int k) {
        int no=1,cnt=0;
        unordered_set<int>s;
        for(auto it : arr)
        {
            s.insert(it);
        }
            while(cnt!=k)
            {
                if(!s.count(no)) cnt++;
                no++;
            }
        return no-1;
    }*/
   // Optimal Approach->Using binary Search
  //TC:=>O(logN) && SC:=>O(1)
    int findKthPositive(vector<int>& arr, int k){
        int low=0,high=arr.size()-1,mid,ans;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            int missed=arr[mid]-mid-1; //tells us the missed number till mid               
            if(missed>=k)
            {
                ans=arr[mid]-(missed-k)-1;
                high=mid-1;
            }else
            {
                low=mid+1;
                ans=arr[mid]+k-missed;
            }
        }
        return ans;
    }
};
 
