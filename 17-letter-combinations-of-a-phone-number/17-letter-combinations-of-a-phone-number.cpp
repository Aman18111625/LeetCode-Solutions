class Solution {
    vector<string>res;//to store result
    unordered_map<int,string>mpp;//to store key as number and value as string according to phone keyboard
    void helper(string digits,int i,int n,string& temp)
    {
        if(i==n)
        {
            res.push_back(temp);
            return ;
        }
       for(auto it : mpp[digits[i]-'0'])//for every char we have only two options
       {
           temp.push_back(it);//op1->we can include 
           helper(digits,i+1,n,temp);//call for next
           temp.pop_back();//op2->we don't want to include
       }
    }
public:
    vector<string> letterCombinations(string digits) {
        res.clear();
        int n=digits.size();
        if(n==0) return res;
        //fidding map
        mpp[2]="abc";
        mpp[3]="def";
        mpp[4]="ghi";
        mpp[5]="jkl";
        mpp[6]="mno";
        mpp[7]="pqrs";
        mpp[8]="tuv";
        mpp[9]="wxyz";
        string combi="";
        helper(digits,0,n,combi);
        return res;
    }
};