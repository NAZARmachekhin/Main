#include <bits/stdc++.h>
using namespace std;

struct TLinkTwo
{
    int data = 0;
    TLinkTwo* next = NULL;
    TLinkTwo* prev = NULL;
};

void push(TLinkTwo*& head, int data, char pos)
{
    if (head == NULL)
    {
        head = new TLinkTwo;
        head->data = data;
    }
    else if (pos == 'f')
    {
        TLinkTwo *temp=new TLinkTwo;
        temp->data = data;
        head->next = temp;
        temp->prev = head;
        head = temp;
    }
    else if (pos == 'b')
    {
        TLinkTwo* tail, *temp;
        tail = head;
        while (tail->prev!=NULL)
        {
            tail = tail->prev;
        }
        temp = new TLinkTwo;
        temp->next = tail;
        tail->prev = temp;
        temp->data = data;
    }
}

int size_(TLinkTwo* head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->prev;
    }
    return cnt;
}

void clear_(TLinkTwo*& head)
{
    while (head!=NULL)
    {
        TLinkTwo* temp = head;
        head = head->prev;
        delete temp;
    }
}

bool front(TLinkTwo*head, int&data)
{
    if (head == NULL)return false;
    data = head->data;
    return true;
}

bool back(TLinkTwo* head, int& data)
{
    if (head == NULL)return false;
    while (head->prev != NULL)head = head->prev;
    data = head->data;
    return true;
}

bool pop(TLinkTwo*& head, int& data, char pos)
{
    if (head == NULL)return false;
    if (head->prev == NULL)
    {
        data = head->data;
        clear_(head);
    }
    else if (pos == 'f')
    {
        data = head->data;
        TLinkTwo *temp = head;
        head = head->prev;
        head->next = NULL;
        delete temp;
    }
    else if (pos == 'b')
    {
        TLinkTwo * tail=head;
        while (tail->prev != NULL)
        {
            tail = tail->prev;
        }
        data = tail->data;
        tail->next->prev = NULL;
        delete tail;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    TLinkTwo* head = NULL;
    string s;
    bool end = false;
    int data = 0;
    while (!end)
    {
        cin >> s;
        if (s == "exit")
        {
            end = true;
            cout << "bye\n";
        }
        if (s == "push_front")
        {
            cin >> data;
            push(head, data,'f');
            cout << "ok" << "\n";
        }
        if (s == "push_back")
        {
            cin >> data;
            push(head, data,'b');
            cout << "ok" << "\n";
        }
        if (s == "pop_front")
        {
            if (!pop(head, data,'f'))cout << "error\n";
            else cout << data << "\n";
        }
        if (s == "pop_back")
        {
            if (!pop(head, data,'b'))cout << "error\n";
            else cout << data << "\n";
        }
        if (s == "front")
        {
            if (!front(head, data))cout << "error\n";
            else cout << data << "\n";
        }
        if (s == "back")
        {
            if (!back(head, data))cout << "error\n";
            else cout << data << "\n";
        }
        if (s == "size")cout << size_(head) << "\n";
        if (s == "clear")
        {
            clear_(head);
            cout << "ok\n";
        }
    }
}