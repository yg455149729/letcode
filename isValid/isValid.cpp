#include <iostream>
#include <string>
#define Maxsize 500
using namespace std;
class Stack{
    public:
        Stack(){
            this->top=-1;
         }
        void Push(char c);
        char Pop();

    private:
        char* container=new char[Maxsize];
        int top;
};
char Stack::Pop() {
    if(top>=0){
        this->top-=1;
        return container[top+1];
    }
    else{
        return 'e';
    }
}
void Stack::Push(char c) {
    this->top+=1;
    this->container[top]=c;
}
bool isValid(string s) {
    Stack stack;
    for(int i=0;i<s.length();i++){
        char tmp=s[i];
        switch(tmp){
            case'(': {};
            case'[': {};
            case'{': {
                stack.Push(tmp);
                break;
            }
            case')': {char out=stack.Pop();if(out!='(' or out=='e'){return false; } break;}
            case']': {char out=stack.Pop();if(out!='[' or out=='e'){return false;}break;}
            case'}': {char out=stack.Pop();if(out!='{' or out=='e'){return false;}break;}

        }
        }
        if(stack.Pop()=='e')
            return true;
        else{
            return false;
        }

    }
    int main(void){
    string s[5]={"]","()[]{}","(]","([)]","{[]}"};
    for(int i=0;i<=4;i++){
        cout<<(isValid(s[i]))<<endl;
    }
        return  0;
}
//bool isValid(char* s) {
//
//    int length=0;//定义字符串长度
//    while(*(s+length))length++;//获取字符串长度
//    char* ptr=(char*)malloc(length/2);//分配内存空间
//    memset(ptr,0,length/2);//初始化内存空间,比new更好
//    int i,a=0;
//    for(i=0;i<length;i++)
//    {
//        if((*(s+i)=='(')||(*(s+i)=='{')||(*(s+i)=='['))
//        {
//            a++;
//            *(ptr+a)=*(s+i);
//        }
//            //'('与')'的ASCII值差1，'['与']'，'{'与'}'的ASCII值差2
//        else if((*(s+i)==(*(ptr+a)+1))||(*(s+i)==(*(ptr+a)+2)))
//        {
//            a--;
//        }
//        else return 0;
//    }
//    if(a)
//        return 0;
//    return 1;
//
//}
