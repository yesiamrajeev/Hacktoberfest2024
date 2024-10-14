import java.util.Scanner;

class Selection_Sort {

    void initialize(int arr[]) {
        System.out.println("Enter array elements:");
        Scanner in = new Scanner(System.in);
        for (int i = 0; i < arr.length; i++)
            arr[i] = in.nextInt();
        in.close();
    }

    void display(int arr[]) {
        System.out.println("The array elements are:");
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    void sort(int arr[]) {
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length - 1 - i ; j++) {  
                if(arr[j]>arr[j+1]){
                    arr[j] = arr[j] + arr[j+1] - (arr[j+1] = arr[j]);
                }
            }
         }
    }

    public static void main(String args[]) {
        int[] arr = new int[5];
        Selection_Sort sorter = new Selection_Sort();  
        sorter.initialize(arr);
        sorter.display(arr);
        sorter.sort(arr);
        sorter.display(arr);
    }
}