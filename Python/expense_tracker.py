import json
from datetime import datetime

# Initialize a file to store expenses
EXPENSE_FILE = "expenses.json"

# Load existing expenses or create a new file
try:
    with open(EXPENSE_FILE, "r") as file:
        expenses = json.load(file)
except FileNotFoundError:
    expenses = []

def add_expense():
    amount = float(input("Enter the expense amount: "))
    category = input("Enter the category (e.g., Food, Transport, etc.): ")
    description = input("Enter a short description: ")
    date = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

    expense = {
        "amount": amount,
        "category": category,
        "description": description,
        "date": date
    }

    expenses.append(expense)
    with open(EXPENSE_FILE, "w") as file:
        json.dump(expenses, file, indent=4)
    print("Expense added successfully!")

def view_expenses():
    print("\nExpenses:")
    for expense in expenses:
        print(f"Amount: {expense['amount']}, Category: {expense['category']}, Description: {expense['description']}, Date: {expense['date']}")
    print("\n")

def get_expenses_by_category():
    category = input("Enter the category to filter by: ")
    category_expenses = [exp for exp in expenses if exp["category"].lower() == category.lower()]

    print(f"\nExpenses in category '{category}':")
    for exp in category_expenses:
        print(f"Amount: {exp['amount']}, Description: {exp['description']}, Date: {exp['date']}")
    print("\n")

def total_expense():
    total = sum(exp["amount"] for exp in expenses)
    print(f"\nTotal expenses so far: ${total:.2f}\n")

def main():
    print("Welcome to the Expense Tracker!")
    while True:
        print("\nOptions:")
        print("1. Add an expense")
        print("2. View all expenses")
        print("3. View expenses by category")
        print("4. View total expenses")
        print("5. Exit")

        choice = input("Choose an option: ")
        if choice == "1":
            add_expense()
        elif choice == "2":
            view_expenses()
        elif choice == "3":
            get_expenses_by_category()
        elif choice == "4":
            total_expense()
        elif choice == "5":
            print("Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
