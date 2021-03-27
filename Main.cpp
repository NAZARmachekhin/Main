#include <bits/stdc++.h>
using namespace std;

struct TLinkOne
{
    int data = 0;
    TLinkOne* next;
};

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

bool push(TLinkOne*& head, int data, int pos)
{
    TLinkOne* n = new TLinkOne;
    n->data = data;
    if (pos == 0)
    {
        n->next = head;
        head = n;
    }
    else if (pos > size_(head)) return false;
    else
    {
        TLinkOne* cnt = head;
        for (int i = 1; i < pos; i++)
            cnt = cnt->next;
        n->next = cnt->next;
        cnt->next = n;
    }
    return true;
}


bool pop(TLinkOne*& head, int& data, int pos)
{
    if (size_(head) == 0)return false;
    if (pos + 1 > size_(head))return false;
    if (pos == 0)
    {
        data = head->data;
        TLinkOne* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    TLinkOne* temp, * cnt = head;
    for (int i = 1; i < pos; i++)cnt = cnt->next;
    temp = cnt->next;
    cnt->next = temp->next;
    data = temp->data;
    delete temp;
    return true;
}

bool back_(TLinkOne* head, int& data)
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

void fill(TLinkOne*& head)
{
    int data;
    int zeros=0;
    int _size = 0;
    while (cin >> data)
    {
        if (data)
        {
            push(head, data, _size);
            _size++;
        }
        else zeros++;
    }
    for (int i = 0; i < zeros; i++)
    {
        push(head, 0, _size);
        _size++;
    }
}

void out_list(TLinkOne* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    TLinkOne* head = NULL;
    fill(head);
    out_list(head);
}