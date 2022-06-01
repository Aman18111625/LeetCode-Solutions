class Solution {
public:
    bool isPerfectSquare(int num) {
        int temp=sqrt(num);
        return temp*temp==num;
    }
};