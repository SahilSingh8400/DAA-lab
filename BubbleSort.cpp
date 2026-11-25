#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    int comparisons = 0;
    int swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        bool flag = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swaps++;
                flag = true;
            }
        }

        if (!flag)
            break;
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nComparisons: " << comparisons;
    cout << "\nSwaps: " << swaps << endl;
}

int main()
{
    int arr[] = {2,4,5,7,8,4};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    return 0;
}