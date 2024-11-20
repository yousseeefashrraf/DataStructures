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


int main(){
    list l1, l2;
    node * tmp;
    int n;
    
    cout<<"Enter number of nodes in the lists: ";
    cin>>n;
    int value;
    for(int i=0; i<n;i++){
        tmp = new node;
        tmp->next=NULL;
        cout<<"Enter value for the node number "<<i<<": ";
        cin>>value;
        tmp->val=value;
        l1.attach(tmp);
    }
    
    for(int i=0;i<n;i++){
        tmp = new node;
        tmp->next=NULL;
        cout<<"Enter value for the node number "<<i<<": ";
        cin>>value;
        tmp->val=value;
        l2.attach(tmp);
    }
    
    //Cut repetead nodes from l2
    cout<<"Before cut: ";
    listOut (l2);
    
    node * pTravl1 = l1.head;

    node * pTravl2Back=l2.head;
    node * pTravl2 = l2.head;
    
    while (pTravl1 != NULL) {
        if (pTravl1->val == pTravl2->val){
            if(l2.head == pTravl2){
                l2.head = pTravl2->next;
                pTravl2->next = NULL;
                delete pTravl2;
                pTravl2 = l2.head;
            } else {
                if (l2.tail == pTravl2 ){
                    l2.tail = pTravl2Back;
                }
                pTravl2Back->next = pTravl2->next;
                pTravl2->next = NULL;
                delete pTravl2;
                pTravl2 = pTravl2Back->next;
       
            }
        } else {
            pTravl2Back = pTravl2;
            pTravl2 = pTravl2->next;
        }
        
        pTravl1 = pTravl1->next;
    }
    
    cout<<"After cut: ";
    listOut (l2);
}
