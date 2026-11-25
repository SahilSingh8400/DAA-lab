#include <iostream>
using namespace std;

// int linear(int arr[], int key, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == key)
//         {
//             return i;   
//         }
//     }
//     return -1;          
// }

int linear(int arr[],int key,int n){
    if(n==0){
        return -1;
    }
    if(arr[n-1]==key){
        return n-1;
    }

    return linear(arr,key,n-1);
}
int binary(int arr[], int key, int n)
{
    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 40;

    int pos = linear(arr, key, n);
    if (pos != -1)
        cout << "Linear Search: Element found at position " << pos + 1 << endl;
    else
        cout << "Linear Search: Element not found." << endl;

    pos = binary(arr, key, n);
    if (pos != -1)
        cout << "Binary Search: Element found at position " << pos + 1 << endl;
    else
        cout << "Binary Search: Element not found." << endl;

    return 0;
}