#include <iostream>
#include <stdio.h>
using namespace std;

class cNode {
public:
    int info;
    cNode * pNext;
    cNode * pUp;

};
class cStack{
public:
    cNode * head;
    cStack(){
        head = NULL;
    }
    void push (cNode * pnn){
        pnn -> pNext = head;
        head = pnn;
    }
    
    cNode * pop(){
        cNode * pTrav = head;
        if(pTrav == NULL){
            return NULL;
        }
        head = head -> pNext;
        pTrav->pNext = NULL;
        return pTrav;
    }
};

class list{
public:
    cNode * head;
    cNode * tail;
    cNode * currentRow;
    list(){
        head = tail = NULL;
    }
    ~list(){
        cNode * pTrav = head;
        while(pTrav != NULL){
            head = pTrav->pNext;
            pTrav->pNext = NULL;
            delete pTrav;
            pTrav = head;
        }
    }

    
    void attach(cNode * newcNode){
        if (head == NULL){
            head = newcNode;
            tail = newcNode;
            currentRow = head;
        } else {
            tail->pNext = newcNode;
            tail = newcNode;
        }
    }
    void attachByValue (int value){
        cNode * newNode = new cNode();
        newNode-> info = value;
        newNode->pNext = NULL;
        newNode->pUp = NULL;
        
        if (head == NULL){
            head = newNode;
            tail = newNode;
            currentRow = head;
        } else {
            tail->pNext = newNode;
            tail = newNode;
        }
    
    }
    void copyRow(list & NewRow){
        cNode * pTrav = currentRow;
        cNode * pTravNextRow = NewRow.head;
        while (pTrav != NULL && pTravNextRow !=NULL) {
            pTrav->pUp = pTravNextRow;
            pTrav = pTrav->pNext;
            pTravNextRow = pTravNextRow->pNext;
        }
        currentRow = NewRow.head;
    }
    
    void listOut (){
        cNode * pTrav = head;
        cNode * pTravRow = head;
        while (pTravRow != NULL) {
            pTrav = pTravRow;
            cout<<"[";
            while (pTrav!=NULL) {
                if (pTrav->pNext!=NULL){
                    cout<<pTrav->info<<" ,";
                } else { cout<<pTrav->info; }
                pTrav=pTrav->pNext;
            }
            cout<<"]\n";
            pTravRow = pTravRow->pUp;
        }
        

    }
    
    void Display_In_Reverse(char * path){
        cNode * pTrav = head;
        cNode * tmp;
        cStack x;
        int i = -1;
        
        while (pTrav != NULL && (path[i]!='\0' || i==-1)) {
            i++;
            tmp = new cNode();
            tmp ->pNext = tmp->pUp = NULL;
            tmp->info = pTrav->info;
            x.push(tmp);
            if (path[i] == 'U'){
                pTrav = pTrav->pUp;
            } else if (path[i] == 'R'){
                pTrav = pTrav->pNext;
            }

        }

        while (x.head != NULL){
            cout<<x.head -> info<<" ";
            delete x.pop();
        }
        cout<<endl;
    }
    

};




int main (){
    list l;
    list r2;
    l.attachByValue(17);
    l.attachByValue(37);
    l.attachByValue(54);
    l.attachByValue(90);
    l.attachByValue(34);
    l.attachByValue(102);
    l.attachByValue(104);
    
    r2.attachByValue(22);
    r2.attachByValue(33);
    r2.attachByValue(25);
    r2.attachByValue(43);
    l.copyRow(r2);
    r2.head = r2.tail = NULL;
    
    r2.attachByValue(47);
    r2.attachByValue(80);
    r2.attachByValue(34);
    r2.attachByValue(38);
    r2.attachByValue(19);
    r2.attachByValue(52);
    l.copyRow(r2);
    r2.head = r2.tail = NULL;
    
    r2.attachByValue(20);
    r2.attachByValue(23);
    r2.attachByValue(42);
    r2.attachByValue(80);
    l.copyRow(r2);
    r2.head = r2.tail = NULL;
    
    r2.attachByValue(40);
    r2.attachByValue(31);
    r2.attachByValue(15);
    r2.attachByValue(17);
    r2.attachByValue(41);
    l.copyRow(r2);
    r2.head = r2.tail = NULL;
    
    l.listOut();
    
    char * path;
    path = new char [10];
    cout<<"Enter path: ";
    cin.getline(path, 10);
    l.Display_In_Reverse(path);
}
