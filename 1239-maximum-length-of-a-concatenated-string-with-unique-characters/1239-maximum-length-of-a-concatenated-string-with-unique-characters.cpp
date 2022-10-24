class Solution {
    int isUnique(string s)
    {
        char ch[26]={0};
        for(int i=0;i<s.size();i++)
            if(ch[s[i]-'a']++>0) return -1;
            
        return s.size();
    }
    void helper(vector<string>&arr,string curr,int index,vector<int>&ans)
    {
        if(index==arr.size() and isUnique(curr)>ans[0]) 
        {
            ans[0]=curr.size();
            return ;
        }
        if(index==arr.size()) return ;
        helper(arr,curr+arr[index],index+1,ans);
        helper(arr,curr,index+1,ans);
    }
public:
    int maxLength(vector<string>& arr) {
        vector<int>ans(1);
        helper(arr,"",0,ans);
        return ans[0];
    }
};