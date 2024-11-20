
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
    
    

void listOut (list &main){
    node * pTrav = main.head;
    cout<<"[";
    while (pTrav!=NULL) {
        if (pTrav->next!=NULL){
            cout<<pTrav->val<<" ,";
        } else { cout<<pTrav->val; }
        pTrav=pTrav->next;
    }
    cout<<"]\n";
}

void splist_1(list& mainList,list &l1,list &l2){
    int size = 0;
    node * pTrav = mainList.head;
    while(pTrav!=NULL){
        size++;
        pTrav=pTrav->next;
    }
    size++;
    pTrav = mainList.head;
    node * newTmp;
    int ct=0;
    while(pTrav!=NULL){
        if (ct == size/2)
            break;
            
            newTmp = new node();
            newTmp->next=NULL;
            newTmp->val = pTrav->val;
            l1.attach(newTmp);
            pTrav=pTrav->next;
            ct++;
        }
        
        while(pTrav!=NULL){
            newTmp = new node();
            newTmp->next=NULL;
            newTmp->val = pTrav->val;
            l2.attach(newTmp);
            pTrav=pTrav->next;
        }
        
    }

void splist_2(list &mainList,list &l1,list &l2){
    node * pTrav = mainList.head;
    int size = 0;
    node *pTravBack = NULL;
    int ct=0;
    while(pTrav!=NULL){
        size++;
        pTrav=pTrav->next;
    }
    size++;
    pTrav = mainList.head;
    while(pTrav!=NULL){
        if (ct == size/2){
            break;
        }

        pTravBack=pTrav;
        pTrav=pTrav->next;
        ct++;
    }
    
    l1.head = mainList.head;
    mainList.head=NULL;
    pTravBack->next=NULL;
    l1.tail = pTravBack;
    
    l2.head=pTrav;
    l2.tail=mainList.tail;
    mainList.tail=NULL;
    
}

int main() {
    list mainList;
    list l2;
    list l3;
    list l4, l5;
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
    cout<<"MainList before split_(COPY AND PASTE): ";
    listOut(mainList);
    splist_1(mainList, l2, l3);
    cout<<"MainList after split_(COPY AND PASTE): ";
    listOut(mainList);
    cout<<"First list: ";
    listOut(l2);
    cout<<"Second list: ";
    listOut(l3);
    
    
    cout<<"MainList before split_(CUT AND PASTE): ";
    listOut(mainList);
    
    cout<<"MainList after split_(CUT AND PASTE): ";
    splist_2(mainList, l4, l5);
    listOut(mainList);


    cout<<"Third list: ";
    listOut(l4);
    cout<<"Fourth list: ";
    listOut(l5);
}
