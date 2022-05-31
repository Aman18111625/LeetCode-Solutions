class Solution {
public:
  //Brute-Force Approach
  //Simply Check all the binary code of length K in String S exist or not .If any of them is not exist then return false .
  //This solution will give us TLE .
  //TC:=>O(N*2^K)
  //SC:=>O(1)
//   bool hasAllCodes(string s, int k) {
// 	int n = s.size(); 
// 	for(int num = 0; num <= (1 << k); num++){
// 		string binaryCode = bitset<20>(num).to_string().substr(20-k, k);
// 		if(s.find(binaryCode) == string::npos) return false;
// 	}        
// 	return true;
// }
  
  
  //Optimized Approach:=>We can observe that we only need to verify if all possible codes of length k exists in the string s. Instead of generating all the codes and then checking if each one exists in s, we can just check all the substrings of length k in the string s. If number of all the distinct substrings of length k is 2^k, we are sure that all binary codes exists in the given string. We can use a hashset to keep track of all distinct substrings found.
  
  //Time-Complexity:=>O(N*K) where N->length of String and K->length of Binary Code
  //Space-Complexity:=>O(N*k)
    bool hasAllCodes(string s, int k) {
        int n = s.size(); 
    unordered_set<string> set;
    for(int i = 0; i <= n - k; i++) set.insert(s.substr(i, k));
    // if number of distinct substrings in s equals 2^k (1 << k), return true else return false
    return set.size() == (1 << k);
    }
};