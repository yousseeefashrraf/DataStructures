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
    int ct = 0;
    int posPStart;
    int posPEnd;
    node * pEndInterval = NULL;
    node * tmp;
    while (pTrav!=NULL) {
        if (pTrav->val > max){
            max=pTrav->val;
            pStartInterval=pTrav;
            posPStart = ct;
        }
        
        if (pTrav->val < min){
            min =pTrav->val;
            pEndInterval = pTrav;
            posPEnd=ct;
        }
        
        pTrav=pTrav->next;
        ct++;
    }
    //if posPStart is greater that means that it's actually the pos of the end interval; therefore, we need to swap them!
    if(posPStart>posPEnd){
        tmp = pStartInterval;
        pStartInterval = pEndInterval;
        pEndInterval = tmp;
    }
    tmp = new node();
    tmp->next = NULL;
    tmp->val = pStartInterval->val;
    modified.attach(tmp);
    tmp = new node();
    tmp->next = NULL;
    tmp->val = pEndInterval->val;
    modified.attach(tmp);
    
    pTrav = pStartInterval->next;
    while (pTrav!=pEndInterval ) {
        tmp = new node();
        tmp->next = NULL;
        tmp->val = pTrav->val;
        modified.attach(tmp);
        pTrav=pTrav->next;
    }
    
    
}
int main (){
    list l2;
    list mainList;
    
    node * tmp;
    int n;
    cout<<"Enter number of nodes in the main list: ";
    cin>>n;
    int value;
    for(int i=0; i<n;i++){
        tmp = new node;
        tmp->next=NULL;
        cout<<"Enter value for the node number "<<i<<": ";
        cin>>value;
        tmp->val=value;
        mainList.attach(tmp);
    }
    
    cout<<"Targetd list: ";
    listOut(mainList);
    cout<<"Intervall between min. and max. : ";
    copyInMinMax(mainList, l2);
    listOut(l2);
}
