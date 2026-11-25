#include <bits/stdc++.h>
using namespace std;
struct Item
{
    int value;
    int weight;
};
bool compare(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}
double fractionalKnapsack(vector<Item> &items, int capacity)
{
    sort(items.begin(), items.end(), compare);
    double totalValue = 0.0;
    int currWeight = 0;
    for (int i = 0; i < (int)items.size(); i++)
    {
        if (currWeight + items[i].weight <= capacity)
        {
            currWeight += items[i].weight;
            totalValue += items[i].value;
        }
        else
        {
            int remain = capacity - currWeight;
            totalValue += items[i].value * ((double)remain / items[i].weight);
            break;
        }
    }
    return totalValue;
}
int main()
{
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;
    vector<Item> items(n);
    cout << "Enter value and weight of each item: ";
    for (int i = 0; i < n; i++)
        cin >> items[i].value >> items[i].weight;
    cout << "Enter capacity of knapsack: ";
    cin >> capacity;
    double result = fractionalKnapsack(items, capacity);
    cout << "Maximum value in knapsack: " << result << endl;
    cout << "This program is executed by Sahil Singh (Roll No: 2400320100951)" << endl;
    return 0;
}
