//39. Combination Sum

/*
    Given an array of distinct integers candidates and a target integer target, 
    return a list of all unique combinations of candidates where the chosen numbers sum to target.
    You may return the combinations in any order.

    The same number may be chosen from candidates an unlimited number of times. 
    Two combinations are unique if the frequency of at least one of the chosen numbers is different.

    The test cases are generated such that the number of unique combinations that sum up to 
    target is less than 150 combinations for the given input.
*/

/*
    Pattern: pick and not pick using backtracking

    Approach:
       1. we will be using 2 functions:
          - combinationSumHelper: This function will be used to generate the combinations.
          - combinationSum: This function will be used to find the combinations by calling the combinationSumHelper function.
        
        2. combinationalsum:
        // parameters:
            - candidates: the input array of integers.
            - target: the target integer.
        Logic:
            1. vector of vector of integers to store the combinations.
            2. vector of integers to store the current combination.
            3. call the recursive function to generate the combinations.
            // combinationSumHelper(int index, int target, const vector<int>& candidates, vector<int>& current, vector<vector<int>>& result):
            4. return the combinations.

        3. combinationSumHelper:
        // parameters:
            - index: the current index in the array.
            - target: the remaining target sum.
            - candidates: the input array of integers.
            - current: the current combination being generated.
            - result: to store the final list of combinations.
        Logic:
            1. if target is equal to 0, we have found a valid combination.
            //base case:
            if(index==candidates.size()){
                if(target == 0){
                    result.push_back(current);
                }
                return;
            }
            
            2. if target is less than 0, we have exceeded the target sum.
               if(candidates[index] <= target){
                    current.push_back(candidates[index]);
                    combinationSumHelper(index, target - candidates[index], candidates, current, result);
                    current.pop_back();
               }
            3. include the current element in the combination and call the recursive function with the same index.
            4. exclude the current element from the combination and call the recursive function with index + 1.
            5. combinationSumHelper(index + 1, target, candidates, current, result);

*/

/*
    time complexity: O(2^n) where n is the number of elements in the candidates array.
    space complexity: O(n) for the recursion stack.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> combinationSum(vector<int> candi, int &target){
    vector<vector<int>> result;
    vector<int> current;
    int index = 0;
    combinationSumHelper(index, target, candi, current, result);
    return result;

}

void combinationSumHelper(int index, int target, const vector<int>& candi, vector<int>& current, vector<vector<int>>& result){
    //Base Case: If we have reached the end of the array
    if(index == candi.size()){
        if(target == 0){
            result.push_back(current);
        }
        return;
    }
    // If the current element is less than or equal to the target, we can include it in the combination
    if(candi[index] <= target){
        current.push_back(candi[index]);
        combinationSumHelper(index, target - candi[index], candi, current, result);
        current.pop_back(); // Backtrack to explore other combinations
    }
    // Exclude the current element from the combination and move to the next element
    combinationSumHelper(index + 1, target, candi, current, result);
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> combinations = combinationSum(candidates, target);
    
    cout << "Combinations that sum to " << target << ":\n";
    for(const auto& combo : combinations) {
        cout << "[ ";
        for(int num : combo) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}