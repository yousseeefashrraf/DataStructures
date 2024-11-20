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
    
    void insert(list & l2){
        cNode * pTravl2 = l2.head;
        cNode * pTrav = head;
        cNode * pB;
        while (pTrav != NULL && pTravl2!=NULL) {
            if(pTrav -> info > pTravl2->info){
                l2.head = l2.head->pNext;
                pTravl2 -> pNext = pTrav;
                pB -> pNext = pTravl2;
                pTrav = pTravl2;
                pTravl2 = l2.head;
            } else {
                pB = pTrav;
                pTrav = pTrav->pNext;
            }

            

        }
        
        tail -> pNext = l2.head;
        tail = l2.tail;
        l2.head = l2.tail = NULL;
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
    int NC;
    cNode * pnn;
    int ct=1;
    cNode * pMaster;
    cin>>NC;
    pnn = new cNode();
    ct++;
    cNode * pB;
    
    cin>>pnn->info;
    l.attach(pnn);
    
    pB = pnn;
    for( ; ct<= NC;ct++){
        pMaster = new cNode();
        pMaster->pNext = pMaster->pDown = NULL;
        cin>>pMaster->info;
        for(int k =1; k<ct;k++){
            pnn = new cNode();
            pnn->pNext = pnn->pDown = NULL;
            cin>>pnn->info;
            if(pMaster->pDown == NULL){
                pMaster->pDown = pnn;
                pnn -> pNext = pnn;
            } else {
                pMaster ->pDown ->pNext -> pDown = pnn;
                pMaster -> pDown -> pNext = pnn;
            }
        }
        l.attach(pMaster);
        pB = pnn;
        for(int j=1; j< ct; j++){
            pMaster = new cNode();
            pMaster->pNext = pMaster->pDown = NULL;
            cin>>pMaster->info;
            for(int k = 1; k<ct;k++){
                pnn = new cNode();
                pnn->pNext = pnn->pDown = NULL;
                cin>>pnn->info;
                if(pMaster->pDown == NULL){
                    pMaster->pDown = pnn;
                    pnn -> pNext = pnn;
                } else {
                    pMaster ->pDown ->pNext -> pDown = pnn;
                    pMaster -> pDown -> pNext = pnn;
                }
            }
            pB->pNext = pMaster;
            pB = pnn;
            
        }

        
        
        
        pB = pMaster;
    }
        
    cNode * pTrav = l.head;
    cNode * pTrav2 = l.head;
    cNode * pTrav3 = l.head;
    
}

//4
//1
//2 3 4 5
//-1 -2 -3 -4 -5 -6 -7 -8 -9
//4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
