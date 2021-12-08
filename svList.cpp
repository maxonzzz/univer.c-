#include <iostream>

using namespace std;

class Node{
public:
    int item;       
    Node *next;     
    Node(int i,Node *n=nullptr):item(i),next(n){}   
};


void insNode(Node *node, Node *insnode, int n){
   cout << "Input elem after number " << n << endl;
   if (n==0){   
       node->item = insnode->item;
       node->next = nullptr;
       return;
   }
   int i = 1;
   while (i < n){
       ++i;
       node = node->next;   
   }
   insnode->next = node->next;  
   node->next = insnode;
}


Node *delNode(Node *node, int n){
    Node *nodePrev = node;
    if(n==1){               
        if (node->next==nullptr){
            node = NULL;
            nodePrev = node;
            return node;
        }
        nodePrev = node;    
        node=node->next;    
        nodePrev->next = node->next;   
        nodePrev->item = node->item;
        node = nodePrev;    
        return node;
    }  
    int i = 1;
    while(i<n-1){
        node = node->next;
        ++i;
    }
    nodePrev = node;
    node = node->next;
    nodePrev->next = node->next;
    node = nodePrev;
    
    return node;
}

// размер списка
int capacityList(Node *node){
    int i = 0;
    for(;node;i++)
        node = node->next;
    return i;
}


int getNode(Node *node, int n){
    for(int i = 1;i<n;i++){
        node = node->next;
    }
    return node->item;
}

int main()
{
    Node *list = new Node(0);
    Node *prev = nullptr;
    Node *insnode;      // узел для вставки

    for(int i = 0;i<10;i++){
        insnode = new Node(i);
        insNode(list,insnode,i);  // добавляем в конец списка
    }

    insnode = new Node(13);
    insNode(list,insnode,3);  // вставляем после третьего узла

    cout << "Knots in list:" << capacityList(list) << endl;

    // получить 4-й узел
    cout << "Knot № 4:\n";
    cout << getNode(list,4) << endl;

    // напечатать список с начала
    cout << "list from beginning:\n";
    for(int i = 1; i<=capacityList(list);i++)
        cout << getNode(list,i) << endl;

    // напечатать список с конца
    cout << "list from end:\n";
    for(int i = capacityList(list);i>0;i--)
        cout << getNode(list,i) << endl;

    // напечатать узлы с четными номерами
    cout << "Узлы с четными номерами:\n";
    for(int i=0;i<=capacityList(list);i+=2){
        cout << getNode(list,i) << endl;
    }

    // удалить четвертый узел
    Node *temp = nullptr;
    cout << "delete knot 4:\n";
    temp = delNode(list,4);
    cout << "list from beginning:\n";
    for(int i = 1; i<=capacityList(list);i++)
        cout << getNode(list,i) << endl;

    cout << "delete knot 1:\n";
    temp = delNode(list,1);
    cout << "list from beginning:\n";
    for(int i = 1; i<=capacityList(list);i++)
        cout << getNode(list,i) << endl;

    // удалить весь список
    cout << "clear all list\n";
    while(temp){
        temp = delNode(list,1);
    }
    list = NULL;

    // вывести длину списка
    cout << capacityList(list) << endl;

    delete list;
    delete insnode;
    return 0;
}