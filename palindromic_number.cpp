#include<iostream>
using namespace std;

int main(){
    int num, rem, for_num, rev_num=0;
    cout<<"Enter an integer: ";
    cin>>num;
    for_num = num;
    while(num>0){
        rem = num%10;
        rev_num = rev_num*10 + rem;
        num = num/10;
    }
    if (rev_num == for_num){
        cout<<"The Entered Number is Palindromic Number";
    }
    else{
        cout<<"The Entered Number is not Palindromic Number";
    }
}