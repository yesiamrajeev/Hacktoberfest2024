import java.util.ArrayList;
import java.util.Collections;

public class BucketSort {

    // Main function to implement Bucket Sort
    public static void bucketSort(float[] array) {
        int n = array.length;
        if (n <= 0) return;

        // 1. Create an array of empty buckets
        ArrayList<Float>[] buckets = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            buckets[i] = new ArrayList<>();
        }

        // 2. Distribute elements into buckets
        for (float num : array) {
            int bucketIndex = (int) (num * n); // Index in the bucket array
            buckets[bucketIndex].add(num);
        }

        // 3. Sort each bucket
        for (int i = 0; i < n; i++) {
            Collections.sort(buckets[i]);
        }

        // 4. Concatenate all buckets back into the original array
        int index = 0;
        for (int i = 0; i < n; i++) {
            for (float num : buckets[i]) {
                array[index++] = num;
            }
        }
    }

    // Main method to test Bucket Sort implementation
    public static void main(String[] args) {
        float[] array = {0.42f, 0.32f, 0.23f, 0.52f, 0.25f, 0.47f, 0.51f};
        System.out.println("Original Array: ");
        for (float num : array) {
            System.out.print(num + " ");
        }
        
        bucketSort(array);

        System.out.println("\nSorted Array: ");
        for (float num : array) {
            System.out.print(num + " ");
        }
    }
}
