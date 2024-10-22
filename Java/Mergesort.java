import java.util.Arrays;

public class Mergesort {
    public static void main(String[] args) {
        int[] arr = {9,8,7,6,5,4,3,2,1};
        mergeSort(arr);
        System.out.println(Arrays.toString(arr));
    }

    public static void mergeSort(int[] arr) {
        int start = 0;
        int end = arr.length-1;
        mergeSort(arr, start, end);
    }

    private static void mergeSort(int[] arr, int start, int end) {
        if (start == end) {
            return;
        }
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }

    private static void merge(int[] arr, int start, int mid, int end) {
        int i = start;
        int j = mid+1;
        int k = 0;
        int[] merged = new int[end-start+1];
        while (i <= mid && j <= end) {
            if (arr[i] < arr[j]) {
                merged[k] = arr[i];
                i++;
            } else {
                merged[k] = arr[j];
                j++;
            }
            k++;
        }
        while (i <= mid) {
            merged[k] = arr[i];
            i++;
            k++;
        }
        while (j <= end) {
            merged[k] = arr[j];
            j++;
            k++;
        }
        System.arraycopy(merged, 0, arr, start, merged.length);
    }
}
