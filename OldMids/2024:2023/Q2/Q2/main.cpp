#include <iostream>
using namespace std;
class cNode {
public:
    int info;
    cNode * pNext;
    cNode * pDown;
    int val;

};
class list{
public:
    cNode * head;
    cNode * tail;
    cNode * pExtra;

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
    void attachAti(int value, int i, int f){
        cNode * pnn;
        pnn = new cNode();
        pnn -> pNext = NULL;
        pnn -> pDown = NULL;
        
        pnn -> info = value;
        if(f==1){
            if (head == NULL){
                head = pnn;
                tail = pnn;
            } else {
                tail->pNext = pnn;
                tail = pnn;
            }
           pnn -> val = 0;
        }
        cNode * pTrav ;
        if(f==2){
            pTrav = head;
            
            for(int k = 0; k < i; k++){
                pExtra = pTrav;
                pTrav = pTrav->pNext;
            }
            
            if(pTrav -> pDown == NULL){
                pnn -> pNext = pnn;
                pnn->pNext = pnn;
                pTrav -> val++;
            } else {
                pTrav -> val++;
                if(pTrav->val == 2){
                    pnn->pNext = pTrav ->pDown;
                }
                pTrav -> pDown -> pNext -> pDown = pnn;
                pTrav -> pDown ->pNext = pnn;
                
                if(pTrav->val > 2 && pTrav->val % 2 ==0){
                    pTrav -> pDown -> pDown -> pNext = pTrav-> pDown -> pDown -> pNext -> pDown;
                }
                
                cNode * pnn2;
                pnn2 = new cNode();
                pnn2 -> info = -1;
                pnn2->pNext = NULL;
                pnn2->pDown = NULL;
                
                if(pExtra -> pDown -> pDown -> pNext -> pDown == pExtra -> pDown->pDown ){
                    pnn2 -> pNext = pExtra -> pDown -> pDown ->pNext;
                }
                
                pnn2->pDown=pExtra -> pDown -> pDown -> pNext ->pDown;
                pExtra -> pDown -> pDown -> pNext -> pNext -> pDown=pnn2;
                pExtra -> val ++;
                
                if( pExtra->val % 2 ==0){
                    pExtra -> pDown -> pDown -> pNext = pExtra -> pDown -> pDown -> pNext -> pDown;
                }
            }
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

int main(){
    list l;
    l.attachAti(70, 1, 1);
    l.attachAti(40, 1, 1);
    l.attachAti(30, 1, 1);
    l.attachAti(22, 1, 1);
    int i = 0;
    cNode * pTrav = l.head;
    while(pTrav -> pNext != NULL && i!=2){
        
        pTrav = pTrav->pNext;
        i++;
    }
    cNode * pnn;
    pnn = new cNode();
    pnn -> info = 43;
    pnn -> pNext = NULL;
    pTrav -> pDown = pnn;
    pnn = new cNode();
    pnn -> info = 44;
    pnn -> pNext = NULL;
    pTrav -> pDown -> pDown = pnn;
    
    
    l.attachAti(33, 3, 2);
    cNode * pTrav1 = l.head;
    cNode * pTrav2 = l.head;
    while(pTrav1 != NULL){
        pTrav2 = pTrav1;
        while (pTrav2!=NULL) {
            cout<<pTrav2->info<<" ";
            pTrav2 = pTrav2->pNext;
        }
        cout<<endl;
        pTrav1 = pTrav1->pDown;
    }
}
