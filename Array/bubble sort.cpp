// bubble sort
/*
Given an array of integers, sort the array using bubble sort algorithm and return the sorted array.

Example:
Given [4, 3, 2, 1]
Return [1, 2, 3, 4]
*/

vector<int> Solution::bubbleSort(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    vector<int> res = A;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (res[j] > res[j + 1]) {
                int temp = res[j];
                res[j] = res[j + 1];
                res[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
    return res;
}
