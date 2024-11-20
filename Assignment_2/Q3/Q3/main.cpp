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

void rotateByNumber(list &main, int nRotations){
    node * pTrav;
    for (int i=0; i<nRotations; i++){
        pTrav=main.head;
        while (pTrav->next->next!=NULL) {
            pTrav=pTrav->next;
        }
        
        main.tail->next = main.head;
        main.head = main.tail;
        pTrav->next = NULL;
        main.tail = pTrav;
    }
}
int main (){
    list l2;
    list l3;
    int nRotation;
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
    cout<<"Number of rotations: ";
    cin>>nRotation;
//    l1.attachByValue(20);
//    l1.attachByValue(16);
//    l1.attachByValue(44);
//    l1.attachByValue(12);
//    l1.attachByValue(55);
//    l1.attachByValue(99);

    cout<<"Original list: ";
    listOut(mainList);
    rotateByNumber(mainList, nRotation);
    cout<<"Rotated list: ";
    listOut(mainList);
}
