import java.util.*;

public class Fibonacci {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the number of Fibonacci numbers to display:");
        int num = s.nextInt();

        int a = 0, b = 1; // Starting values for the Fibonacci sequence

        System.out.println("Fibonacci Series:");

        for (int i = 0; i < num; i++) {
            System.out.print(a + " "); // Print the current number
            int next = a + b; // Calculate the next number
            a = b; // Update a to the next number
            b = next; // Update b to the next number
        }

        s.close();
    }
}
