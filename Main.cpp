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

bool pop(TLinkOne*& head, int& data)
{
    if (size_(head) == 0)return false;
    data = head->data;
    TLinkOne* n = head;
    head = head->next;
    delete n;
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

int operate(int a, int b, char action)
{
    if (action == '+')return a + b;
    if (action == '-')return a - b;
    if (action == '*')return a * b;
    return 0;
}

bool check_num(string s)
{
    if (s.size() == 1 && isdigit(s[0]))return true;
    if (s.size() > 1)return true;
    return false;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    TLinkOne* nums = NULL;
    string s;
    int num1 = 0, num2 = 0;
    while (cin >> s)
    {
        if (check_num(s))
        {
            push(nums, stoll(s));
        }
        else
        {
            pop(nums, num2);
            pop(nums, num1);
            push(nums, operate(num1, num2, s[0]));
        }
    }
    pop(nums, num1);
    cout << num1 << "\n";
}