class Solution {
public:
    /*
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
    int findKthPositive(vector<int>& arr, int k){
        int i=0,j=arr.size()-1,mid,ans;
        while(i<=j)
        {
            int mid=(i+j)>>1;
            int missed=arr[mid]-mid-1; //tells us the missed number till mid                 
            if(missed>=k)
            {
                ans=arr[mid]-(missed-k)-1;
                j=mid-1;
            }else
            {
                i=mid+1;
                ans=arr[mid]+k-missed;
            }
        }
        return ans;
    }
};
 
