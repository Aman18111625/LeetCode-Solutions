class Solution {
public:
    //help to sort according to the end time
    static bool comp(vector<int>&a,vector<int>&b){
      return a[1]<b[1];
    }
   
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(begin(courses),end(courses),comp);//sort the array according to lastday in increasing order
       //max-Heap->to store duration of the courses
        priority_queue<int>pq;
        int time=0;//store the total time taken till now
        for(auto course : courses){
          //if total time taken including this course is lesser than or equal to the last             day then add couse to queue and add the time to total time
           if(time+course[0]<=course[1]){
             time+=course[0];
             pq.push(course[0]);
           } 
           else if(!pq.empty() && pq.top()>=course[0]){//else there are element in priority queue then check if current course is shorter than the max previous course then just replace that with current
             (time-=pq.top())+=course[0];
             pq.pop();
             pq.push(course[0]);
           }
        }
        //as pq only contains the courses taken so size of pq is the number of courses.
        return pq.size();
    }
};

  
    
  