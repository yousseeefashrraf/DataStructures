#include <iostream>
using namespace std;

class cNode {
public:
    int info;
    cNode * pNext;


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

    
    void attach(int val){
        cNode * newcNode = new cNode();
        newcNode->pNext = NULL;
        newcNode->info = val;
        if (head == NULL){
            head = newcNode;
            tail = newcNode;
        } else {
            tail->pNext = newcNode;
            tail = newcNode;
        }
    }
    
    
    };

void displayInTwo(cNode * pTrav, int i, int len, cNode *& pCatch, int f){
    if(pTrav == NULL){return;}
    if(pTrav == pCatch && f==2){return;}
    if(f){cout<<pTrav->info<<"<<";}
    
    displayInTwo(pTrav->pNext, i+1, len, pCatch,f);
    if(i==len/2 && !f){
        pCatch = pTrav;
        displayInTwo(pTrav, i, len, pCatch,1);

    }
    
    if(!i && !f) {
        displayInTwo(pTrav, i, len, pCatch,2);
    }
}
int main(){
    
    list l;
    l.attach(77);
    l.attach(80);
    l.attach(18);
    l.attach(25);
    l.attach(45);
    l.attach(12);
    l.attach(7);
    l.attach(32);

    cNode * pTrav = l.head;
    int f=0;
    cNode * pCatch = NULL;
    displayInTwo(l.head, 0, 8, pCatch, f);
}
