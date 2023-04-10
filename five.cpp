#include <bits/stdc++.h>
using namespace std;

int calcCost(int arr[], int N)
{
    int c = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[i])
            {
                c++;
            }
        }
    }
    return c;
}

void swap(int arr[], int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int main()
{
    int N;
    cout << "----------SIMPLE HILL CLIMBING	\n\n";
    cout << "Enter the number of elements : ";
    cin >> N;
    int arr[N];
    cout << "\nEnter Elements : ";
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    int bestCost = calcCost(arr, N), newCost, swaps = 0;
    while (bestCost > 0)
    {
        for (int i = 0; i < N - 1; i++)
        {
            swap(arr, i, i + 1);
            newCost = calcCost(arr, N);

            if (bestCost > newCost)
            {
                cout << "After swap " << ++swaps << " : ";
                for (int i = 0; i < N; i++)
                {
                    cout << arr[i] << ' ';
                }
                cout << "\n\n";
                bestCost = newCost;
            }
            else
            {
                swap(arr, i, i + 1);
            }
        }
    }
    cout << "Final answer\n";
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}
