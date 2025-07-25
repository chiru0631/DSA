//40. Combination Sum II

/*
    Problem Statment:
    Given a collection of candidate numbers (candidates) and a target number (target), 
    find all unique combinations in candidates where the candidate numbers sum to target.

    Each number in candidates may only be used once in the combination.

    Note: The solution set must not contain duplicate combinations.
*/

/*
    Approach:
    1. We will use recursion to generate the combinations.
    
    we will be using 2 functions:
        - combinationSum2Helper: This function will be used to generate the combinations.
        - combinationSum2: This function will be used to find the combinations by calling the combinationSum2Helper function.

    combinationSum2 :
    // parameters:
         - candidates: the input array of integers.
         - target: the target integer.
    Logic: 
        1. vector of vector of integers to store the combinations.

        2. vector of integers to store the current combination.

        3. sort the input array to handle duplicates.
        4. call the recursive function to generate the combinations.
        // combinationSum2Helper(int index, int target, const vector<int>& candidates, vector<int>& current, vector<vector<int>>& result):
        5. return the combinations.

    combinationSum2Helper :
    // parameters:
        - index: the current index in the array.
        - target: the remaining target sum.
        - candidates: the input array of integers.
        - current: the current combination being generated.
        - result: to store the final list of combinations.
    Logic:
        1. if target is equal to 0, we have found a valid combination.
        //base case:
        
            if(target == 0){
                result.push_back(current);
            }
            return;
        
            2. iterate through the candidates starting from the current index.
        //for loop:
            if i > index and candidates[i] == candidates[i - 1], continue to avoid duplicates.;
        3. if the current candidate is greater than the target, break the loop as further candidates will also be greater.
        //if(candidates[i] > target) break;
        4. include the current candidate in the combination and recursively call the function with the next index and reduced target.
        //current.push_back(candidates[i]);
        combinationSum2Helper(i + 1, target - candidates[i], candidates, current, result);
        current.pop_back();

    }
}
*/

/*
    Time Complexity: O(2^n), where n is the number of candidates. In the worst case, we may explore all subsets of candidates.
    Space Complexity: O(n), where n is the number of candidates. The space is used for the recursion stack and to store the combinations.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void combinationSum2Helper(int index, int target, const vector<int>& candidates, vector<int>& current, vector<vector<int>>& result){
    if(target==0){
        result.push_back(current);
        return;
    }
    for(int i=index;i<candidates.size();i++){
        if(i>index && candidates[i]==candidates[i-1])continue; // skip duplicates
        if(candidates[i]>target) break;
        current.push_back(candidates[i]);
        combinationSum2Helper(i + 1, target - candidates[i], candidates, current, result);
        current.pop_back(); // backtrack
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
    vector<vector<int>> result;
    vector<int> current;
    sort(candidates.begin(), candidates.end());
    combinationSum2Helper(0, target, candidates, current, result);
    return result;
}

int main() {
    // Example usage
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> combinations = combinationSum2(candidates, target);
    
    // Output the combinations
    for (const auto& combo : combinations) {
        for (int num : combo) {
            cout << num << " ";
        }
        /*
        Output the combinations
        Example Output: 1 1 6 
                        1 2 5 
                        1 7 
                        2 6 
                        10
        */
        cout << endl;
    }
    
    return 0;
}

