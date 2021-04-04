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

int tree_level(TLinkThree* head)
{
    if (head == NULL) return 0;
    int cnt = 1;
    cnt += max(tree_level(head->left), tree_level(head->right));
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    TLinkThree* head = NULL;
    int number = 0;
    cin >> number;
    while (number != 0)
    {
        push(head, number, 1);
        cin >> number;
    }
    cout << tree_level(head) << "\n";
}