class Solution {
public:
    string interpret(string command) {
        unordered_map<string,string>mpp;
        mpp["(al)"]="al";
        mpp["()"]="o";
        mpp["G"]="G";
        string temp="",res="";
        for(auto &ch : command){
          temp+=ch;
          if(mpp.find(temp)!=mpp.end()){
            res+=mpp[temp];
            temp="";
          }
        }
        return res;
    }
};