class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(startFuel==target) return 0;
        priority_queue<int>maxHeap;
        int minStops=0;
        int currentStationIndex = 0;
        int n = size(stations);
        while(startFuel<target){
          while(currentStationIndex < n and stations[currentStationIndex][0]<=startFuel){
                maxHeap.push(stations[currentStationIndex][1]);
                currentStationIndex++;
          }
          if(maxHeap.empty())
             return -1;
          startFuel+=maxHeap.top();
          maxHeap.pop();
          minStops++;
        }
        return minStops;
    }
};