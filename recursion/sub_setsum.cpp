//Subset Sums

/*
    Problem Statement:
    Given a array arr of integers, return the sums of all subsets in the list.  
    Return the sums in any order.
*/

/*
    Approach:

    Brute Force:
        Idea is to generate the power set of the array and then calculate the sum of each subset.
        This can be done using recursion.
        1. Base Case: If the array is empty, return a vector with a single element 0.
        2. Recursive Case: For each element in the array, we can either include it in the subset or not.
           - If we include it, we add its value to the sum of the subset.
           - If we do not include it, we simply take the sum of the subset without that element.
    
        3. Combine the results from both cases to get the final list of subset sums.

    Optimization:
         1. we will use recursion to generate the subset sums.
         2. we will have two parameters for the recursion:
            - index: to keep track of the current element in the array.
            - current_sum: to keep track of the sum of the current subset.
        3. we will use pick and not pick approach to generate the subset sums.
           - If we pick the current element, we add its value to the current sum and move to the next element.
           - If we do not pick the current element, we simply move to the next element without adding its value.
        4. base case will be when we reach the end of the array, we will add the current sum to the result vector.
        5. return the result vector containing all subset sums.
*/

/*
    Dry Run:
    Input: arr = [1, 2, 3]
    Output: [0, 1, 2, 3, 3, 4, 5, 6]
    Explanation:
    - The subsets are: [], [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3]
    - Their sums are: 0, 1, 2, 3, 3, 4, 5, 6
    - The output is the list of all subset sums: [0, 1, 2, 3, 3, 4, 5, 6]

*/

/*
    time complexity: O(2^n) where n is the number of elements in the array.
    space complexity: O(n) for the recursion stack.
*/

#include <iostream>
#include <vector>
using namespace std;

void subsetSumsHelper(const vector<int>& arr, int index, int current_sum, vector<int>& result){
    // Base case: If we have considered all the elements
    if(index == arr.size()){
        result.push_back(current_sum);
        return;
    }
    // Include the current element in the subset
    subsetSumsHelper(arr, index+1, current_sum+ arr[index],result);
    // Exclude the current element from the subset
    subsetSumsHelper(arr, index+1, current_sum,result);


}

vector<int> subsetSums(const vector<int>& arr) {
    vector<int> result;
    subsetSumsHelper(arr, 0, 0, result);
    return result;
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> result = subsetSums(arr);
    
    cout << "Subset Sums: ";
    for(int sum : result) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}