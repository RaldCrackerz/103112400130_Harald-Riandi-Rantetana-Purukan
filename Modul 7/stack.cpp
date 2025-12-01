#include "stack.h"

bool isEmpty(Stack S) {
    return S.top == -1; 
}
bool isFull(Stack S) {
    return S.top == MAX_SIZE - 1; 
}
void CreateStack(Stack &S) {
    S.top = -1; 
}

void push(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack Penuh, tidak bisa push " << x << endl;
        return;
    }
    S.top++;
    S.info[S.top] = x;
}
infotype pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong, tidak bisa pop." << endl;
        return 0; 
    }
    infotype poppedData = S.info[S.top];
    S.top--; 
    return poppedData;
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
        return;
    }

    cout << "[TOP] ";
   
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
   
    int start = 0;
    int end = S.top;

    while (start < end) {
        infotype temp = S.info[start];
        S.info[start] = S.info[end];
        S.info[end] = temp;
        
        start++;
        end--;
    }
}

void getInputStream(Stack &S) {
    char inputChar;
    cout << "Masukkan stream karakter: "; 
    
    while (cin.get(inputChar) && inputChar != '\n') {
        if (isFull(S)) {
            cout << "\nStack Penuh, tidak bisa menerima input lagi." << endl;
            break;
        }
        push(S, inputChar);
    }
}