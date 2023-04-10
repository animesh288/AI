#include <bits/stdc++.h>
using namespace std;
int im = 3, ic = 3, i, fm = 0, fc = 0, status = 0, slt = 0;
bool flag = false;
void display(char bpass1, char bpass2)
{
    cout << "\n\n\n";
    for (int i = 0; i < fm; i++)
        cout << " M ";
    for (int i = 0; i < fc; i++)
        cout << " C ";
    if (flag == 0)
        cout << " ~~~~~WATER~~~~~<BOAT(" << bpass1 << "," << bpass2 << ")> ";
    else
        cout << " <BOAT(" << bpass1 << "," << bpass2 << ")>~~~~~WATER~~~~~ ";
    for (int i = 0; i < im; i++)
        cout << " M ";
    for (int i = 0; i < ic; i++)
        cout << " C ";
}
bool win()
{
    return (fc == 3 && fm == 3) ? 0 : 1;
}
void solution()
{
    while (win())
    {
        if (!flag)
        {
            switch (slt)
            {
            case 1:
                display('C', ' ');
                ic++;
                break;
            case 2:
                display('C', 'M');
                ic++;
                im++;
                break;
            }
            if (((im - 2) >= ic && (fm + 2) >= fc) || (im - 2) == 0)
            {
                im = im - 2;
                slt = 1;
                display('M', 'M');
                flag = 1;
            }
            else if ((ic - 2) < (im && (fm == 0 || (fc + 2) <= fm)) || im == 0)
            {
                ic = ic - 2;
                slt = 2;
                display('C', 'C');
                flag = 1;
            }
            else if ((ic--) <= (im--) && (fm++) >= (fc++))
            {
                ic = ic - 1;
                im = im - 1;
                slt = 3;
                display('M', 'C');
                flag = 1;
            }
        }
        else
        {
            switch (slt)
            {
            case 1:
                display('M', 'M');
                fm = fm + 2;
                break;
            case 2:
                display('C', 'C');
                fc = fc + 2;
                break;
            case 3:
                display('M', 'C');
                fc = fc + 1;
                fm = fm + 1;
                break;
            }
            if (win())
            {
                if (((fc > 1 && fm == 0) || im == 0))
                {
                    fc--;
                    slt = 1;
                    display('C', ' ');
                    flag = 0;
                }
                else if ((ic + 2) > im)
                {
                    fc--;
                    fm--;
                    slt = 2;
                    display('C', 'M');
                    flag = 0;
                }
            }
        }
    }
}
int main()
{
    cout << "MISSIONARIES AND CANNIBAL SOLUTION";
    display(' ', ' ');
    solution();
    display(' ', ' ');
    return 0;
}