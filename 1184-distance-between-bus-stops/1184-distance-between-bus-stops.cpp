class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int s, int d) {
        int n=distance.size();
        if(s==d) return 0;
        int sum1=0,sum2=0;
        //distance in clockwise direction
        int i=s;
        while(i!=d){
          sum1+=distance[i];
          i=(i+1)%n;
        }
        //distance in counter-clockwise 
         i=d;
        while(i!=s){
          sum2+=distance[i];
          i=(i+1)%n;
        }
        return min(sum1,sum2);
    }
};

  
       