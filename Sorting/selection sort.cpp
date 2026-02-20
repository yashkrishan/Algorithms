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
//  Pass 1: Find min in [64,25,12,22,11] -> 11, swap with 64 -> [11,25,12,22,64]
//  Pass 2: Find min in [25,12,22,64] -> 12, swap with 25 -> [11,12,22,25,64]
//  Pass 3: Find min in [22,25,64] -> 22, no swap needed -> [11,12,22,25,64]
//  Pass 4: Find min in [25,64] -> 25, no swap needed -> [11,12,22,25,64]
//  Result: [11, 12, 22, 25, 64]
//
//  Constraints:
//  ------------
//  - Time Complexity: O(n^2) - worst, average, and best cases
//  - Space Complexity: O(n) - returns a new sorted vector (O(n) space)
//  - In-place Space: O(1) - algorithm itself uses constant extra space
//  - Stable: No - equal elements may change relative order
//  - Adaptive: No - does not benefit from partially sorted arrays
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

// Swaps two integers by reference
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Prints vector elements to console
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
    // Performs selection sort on the input vector and returns a sorted copy
    // Time Complexity: O(n^2) - nested loops for finding min and swapping
    // Space Complexity: O(n) - returns a new sorted vector
    vector<int> selectionSort(const vector<int>& input) {
        // Create a copy to avoid modifying the original
        vector<int> result = input;
        
        int n = result.size();
        
        // Edge case: empty or single element array is already sorted
        if (n <= 1) {
            return result;
        }
        
        // Selection sort algorithm
        // Outer loop: iterate through each position in the array
        for (int i = 0; i < n - 1; ++i) {
            // Find the minimum element in the unsorted portion (from i to n-1)
            int minIndex = i;
            
            for (int j = i + 1; j < n; ++j) {
                if (result[j] < result[minIndex]) {
                    minIndex = j;
                }
            }
            
            // Swap the minimum element with the first unsorted element
            // only if the minimum is not already in the correct position
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
        printVector(input, "  Input   ");
        printVector(result, "  Output  ");
        cout << "  Expected: ";
        printVector(expected, "");
        cout << "  Status: " << (result == expected && verifySorted(result) ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 2: Single element
    {
        vector<int> input = {42};
        vector<int> expected = {42};
        vector<int> result = solution.selectionSort(input);
        
        cout << "Test 2: Single Element" << endl;
        printVector(input, "  Input   ");
        printVector(result, "  Output  ");
        cout << "  Expected: ";
        printVector(expected, "");
        cout << "  Status: " << (result == expected && verifySorted(result) ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 3: Already sorted
    {
        vector<int> input = {1, 2, 3, 4, 5};
        vector<int> expected = {1, 2, 3, 4, 5};
        vector<int> result = solution.selectionSort(input);
        
        cout << "Test 3: Already Sorted" << endl;
        printVector(input, "  Input   ");
        printVector(result, "  Output  ");
        cout << "  Expected: ";
        printVector(expected, "");
        cout << "  Status: " << (result == expected && verifySorted(result) ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 4: Reverse sorted
    {
        vector<int> input = {5, 4, 3, 2, 1};
        vector<int> expected = {1, 2, 3, 4, 5};
        vector<int> result = solution.selectionSort(input);
        
        cout << "Test 4: Reverse Sorted" << endl;
        printVector(input, "  Input   ");
        printVector(result, "  Output  ");
        cout << "  Expected: ";
        printVector(expected, "");
        cout << "  Status: " << (result == expected && verifySorted(result) ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 5: Array with duplicates
    {
        vector<int> input = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
        vector<int> expected = {1, 1, 2, 3, 3, 4, 5, 5, 6, 9};
        vector<int> result = solution.selectionSort(input);
        
        cout << "Test 5: Array with Duplicates" << endl;
        printVector(input, "  Input   ");
        printVector(result, "  Output  ");
        cout << "  Expected: ";
        printVector(expected, "");
        cout << "  Status: " << (result == expected && verifySorted(result) ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 6: Random unsorted array
    {
        vector<int> input = {64, 25, 12, 22, 11};
        vector<int> expected = {11, 12, 22, 25, 64};
        vector<int> result = solution.selectionSort(input);
        
        cout << "Test 6: Random Unsorted Array" << endl;
        printVector(input, "  Input   ");
        printVector(result, "  Output  ");
        cout << "  Expected: ";
        printVector(expected, "");
        cout << "  Status: " << (result == expected && verifySorted(result) ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 7: Negative numbers
    {
        vector<int> input = {-5, 3, -2, 8, -1, 0, 7};
        vector<int> expected = {-5, -2, -1, 0, 3, 7, 8};
        vector<int> result = solution.selectionSort(input);
        
        cout << "Test 7: Negative Numbers" << endl;
        printVector(input, "  Input   ");
        printVector(result, "  Output  ");
        cout << "  Expected: ";
        printVector(expected, "");
        cout << "  Status: " << (result == expected && verifySorted(result) ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 8: Two elements
    {
        vector<int> input = {2, 1};
        vector<int> expected = {1, 2};
        vector<int> result = solution.selectionSort(input);
        
        cout << "Test 8: Two Elements" << endl;
        printVector(input, "  Input   ");
        printVector(result, "  Output  ");
        cout << "  Expected: ";
        printVector(expected, "");
        cout << "  Status: " << (result == expected && verifySorted(result) ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 9: All same elements
    {
        vector<int> input = {7, 7, 7, 7};
        vector<int> expected = {7, 7, 7, 7};
        vector<int> result = solution.selectionSort(input);
        
        cout << "Test 9: All Same Elements" << endl;
        printVector(input, "  Input   ");
        printVector(result, "  Output  ");
        cout << "  Expected: ";
        printVector(expected, "");
        cout << "  Status: " << (result == expected && verifySorted(result) ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    // Test Case 10: Large array (verify it doesn't crash)
    {
        vector<int> input;
        for (int i = 100; i >= 1; --i) {
            input.push_back(i);
        }
        vector<int> result = solution.selectionSort(input);
        
        cout << "Test 10: Large Array (100 elements, reverse order)" << endl;
        cout << "  Input size: " << input.size() << endl;
        cout << "  Output size: " << result.size() << endl;
        cout << "  Status: " << (verifySorted(result) ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }
    
    cout << "========================================" << endl;
    cout << "         All Tests Completed!          " << endl;
    cout << "========================================" << endl;
    
    return 0;
}
