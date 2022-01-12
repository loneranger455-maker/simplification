#include<iostream>
#include "stack_class.cpp"
using namespace std;
int precedence(char opr){
switch (opr)
{
case '^':
    return 3;
case '/':
    return 2;
case '*':
    return 1;
case '-':
    return 0;
case '+':
    return 0;
default:
    return -1;
}
}
bool isoperator(char opp){ 
    if(opp=='/'||opp=='*'||opp=='-'||opp=='+'||opp=='^'){
        return true;
    }
    else 
    return false;
}
Stack<string> to_postfix(){
    Stack<char> oper;
    Stack <string> express;
    string operand;
    string expression;
    int check_parenthesis=0;
    cout<<"enter the expression:";
    cin>>expression;
    for(string::iterator i=expression.begin();i!=expression.end();i++){

       if (isoperator(*i)){
           express.push(operand);//55-7+9//557-9+
             operand.clear();
           if(oper.empty()){
               oper.push(*i);
           }
        
           else{
        
           while (!oper.empty()&&precedence(oper.top())>=precedence(*i))
           {
                operand.push_back(oper.pop());
                express.push(operand);
                operand.clear();
                  }
            oper.push(*i);}}
        else if(*i=='('){
            oper.push('(');
            check_parenthesis+=1;;
        }
        else if(*i==')'){
            if(check_parenthesis==0){
                cout<<"the input is invalid"<<endl;
                exit(0);
            }
           
            else{
                 check_parenthesis-=1;
                express.push(operand);
                operand.clear();
                while (true)
                {
                    char tempa=oper.pop();
                    if(tempa=='('){
                    
                    break;}
                    operand.push_back(tempa);
                    express.push(operand);     
                     operand.clear();         }
                    
                    operand.clear();
                // express.push(")");
               
            }
        }
       else{
           operand.push_back(*i);
       }
    }
    if(check_parenthesis!=0){
        cout<<"unmatched parethesis"<<endl;
        exit(0);
    }
    express.push(operand);
    operand.clear();
    
    while (!oper.empty()){
        operand.push_back(oper.pop());
        express.push(operand);
        operand.clear();
    }
    return express;
}
