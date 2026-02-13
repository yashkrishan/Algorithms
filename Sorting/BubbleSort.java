import java.util.Arrays;
import java.util.Date;
import java.util.Random;

/**
 * BubbleSort implementation in Java.
 * This class provides an optimized Bubble Sort algorithm with O(n) best-case time complexity.
 * It includes methods for sorting, benchmarking, and validation, mirroring the specified interfaces.
 */
public class BubbleSort {

    // --- Data Models ---

    /**
     * Encapsulates the input data for the sorting algorithm.
     */
    public static class SortInput {
        public int[] elements;
        public String order; // "ASC" or "DESC"

        public SortInput(int[] elements, String order) {
            this.elements = elements;
            this.order = (order != null) ? order : "ASC";
        }
    }

    /**
     * Tracks performance statistics of the sorting execution.
     */
    public static class SortMetrics {
        public long comparison_count;
        public long swap_count;
        public long execution_time_ns;

        public SortMetrics(long comparison_count, long swap_count, long execution_time_ns) {
            this.comparison_count = comparison_count;
            this.swap_count = swap_count;
            this.execution_time_ns = execution_time_ns;
        }

        @Override
        public String toString() {
            return "SortMetrics{" +
                    "comparison_count=" + comparison_count +
                    ", swap_count=" + swap_count +
                    ", execution_time_ns=" + execution_time_ns + " ns" +
                    '}';
        }
    }

    /**
     * Represents the result of a sorting operation.
     */
    public static class SortResult {
        public int[] sorted_elements;
        public boolean is_sorted;
        public Date timestamp;

        public SortResult(int[] sorted_elements, boolean is_sorted) {
            this.sorted_elements = sorted_elements;
            this.is_sorted = is_sorted;
            this.timestamp = new Date();
        }
    }

    /**
     * Response structure for ExecuteBubbleSort interface.
     */
    public static class ExecuteBubbleSortResponse {
        public SortMetrics metrics;
        public int[] sorted_elements;

        public ExecuteBubbleSortResponse(SortMetrics metrics, int[] sorted_elements) {
            this.metrics = metrics;
            this.sorted_elements = sorted_elements;
        }
    }

    /**
     * Complexity information about the Bubble Sort implementation.
     */
    public static class AlgorithmInfo {
        public String name = "Bubble Sort";
        public boolean stable = true;
        public String time_complexity = "O(n^2)";
        public String space_complexity = "O(1)";

        @Override
        public String toString() {
            return "AlgorithmInfo{" +
                    "name='" + name + '\'' +
                    ", stable=" + stable +
                    ", time_complexity='" + time_complexity + '\'' +
                    ", space_complexity='" + space_complexity + '\'' +
                    '}';
        }
    }

    /**
     * Result of a benchmark execution.
     * Aligns with the RunBenchmark interface response.
     */
    public static class BenchmarkResult {
        public int array_size;
        public double average_time_ns;

        public BenchmarkResult(int array_size, double average_time_ns) {
            this.array_size = array_size;
            this.average_time_ns = average_time_ns;
        }

        @Override
        public String toString() {
            return "BenchmarkResult{" +
                    "array_size=" + array_size +
                    ", average_time_ns=" + String.format("%.2f", average_time_ns) + " ns" +
                    '}';
        }
    }

    // --- Core Implementation ---

    /**
     * Standard in-place bubble sort implementation.
     * This method provides a simple interface for sorting an array in ascending order.
     * Now returns SortMetrics to integrate metrics counting.
     * 
     * @param arr The array to be sorted.
     * @return SortMetrics containing performance data.
     */
    public static SortMetrics bubbleSort(int[] arr) {
        return sort(arr, "ASC");
    }

    /**
     * Executes the optimized bubble sort algorithm on the provided integer array.
     * 
     * @param elements The array of integers to be sorted.
     * @param order Desired sort order ("ASC" or "DESC").
     * @return SortMetrics containing performance data.
     */
    public static SortMetrics sort(int[] elements, String order) {
        long startTime = System.nanoTime();
        long comparisons = 0;
        long swaps = 0;

        if (elements == null || elements.length <= 1) {
            long endTime = System.nanoTime();
            return new SortMetrics(0, 0, endTime - startTime);
        }

        int n = elements.length;
        boolean swapped;
        boolean ascending = order == null || !order.equalsIgnoreCase("DESC");

        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                comparisons++;
                boolean shouldSwap = ascending ? (elements[j] > elements[j + 1]) : (elements[j] < elements[j + 1]);
                if (shouldSwap) {
                    // Swap elements[j] and elements[j+1]
                    int temp = elements[j];
                    elements[j] = elements[j + 1];
                    elements[j + 1] = temp;
                    swaps++;
                    swapped = true;
                }
            }
            // Optimization: if no two elements were swapped by inner loop, then break
            if (!swapped) {
                break;
            }
        }

        long endTime = System.nanoTime();
        return new SortMetrics(comparisons, swaps, endTime - startTime);
    }

    /**
     * Executes the optimized bubble sort algorithm on the provided integer array.
     * Aligns with the ExecuteBubbleSort interface.
     * 
     * @param input SortInput containing elements and order.
     * @return ExecuteBubbleSortResponse containing metrics and sorted elements.
     */
    public static ExecuteBubbleSortResponse executeBubbleSort(SortInput input) {
        if (input == null || input.elements == null) {
            return new ExecuteBubbleSortResponse(new SortMetrics(0, 0, 0), new int[0]);
        }
        SortMetrics metrics = sort(input.elements, input.order);
        return new ExecuteBubbleSortResponse(metrics, input.elements);
    }

    // --- Utility Methods ---

    /**
     * Retrieves complexity information about the Bubble Sort implementation.
     * Aligns with the GetAlgorithmInfo interface.
     */
    public static AlgorithmInfo getAlgorithmInfo() {
        return new AlgorithmInfo();
    }

    /**
     * Runs a performance benchmark with a generated random array of specified size.
     * Aligns with the RunBenchmark interface.
     * 
     * @param arraySize Size of the random array.
     * @param iterations Number of benchmark iterations.
     * @return BenchmarkResult containing average execution time.
     */
    public static BenchmarkResult runBenchmark(int arraySize, int iterations) {
        if (iterations <= 0) {
            return new BenchmarkResult(arraySize, 0);
        }
        long totalTime = 0;
        Random random = new Random();

        for (int i = 0; i < iterations; i++) {
            int[] arr = new int[arraySize];
            for (int j = 0; j < arraySize; j++) {
                arr[j] = random.nextInt();
            }
            SortMetrics metrics = sort(arr, "ASC");
            totalTime += metrics.execution_time_ns;
        }
        return new BenchmarkResult(arraySize, (double) totalTime / iterations);
    }

    /**
     * Utility to verify if an array is correctly sorted.
     * Optionally respects ASC/DESC order.
     * 
     * @param elements The array to check.
     * @param order Desired sort order ("ASC" or "DESC").
     * @return true if sorted, false otherwise.
     */
    public static boolean isSorted(int[] elements, String order) {
        if (elements == null || elements.length <= 1) {
            return true;
        }
        boolean ascending = order == null || !order.equalsIgnoreCase("DESC");
        for (int i = 0; i < elements.length - 1; i++) {
            if (ascending) {
                if (elements[i] > elements[i + 1]) {
                    return false;
                }
            } else {
                if (elements[i] < elements[i + 1]) {
                    return false;
                }
            }
        }
        return true;
    }

    /**
     * Utility to verify if an array is correctly sorted in ascending order.
     */
    public static boolean isSorted(int[] elements) {
        return isSorted(elements, "ASC");
    }

    /**
     * Utility to verify if an array is correctly sorted.
     * Aligns with the ValidateSort interface.
     * 
     * @param elements The array to validate.
     * @return SortResult containing validation status.
     */
    public static SortResult validateSort(int[] elements) {
        return validateSort(elements, "ASC");
    }

    /**
     * Utility to verify if an array is correctly sorted with specified order.
     * 
     * @param elements The array to validate.
     * @param order The order to check against.
     * @return SortResult containing validation status.
     */
    public static SortResult validateSort(int[] elements, String order) {
        return new SortResult(elements, isSorted(elements, order));
    }

    /**
     * Checks if the sorting service is operational.
     */
    public static String healthCheck() {
        return "{\"status\": \"UP\", \"version\": \"1.0.0\"}";
    }

    // --- Main Method for Testing ---

    public static void main(String[] args) {
        // Argument parsing for benchmark mode
        if (args.length > 0 && args[0].equalsIgnoreCase("--benchmark")) {
            int size = 1000;
            int iterations = 10;
            if (args.length >= 2) {
                try {
                    size = Integer.parseInt(args[1]);
                } catch (NumberFormatException ignored) {}
            }
            if (args.length >= 3) {
                try {
                    iterations = Integer.parseInt(args[2]);
                } catch (NumberFormatException ignored) {}
            }
            System.out.println("=== Bubble Sort Benchmark Mode ===");
            System.out.println("Array Size: " + size);
            System.out.println("Iterations: " + iterations);
            BenchmarkResult result = runBenchmark(size, iterations);
            System.out.println("Result:     " + result);
            return;
        }

        System.out.println("=== Bubble Sort Standalone Implementation ===");
        
        // 1. Example Unsorted Array
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        System.out.println("\n[Standard Sorting Test]");
        System.out.println("Original array: " + Arrays.toString(arr));
        
        // 2. Call bubbleSort (demonstrating it's in-place and returns metrics)
        int[] originalRef = arr;
        SortMetrics metrics = bubbleSort(arr);
        
        // 3. Print result
        System.out.println("Sorted array:   " + Arrays.toString(arr));
        System.out.println("In-place check: " + (arr == originalRef ? "PASSED (Same reference)" : "FAILED (Different reference)"));
        System.out.println("Metrics:        " + metrics);
        System.out.println("Is sorted:      " + isSorted(arr));

        // 4. Interface Alignment Tests
        System.out.println("\n[Interface Alignment Tests]");
        
        // ExecuteBubbleSort
        int[] arr2 = {5, 1, 4, 2, 8};
        SortInput input = new SortInput(arr2, "DESC");
        System.out.println("Executing sort (DESC) on: " + Arrays.toString(arr2));
        ExecuteBubbleSortResponse response = executeBubbleSort(input);
        System.out.println("Sorted result:  " + Arrays.toString(response.sorted_elements));
        System.out.println("Metrics:        " + response.metrics);
        
        // ValidateSort
        SortResult validation = validateSort(response.sorted_elements, "DESC");
        System.out.println("Validation (DESC check): " + validation.is_sorted);

        // 5. Edge Cases (Demonstrating they do not crash)
        System.out.println("\n[Edge Case Tests]");
        
        System.out.print("Testing null array: ");
        try {
            bubbleSort(null);
            System.out.println("PASSED (No crash)");
        } catch (Exception e) {
            System.out.println("FAILED (Crashed: " + e.getMessage() + ")");
        }

        int[] emptyArr = {};
        System.out.print("Testing empty array: ");
        bubbleSort(emptyArr);
        System.out.println("PASSED (No crash, result: " + Arrays.toString(emptyArr) + ")");

        int[] singleArr = {42};
        System.out.print("Testing single element array: ");
        bubbleSort(singleArr);
        System.out.println("PASSED (No crash, result: " + Arrays.toString(singleArr) + ")");

        // 6. Additional Features
        System.out.println("\n[Additional Features]");
        System.out.println("Algorithm Info: " + getAlgorithmInfo());
        System.out.println("Health Check:   " + healthCheck());
        
        // 7. Default Benchmark
        int size = 100;
        int iterations = 10;
        System.out.println("\n[Default Benchmark]");
        System.out.println("Running benchmark (Size: " + size + ", Iterations: " + iterations + ")...");
        BenchmarkResult result = runBenchmark(size, iterations);
        System.out.println("Result: " + result);
        System.out.println("\nTip: Run with '--benchmark [size] [iterations]' for custom benchmarks.");
    }
}
