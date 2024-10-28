def start_game():
    print("Welcome to the Dungeon Escape!")
    print("You wake up in a dark dungeon with two doors in front of you.")
    print("One leads to freedom; the other leads to a monster!")
    choice = input("Do you go through door 1 or door 2? (Enter 1 or 2): ")

    if choice == "1":
        monster_room()
    elif choice == "2":
        treasure_room()
    else:
        print("Invalid choice! The dungeon swallows you in darkness.")
        game_over()

def monster_room():
    print("\nYou encounter a ferocious monster!")
    print("You can either fight it or try to run away.")
    choice = input("Do you FIGHT or RUN? (Enter 'fight' or 'run'): ").lower()

    if choice == "fight":
        print("You bravely fight the monster...")
        print("And... you win! The monster drops a key to the exit!")
        print("You unlock the dungeon door and escape. YOU WIN!")
    elif choice == "run":
        print("You try to run, but the monster catches you!")
        game_over()
    else:
        print("Invalid choice! The monster attacks!")
        game_over()

def treasure_room():
    print("\nYou enter a room filled with gold and jewels.")
    print("However, there's a sleeping dragon guarding the treasure.")
    choice = input("Do you take the treasure or leave quietly? (Enter 'take' or 'leave'): ").lower()

    if choice == "take":
        print("The dragon wakes up and incinerates you! GAME OVER.")
    elif choice == "leave":
        print("You quietly leave the room and find an exit. YOU WIN!")
    else:
        print("Invalid choice! The dragon wakes up!")
        game_over()

def game_over():
    print("\nGAME OVER! Thanks for playing.")

if __name__ == "__main__":
    start_game()
