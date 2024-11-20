
#include "SLD.hpp"
#include <iostream>



    list::list(){
        head = tail = NULL;
    }
    list::~list(){
        cNode * pTrav = head;
        while(pTrav != NULL){
            head = pTrav->pNext;
            pTrav->pNext = NULL;
            delete pTrav;
            pTrav = head;
        }
    }

    
    void list::attach(cNode * newcNode){
        if (head == NULL){
            head = newcNode;
            tail = newcNode;
        } else {
            tail->pNext = newcNode;
            tail = newcNode;
        }
    }
    void list::attachByValue (int value){
        cNode * newNode = new cNode();
        newNode-> info = value;
        newNode->pNext = NULL;
        newNode->pDown = NULL;
        
        if (head == NULL){
            head = newNode;
            tail = newNode;
        } else {
            tail->pNext = newNode;
            tail = newNode;
        }
    
    }
    
    void list::listOut (){
        cNode * pTrav = head;
        std::cout<<"[";
        while (pTrav!=NULL) {
            if (pTrav->pNext!=NULL){
                std::cout<<pTrav->info<<" ,";
            } else { std::cout<<pTrav->info; }
            pTrav=pTrav->pNext;
        }
        std::cout<<"]\n";
    }

    cStack::cStack(){
        head = NULL;
    }
    void cStack:: push (cNode * pnn){
        pnn -> pNext = head;
        head = pnn;
    }
    
    cNode * cStack:: pop(){
        cNode * pTrav = head;
        if(pTrav == NULL){
            return NULL;
        }
        head = head -> pNext;
        pTrav->pNext = NULL;
        return pTrav;
    }



