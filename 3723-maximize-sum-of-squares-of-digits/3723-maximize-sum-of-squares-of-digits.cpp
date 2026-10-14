class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num) return "";
        int n1 = sum/9, n2= sum%9;
        if(n1==num) return string(n1,'9');
        return string(n1,'9') + char(n2+'0') + string((num-n1-1),'0');
    }
};