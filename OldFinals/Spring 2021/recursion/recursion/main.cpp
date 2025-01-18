#include <iostream>
using namespace std;

class cTNode{
public:
    int info;
    cTNode * pRight;
    cTNode * pLeft;
};
class binaryTree{
public:
    cTNode * root;
    binaryTree(){
        root = NULL;
    }
    void insert(cTNode * pnn){
        cTNode * pBack = NULL;
        cTNode * pTrav = root;
        if(pTrav == NULL){
            root = pnn;
        } else {
            while (pTrav != NULL) {
                pBack = pTrav;
                if(pTrav->info > pnn->info){
                    pTrav = pTrav->pLeft;
                } else {
                    pTrav = pTrav->pRight;
                }
            }
        }
    }
    
    void CreateAndInsert(int val){
        cTNode * pnn;
        pnn = new cTNode();
        pnn ->pLeft = pnn->pRight = NULL;
        pnn -> info = val;
        cTNode * pBack = NULL;
        cTNode * pTrav = root;
        if(pTrav == NULL){
            root = pnn;
        } else {
            while (pTrav != NULL) {
                pBack = pTrav;
                if(pTrav->info > pnn->info){
                    pTrav = pTrav->pLeft;
                } else {
                    pTrav = pTrav->pRight;
                }
            }
            
            if(pnn->info > pBack->info){
                pBack->pRight = pnn;
            } else {
                pBack->pLeft = pnn;

            }
        }
    }
    void display(cTNode * pTrav, int flag){
        if (pTrav == NULL)
            return ;
            
        if(!flag){
            display(pTrav->pLeft, flag);
        } else {
            display(pTrav->pRight, flag);
        }
        
        cout<<pTrav->info<<" <- ";
    }
    

};

int howMany(cTNode * pTrav){
    if(pTrav == NULL){
        return 0;
    }
    
    if(pTrav->pLeft == NULL && pTrav->pRight == NULL){
        return 1;
    }
    int ct = 0;
    ct += howMany(pTrav->pLeft);
    ct += howMany(pTrav->pRight);
    return ct;
}

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

void doIt(cNode * pTrav, cNode * pB, int & f, int & ct, int & tot){
    if(pTrav == NULL){
        f=1;
        return ;
    }
    
    doIt(pTrav->pNext, pTrav, f, ct, tot);
    if(f){
        ct++;
    }
    
    if(ct<=2){
        tot += pTrav->info;
    } else {
        if(pTrav->info == tot){
            pB->pNext = pTrav->pNext;
            pTrav->pNext = NULL;
            delete pTrav;
        }
    }
}
int main(){
    
    list l;
    l.attach(77);
    l.attach(80);
    l.attach(75);
    l.attach(20);
    l.attach(30);
    l.attach(75);
    l.attach(15);
    l.attach(60);
    l.listOut();
    int f =0, ct=0, tot=0;
    doIt(l.head, NULL, f, ct, tot);
    l.listOut();
    
}
