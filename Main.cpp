#include <bits/stdc++.h>
using namespace std;

struct TLinkOne
{
    int data = 0;
    TLinkOne* next = NULL;
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

void push_queue(TLinkOne*& head, int data)
{
    TLinkOne* n = new TLinkOne;
    n->data = data;
    if (head == NULL)head = n;
    else
    {
        TLinkOne* i = head;
        while (i->next != NULL)i = i->next;
        i->next = n;
    }
}


bool pop(TLinkOne*& head, int& data)
{
    if (size_(head) == 0)return false;
    data = head->data;
    TLinkOne* n = head;
    head = head->next;
    delete n;
    return true;
}

bool front(TLinkOne* head, int& data)
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

void fill(TLinkOne* &head, int len)
{
    int data;
    for (int i = 0; i < len; i++)
    {
        cin >> data;
        push_queue(head, data);
    }
}

bool win(int a, int b)
{
    if (a == 0 && b == 9)return true;
    if (a == 9 && b == 0)return false;
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    TLinkOne* igor = NULL, *artur=NULL;
    fill(artur, 5);
    fill(igor, 5);
    int cnt = 0;
    int igorCard=0, arturCard=0;
    while (size_(igor) * size_(artur) != 0 && cnt<1000000)
    {
        pop(igor, igorCard);
        pop(artur, arturCard);
        if (win(igorCard, arturCard))
        {
            push_queue(igor, arturCard);
            push_queue(igor, igorCard);
        }
        else
        {
            push_queue(artur, arturCard);
            push_queue(artur, igorCard);
        }
        cnt++;
    }
    if (cnt == 1000000)cout << "Botva\n";
    else
    {
        if (size_(igor) == 0)cout << "Artur ";
        else cout << "Igor ";
        cout << cnt << "\n";
    }
}