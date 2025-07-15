class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)return false;
        long long power = 1;
         for(int i = 0; i < 50; i++)
     {
        if(power == n)return true;
        else if(power > n)return false;
        power *= 3;
     }
        return false;
    }
};