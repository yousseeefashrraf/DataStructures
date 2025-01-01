#include <iostream>
using namespace std;
class node {
public:
    int val;
    node * next;
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
        cout<<"[";
        while (pTrav!=NULL) {
            if (pTrav->next!=NULL){
                cout<<pTrav->val<<" ,";
            } else { cout<<pTrav->val; }
            pTrav=pTrav->next;
        }
        cout<<"]\n";
    }
    
};

void main2() {
    list l1;
    l1.attachByValue(15);
    l1.attachByValue(16);
    l1.attachByValue(17);
    l1.attachByValue(8);
    l1.attachByValue(9);
    l1.attachByValue(10);
    l1.attachByValue(80);
    l1.attachByValue(45);
    cout<<"List 1: ";
    l1.listOut();
    list l2;
    
    l1.cutAndPaste(l2,2,3);
    cout<<"List 1: ";
    l1.listOut();
    cout<<"List 2: ";
    l2.listOut();
    
    list l3;
    l1.cutAndPaste(l3,3);
    cout<<"List 1: ";
    l1.listOut();
    cout<<"List 3: ";
    l3.listOut();
}

int main() {
    list l1;
    list l2;
    list l3;
    node * trav;
    int n;
    cout<<"Enter nodes in list: ";
    cin>>n;
    for(int i=0; i<n;i++){
        trav = new node();
        trav->next=NULL;
        cout<<"Enter node number "<<i<<": ";
        cin>>trav->val;
        l1.attach(trav);
    }
    
    trav = l1.head;
    node * travBack = NULL;
    node * cpy;
    while(trav != NULL){
        for(int i=0; i<4;i++){
            cpy = new node();
            cpy->next=NULL;
            cpy->val = trav->val;
            l2.attach(cpy);
            travBack = trav;
            trav = trav->next;
        }
       
        if (trav->next != NULL){
            for (int i=0; i<3; i++){
                trav = trav->next;
            }
            if (trav->next !=NULL){
                travBack->next = trav->next;
                trav->next = NULL;
                l3.attach(travBack->next);
                l3.tail = trav;

            } else {
                l3.attach(travBack->next);
                travBack->next=NULL;
                l1.tail = travBack;
            }
            trav = l1.tail->next;
        }

    }
    
    l1.listOut();
    l2.listOut();
    l3.listOut();
}
