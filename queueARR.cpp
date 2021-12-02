#include <iostream>
using namespace std;
int queue[100], n = 100, start = - 1, finish = - 1;
void Insert() {
   int val;
   if (finish == n - 1)
   cout<<"Queue Overflow"<<endl;
   else {
      if (start == - 1)
      start = 0;
      cout<<"Insert the element in queue : "<<endl;
      cin>>val;
      finish++;
      queue[finish] = val;
   }
}
void Delete() {
   if (start == - 1 || start > finish) {
      cout<<"Queue Underflow ";
      return ;
   } else {
      cout<<"Element deleted from queue is : "<< queue[start] <<endl;
      start++;;
   }
}
void Display() {
   if (start == - 1)
   cout<<"Queue is empty"<<endl;
   else {
      cout<<"Queue elements are : ";
      for (int i = start; i <= finish; i++)
      cout<<queue[i]<<" ";
         cout<<endl;
   }
}
int main() {
   int key;
   cout<<"1) Insert element to queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter your choice : ";
      cin>>key;
      switch (key) {
         case 1: Insert();
         break;
         case 2: Delete();
         break;
         case 3: Display();
         break;
         case 4: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(key!=4);
   return 0;
}