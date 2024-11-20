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

};
void listOut (list &l){
    node * pTrav = l.head;
    cout<<"[";
    while (pTrav!=NULL) {
        if (pTrav->next!=NULL){
            cout<<pTrav->val<<" ,";
        } else { cout<<pTrav->val; }
        pTrav=pTrav->next;
    }
    cout<<"]\n";
}

void copyInMinMax(list &main, list &modified){
    int min = 99999;
    int max = -99999;
    node * pTrav = main.head;
    node * pStartInterval = NULL;
    node * pBeforeStart = NULL;
    node * pBeforeEnd = NULL;
    node * pBeforeTrav = NULL;
    int ct = 0;
    int posPStart;
    int posPEnd;
    node * pEndInterval = NULL;
    node * tmp;
    while (pTrav!=NULL) {
        if (pTrav->val > max){
            max=pTrav->val;
            pBeforeStart = pBeforeTrav;
            pStartInterval=pTrav;
            posPStart = ct;
        }
        
        if (pTrav->val < min){
            min =pTrav->val;
            pEndInterval = pTrav;
            pBeforeEnd = pBeforeTrav;
            posPEnd=ct;
        }
        pBeforeTrav = pTrav;
        pTrav=pTrav->next;
        ct++;
    }
    

    
    
    

    //if posPStart is greater that means that it's actually the pos of the end interval; therefore, we need to swap them!
    if(posPStart>posPEnd){
        tmp = pStartInterval;
        pStartInterval = pEndInterval;
        pEndInterval = tmp;
        
        tmp = pBeforeStart;
        pBeforeStart = pBeforeEnd;
        pBeforeEnd = tmp;
    }
    
    pTrav = pStartInterval->next;
    tmp = pEndInterval->next;
    
    if (pBeforeStart != NULL){
        if (posPEnd-posPStart != 1 && posPEnd-posPStart != -1){
            pBeforeStart->next = pStartInterval->next;
            pStartInterval->next = NULL;
            modified.attach(pStartInterval);

        } else {
            pBeforeStart->next = pEndInterval->next;
            pEndInterval->next = NULL;
            modified.attach(pStartInterval);
            modified.tail = pEndInterval;
            return ;
        }
    } else {
        if (posPEnd-posPStart != 1 && posPEnd-posPStart != -1){
            main.head = pStartInterval->next;
            pStartInterval->next = NULL;
            modified.attach(pStartInterval);
        } else {
            main.head = pEndInterval->next;
            pEndInterval->next = NULL;
            modified.attach(pStartInterval);
            modified.tail = pEndInterval;
            return ;
        }
        
    }

        if (pEndInterval->next != NULL){
            pBeforeEnd -> next = pEndInterval->next;
            pEndInterval->next = NULL;
            modified.attach(pEndInterval);
        } else {
            pBeforeEnd -> next = NULL;
            main.tail = pBeforeEnd;
            modified.attach(pEndInterval);
        }
    
    
    pEndInterval = tmp;
    
    while (pTrav!=pEndInterval) {
        tmp = new node();
        tmp->next = NULL;
        tmp->val = pTrav->val;
        modified.attach(tmp);
        pTrav=pTrav->next;
    }
    
    
   
}
int main (){
    list l1;
    list l2;
    list l3;

    l1.attachByValue(20);
    l1.attachByValue(7);
    l1.attachByValue(90);
    l1.attachByValue(44);
    l1.attachByValue(12);

    l1.attachByValue(10);

    listOut(l1);
    copyInMinMax(l1, l2);
    listOut(l1);
    listOut(l2);
}
