
#include <iostream>
#include <ctime>
using namespace std;
 
struct Stack
{
    double data;
    Stack* next;
};
 
Stack* top = NULL;
int const INF = 1e9;
 
Stack* push(int input) {
    Stack* newEl = new Stack;           
    newEl->data = input;                
    newEl->next = top;                  
    top = newEl;
    return newEl;
}
 
void show() {
    Stack* currentEl = top;
    while (currentEl != NULL)
    {
        cout << currentEl->data << endl;
        currentEl = currentEl->next;        
    }
}
 
void pop() {
    Stack* temp = top->next;
    cout << "object " << top->data << " is deleted" << endl;
    delete top;
    top = temp;
}
 
void cleanStack() {
    while (top != NULL)
    {
        pop();
    }
}
 
void average() {
    if (top == NULL)
    {
        cout << "Stack is empty! error!" << endl;
        return;
    }
    Stack* currentEl = top;
    double summa = 0;
    int counter = 0;
    while (currentEl != NULL)
    {
        counter++;
        summa += currentEl->data;
        currentEl = currentEl->next;
    }
    double mid = summa / counter;
    top->data = mid;
}
 
void addressSort() {
    Stack* t = NULL, * t1, * temp;
    push(INF);
    if (top->next->next == NULL) return;
    do {
        for (t1 = top; t1->next->next != t; t1 = t1->next) {    
            if (t1->next->data > t1->next->next->data) {    
                temp = t1->next->next;                      
                t1->next->next = temp->next;                
                temp->next = t1->next;                      
                t1->next = temp;                            
            }                                               
        }
        t = t1->next;
    } while (top->next->next != t);
    pop();
}
 
void dataSort() {
    Stack* t = NULL;
    Stack* t1;
    double temp;
    do {
        for (t1 = top; t1->next != t; t1 = t1->next) {
            if (t1->data > t1->next->data) {
                temp = t1->data;
                t1->data = t1->next->data;
                t1->next->data = temp;
            }
        }
        t = t1;
    } while (top->next != t);
}
 
int main()
{
    
    while (true) {
        cout << "1. Creation " << endl
            << "2. Adding" << endl
            << "3. Look through" << endl
            << "4. Delete top" << endl
            << "5. Clear" << endl
            << "6. Change first elem on average" << endl
            << "7. Sort" << endl
            << "0. Exit" << endl;
        int menu;
        cin >> menu;
        cout << endl;
        switch (menu) {
        case 1: case 2:
            if (menu == 1 && top != NULL) {
                cout << "Clear memory for creation!" << endl;
                break;
            }
            cout << "Enter number of elements: ";
            int elCount;
            cin >> elCount;
            for (int i = 0; i < elCount; i++) {
                int element;
                element = rand() % 50 - 25;
                top = push(element);
            }
            if (menu == 1) {
                cout << "Stack has " << elCount << " elements" << endl;
            }
            else {
                cout << "In stack added " << elCount << " elements" << endl;
            }
            cout << endl;
            break;
 
        case 3:
            if (!top) {
                cout << "Stack is empty!" << endl;
                cout << endl;
                break;
            }
            cout << "--- Stack ---" << endl;
            show();
            cout << endl;
            break;
 
        case 4:
            if (top != NULL) {
                pop();
                cout << "Top is deleted!" << endl;
            }
            else {
                cout << "Stack is empy! error..." << endl;
            }
            cout << endl;
            break;
 
        case 5:
            if (top != NULL) {
                cleanStack();
                cout << "Memory is cleared!" << endl;
            }
            else {

                cout << "Stack is empy! error..." << endl;
            }
            cout << endl;
            break;
 
        case 6:
            average();
            cout << "The first element changed on average!" << endl << endl;
            break;
 
        case 7:
            if (top == NULL)
            {
                cout << "Stack is empy! error..." << endl << endl;
                break;
            }
            cout << "Choose the variant of sort: " << endl
                << "1. Address change" << endl
                << "2. Information change" << endl;
            int menu;
            cin >> menu;
            cout << endl;
            switch (menu)
            {
            case 1:
                addressSort();
                cout << "Sort is comleted!" << endl;
                break;
            case 2:
                dataSort();
                cout << "Sort is comleted!!" << endl;
                break;
            default:
                cout << "Error!" << endl;
                break;
            }
            cout << endl;
            break;
 
        case 0:
            if (top != NULL) cleanStack();
            return 0;
        }
    }
}