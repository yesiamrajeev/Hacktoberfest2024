import java.util.Random;
import java.util.Scanner;

public class SnakeAndLadder {
    static int playerPosition = 0;
    static int[][] snakes = { {27, 5}, {40, 3}, {43, 18}, {54, 31}, {66, 45}, {76, 58}, {89, 53}, {99, 41} };
    static int[][] ladders = { {4, 25}, {13, 46}, {33, 49}, {42, 63}, {50, 69}, {62, 81}, {74, 92}, {82, 98} };
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();
        boolean gameWon = false;

        while (!gameWon) {
            System.out.println("Press Enter to roll the dice");
            scanner.nextLine();
            int dice = random.nextInt(6) + 1;
            System.out.println("You rolled a " + dice);

            playerPosition += dice;

            if (playerPosition > 100) {
                playerPosition -= dice;
            } else {
                playerPosition = checkSnakesAndLadders(playerPosition);
            }

            System.out.println("You are now on square " + playerPosition);

            if (playerPosition == 100) {
                gameWon = true;
                System.out.println("Congratulations! You've won the game!");
            }
        }

        scanner.close();
    }

    static int checkSnakesAndLadders(int position) {
        for (int[] snake : snakes) {
            if (position == snake[0]) {
                System.out.println("Oops! Bitten by a snake. Slide down to " + snake[1]);
                return snake[1];
            }
        }

        for (int[] ladder : ladders) {
            if (position == ladder[0]) {
                System.out.println("Yay! Climbed a ladder. Move up to " + ladder[1]);
                return ladder[1];
            }
        }

        return position;
    }
}
