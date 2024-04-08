#include <iostream>
#include <stdexcept>

#ifndef QUEUE_H
#define QUEUE_H

//Queue of maximum MAX_SIZE elements of type T
template <typename T, int MAX_SIZE>
class queue{
private:
    T data[MAX_SIZE] = {};
    int front, rear;

public:

    //Create an empty queue
    queue(){
        front = 0;
        rear = 0;
    }

    //Create a queue from an existing array, arr of n elements
    queue(T arr[], int n){
        if(n >= MAX_SIZE)
            throw std::runtime_error("Exceeds max size!\n");
        for(int i = 0; i < n; i++)
            data[i] = arr[i];
        front = 0;
        rear = n;
    }

    bool isempty(){
        return front == rear;
    }

    bool isfull(){
        return rear - front ==  MAX_SIZE;
    }

    //Deletes and returns the top element, throws runtime error on underflow
    int dequeue(){
        if(isempty())
            throw std::runtime_error("The queue is empty! Cannot dequeue!\n");
        return data[front++ % MAX_SIZE];
    }

    //Pushes element onto the top, throws runtime error on overflow
    void enqueue(T element){
        if(isfull())
            throw std::runtime_error("The queue is full! Cannot enqueue!\n");
        data[rear++ % MAX_SIZE] = element;
    }

    //Returns the top element, throws runtime error on underflow
    int peek(){
        if(isempty())
            throw std::runtime_error("The queue is empty! Cannot Peek!\n");
        return data[front];
    }

    int size(){
        return rear - front;
    }
};

#endif