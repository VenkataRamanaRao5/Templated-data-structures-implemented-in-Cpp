#include <iostream>
#include <stdexcept>

#ifndef HEAP_H
#define HEAP_H

/*
Heap of maximum MAX_SIZE elements of type T
Can act as both min heap and max heap based on isMin
*/
template <typename T, int MAX_SIZE>
class heap{
protected:
    T data[MAX_SIZE] = {};
    int n;

    
    void swap(T& one, T& two){
        T temp = one;
        one = two;
        two = temp;
    }

    int parent(int index){
        return (index - 1) / 2;
    }

    int left_child(int index){
        return 2 * index + 1;
    }

    int right_child(int index){
        return 2 * index + 2;
    }

    void display(){
        for(int i = 0; i < n; i++)
            std :: cout << data[i] << " ";
        std :: cout << std :: endl;
    }

public:
    //Create an empty heap
    heap(){
        n = 0;
    }

    /*
    The comparison function that has to be implemented.
    Should return -1 if left should be a parent of right and 1 if vice versa
    */
    virtual int compare(T left, T right) = 0;

    bool isempty(){
        return n == 0;
    }

    bool isfull(){
        return n ==  MAX_SIZE;
    }

    //Returns the top element, throws runtime error when empty
    T peek(){
        if(isempty())
            throw std :: runtime_error("Heap is empty!\n");
        else
            return data[0];
    }

    // Pops the top element, throws runtime error on underflow
    T extractTop(){
        if(isempty())
            throw std :: runtime_error("Heap is empty!\n");
        else
            return deleteAndReturn(0);
    }

    //Insert element el into the heap, throws runtime error on overflow
    void insert(T el){
        if(isfull())
            throw std :: runtime_error("Heap is full!\n");
        else{
            data[n] = el;
            for(int index = n; index > 0 && compare(data[parent(index)], data[index]) > 0; index = parent(index))
                swap(data[parent(index)], data[index]);
            n++;
        }
    }

    //Deletes and returns the element at index at, throws runtime error on underflow
    T deleteAndReturn(int at){
        if(isempty())
            throw std :: runtime_error("Heap is empty!\n");
        else{
            --n;
            int index = at;
            swap(data[at], data[n]);
            while(index < n / 2){
                if(compare(data[index], data[left_child(index)]) > 0){
                    if(right_child(index) < n && compare(data[index], data[right_child(index)]) > 0){
                        if (compare(data[left_child(index)], data[right_child(index)]) < 0){
                            swap(data[index], data[left_child(index)]);
                            index = left_child(index);
                        }
                        else{
                            swap(data[index], data[right_child(index)]);
                            index = right_child(index);
                        }
                    }
                    else{
                        swap(data[index], data[left_child(index)]);
                        index = left_child(index);
                    }
                }
                else if(right_child(index) < n && compare(data[index], data[right_child(index)]) > 0){
                    swap(data[index], data[right_child(index)]);
                    index = right_child(index);
                }
                else{
                    break;
                }
            }
        }
        return data[n];
    }

};

template <typename T, int MAX_SIZE>
class minHeap: public heap<T, MAX_SIZE>{

    int compare(T left, T right){
        if(left < right)    return -1;
        else if(left > right)   return 1;
        else return 0;
    }
};

template <typename T, int MAX_SIZE>
class maxHeap: public heap<T, MAX_SIZE>{

    int compare(T left, T right){
        if(left < right)    return 1;
        else if(left > right)   return -1;
        else return 0;
    }
};

#endif