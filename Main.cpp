#include <bits/stdc++.h>
using namespace std;

struct TLinkThree
{
    int data = 0;
    TLinkThree* left = NULL, * right = NULL, * parent = NULL;
};


void push(TLinkThree*& head, int data, bool ban_same = false)
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
            if (ban_same && data == temp->data)connected = true;
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


void fill_tree(TLinkThree *&head)
{
    int number;
    cin >> number;
    while (number != 0)
    {
        push(head, number, 1);
        cin >> number;
    }
}

void find_brunches(TLinkThree* head, int& len, int m[])
{
    if (head == NULL)return;
    find_brunches(head->left, len, m);
    if ((head->left!=NULL && head->right==NULL)||(head->left==NULL && head->right))
    {
        m[len] = head->data;
        len++;
    }
    find_brunches(head->right, len, m);
}

void out_arr(int m[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << m[i] << " ";
    }
    cout << "\n";
}

int brunches[100000];
int len = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    TLinkThree* head = NULL;
    fill_tree(head);
    find_brunches(head, len, brunches);
    out_arr(brunches, len);
}