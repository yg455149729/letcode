 int reverse(int x) {
        int result=0;
        while(x!=0){
            int temp=x%10;
              x/=10;
            if(result>INT_MAX/10||(result==INT_MAX/10&&temp>7)) return 0;
            if(result<INT_MIN/10||(result==INT_MIN/10&&temp<-8)) return 0;
            result=result*10+temp;
           
        }
        return result;
    }
    //没什么好说的，就是很简单的不断余10加的过程。需要要注意的就是官方提醒的注意：
    //假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
