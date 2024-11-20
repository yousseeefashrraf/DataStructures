
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
    list l[20];
    list newL;
    node * pnn;
    node * start1;
    node * start2;
    node * end1;
    node * end2;
    node * start1B = NULL;
    node * start2B=NULL;
    int n;
    for(int i=0; i<20; i++){
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
    
    for(int i=0, k=19; i<k ;i++,k--)
    {
        start1 = l[i].head;
        start2 = l[k].head;
        
        while(start1 != NULL && start1->val > 0){
            start1B = start1;
            start1=start1->next;

        }
        
        end1 = start1;
        while(end1 != l[i].tail && end1 != NULL){
            end1 = end1->next;
            if(end1 -> val < 0)
                break;
        }
        
        if (end1 != NULL){
            if (start1B == NULL){
                l[i].head = end1->next;
                end1->next = NULL;
                newL.attach(start1);
                newL.tail = end1;
            } else {
                if (end1==l[i].tail){
                    l[i].tail = end1;
                }
                start1B->next=end1->next;
                end1->next = NULL;
                newL.attach(start1);
                newL.tail = end1;
            }
            
        }
        //check Kth list
        while(start2 != NULL && start2->val > 0){
            start2B = start2;
            start2=start2->next;

        }
        
        end2 = start2;
        while(end2 != l[k].tail && end2 != NULL){
            end2 = end2->next;
            if(end2->val < 0)
                break;
        }
        
        if (end2 != NULL){
            if (start2B == NULL){
                l[k].head = end2->next;
                end2->next = NULL;
                newL.attach(start2);
                newL.tail = end2;
            } else {
                if (end2==l[k].tail){
                    l[k].tail = end2;
                }
                start2B->next=end2->next;
                end2->next = NULL;
                newL.attach(start2);
                newL.tail = end2;
            }

        }
    }
    
    listOut(newL);
}
