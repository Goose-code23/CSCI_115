#include<iostream>
using namespace std;
#define MAX 10


class Stack
{
public:
    int Top;
    // This will be the top of our stack
    public:
    int arr1[MAX]; // we are setting the max size of our array to 10;

    Stack(){ Top = -1; }
    bool push(int n);
    int pop();
    int peak();
    bool isEmpty();
};

bool Stack::push(int n){
    if(Top >= (MAX -1)){
        cout<<"Stack overflow";
        return false;
    }
    else{
        arr1[++Top] = n;
        cout << n << " Pushed into Stack\n";
        return true;
    }
}

int Stack::pop(){ 
    if (Top < 0){
        cout << "Stack underflow";
        return 0;
    }
    else {
        int n = arr1[Top --];
        return n;
    }
}

int Stack::peak(){
    if( Top < 0 ){
        cout << "Stack is Empty" << endl;
        return 0;
    }
    else{
        int n = arr1[Top];
        return n;
    }
}

bool Stack::isEmpty(){
    return (Top < 0);
}

int main(){
    class Stack s;
    s.push(20);
    s.push(40);
    s.push(60);

    cout << s.pop() << " Popped from stack\n";

    cout << "Top Element: " << s.peak() << endl;

    cout <<"Element in stack : ";
    while(!s.isEmpty())
    {
        cout << s.peak() <<" ";

        s.pop();
    }
    return 0;
}