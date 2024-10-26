import java.util.Arrays;

public class RadixSort {

    // Function to get the maximum value in the array
    private static int getMax(int[] array) {
        int max = array[0];
        for (int i = 1; i < array.length; i++) {
            if (array[i] > max) {
                max = array[i];
            }
        }
        return max;
    }

    // A function to perform counting sort based on the specified digit place
    private static void countingSort(int[] array, int place) {
        int n = array.length;
        int[] output = new int[n];
        int[] count = new int[10]; // For digits 0 to 9

        // Count occurrences of each digit at the 'place'
        for (int i = 0; i < n; i++) {
            int digit = (array[i] / place) % 10;
            count[digit]++;
        }

        // Update count[i] so that it contains the actual position of this digit in output[]
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // Build the output array using count array
        for (int i = n - 1; i >= 0; i--) {
            int digit = (array[i] / place) % 10;
            output[count[digit] - 1] = array[i];
            count[digit]--;
        }

        // Copy the output array back to the original array
        System.arraycopy(output, 0, array, 0, n);
    }

    // The main function to implement Radix Sort
    public static void radixSort(int[] array) {
        int max = getMax(array);

        // Perform counting sort for each digit place (1, 10, 100, ...)
        for (int place = 1; max / place > 0; place *= 10) {
            countingSort(array, place);
        }
    }

    // Main method to test the Radix Sort implementation
    public static void main(String[] args) {
        int[] array = {170, 45, 75, 90, 802, 24, 2, 66};
        System.out.println("Original Array: " + Arrays.toString(array));

        radixSort(array);

        System.out.println("Sorted Array: " + Arrays.toString(array));
    }
}
