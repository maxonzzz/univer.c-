#include <iostream> 
using namespace std; 
struct Node 
{ 
 int data;  
 Node* next; 
}; 
struct QuePtrueue 
{ 
 int size; 
 Node* first; 
 Node* last; 
}; 
void Creation(QuePtrueue* QuePtr) 
{ 
 QuePtr->first = new Node; 
 QuePtr->first->next = NULL; 
 QuePtr->last = QuePtr->first; 
 QuePtr->size = 0; 
} 
bool Full(QuePtrueue* QuePtr) 
{ 
 if (QuePtr->first == QuePtr->last) return true; 
 else return false; 
} 
int Top(QuePtrueue* QuePtr) 
{ 
 return QuePtr->first->next->data; 
} 
void Add(QuePtrueue* QuePtr) 
{ 
 int token; 
 cout << "\nEnter the purchase price, and the number of purchases through spaces without spaces  > "; cin >> token; 
 QuePtr->last->next = new Node; 
 QuePtr->last = QuePtr->last->next; 
 QuePtr->last->data = token; 
 QuePtr->last->next = NULL; 
 QuePtr->size++; 
 cout << "\nElem added\n\n"; 
} 
void Delete(QuePtrueue* QuePtr) 
{ 
 QuePtr->first = QuePtr->first->next;  
 QuePtr->size--; 
 cout << "\nElem deleted\n\n"; 
} 
int Length(QuePtrueue* QuePtr) 
{    
 return QuePtr->size; 
} 
int main() 
{ 
  
 QuePtrueue QuePtr; 
 Creation(&QuePtr); 
 char number; 
 do 
 { 
  
  cout << "  1. Add element " << endl; 
  cout << "  2. Queue length " << endl; 
  cout << "  3. Output the first elem " << endl;
  cout << "  4. Delete element " << endl;  
  cout << "  0. Finish work " << endl; 
  cout << "-------------------------------" << endl; 
  cout << "Enter the command number > "; cin >> number; 
  switch (number) 
  { 
  case '1':  Add(&QuePtr); 
   break; 
   
  case '2': 
   if (Full(&QuePtr)) cout << endl << "The Queue is empty\n"; 
   else cout << "\nNumber of purchases: " << Length(&QuePtr) << "\n"; 
   break; 
  
  case '3': 
   if (Full(&QuePtr)) cout << endl << "The Queue is empty\n"; 
   else { cout << "\nPochatkovyy element: " << Top(&QuePtr) << "\n"; } 
   break; 
   
  case '4': 
   if (Full(&QuePtr)) cout << endl << "The Queue empty\n"; 
   else Delete(&QuePtr); 
   break; 
   
  case '0': break; 
  default: cout << endl << "Failure"; 
   break; 
  } 
 } while (number != '0'); 
 system("pause"); 
}

