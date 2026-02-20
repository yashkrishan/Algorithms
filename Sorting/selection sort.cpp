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
//  Example:
//  Given: [64, 25, 12, 22, 11]
//  Pass 1: Find min in [64, 25, 12, 22, 11] -> 11, swap with 64 -> [11, 25, 12, 22, 64]
//  Pass 2: Find min in [25, 12, 22, 64] -> 12, swap with 25 -> [11, 12, 25, 22, 64]
//  Pass 3: Find min in [25, 22, 64] -> 22, swap with 25 -> [11, 12, 22, 25, 64]
//  Pass 4: Find min in [25, 64] -> 25, swap with 25 -> [11, 12, 22, 25, 64]
//  Result: [11, 12, 22, 25, 64]
//
//  Constraints:
//  ------------
//  - Time Complexity: O(n^2) - worst, average, and best cases
//  - Space Complexity: O(n) - returns a new sorted vector (does not modify input)
//  - Not stable: may change the relative order of equal elements
//  - In-place: No (returns sorted copy)
//
// ============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// ============================================================================
// Helper Functions
// ============================================================================

// Standalone swap helper function using pass-by-reference for efficient swapping
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Utility function to print vector elements to console for debugging
void printVector(const vector<int>& vec, const string& label = "Vector") {
    cout << label << ": [";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// Validates that a vector is sorted in ascending order
bool verifySorted(const vector<int>& vec) {
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
    // Public method that performs selection sort on input vector and returns sorted copy
    vector<int> selectionSort(vector<int> nums) {
        // Create a copy to avoid modifying the original vector
        vector<int> result = nums;
        int n = result.size();
        
        // Edge case: if array has 0 or 1 element, it's already sorted
        if (n <= 1) {
            return result;
        }
        
        // Selection sort algorithm
        // Outer loop: iterate through each position from 0 to n-1
        for (int i = 0; i < n - 1; ++i) {
            // Assume the current position has the minimum element
            int minIndex = i;
            
            // Inner loop: find the minimum element in the unsorted portion
            for (int j = i + 1; j < n; ++j) {
                if (result[j] < result[minIndex]) {
                    minIndex = j;
                }
            }
            
            // Swap the minimum element with the first unsorted element
            // Only swap if a smaller element was found
            if (minIndex != i) {
                swap(result[i], result[minIndex]);
            }
        }
        
        return result;
    }
};

// ============================================================================
// Main Function - Test Cases
// ============================================================================

int main() {
    Solution solution;
    
    cout << "========================================" << endl;
    cout << "     Selection Sort Algorithm Tests    " << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    // Test Case 1: Empty array
    {
        vector<int> input = {};
        vector<int> expected = {};
        vector<int> result = solution.selectionSort(input);
        
        cout << "Test 1: Empty Array" << endl;
        printVector(input, "  Input");
        printVector(result, "  Output");
        cout << "  Expected: []" << endl;
        cout << "  Status: " << (result == expected && verifySorted(result) ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 2: Single element
    {
        vector<int> input = {42};
        vector<int> expected = {42};
        vector<int> result = solution.selectionSort(input);
        
        cout << "Test 2: Single Element" << endl;
        printVector(input, "  Input");
        printVector(result, "  Output");
        cout << "  Expected: [42]" << endl;
        cout << "  Status: " << (result == expected && verifySorted(result) ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 3: Already sorted array
    {
        vector<int> input = {1, 2, 3, 4, 5};
        vector<int> expected = {1, 2, 3, 4, 5};
        vector<int> result = solution.selectionSort(input);
        
        cout << "Test 3: Already Sorted" << endl;
        printVector(input, "  Input");
        printVector(result, "  Output");
        cout << "  Expected: [1, 2, 3, 4, 5]" << endl;
        cout << "  Status: " << (result == expected && verifySorted(result) ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 4: Reverse sorted array
    {
        vector<int> input = {5, 4, 3, 2, 1};
        vector<int> expected = {1, 2, 3, 4, 5};
        vector<int> result = solution.selectionSort(input);
        
        cout << "Test 4: Reverse Sorted" << endl;
        printVector(input, "  Input");
        printVector(result, "  Output");
        cout << "  Expected: [1, 2, 3, 4, 5]" << endl;
        cout << "  Status: " << (result == expected && verifySorted(result) ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 5: Array with duplicates
    {
        vector<int> input = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
        vector<int> expected = {1, 1, 2, 3, 3, 4, 5, 5, 6, 9};
        vector<int> result = solution.selectionSort(input);
        
        cout << "Test 5: Array with Duplicates" << endl;
        printVector(input, "  Input");
        printVector(result, "  Output");
        printVector(expected, "  Expected");
        cout << "  Status: " << (result == expected && verifySorted(result) ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 6: Random unsorted array
    {
        vector<int> input = {64, 25, 12, 22, 11};
        vector<int> expected = {11, 12, 22, 25, 64};
        vector<int> result = solution.selectionSort(input);
        
        cout << "Test 6: Random Unsorted Array" << endl;
        printVector(input, "  Input");
        printVector(result, "  Output");
        cout << "  Expected: [11, 12, 22, 25, 64]" << endl;
        cout << "  Status: " << (result == expected && verifySorted(result) ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 7: Negative numbers
    {
        vector<int> input = {-5, 3, -2, 8, -1};
        vector<int> expected = {-5, -2, -1, 3, 8};
        vector<int> result = solution.selectionSort(input);
        
        cout << "Test 7: Negative Numbers" << endl;
        printVector(input, "  Input");
        printVector(result, "  Output");
        printVector(expected, "  Expected");
        cout << "  Status: " << (result == expected && verifySorted(result) ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 8: Two elements
    {
        vector<int> input = {2, 1};
        vector<int> expected = {1, 2};
        vector<int> result = solution.selectionSort(input);
        
        cout << "Test 8: Two Elements" << endl;
        printVector(input, "  Input");
        printVector(result, "  Output");
        cout << "  Expected: [1, 2]" << endl;
        cout << "  Status: " << (result == expected && verifySorted(result) ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 9: Verify input is not modified (returns copy)
    {
        vector<int> input = {5, 3, 8, 1, 2};
        vector<int> original = input;
        vector<int> result = solution.selectionSort(input);
        
        cout << "Test 9: Input Not Modified (Returns Copy)" << endl;
        printVector(original, "  Original Input");
        printVector(input, "  Input After Sort");
        printVector(result, "  Sorted Output");
        cout << "  Status: " << (input == original ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    cout << "========================================" << endl;
    cout << "         All Tests Completed!          " << endl;
    cout << "========================================" << endl;
    
    return 0;
}
