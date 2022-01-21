class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int total_fuel=0,total_cost=0;
       int n=gas.size();
/*
first of we'll check whether it's possible or not to travel around the circuit once in clockwise direction . For that we'll find totalFuel and totalCose. If totalFuel<totalCose then it means  totalFuel is not sufficient so that we can't travel so simply return -1.
*/
      for(int i=0;i<n;i++)
      {
        total_fuel+=gas[i];
        total_cost+=cost[i];
      }
      if(total_fuel<total_cost) return -1;
      //we're here that means we can travel and ATQ an answer exist.
      int curr_fuel=0,start=0;
      for(int i=0;i<n;i++)
      {
// If at any point our balance/ current fuel is negative that means we can't come to the next petrol pump from the previous pump beacuse our fuel won't allow us to cover such distance. 
//So we'll make the next pump as the start point and proceed. Simultaneously we'll make the current fuel to be 0 as we're starting freshly.
        if(curr_fuel<0)
        {
          curr_fuel=0;
          start=i;
        }
//at any station we'll fill petrol and pay the cost to go to the next station.
        curr_fuel+=(gas[i]-cost[i]);
      }
     return start;
    }
};