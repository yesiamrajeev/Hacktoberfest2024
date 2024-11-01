import json
from datetime import datetime
from getpass import getpass

# Initialize or load diary data
DIARY_FILE = "diary.json"
try:
    with open(DIARY_FILE, "r") as file:
        diary_data = json.load(file)
except FileNotFoundError:
    diary_data = {"password": "", "entries": []}

# Function to set up a new password
def set_password():
    new_password = getpass("Set a new password for your diary: ")
    confirm_password = getpass("Confirm your password: ")
    if new_password == confirm_password:
        diary_data["password"] = new_password
        save_diary_data()
        print("Password set successfully!")
    else:
        print("Passwords do not match. Try again.")
        set_password()

# Function to verify the password
def verify_password():
    if not diary_data["password"]:
        set_password()
    while True:
        password = getpass("Enter your password: ")
        if password == diary_data["password"]:
            print("Access granted!")
            break
        else:
            print("Incorrect password. Try again.")

# Function to add a diary entry
def add_entry():
    entry = input("Write your diary entry: ")
    date = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    diary_data["entries"].append({"date": date, "entry": entry})
    save_diary_data()
    print("Entry added successfully!")

# Function to view all diary entries
def view_entries():
    print("\nDiary Entries:")
    for i, entry in enumerate(diary_data["entries"], start=1):
        print(f"{i}. [{entry['date']}] {entry['entry']}\n")

# Function to save diary data to a file
def save_diary_data():
    with open(DIARY_FILE, "w") as file:
        json.dump(diary_data, file, indent=4)

def main():
    print("Welcome to your Personal Diary!")
    verify_password()
    while True:
        print("\nOptions:")
        print("1. Add a new entry")
        print("2. View all entries")
        print("3. Exit")

        choice = input("Choose an option: ")
        if choice == "1":
            add_entry()
        elif choice == "2":
            view_entries()
        elif choice == "3":
            print("Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
