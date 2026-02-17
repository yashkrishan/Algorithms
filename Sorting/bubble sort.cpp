// bubble sort
/*
Given an array of integers, sort the array in ascending order using the bubble sort algorithm.

Bubble sort works by repeatedly stepping through the list, comparing adjacent elements and swapping
them if they are in the wrong order. The pass through the list is repeated until no swaps are needed.

Example

Input : [5, 1, 4, 2, 8]
Output : [1, 2, 4, 5, 8]

Constraints:
- 1 <= n <= 1000 where n is the number of elements
- -10^9 <= A[i] <= 10^9

Time Complexity: O(n^2)
Space Complexity: O(n) for the returned copy
*/
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Sorts the input vector using bubble sort algorithm.
     * Returns a sorted copy without modifying the original vector.
     * 
     * @param A The input vector to sort
     * @return A new vector containing the sorted elements
     */
    vector<int> bubbleSort(vector<int> A);
};

// Helper function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

vector<int> Solution::bubbleSort(vector<int> A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    // Create a copy to avoid modifying the original
    vector<int> result = A;
    
    int n = result.size();
    
    // Edge case: empty or single element array is already sorted
    if (n <= 1) {
        return result;
    }
    
    // Bubble sort: repeat until no swaps are needed
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        
        // Last i elements are already in place, so we don't need to check them
        for (int j = 0; j < n - i - 1; j++) {
            if (result[j] > result[j + 1]) {
                // Swap adjacent elements if they are in wrong order
                swap(result[j], result[j + 1]);
                swapped = true;
            }
        }
        
        // If no swapping occurred in this pass, array is already sorted
        if (!swapped) {
            break;
        }
    }
    
    return result;
}
