// selection sort
/*
Selection Sort Algorithm Implementation

Time Complexity: O(n^2)
Space Complexity: O(1)
Is Stable: No (can be made stable with modifications)

Selection sort works by repeatedly finding the minimum element from the unsorted part
and putting it at the beginning. The algorithm maintains two subarrays:
1. The sorted portion at the beginning
2. The unsorted remainder

Example:
Input: [64, 25, 12, 22, 11]
Step 1: Find min in [64, 25, 12, 22, 11] -> 11, swap with 64 -> [11, 25, 12, 22, 64]
Step 2: Find min in [25, 12, 22, 64] -> 12, swap with 25 -> [11, 12, 25, 22, 64]
Step 3: Find min in [25, 22, 64] -> 22, swap with 25 -> [11, 12, 22, 25, 64]
Step 4: Find min in [25, 64] -> 25, swap with 25 -> [11, 12, 22, 25, 64]
Output: [11, 12, 22, 25, 64]
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Main selection sort algorithm function that sorts an integer vector in-place in ascending order
void selectionSort(vector<int>& nums) {
    int n = nums.size();
    
    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted portion
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[minIdx]) {
                minIdx = j;
            }
        }
        
        // Swap the found minimum element with the first element
        if (minIdx != i) {
            swap(nums[i], nums[minIdx]);
        }
    }
}

// Helper function to print vector elements to console for debugging and test output verification
void printVector(const vector<int>& nums, const string& label = "Array") {
    cout << label << ": ";
    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

// Validates that a vector is sorted in ascending order, used for test verification
bool verifySorted(const vector<int>& nums) {
    for (size_t i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[i - 1]) {
            return false;
        }
    }
    return true;
}

// Structure to hold test results
struct TestResult {
    int testCaseId;
    bool passed;
    vector<int> actualOutput;
    float executionTimeMs;
    string errorMessage;
};


// Executes a single test case by running selection sort and verifying the output matches expected result
TestResult runTestCase(int testId, const string& testName, const vector<int>& inputData, const vector<int>& expectedOutput) {
    TestResult result;
    result.testCaseId = testId;
    result.passed = false;
    result.executionTimeMs = 0.0f;
    result.errorMessage = "";
    
    // Make a copy of input for sorting
    vector<int> sortedData = inputData;
    
    // Run selection sort
    selectionSort(sortedData);
    
    result.actualOutput = sortedData;
    
    // Verify the result
    if (sortedData == expectedOutput) {
        result.passed = true;
    } else {
        result.errorMessage = "Output does not match expected result";
    }
    
    return result;
}

// Entry point function that runs all test cases and displays results for algorithm verification
int main() {
    cout << "Selection Sort Algorithm Tests" << endl;
    cout << "==============================" << endl << endl;
    
    // Test Case 1: General unsorted array
    {
        vector<int> input = {64, 25, 12, 22, 11};
        vector<int> expected = {11, 12, 22, 25, 64};
        TestResult result = runTestCase(1, "General unsorted array", input, expected);
        
        cout << "Test Case " << result.testCaseId << ": " << "General unsorted array" << endl;
        cout << "Input: ";
        printVector(input, "");
        cout << "Expected: ";
        printVector(expected, "");
        cout << "Actual: ";
        printVector(result.actualOutput, "");
        cout << "Status: " << (result.passed ? "PASSED" : "FAILED") << endl;
        if (!result.passed) {
            cout << "Error: " << result.errorMessage << endl;
        }
        cout << endl;
    }
    
    // Test Case 2: Already sorted array
    {
        vector<int> input = {1, 2, 3, 4, 5};
        vector<int> expected = {1, 2, 3, 4, 5};
        TestResult result = runTestCase(2, "Already sorted array", input, expected);
        
        cout << "Test Case " << result.testCaseId << ": " << "Already sorted array" << endl;
        cout << "Input: ";
        printVector(input, "");
        cout << "Expected: ";
        printVector(expected, "");
        cout << "Actual: ";
        printVector(result.actualOutput, "");
        cout << "Status: " << (result.passed ? "PASSED" : "FAILED") << endl;
        if (!result.passed) {
            cout << "Error: " << result.errorMessage << endl;
        }
        cout << endl;
    }
    
    // Test Case 3: Reverse sorted array
    {
        vector<int> input = {5, 4, 3, 2, 1};
        vector<int> expected = {1, 2, 3, 4, 5};
        TestResult result = runTestCase(3, "Reverse sorted array", input, expected);
        
        cout << "Test Case " << result.testCaseId << ": " << "Reverse sorted array" << endl;
        cout << "Input: ";
        printVector(input, "");
        cout << "Expected: ";
        printVector(expected, "");
        cout << "Actual: ";
        printVector(result.actualOutput, "");
        cout << "Status: " << (result.passed ? "PASSED" : "FAILED") << endl;
        if (!result.passed) {
            cout << "Error: " << result.errorMessage << endl;
        }
        cout << endl;
    }
    
    // Test Case 4: Single element
    {
        vector<int> input = {42};
        vector<int> expected = {42};
        TestResult result = runTestCase(4, "Single element", input, expected);
        
        cout << "Test Case " << result.testCaseId << ": " << "Single element" << endl;
        cout << "Input: ";
        printVector(input, "");
        cout << "Expected: ";
        printVector(expected, "");
        cout << "Actual: ";
        printVector(result.actualOutput, "");
        cout << "Status: " << (result.passed ? "PASSED" : "FAILED") << endl;
        if (!result.passed) {
            cout << "Error: " << result.errorMessage << endl;
        }
        cout << endl;
    }
    
    // Test Case 5: Empty array
    {
        vector<int> input = {};
        vector<int> expected = {};
        TestResult result = runTestCase(5, "Empty array", input, expected);
        
        cout << "Test Case " << result.testCaseId << ": " << "Empty array" << endl;
        cout << "Input: ";
        printVector(input, "");
        cout << "Expected: ";
        printVector(expected, "");
        cout << "Actual: ";
        printVector(result.actualOutput, "");
        cout << "Status: " << (result.passed ? "PASSED" : "FAILED") << endl;
        if (!result.passed) {
            cout << "Error: " << result.errorMessage << endl;
        }
        cout << endl;
    }
    
    // Test Case 6: Array with negative numbers
    {
        vector<int> input = {-5, 3, -10, 8, 0, -1};
        vector<int> expected = {-10, -5, -1, 0, 3, 8};
        TestResult result = runTestCase(6, "Array with negative numbers", input, expected);
        
        cout << "Test Case " << result.testCaseId << ": " << "Array with negative numbers" << endl;
        cout << "Input: ";
        printVector(input, "");
        cout << "Expected: ";
        printVector(expected, "");
        cout << "Actual: ";
        printVector(result.actualOutput, "");
        cout << "Status: " << (result.passed ? "PASSED" : "FAILED") << endl;
        if (!result.passed) {
            cout << "Error: " << result.errorMessage << endl;
        }
        cout << endl;
    }
    
    // Test Case 7: Array with duplicates
    {
        vector<int> input = {3, 1, 4, 1, 5, 9, 2, 6, 5};
        vector<int> expected = {1, 1, 2, 3, 4, 5, 5, 6, 9};
        TestResult result = runTestCase(7, "Array with duplicates", input, expected);
        
        cout << "Test Case " << result.testCaseId << ": " << "Array with duplicates" << endl;
        cout << "Input: ";
        printVector(input, "");
        cout << "Expected: ";
        printVector(expected, "");
        cout << "Actual: ";
        printVector(result.actualOutput, "");
        cout << "Status: " << (result.passed ? "PASSED" : "FAILED") << endl;
        if (!result.passed) {
            cout << "Error: " << result.errorMessage << endl;
        }
        cout << endl;
    }
    
    // Test Case 8: Two elements
    {
        vector<int> input = {2, 1};
        vector<int> expected = {1, 2};
        TestResult result = runTestCase(8, "Two elements", input, expected);
        
        cout << "Test Case " << result.testCaseId << ": " << "Two elements" << endl;
        cout << "Input: ";
        printVector(input, "");
        cout << "Expected: ";
        printVector(expected, "");
        cout << "Actual: ";
        printVector(result.actualOutput, "");
        cout << "Status: " << (result.passed ? "PASSED" : "FAILED") << endl;
        if (!result.passed) {
            cout << "Error: " << result.errorMessage << endl;
        }
        cout << endl;
    }
    
    cout << "==============================" << endl;
    cout << "All tests completed!" << endl;
    
    return 0;
}
