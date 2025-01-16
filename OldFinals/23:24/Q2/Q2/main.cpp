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
    void check(){
        cTNode * pTrav = root;
        cTNode * pCatch;
        cTNode * pStart;
        int flag;
        int ct=0;
        int max = -99999;
        while (pTrav -> pRight != NULL || pTrav-> pLeft != NULL) {
            if(pTrav -> pRight != NULL && pTrav-> pLeft != NULL){
                return ;
            } else {
                ct = 0;
                if(pTrav -> pRight != NULL){
                    pCatch = pTrav;
                    while (pTrav->pRight!=NULL) {
                        ct++;
                        
                        pTrav = pTrav->pRight;
                    }
                } else {
                    pCatch = pTrav;
                    while (pTrav->pLeft!=NULL) {
                        ct++;
                        
                        pTrav = pTrav->pLeft;
                    }
                }
                
                if(ct > max){
                    max = ct;
                    pStart = pCatch;
                }
            }
        }
        
        if(pStart->pLeft!=NULL){
            flag = 0;
        } else {
            flag = 1;
        }
        
        display(pStart, flag);
    }

};
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
    void attach(cNode * newcNode){
        if (head == NULL){
            head = newcNode;
            tail = newcNode;
        } else {
            tail->pNext = newcNode;
            tail = newcNode;
        }
    }
    
    
    };
int main() {
    binaryTree t;
    t.CreateAndInsert(130);
    t.CreateAndInsert(300);
    t.CreateAndInsert(700);
    t.CreateAndInsert(680);
    t.CreateAndInsert(670);
    t.CreateAndInsert(660);
    t.CreateAndInsert(130);
    t.CreateAndInsert(350);
    t.CreateAndInsert(400);
    t.CreateAndInsert(500);
    t.CreateAndInsert(490);
    t.CreateAndInsert(480);
    t.CreateAndInsert(470);
    t.CreateAndInsert(440);
    t.CreateAndInsert(420);
    t.CreateAndInsert(425);

    t.check();
    cout<<endl;

}
