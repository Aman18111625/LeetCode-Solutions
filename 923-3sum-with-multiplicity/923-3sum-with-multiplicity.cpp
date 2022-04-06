class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(begin(arr),end(arr));
        int n=arr.size();
        int mod=1e9+7;
        int cnt=0;
        for(int i=0;i<n-2;i++){
            int low=i+1,high=n-1;
            int temp=target-arr[i];
            while(low<high){
             if(arr[low]+arr[high]==temp){
               if(arr[low]==arr[high]){
                 cnt=(cnt+(((high-low)*(high-low+1))>>1)%mod)%mod; break;
               }else{
                 int l=1,r=1;
                while(low + 1 < high && arr[low] == arr[low + 1]) low++,l++;
				        while(high - 1 >= low && arr[high] == arr[high - 1]) high--,r++;
                  cnt+=(l*r)%mod;
                  low++,high--;
               }
             }else if(arr[low]+arr[high]<temp){
                low++; 
             }else high--;
            }
        }
        return cnt;
    }
};
	
	
	