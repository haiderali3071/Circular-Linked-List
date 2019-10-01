//
//  main.cpp
//  Circular Linked List
//
//  Created by Haider Ali on 10/1/19.
//  Copyright © 2019 Haider Ali. All rights reserved.
//

#include <iostream>
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

};

int main() {
    
    
}
