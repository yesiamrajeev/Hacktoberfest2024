import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class NumberScramble {
    private static final Integer[] GOAL_STATE = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Generate a scrambled version of the goal state
        List<Integer> scrambledList = Arrays.asList(GOAL_STATE.clone());
        Collections.shuffle(scrambledList);
        Integer[] scrambledArray = scrambledList.toArray(new Integer[0]);

        int moves = 0;
        System.out.println("Welcome to Number Scramble!");
        System.out.println("Rearrange the numbers from 1 to 9 in the correct order by swapping them.");

        while (!Arrays.equals(scrambledArray, GOAL_STATE)) {
            System.out.println("\nCurrent Board:");
            printArray(scrambledArray);

            System.out.print("\nEnter the position of the first number to swap (1-9): ");
            int firstPosition = scanner.nextInt() - 1;

            System.out.print("Enter the position of the second number to swap (1-9): ");
            int secondPosition = scanner.nextInt() - 1;

            // Swap the two numbers
            swap(scrambledArray, firstPosition, secondPosition);
            moves++;

            System.out.println("Swap made. Total moves: " + moves);
        }

        System.out.println("\nCongratulations! You've arranged the numbers correctly in " + moves + " moves!");
        scanner.close();
    }

    // Function to swap two elements in the array
    private static void swap(Integer[] array, int index1, int index2) {
        int temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }

    // Function to print the array in a 3x3 grid format
    private static void printArray(Integer[] array) {
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
            if ((i + 1) % 3 == 0) {
                System.out.println(); // New line every 3 numbers
            }
        }
    }
}
