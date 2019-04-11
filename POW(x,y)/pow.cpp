#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

double mypow(double x,int n){
    if(n%2==0 & n!=0 ){
        return pow(mypow(x,n/2),2);
    }
    else if (n!=1 & n!=0){
        return pow(mypow(x,n/2),2)*x;
    }
    else if (n==1){
        return x;
    }
    else if(n==0){
        return 1;
    }
}
double myPow(double x, int n) {
    int flag=(n>=0)? 1:0;
    double result=(flag==1)? mypow(x,n):1/mypow(x,-n);
    return result;

}
int main(){
    cout<<myPow(1.00001,123456) ;
}
