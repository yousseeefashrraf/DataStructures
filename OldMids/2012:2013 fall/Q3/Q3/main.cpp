#include <iostream>
using namespace std;
class cNode {
public:
    int info;
    cNode * pNext;
    cNode * pDown;

};
class list{
public:
    cNode * head;
    cNode * tail;
    list(){
        head = tail = NULL;
    }
    ~list(){
        cNode * pTrav = head;
        while(pTrav != NULL){
            head = pTrav->pNext;
            pTrav->pNext = NULL;
            delete pTrav;
            pTrav = head;
        }
    }

    
    void attach(cNode * newcNode){
        if (head == NULL){
            head = newcNode;
            tail = newcNode;
        } else {
            tail->pNext = newcNode;
            tail = newcNode;
        }
    }
    void attachByValue (int value){
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
    
    void listOut (){
        cNode * pTrav = head;
        cout<<"[";
        while (pTrav!=NULL) {
            if (pTrav->pNext!=NULL){
                cout<<pTrav->info<<" ,";
            } else { cout<<pTrav->info; }
            pTrav=pTrav->pNext;
        }
        cout<<"]\n";
    }
    };
class cStack{
public:
    cNode * head;
    cStack(){
        head = NULL;
    }
    void push (cNode * pnn){
        pnn -> pNext = head;
        head = pnn;
    }
    
    cNode * pop(){
        cNode * pTrav = head;
        if(pTrav == NULL){
            return NULL;
        }
        head = head -> pNext;
        pTrav->pNext = NULL;
        return pTrav;
    }
    
    
};

int main (){
    list l[5];
    l[0].attachByValue(14);
    l[0].attachByValue(32);
    l[0].attachByValue(0);
    l[0].attachByValue(0);
    l[0].attachByValue(41);
    l[0].attachByValue(20);
    l[0].attachByValue(30);
    l[0].attachByValue(49);
    l[0].attachByValue(42);
    
    l[1].attachByValue(37);
    l[1].attachByValue(15);
    l[1].attachByValue(23);
    l[1].attachByValue(43);
    l[1].attachByValue(44);
    l[1].attachByValue(28);
    l[1].attachByValue(0);
    l[1].attachByValue(0);
    l[1].attachByValue(0);
    
    l[2].attachByValue(21);
    l[2].attachByValue(29);
    l[2].attachByValue(0);
    l[2].attachByValue(0);
    l[2].attachByValue(38);
    l[2].attachByValue(13);
    l[2].attachByValue(22);
    l[2].attachByValue(46);
    l[2].attachByValue(0);
    
    l[3].attachByValue(33);
    l[3].attachByValue(129);
    l[3].attachByValue(134);
    l[3].attachByValue(126);
    l[3].attachByValue(238);
    l[3].attachByValue(0);
    l[3].attachByValue(0);
    l[3].attachByValue(0);
    l[3].attachByValue(150);
    
    l[4].attachByValue(210);
    l[4].attachByValue(0);
    l[4].attachByValue(0);
    l[4].attachByValue(260);
    l[4].attachByValue(380);
    l[4].attachByValue(130);
    l[4].attachByValue(0);
    l[4].attachByValue(0);
    l[4].attachByValue(215);
    
    cNode * headH = NULL;
    cNode * pBack = NULL;
    cNode * pFirstE= NULL, * pSecodS = NULL;
    int flag=0;
    list list2;
    cNode * pnn;
    int ct = 0;
    for(int i = 0; i<5; i++){
        cNode * pTrav = l[i].head;
        
        while (pTrav != NULL) {
            if(pTrav->info == 0){
                if(!flag){
                    pFirstE = pTrav;
                    if(i==0){
                        headH = pFirstE;
                    }
                }
                if(flag && pSecodS == NULL){
                    pSecodS = pTrav;

                }
            } 
            else {
                if(pSecodS == NULL && pFirstE != NULL){
                    flag = 1;
                } else {
                    flag = 0;
                }
            }
            if(pFirstE != NULL && pSecodS != NULL){
                cNode * pTravtwo = pFirstE;
                while(pTravtwo != NULL){
                    cout<< pTravtwo->info<<" ";
                    pTravtwo = pTravtwo->pNext;
                }
                cout<<"\n";
                pFirstE->pDown = pSecodS;
                pFirstE = pSecodS;
                pSecodS = NULL;

                flag = 0;
                ct++;
            }

            pTrav = pTrav->pNext;
        }
    }
    

    cout<<ct;
}
