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
    cNode * pExtra;
    int v1, v2;
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

    void attach_when(int val){
        cNode * pnn = new cNode();
        pnn->info = val;
        pnn->pNext = NULL;
        pnn->pDown = NULL;
        
        if(head == NULL){
            head = pnn;
            tail = pnn;
            pExtra = pnn;
            v1 = 1;
            v2 = 4;
        } else {
            if(v1<=v2/2){
                pExtra = tail;
            }
            tail -> pNext = pnn;
            tail = pnn;
            v1++;
        }

        if(v1 == v2){

            v1 = v2/2;
            pExtra->pNext->pDown = head;
            head = pExtra ->pNext;
            pExtra->pNext = NULL;
            pExtra = head;
            v2+=2;
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
    list l;
    l.attach_when(15);
    l.attach_when(70);
    l.attach_when(33);
    l.attach_when(10);
    l.attach_when(40);
    l.attach_when(60);
    l.attach_when(50);
    l.attach_when(25);
    l.attach_when(60);
    l.attach_when(12);
    l.attach_when(39);
    l.attach_when(13);
    l.attach_when(28);
    l.attach_when(11);
    l.attach_when(31);
    l.attach_when(14);
    l.attach_when(84);
    l.attach_when(91);
    l.attach_when(53);
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
