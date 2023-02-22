/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
struct Node
{

    int val;
    Node *nxt;

public:
    Node()
    {
        this->nxt = nullptr;
    }
    Node(int val)
    {
        this->val = val;
        this->nxt = nullptr;
    }
} *tail = nullptr;


void insertAtHead(Node *&head, int val)
{
    Node *temp = new Node(val);
    temp->nxt = head;
    tail->nxt = temp;
    head = temp;
}

void insertTail(Node *&head,int val){
    Node *temp = new Node(val);
    
    
    temp->nxt = tail->nxt;
    tail ->nxt = temp;
   tail = temp;
}
int countLL(Node *head)
{
    int count = 0;
    Node *ptr = head;
    do{
        count++;
        ptr = ptr->nxt;
    }while (ptr != head);
    
    return count;
}
void insertAtParticular(Node *&head, int val, int pos)
{
    Node *temp = new Node(val);
    Node *p = head;
    Node *q = NULL;
    
    if(pos == 1)
    insertAtHead(head,val);
    
    else if(pos == countLL(head))
    insertTail(head,val);
    
    else{
     for (int i = 0; i < pos - 1; i++)
     {
        q = p;
        p = p->nxt;
     }

    temp->nxt = q->nxt;
    q->nxt = temp;
    }
}

void displayLL(Node *head)
{
    Node *ptr = head;
    do{
        cout << ptr->val << ' ';
        ptr = ptr->nxt;
    }while (ptr != head);
}
int main()
{
    Node *head = new Node(10);
    Node *first = new Node(12);
    Node *second = new Node(14);
    Node *third = new Node(16);
    head->nxt = first;
    first->nxt = second;
    second->nxt = third;
    third->nxt = head;
    tail = third;
    insertAtHead(head, 5);
    
    insertAtParticular(head, 13, 2);

    insertTail(head,24);
    int countNodes = countLL(head);

    displayLL(head);
    cout << '\n'
         << countNodes<<'\n'<<tail -> val;
    return 0;
}