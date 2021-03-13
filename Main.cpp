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

    bool pop(TLinkOne *& head, int &data)
    {
        if (size_(head)==0)return false;
        data = head->data;
        TLinkOne* n=head;
        head = head->next;
        delete n;
        return true;
    }

    bool back_(TLinkOne* head, int &data)
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

    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        TLinkOne * head= NULL;
        string s;
        bool end=false;
        int data = 0;
        while (!end)
        {
            cin >> s;
            if (s == "exit")
            {
                end = true;
                cout << "bye\n";
            }
            if (s == "push")
            {
                cin >> data;
                push(head, data);
                cout << "ok" << "\n";
            }
            if (s == "pop")
            {
                if (!pop(head, data))cout << "error\n";
                else cout << data << "\n";
            }
            if (s == "back")
            {
                if (!back_(head, data))cout << "error\n";
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