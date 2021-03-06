/*
class Solution {
    vector<int> NSL(vector<int>&heights)
    {
        vector<int>ans;
        stack<pair<int,int>>st;
        int n=heights.size();
        int pseudoIndex=-1;
        for(int i=0;i<n;i++)
        {
               while(!st.empty() and st.top().first>=heights[i])st.pop();
                if(st.empty()) ans.push_back(pseudoIndex);
                else ans.push_back(st.top().second);
                st.push({heights[i],i});
        }
        return ans;
    }
    vector<int> NSR(vector<int>&heights)
    {
        vector<int>ans;
        stack<pair<int,int>>st;
        int n=heights.size();
        int pseudoIndex=n;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and st.top().first>=heights[i])st.pop();
            if(st.empty()) ans.push_back(pseudoIndex);
            else ans.push_back(st.top().second);
            st.push({heights[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans; 
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>left=NSL(heights);
        vector<int>right=NSR(heights);
        int n=heights.size();
       int width;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            width=right[i]-left[i]-1;
            maxi=max(maxi,width*heights[i]);
        }
        return maxi;
    }
};*/

class Solution {
  public:
    int largestRectangleArea(vector < int > & histo) {
      stack < int > st;
      int maxA = 0;
      int n = histo.size();
      for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
          int height = histo[st.top()];
          st.pop();
          int width;
          if (st.empty())
            width = i;
          else
            width = i - st.top() - 1;
          maxA = max(maxA, width * height);
        }
        st.push(i);
      }
      return maxA;
    }
};