#include <iostream>
using namespace std;
class cNode {
public:
    char ** board;
    int currRow;
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
cNode * giveIitialState(int n){
    cNode * pnn;
    pnn = new cNode();
    pnn ->currRow = 0;

    pnn -> pNext = NULL;
    pnn -> board = new char * [n];
    for(int r=0; r<n; r++){
        pnn -> board[r] = new char[n];
    }
    for(int r=0; r<n; r++){
        for(int c=0; c<n; c++){
            pnn->board[r][c] = ' ';
        }
    }
    return pnn;
}
void copyState(cNode * & currState,cNode * & newState,int n){
    for(int r = 0; r<n; r++){
        for (int c = 0; c<n; c++) {
            newState -> board[r][c] = currState -> board[r][c];
        }
    }
}
int checkIfSafe(cNode * & currState, int n, int column, char killer){
    int isSafe = 1;
    if(currState->board[currState->currRow][column] == killer){
        return 0;
    }
    if(currState->currRow-1 >= 0){
        if(column-1 >= 0 ){
            if(currState->board[currState->currRow-1][column-1] == killer){
                isSafe = 0;
            }
        }
        if(column+1<n){
            if(currState->board[currState->currRow - 1][column+1] == killer){
                isSafe = 0;
            }
        }

    }
    if(currState->currRow+1 < n){
        if(column-1 >= 0 ){
            if(currState->board[currState->currRow+1][column-1] == killer){
                isSafe = 0;
            }
        }
        if(column+1<n){
            if(currState->board[currState->currRow + 1][column+1] == killer){
                isSafe = 0;
            }
        }

    }
    
    
    return isSafe;
}

int solutionIsDone(char ** x, int n){
    int isDone = 0;
    int ct = 0;
    for(int r = 0; r< n; r++){
        for (int c = 0; c<n; c++) {
            if(x[r][c] == 'W' || x[r][c] == 'B'){
                ct++;
            }
        }
    }
    if(ct == n*n){
        isDone = 1;
    }
    return isDone;
}
void DrawBoard(char ** x, int n){
    for(int i = 0; i<n*3+n+1;i++){
        cout<<"-";
    }
    cout<<endl;
    for (int r = 0; r<n; r++) {
        for (int c = 0; c<n; c++) {
            cout<<"| "<<x[r][c]<<" ";

        }
        cout<<"|";
        cout<<endl;
        for(int i = 0; i<n*3+n+1;i++){
            cout<<"-";
        }
        cout<<endl;

    }

    cout<<endl;
}
void initBoard(cNode * & pnn, int n ){
    pnn -> board = new char * [n];
    for(int r=0; r<n; r++){
        pnn -> board[r] = new char[n];
    }
}
void expand(cNode * & currState,cStack & x, int n, char kill, char killer){
    cNode * pnn;
    for(int i=0; i<n;i++){
        pnn = new cNode();
        pnn-> pNext = NULL;
        pnn->currRow = currState->currRow;
        initBoard(pnn, n);
        copyState(currState, pnn, n);
        pnn->board[currState->currRow][i] = kill;
        pnn->currRow++;
        if (checkIfSafe(currState, n, i, killer)) {
            x.push(pnn);
            if(solutionIsDone(pnn->board, n)){
                DrawBoard(pnn->board, n);
                x.pop();
            }
        }
    }
    
}
int main(){
    cStack x;
    int n = 5;
    cNode * pnn;
    cNode * currState;
    
    pnn = giveIitialState(n);
    x.push(pnn);
    
    while (x.head != NULL) {
        currState = x.pop();
        expand(currState, x, n,'W','B');
        expand(currState, x, n,'B','W');


    }
    
}
