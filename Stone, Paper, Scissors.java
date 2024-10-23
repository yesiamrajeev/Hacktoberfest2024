import java.util.Random;
import java.util.Scanner;

public class StonePaperScissors {
    
    public static String determineWinner(String userChoice, String computerChoice) {
        if (userChoice.equals(computerChoice)) {
            return "It's a tie!";
        }
        
        switch (userChoice) {
            case "stone":
                return (computerChoice.equals("scissors")) ? "You win!" : "Computer wins!";
            case "paper":
                return (computerChoice.equals("stone")) ? "You win!" : "Computer wins!";
            case "scissors":
                return (computerChoice.equals("paper")) ? "You win!" : "Computer wins!";
            default:
                return "Invalid input.";
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();
        
        String[] choices = {"stone", "paper", "scissors"};
        
        System.out.println("Welcome to Stone, Paper, Scissors Game!");
        
        while (true) {
            System.out.print("Enter your choice (stone, paper, scissors) or 'exit' to quit: ");
            String userChoice = scanner.next().toLowerCase();
            
            if (userChoice.equals("exit")) {
                System.out.println("Thanks for playing! Goodbye.");
                break;
            }
            
            if (!userChoice.equals("stone") && !userChoice.equals("paper") && !userChoice.equals("scissors")) {
                System.out.println("Invalid choice. Please choose stone, paper, or scissors.");
                continue;
            }
            
            String computerChoice = choices[random.nextInt(3)];
            System.out.println("Computer's choice: " + computerChoice);
            
            String result = determineWinner(userChoice, computerChoice);
            System.out.println(result);
        }
        
        scanner.close();
    }
}
