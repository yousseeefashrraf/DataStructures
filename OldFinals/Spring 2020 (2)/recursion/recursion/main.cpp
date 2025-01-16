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
    void attach2(cNode * newcNode){

        if (head == NULL){
            head = newcNode;
            tail = newcNode;
        } else {
            tail->pNext = newcNode;
            tail = newcNode;
        }
    }

    
    };

void copyAndPasteN(cNode * pTrav, int N, list &l, cNode *&pe, cNode * &ps, int & ct){
    if(pTrav == NULL){
        return ;
    }
    
    ct++;
        
    if(ct<=N){
        cNode * pnn = new cNode();
        pnn->info = pTrav->info;
        pnn->pNext = NULL;
        l.attach2(pnn);
        
        }

    
    copyAndPasteN(pTrav->pNext, N, l,pe, ps,ct );

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
    cNode * pTail = NULL;
    cNode * pS = NULL;
    int ct = 0;
    copyAndPasteN(pTrav, 3, l, pTail, pS, ct);
    l.listOut();

}
