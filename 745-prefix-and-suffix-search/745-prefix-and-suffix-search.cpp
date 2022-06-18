//Approach->1 :: Using Trie DS
/*In this approach we take two Tries : one for Prefix and one for Suffix. Though it passes all TC but gets overall TLE.
Prefix Trie : In this we store word in same order as given.
Ex : "abc" is stored as "a -> b -> c" 
Suffix Trie : In this we store word in reverse order so that suffixes can be searched easily.
Ex: "abc" is stores as "c -> b -> a"
Idea is to store indexes of all words that pass through a Trie node. It will be later used to find intersection of suffix and prefix string. And to get Largest Index if there are multiple words.
When we find both prefix and suffix string in corresponding Tries, we will find the first common index that is present in indexes array of prefix and suffix word.
*/
// struct Node {
//     Node* arr[26];
//     vector<int> indexes;  // To get all the index of words that pass through this node
    
//     bool contains(char ch) {
//         return arr[ch-'a'];
//     }
    
//     void put(char ch, Node* newNode) {
//         arr[ch-'a'] = newNode;
//     }
    
//     Node* getNext(char ch) {
//         return arr[ch-'a'];
//     }
    
//     void putIndex(int idx) {    // Add index of word that pass through it
//         indexes.push_back(idx);
//     }
    
//     vector<int> getIndex() {
//         return indexes;
//     }
// };



// class WordFilter {
//     Node* prefixRoot;
//     Node* suffixRoot;
// public:    
// //Insert the words into Trie For every node insert the index as well It tracks the word that passes through that node
//     void insert(Node* root, string& s, int i) {
//         for(auto& ch : s) {
//             if(!root->contains(ch)) {
//                 root->put(ch, new Node());
//             }
//             root = root->getNext(ch);
//             root->putIndex(i);
//         }
//     }
    
//     WordFilter(vector<string>& words) {
//         prefixRoot = new Node();
//         suffixRoot = new Node();     
//         int i=0;
//         for(auto& word : words) {
//             insert(prefixRoot, word, i);
//             reverse(word.begin(), word.end());
//             insert(suffixRoot, word, i);
//             i++;
//         }
//     }
    
// //Search if word is present or not. If present then return indexes array  Otherwise return empty array
//     vector<int> search(Node* root, string& word) {
//         for(auto& ch : word) {
//             if(!root->contains(ch)) return {};
//             root = root->getNext(ch);
//         }
//         return root->getIndex();
//     }
    
//     int f(string prefix, string suffix) {     
//         vector<int> prefixIndexes = search(prefixRoot, prefix);
//         reverse(suffix.begin(), suffix.end());
//         vector<int> suffixIndexes = search(suffixRoot, suffix);
// //Find the first intersection index from last Since from last we will get the largest index in case if there are multiple valid words 
//         int i = prefixIndexes.size()-1, j = suffixIndexes.size()-1;
//         while(i>=0 && j>=0) {
//             int a = prefixIndexes[i], b = suffixIndexes[j];
//             if(a == b) return a;
//             else (a < b) ? j-- : i--;
//         }
//         return -1;
//     }
// };

//Approach 2:
/*
In this approach we use a simple Trie. Convert word in form suffix + { + prefix so that matching of string becomes easy and fast. We take advantage that maximum length possible of word is 10.
We store all possible suffixes concatenated with prefix and '{'
Ex:  "apple" -> "{apple"  "e{apple"  "le{apple"  "ple{apple"  "pple{apple"  "apple{apple"
Suffixes are "", "e", "le", "ple", "pple", "apple"
Also, we store latest index of word that passes through a particular Trie node. This will give us that largest index in case of multiple valid words.
To search if there is word that has both prefix and suffix strings, we simply need to make a string by concatenating suffix { prefix , and search for this string in Trie that we build.
Ex : prefix = "app" , suffix = "ple" -> string = "ple{app"
This string is present in Trie, and return the index at end of this string. 
Remaining Code is easy to understand.
*/
struct Node {
    Node* arr[27];
    int index = -1;
    
    bool contains(char ch) {
        return arr[ch-'a'] != NULL;
    }
    
    void put(char ch, Node* newNode) {
        arr[ch-'a'] = newNode;
    }
    
    Node* getNext(char ch) {
        return arr[ch-'a'];
    }
    
    void setIndex(int idx) {
        index = idx;
    }
    
    int getIndex() {
        return index;
    }
};

class WordFilter {
    Node* trie;
public:
    
    void insert(Node* root, string& s, int idx) {
        for(auto& ch : s) {
            if(!root->contains(ch)) {
                root->put(ch, new Node());
            }
            root = root->getNext(ch);
            root->setIndex(idx);
        }
    }
    
    WordFilter(vector<string>& words) {
        trie = new Node();
        
        int idx = 0;
        string s = "";
        
        for(auto& word : words) {
            s = "{" + word;
            insert(trie, s, idx);
            
            for(int i=word.size()-1; i>=0; i--) {
                s = word[i] + s;
                insert(trie, s, idx);
            }
            
            idx++;
        }
    }
    
    int f(string prefix, string suffix) {
        
        Node* temp = trie;
        
        string match = suffix + "{" + prefix;
        
        for(auto& ch : match) {
            if(!temp || !temp->contains(ch)) return -1;
            temp = temp->getNext(ch);
        }
        
        return temp->getIndex();
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
  
  