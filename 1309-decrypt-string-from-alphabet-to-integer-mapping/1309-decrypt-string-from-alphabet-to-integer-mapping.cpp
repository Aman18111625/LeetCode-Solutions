class Solution {
public:
    string freqAlphabets(string s) {
     string res = "";
		 int i = 0,n=s.size();
	  	while(i < n){
			if(i + 2 < n && s[i + 2] == '#'){
				int ch = (s[i] - '0') * 10 + (s[i + 1] -  '0');
				res += char(ch+'a'-1);  
				i += 3;
			}
			else{
				res += char((s[i] - '0') + 96);
				i++;
			}
		}
		return res;
    }
};