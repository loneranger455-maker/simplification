#include<iostream>
#include "postflix.h"
using namespace std;
int power(int a,int b){
    int ans=1;
    if(b==0)
    return 1;
    for (int i = 0; i < b; i++)
    {
        ans=ans*a;
    }
    return ans;
    
}
int string_to_int(string str){
    int ans=0;
    for (int i = 0; i < str.length(); i++)
    {
        ans=ans+((int)str[str.length()-1-i]-48)*power(10,i);
    }
    return ans;
    
}
int operation(char oprator,int operand1,int operand2){
    switch (oprator)
    {
        case '^':
        return power(operand1,operand2);
    case '/':
        return operand1/operand2;
    case '*':
        return operand1*operand2;
    case '+':
        return operand1+operand2;
    case '-':
        return operand1-operand2;
    default:
        break;
    }
    return 0;

}
int main(){
    Stack<string> simplify;
    simplify=to_postfix();
    cout<<"postfix is:";
    simplify.display();
    cout<<endl;
    Stack<int> operands;
    for (int i=0;i<simplify.size;i++){
        if (simplify.arraY(i)==""){
            continue;
        }
        
        if(isoperator(simplify.arraY(i)[0])){
            int ans=operation(simplify.arraY(i)[0],operands.pop(),operands.pop());
            operands.push(ans);  
        }
        else{
            operands.push(string_to_int(simplify.arraY(i)));
        }
    }
    cout<<"ans is:"<<operands.top()<<endl;
}