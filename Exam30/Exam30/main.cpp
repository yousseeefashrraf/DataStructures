
#include <iostream>
using namespace std;
class cNode {
public:
    int info;
    cNode * pNext;
    cNode * pExtra;

};
class list{
public:
    cNode * head;
    cNode * tail;
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
        } else {
            tail->pNext = newcNode;
            tail = newcNode;
        }
    }
    void attachByValue (int value){
        cNode * newNode = new cNode();
        newNode-> info = value;
        newNode->pNext = NULL;
        newNode->pExtra = NULL;
        
        if (head == NULL){
            head = newNode;
            tail = newNode;
        } else {
            tail->pNext = newNode;
            tail = newNode;
        }
    
    }
};
    
    

void listOut (list &main){
    cNode * pTrav = main.head;
    cout<<"[";
    while (pTrav!=NULL) {
        if (pTrav->pNext!=NULL){
            cout<<pTrav->info<<" ,";
        } else { cout<<pTrav->info; }
        pTrav=pTrav->pNext;
    }
    cout<<"]\n";
}
void cutPaseTwoLargestinfoues(list &main){
    cNode * pBackByFour = main.head;
    cNode * pTrav = main.head;
    int max1 = -99999;
    int posM1, posM2;
    cNode * pMax1, * pMax2;
    cNode * pB = NULL;
    int max2 = max1+1;
    int ct = 0;
    int flag = 0;
    cNode * catch_pBackByFour;
    cNode * currentBackByFour;
    cNode * max1Back;
    cNode * max2Back;
    
    while (pTrav != NULL){
        if(pTrav->info > max2){
            max1 = max2;
            posM1 = posM2;
            pMax1 = pMax2;
            max1Back = max2Back;
            posM2 = ct;
            max2 = pTrav->info;
            pMax2 = pTrav;
            max2Back = pBackByFour;
            currentBackByFour = max1Back;

        } else {
            if(pTrav->info > max1){
                max1 = pTrav->info;
                posM1 = ct;
                pMax1 = pTrav;
                max1Back = pBackByFour;
                currentBackByFour = max2Back;
            }
            
            
        }
    

        if (ct >= 4){
            pBackByFour = pBackByFour->pNext;
        }
        pTrav->pExtra = pB;
        pB = pTrav;

        pTrav = pTrav -> pNext;

        ct++;
    }

    if (posM1>posM2){
        cNode * tmp = pMax1;
        pMax1 = pMax2;
        pMax2 = tmp;
    }
    cout<<pMax1 -> info<<endl;
    cout<<pMax2 -> info<<endl;
    if (pMax2 != main.tail){
        pMax1->pExtra->pNext = pMax2->pNext;
        pMax2 -> pNext = NULL;
        main.tail -> pNext = pMax1;
        main.tail = pMax2;
    }
    currentBackByFour -> pExtra -> pNext = pMax1->pExtra->pNext;
    pMax1->pExtra->pNext = main.head;
    main.head = currentBackByFour;

}
int main() {
    list l;
    l.attachByValue(12);
    l.attachByValue(56);
    l.attachByValue(35);
    l.attachByValue(95);
    l.attachByValue(14);
    l.attachByValue(11);
    l.attachByValue(34);
    l.attachByValue(57);
    l.attachByValue(60);
    l.attachByValue(240);
    l.attachByValue(180);
    l.attachByValue(17);
    l.attachByValue(350);
    
    cutPaseTwoLargestinfoues(l);
    listOut(l);
    
    

}
