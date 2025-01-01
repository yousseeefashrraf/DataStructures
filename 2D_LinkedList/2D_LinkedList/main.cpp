#include <iostream>
using namespace std;

class node {
public:
    int val;
    node * next;
    node * up;
    
    node (){
        up = NULL;
        next = NULL;
    }
};

class list{
public:
    node * head;
    node * tail;
    list(){
        head = tail = NULL;
    }
    ~list(){
        node * pTrav = head;
        while(pTrav != NULL){
            head = pTrav->next;
            pTrav->next = NULL;
            delete pTrav;
            pTrav = head;
        }
    }
    
    int size(){
        int ct = 0;
        node * pTrav = head;
        while(pTrav != NULL){
            ct++;
            pTrav = pTrav->next;
        }
        return ct;
    }
    
    void attach(node * newNode){
        if (head == NULL){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    void attachByValue (int value){
        node * newNode = new node();
        newNode-> val = value;
        newNode->next = NULL;
        if (head == NULL){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    
    }
    void insert(int index, node * newNode){
        if(index == 0){
            newNode->next=head->next;
            head = newNode;
        }
            
        if (index>=size()-1){
            attach(newNode);
            return ;
        }
        int ct = 0;
        node * pTrav = head;
        node * pPrevious = NULL;
        while (ct<index+1 && pTrav != NULL) {
            ct++;
            pPrevious = pTrav;
            pTrav = pTrav->next;
        }
        newNode->next=pPrevious->next;
        pPrevious->next = newNode;
    }
    void dlt(int index){
        node * pTrav = head;
        node * pPrevious = NULL;
        int ct= 0;
        while (pTrav!=NULL) {
            if (ct==index)
                break;
            
            ct++;
            pPrevious = pTrav;
            pTrav = pTrav->next;
        }
        pPrevious->next=pTrav->next;
        pTrav->next=NULL;
        delete pTrav;
    }
    
    void copyAndPaste(list newList){
        node * pTrav = head;
        node * newNodeInNewList;
        
        while (pTrav!=NULL){
            newNodeInNewList = new node();
            newNodeInNewList->val= pTrav->val;
            newNodeInNewList->next=NULL;
            newList.attach(newNodeInNewList);
            pTrav = pTrav->next;
        }
    }
    
    void cutAndPaste(list &newList, int intervalStart = 0, int intervalEnd = 0){
        if (intervalEnd == 0){
            intervalEnd = size()-1;
        }

        
            node * pTrav = head;
            node * pStart=NULL;
            
            for (int i=0; i<intervalStart-1 && pTrav!=NULL;i++){
                pTrav = pTrav->next;
            }
            pStart=pTrav;

            for(int i = intervalStart; i<=intervalEnd && pTrav!=NULL; i++){
                pTrav = pTrav->next;
            }
        if(intervalStart==0 && intervalEnd>=size()-1){
            newList.head=head;
            newList.tail=tail;
            head = tail = NULL;
        } else if (intervalStart==0){
            head = pTrav->next;
            newList.attach(pStart->next);
            newList.tail=pTrav;
            pTrav->next = NULL;
        } else if (intervalEnd>=size()-1){
            newList.attach(pStart->next);
            newList.tail = tail;
            tail = pStart;
            pStart->next = NULL;

        } else {
            newList.attach(pStart->next);
            pStart->next = pTrav->next;
            newList.tail=pTrav;
            pTrav->next = NULL;
        }

        
        
    }
    void listOut (){
        
        node * pTrav = head;
        node * pTravUp = head->up;
        while (pTrav!=NULL) {
            pTravUp = pTrav->up;
                while(pTravUp!=NULL){
                    if (pTrav->up == pTravUp){
                        cout<<"\n";
                    }
                    if (pTravUp->up != NULL){
                        cout<<pTravUp->val<<"\n|\n^\n";
                    } else {
                            cout<<pTravUp->val<<"\n";
                    }
                    pTravUp = pTravUp->up;
                }
            cout<<pTrav->val<<" ";

            pTrav=pTrav->next;
            }
            

        
    }
    
    void Attach (node * pnn1, node * pnn2, int flag){
        if (flag == 1){
            if (head->up == NULL){
                head -> up = pnn1;
                head->up->next = pnn1;
            } else {
                head->up->next->up=pnn1;
                head->up->next = pnn1;
            }
            if(tail->up == NULL){
                tail -> up = pnn2;
                tail->up->next = pnn2;
            } else {
                tail->up->next->up=pnn2;
                tail->up->next = pnn2;
            }
        }
        
        if (flag == 2){
            attach(pnn1);
            if(tail->up == NULL){
                tail -> up = pnn2;
                tail->up->next = NULL;
            } else {
                tail->up->next->up=pnn1;
                tail->up->next = NULL;
            }
            
        }
    }
};


int main() {
    list l1;
    l1.attachByValue(5);
    l1.attachByValue(10);
    l1.attachByValue(11);
    l1.attachByValue(12);
    l1.attachByValue(13);
    cout<<"List 1: ";
    l1.listOut();
    cout<<"\n\n\n";
    node * p;
    node * p2;
    for(int i=4; i>=2; i--){
        p = new node();
        p->next = NULL;
        p->val = i;
        p2 = new node();
        p2->next = NULL;
        p2->val = i+10;
        
        p->up= NULL;
        p2->up = NULL;
        
        l1.Attach(p, p2, 1);
    }
    
    for(int i=0; i<1; i++){
        p = new node();
        p->next = NULL;
        p->val = 15;
        p2 = new node();
        p2->next = NULL;
        p2->val = 16;
        
        p->up= NULL;
        p2->up = NULL;
        
        l1.Attach(p, p2, 2);
    }

    l1.listOut();
}
