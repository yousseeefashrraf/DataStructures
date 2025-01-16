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
    
    void displayP(cTNode * pTrav, cTNode * pv2){
        if(pTrav == NULL){
            return ;
        }

        
        if(pv2->info>pTrav->info){
            displayP(pTrav->pRight, pv2);

        } else {
            displayP(pTrav->pLeft, pv2);
        }
        
        if(pTrav==pv2->pLeft || pTrav==pv2->pRight){
            return ;
        }
        cout<<pTrav->info<<", ";


    }
    void dd(int v1, int v2){
        
        cTNode * pTrav = root;
        
        while (pTrav!=NULL) {
            cTNode * pv1 = root;
            cTNode * pv2 = pTrav;
            
            while (pv1 != NULL && pv2 != NULL && pv1->info != v1) {
                
                if(v1 > pv1->info){
                    pv1 = pv1->pRight;
                    pv2 = pv2->pRight;
                }else{
                    pv1 = pv1->pLeft;
                    pv2 = pv2->pLeft;
                }
                
            }
            if(pv1->info == v1 && pv2->info == v2){
                displayP(pTrav, pv2);
            }
            
            if(v2>pTrav->info){
                pTrav=pTrav->pRight;
            } else {
                pTrav=pTrav->pLeft;
                
            }
        }
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


int main(){
    
    binaryTree t;
    t.CreateAndInsert(500);
    t.CreateAndInsert(200);
    t.CreateAndInsert(90);
    t.CreateAndInsert(70);
    t.CreateAndInsert(86);
    t.CreateAndInsert(72);
    t.CreateAndInsert(84);
    t.CreateAndInsert(75);
    t.CreateAndInsert(73);
    t.CreateAndInsert(85);
    t.CreateAndInsert(280);
    t.CreateAndInsert(250);
    t.CreateAndInsert(260);
    t.CreateAndInsert(275);
    t.CreateAndInsert(277);
    t.CreateAndInsert(276);
    t.CreateAndInsert(800);
    t.CreateAndInsert(910);
    t.CreateAndInsert(900);
    t.CreateAndInsert(850);
    t.CreateAndInsert(950);
    t.CreateAndInsert(1200);
    t.CreateAndInsert(960);
    t.CreateAndInsert(1100);
    t.CreateAndInsert(980);
    t.CreateAndInsert(990);
    t.CreateAndInsert(1000);
    t.CreateAndInsert(1020);
    t.CreateAndInsert(995);
    t.CreateAndInsert(1300);
    
    t.dd(275, 1000);
}
