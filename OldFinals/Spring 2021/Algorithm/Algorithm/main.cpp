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
    void display(cTNode * pTrav){
        if (pTrav == NULL)
            return ;
            
        
            display(pTrav->pLeft);
            cout<<pTrav->info<<" <- ";

            display(pTrav->pRight);
        
        
    }
    
    void removeMyBrother(int v){
        cTNode * pTrav = root; cTNode * pBack = NULL;
        
        while (pTrav != NULL && pTrav->info != v) {
            pBack = pTrav;
            if(v > pTrav->info){
                pTrav = pTrav->pRight;
            } else {
                pTrav = pTrav->pLeft;
            }
        }
        
        if(pTrav != NULL){
            if(v<pBack->info){
                if(pBack->pRight->pLeft == NULL && pBack->pRight->pRight == NULL){
                    delete pBack->pRight;
                    pBack->pRight = NULL;
                }

            } else {
                if(pBack->pLeft->pLeft == NULL && pBack->pLeft->pRight == NULL){
                    delete pBack->pLeft;
                    pBack->pLeft = NULL;
                }

            }
        }
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
    
    binaryTree t;
    t.CreateAndInsert(20);
    t.CreateAndInsert(10);
    t.CreateAndInsert(8);
    t.CreateAndInsert(11);
    t.CreateAndInsert(30);
    t.display(t.root);
    t.removeMyBrother(8);
    cout<<endl;
    t.display(t.root);

}
