/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<int>ans;
    int ptr=0;
    void makeFlatten(NestedInteger it)
    {
        if(it.isInteger())
        {
            ans.push_back(it.getInteger());
        }else
        {
            for(auto x : it.getList())
            {
                makeFlatten(x);
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
          for(auto &it : nestedList)
             makeFlatten(it);
    }
    
    int next() {
        return ans[ptr++];
    }
    
    bool hasNext() {
      return ptr<ans.size();  
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */