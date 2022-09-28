#include <bits/stdc++.h>
using namespace std;

class Stack{
    int size = 0;
    int length = -1;
    int* arr_stack = new int[size];

    bool empty(){
        return (length == -1);
    }

    bool full(){
        return (length == size-1);
    }

    bool found(int item){
        bool find_item = false;
        if(!empty()){
            for (int i = 0; i <= length; ++i) {
                if (arr_stack[i] == item){
                    find_item = true;
                    break;
                }
            }
        }
        return find_item;
    }

public:

    Stack(int s){
        size = s;
    }

    void push(int item){
        if (!full()){
            length++;
            arr_stack[length] = item;
        }else{
            cout << "Can't push, Stack is full";
        }
    }

    void create(int num){
        if (num <= size){
            for (int i = 0; i < num; ++i) {
                int item;
                cout << "Enter item " << i +1 << " : ";
                cin >> item;
                push(item);
            }
        }else{
            cout << "The numbers of items is more than size of stack";
        }
    }

    void pop(){
        if (!empty()){
            length--;
        }else{
            cout << "Can't delete, Stack is empty" << endl;
        }
    }

    void is_empty(){
        string s = empty() ? "Stack is empty" : "Stack isn't empty";
        cout << s << endl;
    }

    void search(int item) {
        if (empty()) {
            cout << "No " << item << " isn't found, " <<"Stack is empty" << endl;
        }else if(found(item)){
            cout << "Yes " << item << " is found" << endl;
        }else {
            cout << "No " << item << " isn't found, " <<"item don't in it" << endl;
        }
    }

    void get_size(){
            cout << "The size of stack is : " << size << endl;
    }

    void get_length(){
            cout << "The length is : " << length+1 << endl;
    }

    void get_top(){
        if (! empty()){
            cout << "The Top is ==> " << arr_stack[length] << endl;
        }else{
            cout << "No Top, stack is empty" << endl;
        }
    }

    void join(Stack s){
        int* old_arr = arr_stack;
        size += s.size;
        int* new_arr = new int[size];
        for (int i = 0; i <= length; ++i) {
            new_arr[i] = old_arr[i];
        }
        delete[] old_arr;
        arr_stack = new_arr;
        for (int i = 0; i <= s.length; ++i) {
            push(s.arr_stack[i]);
        }
    }

    void reverse(){
        int* old_arr = arr_stack;
        int* new_arr = new int[size];
        int n = length;
        for (int i = 0; i <= length; ++i) {
            new_arr[i] = old_arr[n];
            n--;
        }
        delete[] old_arr;
        arr_stack = new_arr;
    }

    void display(){
        if(!empty()){
            cout << "The stack is ==> ";
            for (int i = length; i > 0; --i) {
                cout << arr_stack[i] << " ";
            }
            cout << arr_stack[0];
            cout << endl;
        }else{
            cout << "Can't display, Stack is empty" << endl;
        }
    }

    void clear(){
        if(!empty()){
            while (! empty()){
                pop();
            }
        } else{
            cout << "Can't Clear, Stack is empty" << endl;
        }
    }

};
