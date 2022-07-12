// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
    bool brainGame(vector<int>nums) {
        // Code here.
        //first find factors 
        vector<int>factor(1005);
    	for(int i = 2; i<= 1000; i++){
    		for(int j = 2*i; j <= 1000; j+=i)
    			factor[j] = max(factor[j], 1 + factor[i]);
    	}
    	//NimSum ->xor of all elements ->if Xor ==0 then A won't be able make the last move else B won't be able to make the last move
    	int x = 0,n=nums.size();
    	for(int i = 0; i < n; i++){
    		x = x ^ factor[nums[i]];
    	}
    	if(x == 0)	return false;
    	return true;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		bool ans = ob.brainGame(nums);
		if(ans)
			cout << "A\n";
		else cout << "B\n";
	}  
	return 0;
}  // } Driver Code Ends