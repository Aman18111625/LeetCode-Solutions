class Solution {
public:
    const int mod=1000000007;
    int numSub(string s) {
       if(s.empty()) return 0; //check string is empty or not ,if yes then simply return 
        //cnt-> if(s[i]==1) we'll increment it else we'll set cnt=0;
        //s=="0110111"=> 1-> 5 times,11->3 times ,111->1 time 
       long cnt=0,res=0;
       for(auto ch : s)
       {
           if(ch=='1') cnt++;
           else cnt=0;
           res=res%mod+cnt%mod;
       }
        return res%mod;
    }
};