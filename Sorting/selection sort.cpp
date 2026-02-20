// ============================================================================
//
// 
// 
//  Selection Sort Algorithm Implementation
// 
// 
// 
// ============================================================================
//
// 
//  Algorithm Description:
//  ---------------------
//  Selection Sort is a comparison-based sorting algorithm that divides the input
//  list into two regions: a sorted region at the left end and an unsorted region
//  at the right end. Initially, the sorted region is empty and the unsorted
//  region contains all elements. The algorithm proceeds by finding the minimum
//  element from the unsorted region and swapping it with the leftmost unsorted
//  element, thereby expanding the sorted region by one element. This process
//  repeats until the entire array is sorted.
// 
//  The algorithm maintains two subarrays:
//    1. The subarray containing the smallest elements (already sorted)
//    2. The remaining subarray (unsorted)
// 
//  At each iteration, the algorithm selects the minimum element from the
//  unsorted subarray and moves it to the beginning of the unsorted subarray,
//  effectively growing the sorted subarray by one element.
// 
// 
// 
//  Example:
//  --------
//  Input:  [64, 25, 12, 22, 11]
// 
//  Pass 1: Find min in [25, 12, 22, 11] -> 11, swap with 64
//          Result: [11, 25, 12, 22, 64]
// 
//  Pass 2: Find min in [12, 22, 64] -> 12, swap with 25
//          Result: [11, 12, 25, 22, 64]
// 
//  Pass 3: Find min in [22, 64] -> 22, swap with 25
//          Result: [11, 12, 22, 25, 64]
// 
//  Pass 4: Find min in [64] -> 64 (no swap needed)
//          Result: [11, 12, 22, 25, 64]
// 
//  Output: [11, 12, 22, 25, 64]
// 
// 
// 
//  Constraints:
//  -------------
//  - Input: A vector of integers
//  - Output: A new vector with elements sorted in ascending order
//  - Time Complexity: O(n^2) comparisons in worst/average/best cases
//  - Space Complexity: O(n) for the returned sorted copy
//  - The algorithm is NOT in-place; it returns a new sorted vector
//  - Handles duplicate elements correctly (stable with respect to equal elements)
//  - Works for any integer values within standard int range
// 
// 
// 
//  Complexity Analysis:
//  ---------------------
//  Time Complexity:
//    - Best Case:   O(n^2) - Even if array is already sorted, we still need to
//                   find the minimum in each pass
//    - Average:     O(n^2) - Same as worst case
//    - Worst Case:  O(n^2) - Must scan all remaining elements in each pass
// 
//  Space Complexity:
//    - O(n) additional space for the returned sorted copy
//    - O(1) auxiliary space for temporary variables
// 
//  Number of Comparisons:
//    - (n-1) + (n-2) + ... + 1 = n*(n-1)/2 = O(n^2)
// 
//  Number of Swaps:
//    - At most n-1 swaps (one per iteration)
//    - This is an advantage over bubble sort which may have O(n^2) swaps
// 
// 
// ============================================================================


#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>


using namespace std;

// ============================================================================
// Helper Functions
// ============================================================================

/**
 * Swaps two integers by reference.
 * 
 * @param a Reference to first integer
 * @param b Reference to second integer
 */
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/**
 * Prints vector elements to console for debugging.
 * 
 * @param vec The vector to print
 * @param label Optional label for the output
 */
void printVector(const vector<int>& vec, const string& label = "Vector") {
    cout << label << ": ";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

/**
 * Validates that a vector is sorted in ascending order.
 * 
 * @param vec The vector to validate
 * @return true if sorted, false otherwise
 */
bool verifySorted(const vector<int>& vec) {
    if (vec.size() <= 1) {
        return true;
    }
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            return false;
        }
    }
    return true;
}

// ============================================================================
// Solution Class
// ============================================================================

class Solution {
public:
    /**
     * Performs selection sort on input vector and returns sorted copy.
     * 
     * @param nums Input vector to be sorted
     * @return New vector with elements sorted in ascending order
     */
    vector<int> selectionSort(const vector<int>& nums) {
        // Create a copy to avoid modifying the original
        vector<int> result = nums;
        int n = result.size();
        
        // Edge case: no need to sort if array has 0 or 1 element
        if (n <= 1) {
            return result;
        }
        
        // Selection sort algorithm
        // Outer loop: iterate through each position from 0 to n-2
        for (int i = 0; i < n - 1; ++i) {
            // Find the minimum element in the unsorted portion
            int minIndex = i;
            
            // Inner loop: scan remaining unsorted elements
            for (int j = i + 1; j < n; ++j) {
                if (result[j] < result[minIndex]) {
                    minIndex = j;
                }
            }
            
            // Swap the found minimum with the element at position i
            // Only swap if the minimum is not already at position i
            if (minIndex != i) {
                swap(result[i], result[minIndex]);
            }
        }
        
        return result;
    }
};

// ============================================================================
// Main Function with Test Cases
// ============================================================================

int main() {
    Solution solution;
    
    cout << "========================================" << endl;
    cout << "Selection Sort Algorithm Test Suite" << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    // Test Case 1: Standard unsorted array
    {
        cout << "Test 1: Standard unsorted array" << endl;
        vector<int> input = {64, 25, 12, 22, 11};
        vector<int> expected = {11, 12, 22, 25, 64};
        vector<int> result = solution.selectionSort(input);
        
        printVector(input, "  Input");
        printVector(result, "  Output");
        printVector(expected, "  Expected");
        
        bool passed = (result == expected) && verifySorted(result);
        cout << "  Status: " << (passed ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 2: Empty array
    {
        cout << "Test 2: Empty array" << endl;
        vector<int> input = {};
        vector<int> expected = {};
        vector<int> result = solution.selectionSort(input);
        
        printVector(input, "  Input");
        printVector(result, "  Output");
        printVector(expected, "  Expected");
        
        bool passed = (result == expected) && verifySorted(result);
        cout << "  Status: " << (passed ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 3: Single element
    {
        cout << "Test 3: Single element" << endl;
        vector<int> input = {42};
        vector<int> expected = {42};
        vector<int> result = solution.selectionSort(input);
        
        printVector(input, "  Input");
        printVector(result, "  Output");
        printVector(expected, "  Expected");
        
        bool passed = (result == expected) && verifySorted(result);
        cout << "  Status: " << (passed ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 4: Already sorted array
    {
        cout << "Test 4: Already sorted array" << endl;
        vector<int> input = {1, 2, 3, 4, 5};
        vector<int> expected = {1, 2, 3, 4, 5};
        vector<int> result = solution.selectionSort(input);
        
        printVector(input, "  Input");
        printVector(result, "  Output");
        printVector(expected, "  Expected");
        
        bool passed = (result == expected) && verifySorted(result);
        cout << "  Status: " << (passed ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 5: Reverse sorted array
    {
        cout << "Test 5: Reverse sorted array" << endl;
        vector<int> input = {5, 4, 3, 2, 1};
        vector<int> expected = {1, 2, 3, 4, 5};
        vector<int> result = solution.selectionSort(input);
        
        printVector(input, "  Input");
        printVector(result, "  Output");
        printVector(expected, "  Expected");
        
        bool passed = (result == expected) && verifySorted(result);
        cout << "  Status: " << (passed ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 6: Array with duplicates
    {
        cout << "Test 6: Array with duplicates" << endl;
        vector<int> input = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
        vector<int> expected = {1, 1, 2, 3, 3, 4, 5, 5, 6, 9};
        vector<int> result = solution.selectionSort(input);
        
        printVector(input, "  Input");
        printVector(result, "  Output");
        printVector(expected, "  Expected");
        
        bool passed = (result == expected) && verifySorted(result);
        cout << "  Status: " << (passed ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 7: Two elements
    {
        cout << "Test 7: Two elements" << endl;
        vector<int> input = {2, 1};
        vector<int> expected = {1, 2};
        vector<int> result = solution.selectionSort(input);
        
        printVector(input, "  Input");
        printVector(result, "  Output");
        printVector(expected, "  Expected");
        
        bool passed = (result == expected) && verifySorted(result);
        cout << "  Status: " << (passed ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 8: Negative numbers
    {
        cout << "Test 8: Negative numbers" << endl;
        vector<int> input = {-5, 3, -10, 0, 7, -2};
        vector<int> expected = {-10, -5, -2, 0, 3, 7};
        vector<int> result = solution.selectionSort(input);
        
        printVector(input, "  Input");
        printVector(result, "  Output");
        printVector(expected, "  Expected");
        
        bool passed = (result == expected) && verifySorted(result);
        cout << "  Status: " << (passed ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 9: Large numbers
    {
        cout << "Test 9: Large numbers" << endl;
        vector<int> input = {1000000, 999999, 500000, 100, 1};
        vector<int> expected = {1, 100, 500000, 999999, 1000000};
        vector<int> result = solution.selectionSort(input);
        
        printVector(input, "  Input");
        printVector(result, "  Output");
        printVector(expected, "  Expected");
        
        bool passed = (result == expected) && verifySorted(result);
        cout << "  Status: " << (passed ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 10: Verify original array is not modified
    {
        cout << "Test 10: Verify original array is not modified" << endl;
        vector<int> input = {64, 25, 12, 22, 11};
        vector<int> originalCopy = input;
        vector<int> result = solution.selectionSort(input);
        
        bool passed = (input == originalCopy);
        cout << "  Original before: ";
        for (size_t i = 0; i < originalCopy.size(); ++i) {
            cout << originalCopy[i];
            if (i < originalCopy.size() - 1) cout << ", ";
        }
        cout << endl;
        cout << "  Original after:  ";
        for (size_t i = 0; i < input.size(); ++i) {
            cout << input[i];
            if (i < input.size() - 1) cout << ", ";
        }
        cout << endl;
        cout << "  Status: " << (passed ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    cout << "========================================" << endl;
    cout << "All tests completed!" << endl;
    cout << "========================================" << endl;
    
    return 0;
}
