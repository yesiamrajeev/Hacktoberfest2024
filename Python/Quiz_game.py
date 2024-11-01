import json
import random

# Initialize or load leaderboard
LEADERBOARD_FILE = "leaderboard.json"
try:
    with open(LEADERBOARD_FILE, "r") as file:
        leaderboard = json.load(file)
except FileNotFoundError:
    leaderboard = []

# Quiz questions and answers
questions = [
    {"question": "What is the capital of France?", "answer": "Paris"},
    {"question": "What is 5 + 7?", "answer": "12"},
    {"question": "What is the chemical symbol for water?", "answer": "H2O"},
    {"question": "Who wrote 'Romeo and Juliet'?", "answer": "Shakespeare"},
    {"question": "What planet is known as the Red Planet?", "answer": "Mars"}
]

def play_quiz():
    score = 0
    random.shuffle(questions)

    print("\nWelcome to the Quiz Game!")
    for i, q in enumerate(questions):
        print(f"Q{i+1}: {q['question']}")
        answer = input("Your answer: ").strip()

        if answer.lower() == q["answer"].lower():
            print("Correct!")
            score += 10
        else:
            print(f"Incorrect! The correct answer was: {q['answer']}")
    
    print(f"\nYour final score is: {score}")
    return score

def update_leaderboard(name, score):
    leaderboard.append({"name": name, "score": score})
    leaderboard.sort(key=lambda x: x["score"], reverse=True)
    with open(LEADERBOARD_FILE, "w") as file:
        json.dump(leaderboard, file, indent=4)
    print("Leaderboard updated!")

def view_leaderboard():
    print("\nLeaderboard:")
    for i, entry in enumerate(leaderboard[:5], start=1):
        print(f"{i}. {entry['name']} - {entry['score']} points")

def main():
    print("Welcome to the Quiz Game with Leaderboard!")
    while True:
        print("\nOptions:")
        print("1. Play the quiz")
        print("2. View leaderboard")
        print("3. Exit")

        choice = input("Choose an option: ")
        if choice == "1":
            name = input("Enter your name: ")
            score = play_quiz()
            update_leaderboard(name, score)
        elif choice == "2":
            view_leaderboard()
        elif choice == "3":
            print("Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
