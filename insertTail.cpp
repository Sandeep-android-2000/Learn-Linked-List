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
    head = temp;
}

void insertTail(Node *&head,int val){
    Node *temp = new Node(val);
    tail = head;
    while(tail->nxt){
        tail = tail->nxt;
    }

    temp->nxt = tail->nxt;
    tail ->nxt = temp;
   tail = temp;
}
int countLL(Node *head)
{
    int count = 0;
    Node *ptr = head;

    while (ptr)
    {
        count++;
        ptr = ptr->nxt;
    }
    return count;
}
void insertAtParticular(Node *&head, int val, int pos)
{
    Node *temp = new Node(val);
    Node *p = head;
    Node *q = NULL;

    for (int i = 0; i < pos - 1; i++)
    {
        q = p;
        p = p->nxt;
    }

    temp->nxt = q->nxt;
    q->nxt = temp;
}

void displayLL(Node *head)
{
    Node *ptr = head;
    while (ptr)
    {
        cout << ptr->val << ' ';
        ptr = ptr->nxt;
    }
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
    third->nxt = nullptr;

    insertAtHead(head, 5);
    insertAtParticular(head, 13, 4);

    insertTail(head,24);
    int countNodes = countLL(head);

    displayLL(head);
    cout << '\n'
         << countNodes<<'\n'<<tail -> val;
    return 0;
}