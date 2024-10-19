#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class Income {
public:
    std::string source;
    double amount;
    std::string date;
    std::string category;

    Income(std::string s, double a, std::string d, std::string c) 
        : source(s), amount(a), date(d), category(c) {}

    void display() {
        std::cout << "Source: " << source << ", Amount: " << amount 
                  << ", Date: " << date << ", Category: " << category << std::endl;
    }
};

class Expense {
public:
    std::string description;
    double amount;
    std::string date;
    std::string category;

    Expense(std::string d, double a, std::string dt, std::string c) 
        : description(d), amount(a), date(dt), category(c) {}

    void display() {
        std::cout << "Description: " << description << ", Amount: " << amount 
                  << ", Date: " << date << ", Category: " << category << std::endl;
    }
};

class Goal {
public:
    std::string name;
    double targetAmount;
    double currentSavings;
    std::string deadline;

    Goal(std::string n, double ta, double cs, std::string dl) 
        : name(n), targetAmount(ta), currentSavings(cs), deadline(dl) {}

    void display() {
        std::cout << "Goal: " << name << ", Target: " << targetAmount 
                  << ", Current: " << currentSavings << ", Deadline: " << deadline << std::endl;
    }
};

class User {
public:
    std::string username;
    std::string password;
    std::vector<Income> incomes;
    std::vector<Expense> expenses;
    std::vector<Goal> goals;

    User(std::string u, std::string p) : username(u), password(p) {}

    void addIncome(const Income& income) {
        incomes.push_back(income);
    }

    void addExpense(const Expense& expense) {
        expenses.push_back(expense);
    }

    void addGoal(const Goal& goal) {
        goals.push_back(goal);
    }

    void displayFinancialOverview() {
        std::cout << "Incomes: \n";
        for (const auto& inc : incomes) inc.display();
        
        std::cout << "Expenses: \n";
        for (const auto& exp : expenses) exp.display();
        
        std::cout << "Goals: \n";
        for (const auto& g : goals) g.display();
    }
};

class FinanceManager {
private:
    std::vector<User> users;

public:
    void registerUser(const std::string& username, const std::string& password) {
        users.push_back(User(username, password));
    }

    void displayUsers() {
        for (const auto& user : users) {
            std::cout << "User: " << user.username << std::endl;
        }
    }
};

int main() {
    FinanceManager financeManager;
    financeManager.registerUser("JohnDoe", "password123");

    User& currentUser = financeManager.users[0];
    currentUser.addIncome(Income("Job Salary", 5000, "2024-01-01", "Salary"));
    currentUser.addExpense(Expense("Groceries", 300, "2024-01-02", "Food"));
    currentUser.addGoal(Goal("Vacation", 2000, 500, "2024-12-31"));

    currentUser.displayFinancialOverview();

    return 0;
}
