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
    list l1;
    l1.attachByValue(33);
    l1.attachByValue(67);
    l1.attachByValue(80);
    l1.attachByValue(90);
    l1.attachByValue(120);
    l1.attachByValue(130);
    l1.attachByValue(400);

    list l2;
    l2.attachByValue(45);
    l2.attachByValue(100);
    l2.attachByValue(250);
    l2.attachByValue(300);

    
    l1.insert(l2);
    l1.listOut();

}
