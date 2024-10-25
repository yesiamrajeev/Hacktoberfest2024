// BankAccount.java
class BankAccount {
    private String accountHolder;
    private double balance;

    // Constructor to initialize account
    public BankAccount(String accountHolder, double initialBalance) {
        this.accountHolder = accountHolder;
        this.balance = initialBalance;
    }

    // Method to deposit money
    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Successfully deposited $" + amount);
        } else {
            System.out.println("Deposit amount must be positive.");
        }
    }

    // Method to withdraw money
    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("Successfully withdrew $" + amount);
        } else {
            System.out.println("Insufficient balance or invalid amount.");
        }
    }

    // Method to display account details
    public void displayAccountDetails() {
        System.out.println("Account Holder: " + accountHolder);
        System.out.println("Current Balance: $" + balance);
    }

    public static void main(String[] args) {
        // Create a new bank account
        BankAccount account = new BankAccount("John Doe", 1000.00);

        // Display account details
        account.displayAccountDetails();

        // Perform deposit and withdrawal
        account.deposit(500);
        account.withdraw(300);

        // Display updated account details
        account.displayAccountDetails();
    }
}
