#include <iostream>
#include <stdexcept>

#ifndef LINK_H
#define LINK_H

//Linkedlist of elements of type T
template<typename T>
class linkedlist{
    class Node{
    public:
        T data;
        Node *next;

        Node(T val){
            data = val;
            next = NULL;
        }
    };

    Node* head;

    void helperIns(Node** nodes, T val, int pos){
        if(pos == 0){
            Node* temp = new Node(val);
            temp->next = *nodes;
            *nodes = temp;
        }
        else{
            if(!*nodes)  throw std::runtime_error("Invalid position for insert!\n");
            else helperIns(&((*nodes)->next), val, pos - 1);
        }
    }

    void helperDel(Node** list, int pos){
        if(!(*list))    throw std::runtime_error("Invalid position for delete!\n");
        if(pos == 0)
            *list = (*list)->next;
        else
            helperDel(&((*list)->next), pos - 1);
    }

    T helperAt(Node* head, int pos){
        if(!head)   throw std::runtime_error("Invalid position for at!\n");
        if(pos == 0)
            return head->data;
        else
            return helperAt(head->next, pos - 1);
    }

    bool helperIn(T val){
        if(!head) return false;
        if(head->data == val)  return true;
        else return helperIn(head->next, val);
    }
public:
    //Create an empty linkedlist
    linkedlist(){
        head = NULL;
    }

    //Create a node with data val
    linkedlist(T val){
        head = new Node(val);
    }

    //insert data val at position pos, throws runtime_error when pos is invalid
    void insert(T val, int pos){
        if(pos < 0)  throw std::runtime_error("Invalid position for insert!\n");
        else helperIns(&head, val, pos);
    }

    bool in(T val){
        return helperIn(val);
    }
    //deletes the node at position pos, throws runtime_error when pos is invalid
    void del(int pos){
        if(pos < 0)   throw std::runtime_error("Invalid position for del!\n");
        else helperDel(&head, pos);
    }

    //returns the data at position pos, throws runtime_error when pos is invalid
    T at(int pos){
        if(pos < 0)   throw std::runtime_error("Invalid position for at!\n");
        return helperAt(head, pos);
    }
};

#endif