class Solution {
public:
    //Brute-Force Approach:-insert all the roman into map and find answer
    //TC:=>O(N) 
    //SC:=>O(N)
    // int romanToInt(string s) {
    //     unordered_map<char,int>mp;
    //     mp.insert({'I',1});
    //     mp.insert({'V',5});
    //     mp.insert({'X',10});
    //     mp.insert({'L',50});
    //     mp.insert({'C',100});
    //     mp.insert({'D',500});
    //     mp.insert({'M',1000});
    //     int n=s.size();//let's say s="IIX" so intially ans=10 now c1='I' and c2='X' so ans-=1=>ans=9 because "IX"=9,now c1='I',c2='I' so ans+=1 =>ans=10 which is our answer
    //     int ans=mp[s.back()];
    //     for(int i=n-2;i>=0;i--){
    //       char c1=s[i];
    //       char c2=s[i+1];
    //       if(mp[c1]<mp[c2]){
    //         ans-=mp[c1];
    //       }else{
    //         ans+=mp[c1];
    //       }
    //     }
    //     return ans;
    // }
  //Optimal Approach->Just which roman number present ->add those and after that according to roman combination remove values
  //TC:->O(N)
  //SC:->O(1)
  int romanToInt(string s) {
        int sum = 0;
        for(auto i : s) {
            if(i == 'M') sum += 1000;
            else if(i == 'D') sum += 500;
            else if(i == 'C') sum += 100;
            else if(i == 'L') sum += 50;
            else if(i == 'X') sum += 10;
            else if(i == 'V') sum += 5;
            else if(i == 'I') sum += 1;
        }
        if(s.find("IV") != -1) sum -= 2;
        if(s.find("IX") != -1) sum -= 2;
        if(s.find("XL") != -1) sum -= 20;
        if(s.find("XC") != -1) sum -= 20;
        if(s.find("CD") != -1) sum -= 200;
        if(s.find("CM") != -1) sum -= 200;

        return sum;
    }
};