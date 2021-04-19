#include <bits/stdc++.h>
using namespace std;

struct TLinkOne
{
    long long data = 0;
    long long stack_minimum = 0;
    TLinkOne* next;
};

void push(TLinkOne*& head, long long data)
{
    TLinkOne* n = new TLinkOne;
    n->data = data;
    n->next = head;
    n->stack_minimum = n->data;
    if (head != NULL)
    {
        n->stack_minimum = min(data, head->stack_minimum);
    }
    head = n;
}

bool pop(TLinkOne*& head)
{
    if (head==NULL)return false;
    TLinkOne* n = head;
    head = head->next;
    delete n;
    return true;
}

int back_min(TLinkOne* head)
{
    if (head==NULL)return 0;
    return head->stack_minimum;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    TLinkOne* head = NULL;
    long long a, b, c, x0;
    long long res = 0;
    int cnt = 0;
    cin >> cnt >> a >> b >> c >> x0;
    for (int i = 0; i < cnt; i++)
    {
        x0 = (a * x0 * x0 + b * x0 + c) / 100 % 1000000;
        if (x0 % 5 < 2)
            pop(head);
        else
            push(head, x0);
        res += back_min(head);
    }
    cout << res << "\n";
}