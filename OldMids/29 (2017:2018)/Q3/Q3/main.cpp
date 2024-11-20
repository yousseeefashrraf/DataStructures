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


int main(){
    list clist;
    int N;
    cNode * pMaster;
    cNode * pnn;
    cNode * pb=NULL;
    cNode * bPrev = NULL;
    cNode * pCatch ;
    int flag = 1;
    int ct = 0;
    N=9;
    for(int i = N; i>0;i-=3){
        
        for(int rounds = 0; rounds<3; rounds++){
            pMaster = new cNode();
            pMaster-> info = ct++;
            pb=pMaster;
            for(int k = 1; k<i; k++){
                pnn = new cNode;
                pnn->info = ct++;
                if(pMaster->pDown == NULL){
                    pMaster->pDown = pnn;
                    pnn -> pNext = pnn;
                } else{
                    pMaster->pDown->pNext->pDown = pnn;
                    if(i<=3 && rounds == 2){
                        pnn->pNext = pb;
                        pb = pnn;
                    } else{
                        pMaster->pDown->pNext = pnn;
                    }
                    if(rounds == 2 && k==i-4){
                        pCatch = pnn;
                    }
                    if(rounds == 2 && k > i-4 && i!=3){
                        pnn->pNext = pb;
                    }
                    if(k==(i-1)){
                        if(bPrev != NULL){
                            bPrev->pNext = pnn;
                            bPrev = pnn;
                        } else{
                            bPrev = pnn;
                        }

                    }
                }
                
                pb = pnn;
            }
            bPrev = pnn;
            clist.attach(pMaster);
        }
        bPrev = pCatch;
    }
    clist.tail->pDown->pNext = clist.tail;
    cNode * pTrav = clist.head->pDown->pNext;
    ct = 0;
    int i =0;
    while(pTrav != NULL){
        pTrav->info = i;
        if(ct<(2*N-1)/2){
            i++;
        } else {
            i--;
        }
        pTrav = pTrav->pNext;
        ct++;
    }
    
    pTrav = clist.head->pDown->pNext;
    while(pTrav != NULL){
        cout<<pTrav->info<<" ";
        pTrav = pTrav->pNext;
        
    }
    pTrav = clist.head->pDown->pNext;
    cStack x;
    for(i = 0; i<(2*N-1)/2; i++){
        pnn = new cNode();
        pnn->info = pTrav->info;
        x.push(pnn);
        pTrav = pTrav->pNext;
    }
    if((2*N-1)%2 != 0){
        pTrav = pTrav->pNext;
    }
    int isMirror = 1;
    for(i = 0; i<(2*N-1)/2; i++){
        if(x.head->info != pTrav->info){
            isMirror = 0;
        }
        delete x.pop();
        pTrav = pTrav->pNext;
    }
    
    isMirror ? cout<<"The list is mirrored\n" : cout<<"The list is NOT mirrored\n";
    
    
}
