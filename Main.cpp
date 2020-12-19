#include <bits/stdc++.h>
using namespace std;



class Tlong
{
    static const int Nmax = 10001;
    private:
        
        int len = 1;
        char sign = '+';
        int num[Nmax] = { 0 };

        bool comp_zero(Tlong a)
        {
            return !(a.len == 1 && a.num[Nmax - 1] == 0);
        }

        int compare_abs(Tlong a,Tlong b)
        {
            if (a.len != b.len)
            {
                if (a.len > b.len) return 1;
                return -1;
            }
            for (int i = 0; i < a.len; i++)
            {
                if (a.num[Nmax - a.len + i] > b.num[Nmax - b.len + i]) return 1;
                if (a.num[Nmax - a.len + i] < b.num[Nmax - b.len + i])  return -1;
            }
            return 0;
        }

        int compare(Tlong a, Tlong b)
        {
            if (a.sign != this->sign)
            {
                if (a.sign == '-')return 1;
                return -1;
            }
            if (a.sign == '-')return compare_abs(a,b)*-1;
            return compare_abs(a,b);
                
        }

        Tlong add_abs(Tlong a, Tlong b)
        {
            Tlong res;
            res.len = max(a.len, b.len) + 1;
            int next = 0;
            for (int i = 0; i < res.len; i++)
            {
                res.num[Nmax - i - 1] = (next+a.num[Nmax - i - 1] + b.num[Nmax - i - 1]) % 10;
                next = (next + a.num[Nmax - i - 1] + b.num[Nmax - i - 1]) / 10;
            }
            if (res.num[Nmax - res.len] == 0 && res.len>1)res.len--;
            return res;
        }

        Tlong substract_abs(Tlong dec, Tlong sub)
        {
            Tlong res;
            res.len = dec.len;
            for (int i = 1; i <= dec.len; i++)
            {
                if (dec.num[Nmax - i] < sub.num[Nmax - i])
                {
                    dec.num[Nmax - i - 1]--;
                    dec.num[Nmax - i] += 10;
                }
                res.num[Nmax - i] = dec.num[Nmax - i] - sub.num[Nmax - i];
            }
            while (res.num[Nmax - res.len] == 0 && res.len > 1) --res.len;
            return res;

        }

        Tlong add(Tlong a, Tlong b)
        {
            Tlong res;
            if (a.sign == b.sign)
            {
                res = add_abs(a, b);
                res.sign = a.sign;
            }
            else
            {
                if (compare_abs(a, b) == 1)res = substract_abs(a, b);
                else res = substract_abs(b, a);
                if (compare_abs(a, b) == 1)res.sign = a.sign;
                else res.sign = b.sign;
            }
            if (!comp_zero(res))res.sign = '+';
            return res;
        }

        void plusplus(Tlong& n)
        {
            if (n.sign == '-') decr_abs(n);
            else plusplus_abs(n);
            if (!comp_zero(n))n.sign = '+';
        }

        void decr(Tlong& n)
        {
            if (!comp_zero(n))n.sign = '-';
            if (n.sign == '+') decr_abs(n);
            else plusplus_abs(n);
            if (!comp_zero(n))n.sign = '+';
        }

        void plusplus_abs(Tlong& n)
        {
            int cnt = Nmax - 1;
            while (n.num[cnt] == 9)
            {
                n.num[cnt] = 0;
                cnt--;
            }
            n.num[cnt]++;
            if (n.num[Nmax - n.len - 1])n.len++;
        }

        void decr_abs(Tlong& n)
        {
            int cnt = Nmax - 1;
            while (n.num[cnt] == 0)
            {
                n.num[cnt] = 9;
                cnt--;
            }
            n.num[cnt]--;
            if (n.num[Nmax - n.len]==0 && n.len>1)n.len--;
        }

        Tlong multiply(Tlong a, Tlong b)
        {
            Tlong res;
            if (a.sign != b.sign)res.sign = '-';
            res.len = a.len + b.len + 11;
            for (int i = 1; i <= a.len; ++i)
                for (int j = 1; j <= b.len; ++j)
                    res.num[Nmax - i - j + 1] += a.num[Nmax - i] * b.num[Nmax - j];
            for (int i = 1; i < res.len; ++i)
            {
                res.num[Nmax - i - 1] += res.num[Nmax - i] / 10;
                res.num[Nmax - i] %= 10;
            }
            while (res.num[Nmax - res.len] == 0 && res.len > 1)--res.len;
            if (!comp_zero(res))res.sign = '+';
            return res;
        }

        void tenmult(Tlong& a)
        {
            if (comp_zero(a))a.len++;
            for (int i = a.len; i > 0; --i) a.num[Nmax - i - 1] = a.num[Nmax - i];
            a.num[Nmax - 1] = 0;
        }

        Tlong divide(Tlong a, Tlong b)
        {
            Tlong res, temp;
            res.len = a.len;
            int cnt = a.len;
            if (!comp_zero(b))
            {
                throw "Division by zero condition!";
            }
            while (cnt)
            {
                if (compare_abs(temp, b) == -1)
                {
                    tenmult(temp);
                    temp.num[Nmax - 1] = a.num[Nmax - cnt];
                    --cnt;
                }
                while (compare_abs(temp, b) != -1)
                {
                    temp = substract_abs(temp, b);
                    ++res.num[Nmax - cnt - 1];
                }
            }
            if (a.sign == b.sign)res.sign = '+';
            else res.sign = '-';
            if (!comp_zero(res)) res.sign= '+';
            while (res.num[Nmax - res.len] == 0 && res.len > 1)--res.len;
            return res;
        }

        Tlong mod_(Tlong a, Tlong b)
        {
            Tlong temp;
            int cnt = a.len;
            if (!comp_zero(b))
            {
                throw "Division by zero condition!";
            }
            while (cnt)
            {
                if (compare_abs(temp, b) == -1)
                {
                    tenmult(temp);
                    temp.num[Nmax - 1] = a.num[Nmax - cnt];
                    --cnt;
                }
                while (compare_abs(temp, b) != -1)
                {
                    temp = substract_abs(temp, b);
                }

            }
            if (a.sign == '+')temp.sign = '+';
            else temp.sign = '-';
            if (!comp_zero(temp))temp.sign = '+';
            return temp;
        }

        Tlong convert(int num)
        {
            Tlong res;
            if (num < 0)
            {
                res.sign = '-';
                num = -num;
            }
            int i = Nmax - 1;
            while (num)
            {
                res.num[i] = num % 10;
                num /= 10;
                i--;
                res.len++;
            }
            return res;
        }

        Tlong substract(Tlong a, Tlong b)
        {
            if (b.sign == '+')b.sign = '-';
            else b.sign = '+';
            return add(a, b);
        }

        Tlong multiply_halflong(Tlong a, int b)
        {
            Tlong res;
            if (b < 0)res.sign = '-';
            b = abs(b);
            if (res.sign == a.sign)res.sign = '+';
            else res.sign = '-';
            res.len = a.len;
            int next = 0;
            int multiply = 0;
            for (int i = 1; i <= res.len; i++)
            {
                multiply = (a.num[Nmax - i] * b + next);
                res.num[Nmax - i] = multiply % 10;
                next = multiply / 10;
            }
            while (next)
            {
                res.len++;
                res.num[Nmax - res.len] = next % 10;
                next /= 10;
            }
            while (res.num[Nmax - res.len] == 0 && res.len > 1) --res.len;
            if (!comp_zero(res))res.sign = '+';
            return res;
        }

        Tlong divide_halflong(Tlong a, int b)
        {
            Tlong result;
            if (b==0)
            {
                throw "Division by zero condition!";
            }
            else
            {
                if (b < 0)result.sign = '-';
                b = abs(b);
                if (result.sign == a.sign)result.sign = '+';
                else result.sign = '-';
                int dif = 0;
                for (int i = 0; i < a.len; i++)
                {
                    dif = dif * 10 + a.num[Nmax - a.len + i];
                    result.num[Nmax - a.len + i] = dif / b;
                    dif = dif % b;
                }
                result.len = a.len;
                while (result.num[Nmax - result.len] == 0 && result.len>1)result.len--;
                if (!comp_zero(result))result.sign = '+';
            }
            return result;
        }

        int mod_halflong(Tlong& a, int b)
        {
            if (b == 0)
            {
                throw "Division by zero condition!";
            }
            b = abs(b);
            int res;
            if (b == 0) res = 0;
            else
            {
                int dif = 0;
                for (int i = 0; i < a.len; i++)
                {
                    dif = dif * 10 + a.num[Nmax - a.len + i];
                    dif = dif % b;
                }
                res = dif;
            }
            if (a.sign == '-')res = -res;
            return res;
        }


    public:

        void factorial(int n)
        {
            Tlong res;
            res.num[Nmax-1]=1;
            for (int i = 2; i <= n; i++)
            {
                res *= i;
            }
            *this = res;
        }

        Tlong pow(int p)
        {
            Tlong res;
            res.len = 1;
            res.num[Nmax - 1] = 1;
            while (p)
            {
                if (p & 1)
                {
                    res = multiply(res, *this);
                    --p;
                }
                else
                {
                    *this = multiply(*this, *this);
                    p >>= 1;
                }
            }
            return res;
        }

        void operator = (int n)
        {
            *this = convert(n);
        }

        void operator += (int n)
        {
            *this = add(*this, convert(n));
        }

        void operator -= (int n)
        {
            *this = substract(*this, convert(n));
        }

        void operator *= (int n)
        {
            *this = multiply_halflong(*this, n);
        }

        void operator /= (int n)
        {
            *this = divide_halflong(*this, n);
        }

        void operator %= (int n)
        {
            *this = convert(mod_halflong(*this, n));
        }

        int operator % (int n)
        {
            return mod_halflong(*this, n);
        }

        Tlong operator /(int n)
        {
            return divide_halflong(*this, n);
        }

        Tlong operator *(int n)
        {
            return multiply_halflong(*this, n);
        }

        Tlong operator - (int n)
        {
            return substract(*this, convert(n));
        }

        Tlong operator + (int n)
        {
            return add(*this, convert(n));
        }

        void operator +=(Tlong a)
        {
            *this = add(*this, a);
        }

        void operator -=(Tlong a)
        {
            *this = substract_abs(*this, a);
        }

        void operator *=(Tlong a)
        {
            *this = multiply(*this, a);
        }

        void operator /=(Tlong a)
        {
            *this = divide(*this, a);
        }

        void operator %=(Tlong a)
        {
            *this = mod_(*this, a);
        }

        Tlong operator %(Tlong a)
        {
            return mod_(*this, a);
        }

        Tlong operator /(Tlong a)
        {
            return divide(*this, a);
        }

        Tlong operator *(Tlong a)
        {
            return multiply(*this, a);
        }

        Tlong operator --(int)
        {
            decr(*this);
            return *this;
        }

        Tlong& operator --()
        {
            decr(*this);
            return *this;
        }

        Tlong operator ++(int)
        {
            plusplus(*this);
            return *this;
        }

        Tlong& operator ++()
        {
            plusplus(*this);
            return *this;
        }

        Tlong operator +(Tlong a)
        {
            return add(*this,a);
        }

        Tlong operator - (Tlong a)
        {
            return substract(*this, a);
        }

        void input_long()
        {
            string s;
            cin >> s;
            if (s[0] == '+' || s[0] == '-')
            {
                this->sign = s[0];
                s.erase(0, 1);
            }
            else this->sign = '+';
            this->len = (s.size());
            for (int i = 0; i < s.size(); i++)
            {
                this->num[Nmax - this->len + i] = s[i] - 48;
            }
        }

        bool operator > (Tlong a)
        {
            if (compare(*this,a) == 1)return true;
            return false;
        }

        bool operator < (Tlong a)
        {
            if (compare(*this,a) == -1)return true;
            return false;
        }

        bool operator == (Tlong a)
        {
            if (compare(*this,a) == 0)return true;
            return false;
        }

        bool operator >= (Tlong a)
        {
            if (compare(*this,a) >=0)return true;
            return false;
        }

        bool operator <= (Tlong a)
        {
            if (compare(*this,a) <= 0)return true;
            return false;
        }

        bool operator != (Tlong a)
        {
            if (compare(*this,a) !=0)return true;
            return false;
        }

        bool operator > (int a)
        {
            if (compare(*this, convert(a)) == 1)return true;
            return false;
        }

        bool operator < (int a)
        {
            if (compare(*this, convert(a)) == -1)return true;
            return false;
        }

        bool operator == (int a)
        {
            if (compare(*this, convert(a)) == 0)return true;
            return false;
        }

        bool operator >= (int a)
        {
            if (compare(*this, convert(a)) >= 0)return true;
            return false;
        }

        bool operator <= (int a)
        {
            if (compare(*this, convert(a)) <= 0)return true;
            return false;
        }

        bool operator != (int a)
        {
            if (compare(*this, convert(a)) != 0)return true;
            return false;
        }

        void out_long(bool next_line = false)
        {
            if (!comp_zero(*this))this->sign = '+';
            if (this->sign == '-')
            {
                cout << '-';
            }
            for (int i = 0; i < this->len; i++)
            {
                cout << this->num[Nmax - this->len + i];
            }
            if (next_line)cout << "\n";
        }
};

void out_example(Tlong a, Tlong b, Tlong res, char operation)
{
    a.out_long();
    cout << operation;
    if (b < 0)cout << "(";
    b.out_long();
    if (b < 0)cout << ")";
    cout << "=";
    res.out_long();
}


Tlong num1, num2, mod, fact;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    num1.input_long();
    num2.input_long();
    int f;
    cin >> f;
    out_example(num1, num2, num1 + num2, '+');
    cout << "\n";
    out_example(num1, num2, num1 - num2, '-');
    cout << "\n";
    out_example(num1, num2, num1 * num2, '*');
    cout << "\n";
    if (num2 != 0)
    {
        out_example(num1, num2, num1 / num2, '/');
        cout << " (";
        (num1 % num2).out_long();
        cout << ")\n";
    }
    else cout << "Division by zero.\n";
    cout << f << "!=";
    fact.factorial(f);
    fact.out_long(1);
}