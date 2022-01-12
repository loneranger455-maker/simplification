#include<iostream>
#include<cstring>
using namespace std;
template <typename T>
class Stack{
T stack_conatiner[30]={};//33+22
public:
int size;
Stack(){
    size=0;
}
T pop(){
size--;
return(stack_conatiner[size]);                 
                                                                //ab+c-
}
void push(T value){                                     //st1 st2 a+b-c
    stack_conatiner[size]=value;
size++;
}

bool empty(){
    if(size==0)
    return true;
    else 
    return false;
}
void display(){
for(int i=0;i<size;i++){
    cout<<stack_conatiner[i];
}

}
T top(){
    return (stack_conatiner[size-1]);
}
T arraY(int pos){
return stack_conatiner[pos];
}
};