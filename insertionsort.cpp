#include <iostream>
using namespace std;

void insertion(int arr[], int n)
{
    int comparisons = 0;
    int shifts = 0;

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0)
        {
            comparisons++;

            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                shifts++;
                j--;
            }
            else
            {
                break;
            }
        }

        arr[j + 1] = key;
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nComparisons: " << comparisons;
    cout << "\nShifts: " << shifts << endl;
}

int main()
{
    int arr[] = {4, 5, 1, 7, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertion(arr, n);

    return 0;
}