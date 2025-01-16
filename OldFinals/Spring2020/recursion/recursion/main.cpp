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

void copyAndPasteN(cNode * pTrav, int N, list &l, int & f, cNode *&pTail, cNode * &pS, int & ct){
    if(pTrav == NULL){ f=1;  return;}
    copyAndPasteN(pTrav->pNext, N, l,f,pTail, pS,ct );
    
    if(f){
        ct++;
        
        if(ct<=N){
            cNode * pnn = new cNode();
            pnn->info = pTrav->info;
            pnn->pNext = NULL;
            if(pS==NULL){
                pS = pTail = pnn;
                
            } else {
                pnn->pNext = pS;
                pS = pnn;
            }
            }
        if(ct==N){
            pTail->pNext = l.head;
            l.head = pS;
        }
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
    cNode * pTail = NULL;
    cNode * pS = NULL;
    int ct = 0;
    copyAndPasteN(pTrav, 3, l, f, pTail, pS, ct);
    

}
