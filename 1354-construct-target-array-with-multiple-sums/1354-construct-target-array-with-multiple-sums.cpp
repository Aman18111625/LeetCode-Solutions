class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;//Priority queue for storing all the nums in taget in decreasing order
        long long sum = 0;//for storing total sum
        for(auto num : target){//adding the num into pq and find total sum
            pq.push(num);
            sum+=num;
        }
       //iterating untill all elements in pq become 1 (in turn pq.top() will also become 1);
        while(pq.top() != 1){
            int top=pq.top(); pq.pop();//deleting greatest element
            sum -= top;//removing the greatest element as it was last upadted when converting [1,1,1...] array to target. So we are left with sum of other elements.
//when there are elements greater than 1 then sum of other elements can not be 0 or sum can not be greater than top element because sum + x(any number>0) is pq.top().
            if(sum <= 0 || sum >= top) return false;
          //if we delete all copies of sum from pq.top() we get an old element.
            top%=sum;
            top>0?pq.push(top):pq.push(sum);//Adding old element to restore array.
            sum += (top);//updating sum
        }
      //if all elements are 1
        return true;
    }
};