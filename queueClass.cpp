#include <iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

#define MAX_SIZE 100



class Queue {
private:
    double item;
    int i;
    int arr_queue[MAX_SIZE];
    int end;
    int start;

public:

    Queue() {
        end = 0;
        start = 0;
    }

    void input() {
        if (end == MAX_SIZE)
            cout << "\n## Queue is full!";
        else {
            cout << "\nEnter the purchase price  : ";
            cin>>item;
            cout << "\n## Purchase number : " << end + 1 << " , input Value  : " << item;
            arr_queue[end++] = item;
        }
    }

    void deleteData() {
        if (start == end)
            cout << "\n## Queue is Empty!";
        else {
            cout << "\n## Purchase number : " << start << " , delete Value  :" << arr_queue[start];
            start++;
        }
    }

    void display() {
        cout << "\n## Queue Size : " << (end - start);
        for (i = start; i < end; i++)
            cout << "\n## Purchase number : " << i << " , Value  : " << arr_queue[i];
    }
};

int main() {
    int choice, exit_p = 1;
    Queue obj;
    do {
        cout << "\n\n Queue Main Menu";

        cout << "\n1.Input \n2.Delete \n3.Display \nOthers to exit";
        cout << "\nEnter Your Choice : ";
        cin>>choice;
        switch (choice) {
            case 1:
                obj.input();
                break;
            case 2:
                obj.deleteData();
                break;
            case 3:
                obj.display();
                break;
            default:
                exit_p = 0;
                break;
        }
    } while (exit_p);

    return 0;
}
