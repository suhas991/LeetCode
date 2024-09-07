class Solution {
    public int reverse(int x) {
        
        int rev = 0;
        while(x != 0)
        {
            int tail = x%10;
            int newRes = rev * 10 +tail;
            if((newRes - tail)/10 != rev){
                return 0;
            }
            rev=newRes;
            x /= 10;
        }
       return rev;
    }
}

// int result = 0;

//     while (x != 0)
//     {
//         int tail = x % 10;
//         int newResult = result * 10 + tail;
//         if ((newResult - tail) / 10 != result)
//         { return 0; }
//         result = newResult;
//         x = x / 10;
//     }

//     return result;