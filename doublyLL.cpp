#include <iostream>
using namespace std;
struct Node
{

    int val;
    Node *nxt;
    Node *prev;

public:
    Node()
    {
        this->nxt = nullptr;
        this->prev = nullptr;
    }
    Node(int val)
    {
        this->val = val;
        this->nxt = nullptr;
        this->prev = nullptr;
    }
} *tail = nullptr;

void insertAtHead(Node *&head, int val)
{
    Node *temp = new Node(val);
    temp->nxt = head;
    temp->prev = nullptr;
    head = temp;
}

void insertTail(Node *&head, int val)
{
    Node *temp = new Node(val);
    tail = head;

    while (tail->nxt)
    {
        tail = tail->nxt;
    }

    temp->nxt = tail->nxt;
    temp->prev = tail;
    tail->nxt = temp;
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
    if (pos == 1)
        insertAtHead(head, val);
    else if (pos == countLL(head))
        insertTail(head, val);
    else
    {
        Node *p = head;
        Node *q = NULL;

        for (int i = 0; i < pos - 1; i++)
        {
            q = p;
            p = p->nxt;
        }

        temp->nxt = q->nxt;
        temp->prev = q;
        q->nxt = temp;
        p->prev = temp;

    }
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
    head->prev = nullptr;
    first->nxt = second;
    first->prev = head;
    second->nxt = third;
    second->prev = first;
    third->nxt = nullptr;
    third->prev = second;

    insertAtHead(head, 5);

    insertTail(head, 24);
    insertAtParticular(head, 13, 6);
    int countNodes = countLL(head);

    displayLL(head);
    cout << '\n'
         << countNodes << '\n'
         << tail->val;
    return 0;
}