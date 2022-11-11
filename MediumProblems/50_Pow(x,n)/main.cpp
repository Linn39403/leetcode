class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        int multiplier = abs(n);
        for(int i=0;i<multiplier;i++){
            ans *= x;
        }
        if(n < 0){
            //divide 1 by ans
            ans = 1.0 / ans;
        }
        return ans;
    }
};
