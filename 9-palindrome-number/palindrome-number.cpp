class Solution {
public:
    bool isPalindrome(int x) {
        int rev = 0 , digit;
        int num = x;
          if(x<0) return false;
            if (x != 0 && x % 10 == 0) return false;
        while(num > rev)
        {
            digit = num % 10;
            rev = (rev*10)+digit;
            num /= 10;
        }
         return (num == rev || num == rev / 10);
    }
};