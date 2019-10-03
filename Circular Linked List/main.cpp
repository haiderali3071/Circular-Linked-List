//
//  main.cpp
//  Circular Linked List
//
//  Created by Haider Ali on 10/1/19.
//  Copyright © 2019 Haider Ali. All rights reserved.
//

#include <iostream>
//#include "unistd.h"

using namespace std;

class Node {
  
public:
    int data;
    Node *next;
};

class CircularLinkedList {
    
    Node *last;
    Node *ploc;
    Node *loc;
 
public:
    
    CircularLinkedList() {
        
        last = NULL;
        ploc = NULL;
        loc = NULL;
    }
    
    bool isEmpty() {
        return last == NULL;
    }
    
    void insertAtFront(int value) {
       
        Node *nn = new Node();
        nn->data = value;
        
        if(!isEmpty()) {
            
            nn->next = last->next;
            last->next = nn;
        }
        else{
            
            last = nn;
            last->next = last;
        }
    }
    
    void insertAtEnd(int value) {
        
        Node *nn = new Node();
        nn->data = value;
        
        if(!isEmpty()) {
            
            nn->next = last->next;
            last->next = nn;
            last = nn;
        }
        else{
            last = nn;
            last->next = last;
        }
    }
    
    void print() {
        
        
        if(!isEmpty()) {
         Node *temp = last->next;
            do{
                cout<<temp->data<<endl;
                temp = temp->next;
            }while(temp != last->next);
        }
       
    }
    
    void search(int value) {
        
        if (isEmpty()) {
            return;
        }
        ploc = last;
        loc = last->next;

        do {
            if(loc->data<value){
               
                ploc = loc;
                loc = loc->next;
            }
            else {
                break;
            }
        } while (loc != last->next);

        if(loc->data != value) {
            loc = NULL;
        }
        
    }
    
    void insertSorted(int value) {
        
        if(isEmpty()) {
            insertAtEnd(value);
            return;
        }
        search(value);
        
        if(loc != NULL) {
            cout<<"Duplication is not allowed \n";
            return;
        }
        Node *nn = new Node();
        nn->data = value;
    
        if (ploc == last) {
//             if true then there are two possibilities either we insert value at end or at first position of the list.
            if(value>last->data) {
//                insert at the end of list
               nn->next = last->next;
               last->next = nn;
               last = nn;
            }
            else {
//                insert at the top of list
                nn->next = last->next;
                last->next = nn;
            }
        }
        else {
            nn->next = ploc->next;
            ploc->next = nn;
        }
    
    }
    
    
    void deleteValue(int value) {
        
        if(isEmpty()){
            return;
        }
        search(value);
        
        if (loc == NULL) {
            
            cout<<"value is not found";
        }
        else if(loc == last) {
            
            ploc->next = last->next;
            last = ploc;
            delete loc;
            loc = NULL;
        }
        else {
           
            ploc->next = loc->next;
            delete loc;
            loc = NULL;
        }
    }
    
    void destroyList() {
        
        if(isEmpty()){
            return;
        }
        Node *temp;
        
            while(last->next != last){
                temp = last->next;
                last->next = last->next->next;
                delete temp;
            }
          
            delete last;
            last = NULL;
            temp = NULL;
        
    }
    
};
