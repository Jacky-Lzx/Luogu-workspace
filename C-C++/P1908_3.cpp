#include <iostream>

using namespace std;

//// end include
//int cal(int* arrayPtr, int start, int end, int num)
//{
//    int count = 0;
//    for (int i = start; i <= end; i++)
//    {
//        if (arrayPtr[i] > num) count++;
//    }
//    return count;
//}

long mergeSort(int* arrayPtr, int num)
{
    if (num == 1)
        return 0;

    int middle = num / 2;

    long childCount = 0;
    childCount += mergeSort(arrayPtr, middle);
    childCount += mergeSort(arrayPtr + middle, num - middle);

//    for (int i = 0; i < num; i++)
//    {
//        cout << arrayPtr[i] << ' ';
//    }
//    cout << endl;

    int i = 0;
    int j = middle;

    int temp[num];
    int tempIndex = 0;

    long count = 0;
    while(true)
    {
        if (arrayPtr[i] <= arrayPtr[j])
        {
            temp[tempIndex++] = arrayPtr[i++];
            if (i == middle)
            {
                for (int t = j; t < num; t++)
                {
                    temp[tempIndex++] = arrayPtr[t];
                }
                break;
            }
        }
        else
        {
            count += middle - i;
            temp[tempIndex++] = arrayPtr[j++];
            if (j == num)
            {
                for (int t = i; t < middle; t++)
                {
                    temp[tempIndex++] = arrayPtr[t];
                }
                break;
            }
        }
    }
    for(int i = 0; i < num; i++)
    {
        arrayPtr[i] = temp[i];
    }

//    cout << num  << ":" << endl;
//    cout << count << " + " << childCount << endl;
    return count + childCount;
}

int main()
{
    int n;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];

    int* arrayPtr = array;

    long number = mergeSort(arrayPtr, n);

//    for (int i = 0; i < n; i++)
//    {
//        cout << array[i] << ' ';
//    }
//    cout << endl;
    cout << number << endl;
}