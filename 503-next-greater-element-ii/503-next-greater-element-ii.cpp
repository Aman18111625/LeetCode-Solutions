class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        stack<int>st;
         for(int i=n-1;i>=0;i--) st.push(nums[i]);
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty()) ans.push_back(-1);
            else if(!st.empty() and st.top()>nums[i])
                ans.push_back(st.top());
            else if(!st.empty() and st.top()<=nums[i])
            {
                while(!st.empty() and st.top()<=nums[i]) st.pop();
                if(st.empty()) ans.push_back(-1);
                else ans.push_back(st.top());
            }
            st.push(nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};