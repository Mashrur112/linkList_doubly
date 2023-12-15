#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
};
node *head = NULL;
node *tail = NULL;
void ins_last(int v)
{
    // cout<<"fsd";
    node *curr = head;
    node *temp;
    temp = new node();
    temp->data = v;
    temp->next = NULL;
    if (curr == NULL)
    {
        // cout<<"fsd";
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        while (curr->next != NULL)
        {
            curr = curr->next;
        }

        temp->prev = curr;
        // cout<<temp->prev->data;
        curr->next = temp;
        tail = temp;
    }
}
void ins_first(int v)
{
    node *curr = head;
    node *temp;
    temp = new node();
    temp->data = v;
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void ins_any_byPos(int p, int v)
{
    node *curr = head, *prev = head;
    node *temp;
    temp = new node();
    temp->data = v;
    int c = 1;
    while (curr != NULL)
    {
        if (c == p)
            break;
        prev = curr;
        curr = curr->next;
        c++;
    }
    if (c == 1)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else
    {
        prev->next = temp;
        temp->prev = prev;
        temp->next = curr;
        curr->prev = temp;
    }
}
void ins_any_byValue(int o, int n)
{
    node *curr = head, *prev = head;
    node *temp;
    int c = 1;

    while (curr != NULL)
    {
        if (curr->data == o)
            break;
        curr = curr->next;
        c++;
    }
    ins_any_byPos(c, n);
}
void del_byVal(int v)
{
    node *curr = head, *prev = head;
    while (curr != NULL)
    {
        if (curr->data == v)
            break;
        prev = curr;
        curr = curr->next;
    }
    if (curr == prev)
    {
        curr->next->prev = NULL;
        head = curr->next;
    }
    else
    {
        prev->next = curr->next;
        curr->next->prev = prev;
    }
}
void del_byPos(int p)
{
    node *curr = head, *prev = head;
    int c = 1;
    while (curr != NULL)
    {
        if (c == p)
            break;
        prev = curr;
        curr = curr->next;
        c++;
    }
    if (c == 1)
    {
        curr->next->prev = NULL;
        head = curr->next;
    }
    else
    {
        prev->next = curr->next;
        curr->next->prev = prev;
    }
}
void print_fToL()
{
    // cout<<"fsd";
    node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
void print_lToF()
{
    node *curr = tail;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}
void search(int v)
{
    node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == v)
            break;
        curr = curr->next;
    }
    if (curr == NULL)
        cout << "NOT FOUND!" << endl;
    else
        cout << "FOUND" << endl;
}
int size()
{
    node *curr = head;
    int c = 0;
    while (curr != NULL)
    {
        curr = curr->next;
        c++;
    }
    return c;
}
void del_first()
{
    node *curr = head;
    head = curr->next;
    curr->next->prev = NULL;
}
void del_last()
{
    node *curr = tail;
    tail = curr->prev;
    curr->prev->next = NULL;
}

int main()
{
    // cout<<endl;
    ins_last(10);
    print_fToL();

    print_lToF();
    ins_last(15);
    print_fToL();

    print_lToF();
    ins_first(5);
    print_fToL();

    print_lToF();
    ins_any_byPos(1, 7);
    print_fToL();

    print_lToF();
    ins_any_byPos(3, 40);
    print_fToL();

    print_lToF();
    ins_any_byPos(5, 50);
    print_fToL();

    print_lToF();
    ins_any_byValue(40, 45);
    print_fToL();

    print_lToF();
    del_byVal(7);
    print_fToL();

    print_lToF();
    del_byPos(3);
    print_fToL();

    print_lToF();
    search(40);
    print_fToL();

    print_lToF();
    search(10);
    print_fToL();

    print_lToF();
    search(5);
    print_fToL();

    print_lToF();
    del_first();
    print_fToL();

    print_lToF();
    del_last();
    print_fToL();

    print_lToF();
    cout << size() << endl;

    print_fToL();

    print_lToF();
}