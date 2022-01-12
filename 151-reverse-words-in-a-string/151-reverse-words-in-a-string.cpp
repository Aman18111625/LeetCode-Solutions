class Solution {
public:
    /*
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string>res;
        while(ss>>word)
        {
            res.push_back(word);
        }
        reverse(res.begin(),res.end());
        string ans="";
        for(int i=0;i<res.size();i++)
        {
             ans+=res[i];
            if(i!=res.size()-1) ans+=" ";
        } 
            return ans;
    }
    */
    public:
    
    string reverseWords(string s) {
        if(s.size() == 0) return s;
        stack<string> stack;
        string result;
        for(int i=0; i<s.size(); i++) {
            string word;
            if(s[i]==' ') continue; //skip spaces
            while(i<s.size() && s[i]!=' ' ) { //store continuous letters into word
                word += s[i]; i++;
            }
            stack.push(word); //push word to the stack
        }
        while(!stack.empty()) {
            result += stack.top(); stack.pop();
            if(!stack.empty()) result += " ";
        }
        return result;
    }
};