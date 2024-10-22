
import java.util.*;

public class NaturalNumbersSum {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n;
        System.out.println("Enter a Number to print sum of n Numbers: ");

        n = s.nextInt();
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
        }

        System.out.println("The Sum is: " + sum);

    }
}
