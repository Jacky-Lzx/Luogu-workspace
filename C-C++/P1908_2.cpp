//unsolved

#include <iostream>
#include <vector>

using namespace std;

int divide(int* arrayPtr, int n)
{
    int number = 0;
    if (n == 2)
    {
        if (arrayPtr[0] > arrayPtr[1])
        {
            int temp = arrayPtr[0];
            arrayPtr[0] = arrayPtr[1];
            arrayPtr[1] = temp;
            return 1;
        }
        else
            return 0;
    }
    if (n == 1) return 0;

    int count = 0;
    int first = arrayPtr[0];

    int changeIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (arrayPtr[i] < first)
        {
            count++;
            int temp = arrayPtr[i];
            arrayPtr[i] = arrayPtr[changeIndex];
            arrayPtr[changeIndex] = temp;
            changeIndex++;
        }
    }

//    arrayPtr[0] = arrayPtr[changeIndex - 1];
//    arrayPtr[changeIndex - 1] = first;
//    changeIndex++;

    for (int i = 0; i < n; i++)
    {
        cout << arrayPtr[i] << ' ';
    }
    cout << endl;

    if (count == 0) return 0;
    number += count;
    number += divide(arrayPtr + changeIndex, n - changeIndex);
    number += divide(arrayPtr, changeIndex);
    return number;
}

int main()
{
    int n;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];

    int* arrayPtr = array;

    int number = divide(arrayPtr, n);

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
    cout << number << endl;
    
}