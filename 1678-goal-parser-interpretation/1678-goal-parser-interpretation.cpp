class Solution {
public:
  /*
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
    }*/
     string interpret(string command) {
        string s="",str;
        for(char ch: command){
            s+=ch;
            if(s=="G"){
                str+="G";
                s="";
            }else if(s=="()"){
                str+="o";
                s="";
            }else if(s=="(al)"){
                str+="al";
                s="";
            }
        }
        return str;
    }
};