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
void reverseList(list &main){

    node * tmp = main.head;
    node * pTrav =tmp->next;
    
    while(pTrav!=NULL){
        main.head->next = pTrav->next;
        pTrav->next= tmp;
        tmp = pTrav;
        pTrav=main.head->next;
    }
    
    tmp = main.head ;
    main.head = main.tail;
    main.tail = tmp;
}

void reverseList(list &main, list &list1){
    node * PTrav = main.head;
    node * newNode;
    
    while(PTrav!=NULL){
        newNode = new node ();
        newNode->next = NULL;
        newNode->val = PTrav->val;
        if(list1.tail==NULL){
            list1.head=newNode;
            list1.tail=newNode;
        } else{
            newNode->next = list1.head;
            list1.head = newNode;
            
        }
        
        PTrav = PTrav->next;
    }
    
}
int main() {
    list l2;
    list mainList;
    list l3;
    
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
    listOut(mainList);
    reverseList(mainList);
    listOut(mainList);
    
    reverseList(mainList, mainList);
    listOut(l2);

}
