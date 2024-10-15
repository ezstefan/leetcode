class Solution {
public:
    double func(double x, int n){
        if(n==0){
            return 1;
        }
        if(n%2 == 0){
            return func(x*x, n/2);
        }
        else{
            return x*func(x*x, n/2);
        }
    }
    double myPow(double x, int n) {
        if(n<0){
            double ans = func(x,n);
            return 1/ans;
        }
        return func(x,n);
    }
};
