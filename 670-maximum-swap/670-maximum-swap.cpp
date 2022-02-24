class Solution {
public:
    int maximumSwap(int num) {
    int maxDigit = -1;
    int maxDigitIndex = -1;
    int leftIndex = -1;
    int rightIndex = -1;
 
    string ans = to_string(num);
    int size=ans.size();
    for (int i = size - 1; i >= 0; i--) {
        if (ans[i] > maxDigit) {
            maxDigit = ans[i];
            maxDigitIndex = i;
            continue;
        }
        if (ans[i] < maxDigit) {
            leftIndex = i;
            rightIndex = maxDigitIndex;
        }
    }
    if (leftIndex == -1) return num;
    swap(ans[leftIndex], ans[rightIndex]);
    return stoi(ans); 
    }
};