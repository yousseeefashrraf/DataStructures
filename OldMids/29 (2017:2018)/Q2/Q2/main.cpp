#include <iostream>
using namespace std;
class cNode {
public:
    int info;
    cNode * pNext;
    cNode * pExtra;

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
        newNode->pExtra = NULL;
        
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
    
    cNode * flip (int val){
        cNode * pTrav = head;
        cNode * pB = NULL;
        cNode * pS = NULL;
        cNode * pE = NULL;
        int ct = 0;
        cNode * pMid;
        cNode * pBCurrent;
        while (pTrav != NULL) {
            if(pTrav -> info == val){
                if(pS==NULL){
                    pS = pTrav;
                    pTrav->pExtra = pB;
                    pBCurrent = pTrav;
                    pMid = pTrav;

                } else {
                    pE = pTrav;
                    pTrav->pExtra = pB;
                    pBCurrent->pExtra->pExtra = pTrav;
                    pBCurrent = pTrav;
                    if(ct%2 == 0){
                        pMid = pMid -> pExtra -> pExtra;
                    }
                    ct++;
                }
            }
            pB = pTrav;
            pTrav = pTrav -> pNext;
        }
        cNode * pHead = pMid->pNext;
        if(head == pS){
            head = pE -> pNext;
        } else{
            pS->pExtra->pNext = pE->pNext;
        }
        if(tail == pE){
            tail = pS->pExtra;
        }
        
        pE->pNext = pMid;
        
        pMid->pNext= pS;
        pMid->pExtra->pNext = NULL;
        
        
        return pHead;
    }
};

int main() {
    list l;
    l.attachByValue(15);
    l.attachByValue(70);
    l.attachByValue(33);
    l.attachByValue(10);
    l.attachByValue(12);
    l.attachByValue(10);
    l.attachByValue(40);
    l.attachByValue(31);
    l.attachByValue(17);
    l.attachByValue(10);
    l.attachByValue(50);
    l.attachByValue(10);
    l.attachByValue(60);
    l.attachByValue(80);
    l.attachByValue(36);
    l.attachByValue(10);
    l.attachByValue(10);
    l.attachByValue(14);
    l.attachByValue(6);
    l.attachByValue(10);
    l.attachByValue(2);
    l.attachByValue(8);
    list f;
    f.head = l.flip(10);
    f.listOut();
}
