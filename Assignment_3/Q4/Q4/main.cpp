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
    list l[30];
    node * pnn;
    node * pTrav1, * pTrav2, * pB;
    int n;
    for(int i=0; i<30; i++){
        cout<<"Enter number of nodes for list number "<<i<<": ";
        cin>>n;
        
        for(int k = 0; k<n;k++){
            pnn = new node();
            cout<<"Enter the value of node number "<<k<<": ";
            cin>>pnn->val;
            pnn->next = NULL;
            l[i].attach(pnn);
        }
    }
    
    for(int i=0; i<30;i+=2){
        pTrav1 = l[i].head;
        pTrav2 = l[i+1].head;
        pB = NULL;
        node * tail = l[i].tail;
        while (pTrav1 != tail->next && pTrav2 != NULL ) {
            if (pTrav1->val == -1){
                    if (pB == NULL) {
                        l[i+1].head = pTrav2->next;
                        pTrav2->next = NULL;
                        l[i].attach (pTrav2);
                        pTrav2 = l[i+1].head;
                    } else{
                        if(pTrav2 == l[i+1].tail){
                            l[i+1].tail = pB;
                        }
                        
                        pB->next = pTrav2->next;
                        pTrav2->next = NULL;
                        l[i].attach(pTrav2);
                        pTrav2 = pB->next;
                    }

            } else {
                pB = pTrav2;
                pTrav2 = pTrav2->next;
            }
            pTrav1 = pTrav1->next;
            }


        }
        
        
    
    for(int i=0; i<30; i++){
        cout<<"List number "<<i<<": ";
        listOut(l[i]);
    }
    
}
