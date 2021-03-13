#include <bits/stdc++.h>
using namespace std;

struct TLinkOne
{
    int data = 0;
    TLinkOne* next;
};

void push(TLinkOne*& head, int data)
{
    TLinkOne* n = new TLinkOne;
    n->data = data;
    n->next = head;
    head = n;
}

int size_(TLinkOne* head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

bool pop(TLinkOne *& head)
{
    if (size_(head)==0)return false;
    TLinkOne* n=head;
    head = head->next;
    delete n;
    return true;
}

bool back_(TLinkOne* head, int &data)
{
    if (size_(head) == 0)return false;
    data = head->data;
    return true;
}


void clear_(TLinkOne*& top)
{
    while (top != NULL)
    {
        TLinkOne* temp = top;
        top = top->next;
        delete temp;
    } 
}

bool closed(int a, int b)
{
    if (a == '(' && b == ')')return true;
    if (a == '{' && b == '}')return true;
    if (a == '[' && b == ']')return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    TLinkOne * head = NULL;
    char data;
    while (cin >> data)
    {
        if (size_(head) == 0)push(head, data);
        else
        {
            if (closed(head->data, data))pop(head);
            else push(head, data);
        }
    }
    if (size_(head) == 0)cout << "YES\n";
    else cout << "NO\n";
}