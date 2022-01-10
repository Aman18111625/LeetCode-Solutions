class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int>ans(n,-1);
        stack<int>st;
        unordered_map<int,int>map;
        for(int i=0;i<m;i++)
        {
            int elem=nums2[i];
            while(!st.empty() and elem>st.top())
            {
              map[st.top()]=elem;
                st.pop();
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<n;i++)
        {
            int elem=nums1[i];
            if(map.find(elem)!=map.end())
                ans[i]=map[elem];
        }
        return ans;
    }
};