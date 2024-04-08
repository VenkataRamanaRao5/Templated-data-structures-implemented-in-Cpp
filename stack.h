#include <iostream>
#include <stdexcept>

#ifndef STACK_H
#define STACK_H

//Stack of maximum MAX_SIZE elements of type T
template <typename T, int MAX_SIZE>
class stack{
private:
    T data[MAX_SIZE] = {};
    int top;

public:

    //Create an empty stack
    stack(){
        top = 0;
    }

    //Create a stack from an existing array, arr of n elements
    stack(T arr[], int n){
        if(n >= MAX_SIZE)
            throw std::runtime_error("Exceeds max size!\n");
        for(int i = 0; i < n; i++)
            data[i] = arr[i];
        top = n;
    }

    bool isempty(){
        return top == 0;
    }

    bool isfull(){
        return top == MAX_SIZE;
    }

    //Deletes and returns the top element, throws runtime error on underflow
    int pop(){
        if(isempty())
            throw std::runtime_error("The stack is empty! Cannot Pop!\n");
        return data[--top];
    }

    //Pushes element onto the top, throws runtime error on overflow
    void push(T element){
        if(isfull())
            throw std::runtime_error("The stack is full! Cannot Push!\n");
        data[top++] = element;
    }

    //Returns the top element, throws runtime error on underflow
    int peek(){
        if(isempty())
            throw std::runtime_error("The stack is empty! Cannot Peek!\n");
        return data[top - 1];
    }

    int size(){
        return top;
    }
};

#endif