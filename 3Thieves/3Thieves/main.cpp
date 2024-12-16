#include <iostream>
using namespace std;
class cNode {
public:
    int side1[6];
    int side2[6];
    int currSide;
    char history[200];
    cNode * pNext;

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
void append(char x[], int dir){
    int i;
    
    for(i=0; x[i]!= '\0'; i++){
        
    }
    
    if(dir == 1){
        x[i] = 'M';
        x[i+1] = '1';
        x[i+2]=' ';
        x[i+3]='\0';
    }
    if(dir == 2){
        x[i] = 'M';
        x[i+1] = '2';
        x[i+2]=' ';
        x[i+3]='\0';
    }
    if(dir == 3){
        x[i] = 'M';
        x[i+1] = '3';
        x[i+2]=' ';
        x[i+3]='\0';
    }
    
    if(dir == 1000){
        x[i] = '$';
        x[i+1] = '1';
        x[i+2] = '0';
        x[i+3] = '0';
        x[i+4] = '0';
        x[i+5]=' ';
        x[i+6]='\0';
    }
    if(dir == 300){
        x[i] = '$';
        x[i+1] = '3';
        x[i+2] = '0';
        x[i+3] = '0';
        x[i+4]=' ';
        x[i+5]='\0';
    }
    if(dir == 700){
        x[i] = '$';
        x[i+1] = '7';
        x[i+2] = '0';
        x[i+3] = '0';
        x[i+4]=' ';
        x[i+5]='\0';
    }
    if(dir == 0){
        if(i!=0){
            x[i++]='-';
            x[i++]='>';
        }
        x[i]='[';
        x[i+1]=' ';
        x[i+2]='\0';
    }
    if(dir == 10){
        x[i]=']';
        x[i+1]='\0';
    }
}
cNode * giveIitialState(){
    cNode * pnn;
    pnn = new cNode();
    pnn ->currSide = 1;
    pnn -> side1[0] = 1;
    pnn -> side1[1] = 1;
    pnn -> side1[2] = 1;
    pnn -> side1[3] = 1000;
    pnn -> side1[4] = 700;
    pnn -> side1[5] = 300;
    
    pnn -> side2[0] = 0;
    pnn -> side2[1] = 0;
    pnn -> side2[2] = 0;
    pnn -> side2[3] = 0;
    pnn -> side2[4] = 0;
    pnn -> side2[5] = 0;
    pnn -> pNext = NULL;
    return pnn;
}
void copyState(cNode * & currState,cNode * & newState){
    
    for(int i = 0; i<6; i++){
        newState -> side1[i] = currState -> side1[i];
        newState -> side2[i] = currState -> side2[i];
    }
    newState -> currSide = currState -> currSide;
    
    for(int i = 0; i<200; i++){
        newState -> history[i] = currState -> history[i];
    }
//
}
int checkIfSafe(cNode * & currState){
    int isSafe = 1;
    int i;
    int side1Tot = 0;
    int side2Tot = 0;
    int money1 = 0;
    int money2 = 0;
        if(currState->side1[0]==1){
            side1Tot += 1000;
        }
        
        if(currState->side1[1]==1){
            side1Tot += 700;
        }
        if(currState->side1[2]==1){
            side1Tot += 300;
        }
        
        if(currState->side2[0]==1){
            side2Tot += 1000;
        }
        
        if(currState->side2[1]==1){
            side2Tot += 700;
        }
        if(currState->side2[2]==1){
            side2Tot += 300;
        }
    for( i = 3; i<6;i++){
        money1 += currState->side1[i];
        money2 += currState->side2[i];
    }
    
    if(side1Tot<money1 && side1Tot!= 0){
        isSafe = 0;
    }
    if(side2Tot<money2 && side2Tot != 0){
        isSafe = 0;
    }
    return isSafe;
}

int solutionIsDone(int x[]){
    for(int r = 0; r< 6; r++){
        if(x[r]!=0){
            return 0;
        }
    }
    return 1;
}
int isVisted (list & visted, cNode * currState){
    int isSimilar = 1;
    cNode * pTrav = visted.head;
    while (pTrav != NULL) {
         isSimilar = 1;
        for(int i=0; i<6;i++){
            if(currState->side1[i] != pTrav->side1[i]){
                isSimilar = 0;
            }
            if(currState->side2[i] != pTrav->side2[i]){
                isSimilar = 0;
            }
            if(currState->currSide != pTrav->currSide){
                isSimilar = 0;
            }
        }
        for(int i =0; currState->history[i]!='\0' && pTrav->history[i]!='\0';i++ ){
            if(currState->history[i]!= pTrav->history[i]){
                isSimilar = 0;
            }
        }
        if(isSimilar){
            return 1;
        }
        pTrav = pTrav->pNext;
    }
    return 0;
}


void expand(cNode * & currState,cStack & x, list & visitedList){
    cNode * pnn;
    for(int i=0; i<3;i++){
        for(int k = 0; k<6;k++){
            pnn = new cNode();
            pnn->pNext  = NULL;
            copyState(currState, pnn);
            if(pnn->currSide==1){
                if(currState->side1[i]>=1 && currState->side1[k]>=1){
                    append(pnn->history, 0);
                    if(i<3){
                        append(pnn->history, i+1);
                    } else{
                        append(pnn->history, pnn->side1[i]);
                    }
                    if(k<3){
                        append(pnn->history, k+1);
                    } else{
                        append(pnn->history, pnn->side1[k]);
                    }
                    append(pnn->history, 10);
                    
                    pnn->side2[i]=pnn->side1[i];
                    pnn->side2[k]=pnn->side1[k];
                    pnn->side1[i]=0;
                    pnn->side1[k]=0;
                    pnn->currSide=2;
                    if(checkIfSafe(pnn) && !isVisted(visitedList, pnn)){
                        cNode * pVisit = new cNode();
                        pVisit->pNext = NULL;
                        copyState(pnn, pVisit);
                        if(!solutionIsDone(pnn->side1)){
                            visitedList.attach(pVisit);
                            x.push(pnn);
                        } else {
                            cout<<"Solution : ";
                            for(int i = 0;pnn->history[i] !='\0';i++ ){
                                cout<<pnn->history[i];
                            }
                            cout<<endl;
                            cout<<endl;

                        }
                        }
     
                }
            }
            
            if(pnn->currSide==2){
                if(currState->side2[i]>=1 && currState->side2[k]>=1){
                    append(pnn->history, 0);
                    if(i<3){
                        append(pnn->history, i+1);
                    } else{
                        append(pnn->history, pnn->side2[i]);
                    }
                    if(k<3){
                        append(pnn->history, k+1);
                    } else{
                        append(pnn->history, pnn->side2[k]);
                    }
                    append(pnn->history, 10);
                    
                    pnn->side1[i]=pnn->side2[i];
                    pnn->side1[k]=pnn->side2[k];
                    pnn->side2[i]=0;
                    pnn->side2[k]=0;
                    pnn->currSide=1;

                    if(checkIfSafe(pnn) && !isVisted(visitedList, pnn)){
                        cNode * pVisit = new cNode();
                        pVisit->pNext = NULL;
                        copyState(pnn, pVisit);
                        if(!solutionIsDone(pnn->side1)){
                            visitedList.attach(pVisit);
                            x.push(pnn);
                        } else {
                            cout<<"Solution : ";
                            for(int i = 0;pnn->history[i] !='\0';i++ ){
                                cout<<pnn->history[i];
                            }
                            cout<<endl;
                            cout<<endl;
                        }
                        }
     
                }
            }
            
            
        }

        }
    
    
}
int main(){
    cStack x;
    cNode * pnn;
    cNode * currState;
    list visited;
    pnn = giveIitialState();
    x.push(pnn);
    cNode * vnn = giveIitialState();
    visited.attach(vnn);

    while (x.head != NULL) {
        currState = x.pop();
        expand(currState, x,visited);
        delete currState;
    }
    
}
