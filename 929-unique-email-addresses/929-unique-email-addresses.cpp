class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
         unordered_set<string>mpp;
         for(auto email : emails)
         {
             string temp="";
             for(auto ch : email)
             {
                 if(ch=='+' or ch=='@') break;
                 if(ch=='.') continue;
                 temp+=ch;
             }
             temp+=email.substr(email.find('@'));
             mpp.insert(temp);
         }
        return mpp.size();  
    }
};