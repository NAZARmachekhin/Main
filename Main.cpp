#include <bits/stdc++.h>
using namespace std;

struct TLinkThree
{
    int data = 0;
    int cnt = 1;
    TLinkThree* left = NULL, * right = NULL, * parent = NULL;
};


void push(TLinkThree*& head, int data)
{
    TLinkThree* new_ = new TLinkThree;
    new_->data = data;
    if (head == NULL)head = new_;
    else
    {
        bool connected = false;
        TLinkThree* temp = head;
        while (!connected)
        {
            if (data == temp->data)
            {
                temp->cnt++;
                connected = true;
            }
            else if (data <= temp->data)
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
            else if (data > temp->data)
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

void cout_tree(TLinkThree* head)
{
    if (head == NULL)return;
    cout_tree(head->left);
    cout << head->data << " " << head->cnt << "\n";
    cout_tree(head->right);
}

void fill_tree(TLinkThree*& head)
{
    int number;
    cin >> number;
    while (number != 0)
    {
        push(head, number);
        cin >> number;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    TLinkThree* head = NULL;
    fill_tree(head);
    cout_tree(head);
}