//Fractional Knapsack

/*
    Problem Statement:

    Given two arrays, val[] and wt[], representing the values and weights of items, 
    and an integer capacity representing the maximum weight a knapsack can hold, 
    determine the maximum total value that can be achieved by putting items in the knapsack. 
    You are allowed to break items into fractions if necessary.
    Return the maximum value as a double, rounded to 6 decimal places.
    
*/

/*
    Approach:
    1. Create a vector of pairs to store the value-to-weight ratio for each item.
       - vector<pair<double, pair<int, int>>> items;// stores ratio, value, weight
    2. Calculate the value-to-weight ratio for each item and store it in the vector.
       - for (int i = 0; i < val.size(); i++) {
              - double ratio = static_cast<double>(val[i]) / wt[i];
              - items.push_back({ratio, {val[i], wt[i]}});
    }
    2. sort the items based on the value-to-weight ratio in descending order.
       - sort(items.begin(), items.end(), greater<>());// sort by ratio
       // or we could use a custom comparator
       - sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
           return a.first > b.first;
       });

    3. Initialize variables to keep track of the total value and remaining capacity.
       - double totalValue = 0.0;
       - int remainingCapacity = capacity;
    4. Iterate through the sorted items and add their values to the total value.
       - for (const auto& item : items) {
           - double ratio = item.first;
           - int value = item.second.first;
           - int weight = item.second.second;
           - if (remainingCapacity >= weight) {
               - totalValue += value;
               - remainingCapacity -= weight;
           - } else {
               - totalValue += ratio * remainingCapacity;
               - break;
           - }
       - }
    5. Return the total value rounded to 6 decimal places.
       - return round(totalValue * 1e6) / 1e6;

    Dry Run Example:
    val = {60, 100, 120};
    wt = {10, 20, 30};
    capacity = 50;

    1. Calculate ratios:
       - items = {{6.0, {60, 10}}, {5.0, {100, 20}}, {4.0, {120, 30}}}
    2. Sort items by ratio:
       - items = {{6.0, {60, 10}}, {5.0, {100, 20}}, {4.0, {120, 30}}}
    3. Initialize totalValue = 0.0, remainingCapacity = 50.
    4. Iterate through items:

         - For item {6.0, {60, 10}}:
              - remainingCapacity >= 10, so totalValue += 60, remainingCapacity -= 10 (totalValue = 60.0, remainingCapacity = 40)
         - For item {5.0, {100, 20}}:
              - remainingCapacity >= 20, so totalValue += 100, remainingCapacity -= 20 (totalValue = 160.0, remainingCapacity = 20)
         - For item {4.0, {120, 30}}:
              - remainingCapacity < 30, so totalValue += 4.0 * 20 (totalValue = 160.0 + 80.0 = 240.0)
    5. Return totalValue = 240.0, rounded to 6 decimal places = 240.000000.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // for std::setprecision
using namespace std;

double fractionalKnapsack(int capacity, vector<int>& val, vector<int>& wt){
    vector<pair<double,pair<int,int>>> items; // stores ratio, value, weight
    for(int i=0;i<val.size();i++){
        double ratio = double(val[i]) / wt[i];
        items.push_back({ratio, {val[i], wt[i]}});
    }
    // sort items by ratio in descending order
    sort(items.begin(), items.end(), greater<>());
    double totalValue = 0.0;
    int remainingCapacity = capacity;
    for(auto& item: items){
        double ratio = item.first;
        int value = item.second.first;
        int weight = item.second.second;
        if(remainingCapacity >= weight){
            totalValue += value;
            remainingCapacity -= weight;
        }
        else{
            totalValue += ratio * remainingCapacity;
            break; // knapsack is full
        }
    }
    return totalValue ;
}

int main() {
    vector<int> val = {60, 100, 120}; // values of items
    vector<int> wt = {10, 20, 30}; // weights of items
    int capacity = 50; // maximum weight capacity of knapsack
    cout << fixed << setprecision(6) << "Maximum value in Knapsack = " << fractionalKnapsack(capacity, val, wt) << endl;
    return 0;
}