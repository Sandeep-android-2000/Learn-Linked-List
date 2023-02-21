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
};
void insertAtHead(Node *&head, int val)
{
    Node *temp = new Node(val);
    temp->nxt = head;
    head = temp;
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
    Node *ptr = head;
    while (ptr)
    {
        cout << ptr->val << ' ';
        ptr = ptr->nxt;
    }
    return 0;
}