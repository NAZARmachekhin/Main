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

void fill_tree(TLinkThree*& head)
{
    int number;
    cin >> number;
    while (number != 0)
    {
        push(head, number, 1);
        cin >> number;
    }
}

bool test_balanced(TLinkThree* head)
{
    if (head == NULL)return true;
    if (abs(tree_level(head->right) - tree_level(head->left)) > 1)return false;
    if (!test_balanced(head->left)) return false;
    if (!test_balanced(head->right)) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    TLinkThree* head = NULL;
    fill_tree(head);
    if (test_balanced(head))cout << "YES\n";
    else cout << "NO\n";
}