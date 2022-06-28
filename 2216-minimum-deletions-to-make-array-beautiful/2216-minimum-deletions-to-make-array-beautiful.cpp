class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        int ind=-1,count=0;
        for(int i=0;i<n;i++){
        //if stack is not empty() && for even ind if nums[i]==st.top() then we need to delete it.
         if(!st.empty() &&  nums[i]==st.top() && ind%2==0){
             count++; 
         }else{//odd ind,so simply push
           ind++;
           st.push(nums[i]);
         }
        }
        if(ind%2==0) count++;//for last ind
        return count;
    }
};

/*

int minDeletion(vector<int>& a) {
        stack<int>s;
        int n=a.size(),index=-1,count=0;
        for(int i=0;i<n;i++){
            if(!s.empty() && a[i]==s.top() && index%2==0){
                count++;
            }
            else{
                index++;
                s.push(a[i]);
            }
        }
        if(index%2==0)
            count++;
        return count;
    }
};
Using two pointer .. O(1) space:

class Solution{
public:
int minDeletion(vector<int>&a){
int n=a.size();
int count=0;
for(int i=0;i<n-1;i++){
		int index=i-count;
	//  since the index keeps changing after every deletion 
		if(a[i+1]==a[i] && index%2==0)
			count++;
}
		if((n-count)%2!=0)
			count++;
		return count;
	}
*/