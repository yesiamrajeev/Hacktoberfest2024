import java.util.Scanner;

public class PalindromeNumber {

    public static boolean isPalindrome(int x) {
        
        int length = String.valueOf(x).length();
        String num = String.valueOf(x);
        for (int i = 0; i < length; i++) {
            if (num.charAt(i) != num.charAt(length - 1 -i)){
                return false;
            }
        }
        return true;
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Input number: ");
        int num = scan.nextInt();
        System.out.println("Is it Palindrome?: " + isPalindrome(num));
    }
}