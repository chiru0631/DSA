//90. Subsets II

/*
    PROBLEM STATEMENT:
    Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

    The solution set must not contain duplicate subsets. Return the solution in any order.
*/

/*
    Approach:
    1. We will use recursion to generate the subset sums.

    we will be using 2 functions:
        - subsetwithoutduplicates: This function will be used to generate the subsets without duplicates.
        - findsubsets: This function will be used to find the subsets by calling the subsetwithoutduplicates function.

    subsetwithoutduplicates :
    // parameters:
         - arr: the input array of integers.
        Logic: 
            1. vector of vector of integers to store the subsets.
            2. vector of integers to store the current subset.
            3. sort the input array to handle duplicates.
            4. call the recursive function to generate the subsets.
            // findsubsets(int index, const vector<int>& arr, vector<int>& current, vector<vector<int>>& result):
            5. return the subsets.
    
    
    findsubsets :
        //parameters:
            - index: the current index in the array.
            - arr: the input array of integers.
            - current: the current subset being generated.
            - result: to store the final list of subsets.
    Logic:
            1. if index is equal to the size of the array, we have reached the end of the array.
            //base case:
            2. push the current subset into the result vector.
             if(index == arr.size()){
                result.push_back(current);
                return;
            }

            3. iterate through the array starting from the current index.
            for(int i = index; i < arr.size(); i++){
                // if the current element is equal to the previous element, skip it to avoid duplicates.
                if(i > index && arr[i] == arr[i-1]) continue;
                
                // include the current element in the subset
                current.push_back(arr[i]);
                findsubsets(i + 1, arr, current, result);
                
                // exclude the current element from the subset
                current.pop_back();
            }
            
            4. if the current element is equal to the previous element, skip it to avoid duplicates.
            5. include the current element in the subset and call the recursive function with index + 1.
            6. exclude the current element from the subset and call the recursive function with index + 1.
*/



/*
    Time Complexity: O(2^n) where n is the number of elements in the array.
    Space Complexity: O(n) for the recursion stack and O(2^n) for storing the subsets.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findsubsets(int index, vector<int>& current, const vector<int>& arr, vector<vector<int>>& result){
    // Base Case: If we have resched the end of the arry
    if(index == arr.size()){
        result.push_back(current);
        return;
    }

    // Iterate through the array starting from the current index
    for(int i=index;i<arr.size();i++){

        // If the current element is equal to the previous element, skip it to avoid duplicates
        if(i>index && arr[i]==arr[i-1]) continue;

        //include the current element in the subset
        current.push_back(arr[i]);
        findsubsets(i+1, current, arr, result);

        // Exclude the current element from the subset
        current.pop_back();
    }

}

vector<vector<int>> subsetwithoutduplicates(const vector<int>& arr){
    vector<vector<int>> result;
    vector<int> current;
    vector<int> sorted_arr = arr; // Create a copy of the input array
    sort(sorted_arr.begin(),sorted_arr.end()); // Sort the array to handle duplicates
    // Recursive function to find subsets
    findsubsets(0,current,sorted_arr,result);
    return result;
}

int main() {
    vector<int> arr = {1, 2, 2};
    vector<vector<int>> result = subsetwithoutduplicates(arr);
    
    cout << "Subsets without duplicates: " << endl;
    for(const auto& subset : result) {
        cout << "{ ";
        for(int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}