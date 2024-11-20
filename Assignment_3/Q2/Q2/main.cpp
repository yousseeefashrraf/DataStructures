
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
int main() {

    list l1, l2;
    node * tmp;
    int n;
    node * pTravMain;
    
    cout<<"Enter number of nodes in first lists: ";
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
    
    cout<<"Enter number of nodes in Second lists: ";
    cin>>n;
    
    for(int i=0;i<n;i++){
        tmp = new node;
        tmp->next=NULL;
        cout<<"Enter value for the node number "<<i<<": ";
        cin>>value;
        tmp->val=value;
        l2.attach(tmp);
    }
    
    node * pTravStart;
    node * pTravEnd;
    pTravStart = pTravEnd = NULL;
    pTravMain = l1.head;
    
    while (pTravMain != NULL){
        int tot = 0;
        pTravStart = l2.head;
        while (pTravStart != NULL){
            if (pTravStart->val == pTravMain->val){
                pTravStart = pTravStart->next;
                pTravEnd = pTravStart;
                break;
            }
            pTravStart = pTravStart->next;
        }

        while ( pTravEnd != NULL ){
            if (pTravEnd -> val != pTravMain->next->val){
                tot += pTravEnd-> val;

            } else {
                break;
            }
            pTravEnd = pTravEnd->next;
        }
        
        cout<<tot<<endl;
        
        pTravStart = pTravEnd = NULL;
        pTravMain = pTravMain->next->next;
    }
}
