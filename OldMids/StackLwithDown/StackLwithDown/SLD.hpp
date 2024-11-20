//
//  StackLwithDown.hpp
//  StackLwithDown
//
//  Created by Youssef Ashraf on 18/11/2024.
//

#ifndef StackLwithDown_
#define StackLwithDown_

/* The classes below are exported */
#pragma GCC visibility push(default)

class cNode{
public:
    int info;
    cNode * pNext;
    cNode * pDown;
    
};
class list{
public:

    cNode * head;
    cNode * tail;
    list();
    ~list();
    void attach(cNode *);
    void attachByValue(int);
    void listOut();
};

class cStack{
public:

    cNode * head;
    cStack();
    ~cStack();
    void push(cNode *);
    cNode* pop();
};


#pragma GCC visibility pop
#endif
