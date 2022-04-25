/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

// class PeekingIterator : public Iterator {
//   queue<int>q;
// public:
// 	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
// 	    // Initialize any member here.
// 	    // **DO NOT** save a copy of nums and manipulate it directly.
// 	    // You should only use the Iterator interface methods.
// 	    for(auto &it : nums) q.push(it);
// 	}
	
//     // Returns the next element in the iteration without advancing the iterator.
// 	int peek() {
//    return q.front();     
// 	}
	
// 	// hasNext() and next() should behave the same as in the Iterator interface.
// 	// Override them if needed.
// 	int next() {
// 	    int temp=q.front();
//       q.pop();
//       return temp;
// 	}
	
// 	bool hasNext() const {
// 	    return !q.empty();
// 	}
// };

 class PeekingIterator : public Iterator {
public:
    int prev;
    bool has;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        has = 1;
	    next();
	}
	int peek() {
        return prev;
	}
	int next() {
        int temp = prev;
	    if(Iterator::hasNext()==false)
            has = false;
        else
            prev = Iterator::next();
        return temp;
	}
	bool hasNext() const {
	    return has;
	}
};