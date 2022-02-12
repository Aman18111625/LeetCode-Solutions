class Solution {
public:
    int ladderLength(string start, string end, vector<string>& wordList) {
        //step-1 insert all the word of WordList into set and check for end word
          unordered_set<string>word;
          for(auto &w : wordList) word.insert(w);
          if(word.find(end)==word.end()) return 0;//end word is not present
      //step2 Use queue to store depth wise word 
           queue<string>q;
           q.push(start);//intially push start word in queue
          int len=start.size();//according to  constraint all the word should be of same size
          int depth=0;
        while(!q.empty())
        {
          depth++;
          int size=q.size();
          for(int i=0;i<size;i++)
          {
            string temp=q.front(); q.pop();
            //now check for each & every character of string temp
             for(int l=0;l<len;l++)
             {
                char curr=temp[l];
                for(char ch='a';ch<='z';ch++)
                {
                  temp[l]=ch;//replace from 'a' to 'z' and check if it's equal to end then return depth+1 else check whether it's present in set or not if not then continue else erase from set and push into queue
                  if(temp==end) return depth+1;
                  if(word.find(temp)==word.end()) continue;
                  word.erase(temp);
                  q.push(temp);
                }
              temp[l]=curr;//backtrack to curr word  because we have to check all the possibility
             }
          }
        }
      return 0;
    }
};

          