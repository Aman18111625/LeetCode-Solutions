struct TrieNode
{
    TrieNode *child[26]={};
    int curIndex=-1;
    vector<int> wordIndex;
};

class Solution {
// public:
   //Brute-Force Approach
   //Time Complexity: O(n^2 * m)
   //Space Complexity: O(1)


//    bool isPalindrome(string &s){
//      int i=0,j=s.size()-1;
//      while(i<=j){
//        if(s[i]!=s[j]) return false;
//        i++,j--;
//      }
//      return true;
//    }  
  
//     vector<vector<int>> palindromePairs(vector<string>& words) {
//       vector<vector<int>>ans;
//       int n=words.size();
//       for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//           if(j!=i){
//             string str=words[i]+words[j];
//             if(isPalindrome(str)){
//               ans.push_back({i,j});
//             } 
//           }
//         }
//       }
//       return ans;
//     }
  
//Better-Approach
//Time Complexity: O(n*k^2) where n is the number of words and k is the length of the longest word
//Space Complexity: O(n * k)
/*
Thought-Process:
1.We can use a hashmap to store the words and their indices.
2.Now, we can iterate over the words and check if the reversed word exists in the hashmap.
3.If it exists, then we can check if the remaining part of the word is a palindrome.
4.If it is, then we can add the indices to the result.
5.We can also check if the word is a palindrome and if the reversed word exists in the hashmap.
6.If it does, then we can add the indices to the result.
*/
	// vector<vector<int>> palindromePairs(vector<string>& words) {
	// vector<vector<int>> result;
	// unordered_map<string, int> wordMap;
	// for (int i = 0; i < words.size(); i++) {
	// wordMap[words[i]] = i;
	// }
	// for (int i = 0; i < words.size(); i++) {
	// string word = words[i];
	// string reversedWord = word;
	// reverse(reversedWord.begin(), reversedWord.end());
	// if (wordMap.find(reversedWord) != wordMap.end() && wordMap[reversedWord] != i){
	// result.push_back({i, wordMap[reversedWord]});
	// }
	// if (isPalindrome(word)) {
	// string emptyString = "";
	// if (wordMap.find(emptyString) != wordMap.end() && wordMap[emptyString] != i) {
	// result.push_back({i, wordMap[emptyString]});
	// result.push_back({wordMap[emptyString], i});
	// }
	// }
	// for (int j = 1; j < word.size(); j++) {
	// string left = word.substr(0, j);
	// string right = word.substr(j);
	// string reversedLeft = left;
	// string reversedRight = right;
	// reverse(reversedLeft.begin(), reversedLeft.end());
	// reverse(reversedRight.begin(), reversedRight.end());
	// if (isPalindrome(left) && wordMap.find(reversedRight) != wordMap.end()) {
	// result.push_back({wordMap[reversedRight], i});
	// }
	// if (isPalindrome(right) && wordMap.find(reversedLeft) != wordMap.end()) {
	// result.push_back({i, wordMap[reversedLeft]});
	// }
	// }
	// }
	// return result;
	// }
  
  //Optimized Approach:-
  //Time-Complexity:=>O(N*K^2)
  //Space-Complexity:=>O(N*K)
  
/*Thought-Process:
1.Idea is to use Trie to store all the words in reverse order
2.For each word, we can check if the current node is a palindrome, if so, we can add all the words in the current node to the answer.
3.We can also check if the current node is a prefix of the current word, if so, we can check if the remaining part of the word is a palindrome, if so, we can add the current word to the answer.
4.We can also check if the current node is a suffix of the current word, if so, we can check if the remaining part of the word is a palindrome, if so, we can add the current word to the answer.
5.We can also check if the current node is a word, if so, we can add the current word to the answer.So that we can find all the palindromes in O(k) time
*/
  public:
  bool isPalindrome(string &s, int i, int j){
        while (i < j){
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    TrieNode *root;
    void insert(string &s, int index){
        TrieNode *cur = root;
        for (int i = s.size() - 1; i >= 0; i--){
            int c = s[i] - 'a';
            if (cur->child[c] == nullptr)
                cur->child[c] = new TrieNode();
            if (isPalindrome(s, 0, i))
                cur->wordIndex.push_back(index);
            cur = cur->child[c];
        }
        cur->wordIndex.push_back(index);
        cur->curIndex = index;
    }


    vector<vector<int>> palindromePairs(vector<string>&words){
        root = new TrieNode();
        for (int i = 0; i < words.size(); i++)
            insert(words[i], i);
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++){
            TrieNode *cur = root;
            string &s = words[i];
          for (int j = 0; j < s.size(); j++){
            if(cur->curIndex != -1 && cur->curIndex != i && isPalindrome(s,j,s.size()-1))
                ans.push_back({i, cur->curIndex});
                cur = cur->child[s[j] - 'a'];
                if (cur == nullptr)
                    break;
            }
            if (cur == nullptr) continue;
            for (int j : cur->wordIndex){
                if (i == j) continue;
                ans.push_back({i, j});
            }
        }
        return ans;
    }
  
};