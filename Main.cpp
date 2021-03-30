#include <bits/stdc++.h>
using namespace std;

struct TLinkThree
{
    int data = 0;
    TLinkThree* left = NULL, * right = NULL, * parent = NULL;
};


void push(TLinkThree*& head, int data, bool ban_same=false)
{
    TLinkThree * new_ = new TLinkThree;
    new_->data = data;
    if (head == NULL)head = new_;
    else
    {
        bool connected = false;
        TLinkThree* temp = head;
        while (!connected)
        {
            if (ban_same && data == temp->data)connected=true;
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

int cont_tree(TLinkThree*& head)
{
    TLinkThree* temp = head;
    int cnt = 1;
    while (temp->left != NULL)
        temp = temp->left;
    while (temp != head)
    {
        cnt++;
        if (temp->right != NULL)
            cnt+=cont_tree(temp->right);
        temp = temp->parent;
    }
    if (head->right != NULL)
        cnt+=cont_tree(head->right);
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    TLinkThree *head = NULL;
    int number = 0;
    cin >> number;
    while (number != 0)
    {
        push(head, number,1);
        cin >> number;
    }
    cout << cont_tree(head) << "\n";
}