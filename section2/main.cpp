#include<iostream>

int& function(int& p){
    p =1;
    int& b=p;

    return b;
}

int main(){
    int k=2;
    int a=function(k);
    std::cout<<a<<std::endl;
    return 0;
}