#include <bits/stdc++.h>
using namespace std;

struct TLinkThree
{
    int data = 0;
    string name="";
    TLinkThree* left = NULL, * right = NULL, * parent = NULL;
};


void push(TLinkThree*& head, int data, string name)
{
    TLinkThree* new_ = new TLinkThree;
    new_->data = data;
    new_->name = name;
    if (head == NULL)head = new_;
    else
    {
        bool connected = false;
        TLinkThree* temp = head;
        while (!connected)
        {
            if (name == temp->name)
            {
                temp->data += data;
                connected = true;
            }
            if (name < temp->name)
            {
                if (temp->left == NULL)
                {
                    new_->parent = temp;
                    temp->left = new_;
                    connected = true;
                }
                else
                    temp = temp->left;
            }
            if (name > temp->name)
            {
                if (temp->right == NULL)
                {
                    new_->parent = temp;
                    temp->right = new_;
                    connected = true;
                }
                else
                    temp = temp->right;
            }
        }
    }
}

void cout_money(TLinkThree* head, string name)
{
    while (head!=NULL && head->name != name)
    {
        if (name < head->name)head = head->left;
        else head = head->right;
    }
    if (head != NULL)cout << head->data << "\n";
    else cout << "ERROR\n";
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    TLinkThree* head = NULL;
    int cnt = 0;
    cin >> cnt;
    int cmd, money;
    string name;
    for (int i = 0; i < cnt; i++)
    {
        cin >> cmd>>name;
        if (cmd == 1)
        {
            cin >> money;
            push(head, money, name);
        }
        else
        {
            cout_money(head,name);
        }
    }
}