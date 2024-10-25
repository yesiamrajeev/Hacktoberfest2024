class Event:
    def __init__(self, title, date, time):
        self.title = title
        self.date = date
        self.time = time

    def __str__(self):
        return f"{self.title} on {self.date} at {self.time}"


class EventManager:
    def __init__(self):
        self.events = []

    def add_event(self, title, date, time):
        event = Event(title, date, time)
        self.events.append(event)
        print(f"Event '{title}' added.")

    def view_events(self):
        if not self.events:
            print("No events scheduled.")
        else:
            print("Scheduled Events:")
            for idx, event in enumerate(self.events, start=1):
                print(f"{idx}. {event}")

    def delete_event(self, index):
        if 0 <= index < len(self.events):
            removed_event = self.events.pop(index)
            print(f"Event '{removed_event.title}' deleted.")
        else:
            print("Invalid event index.")


def main():
    manager = EventManager()
    while True:
        print("\nEvent Manager")
        print("1. Add Event")
        print("2. View Events")
        print("3. Delete Event")
        print("4. Exit")
        
        choice = input("Choose an option (1-4): ")

        if choice == '1':
            title = input("Enter event title: ")
            date = input("Enter event date (YYYY-MM-DD): ")
            time = input("Enter event time (HH:MM): ")
            manager.add_event(title, date, time)
        elif choice == '2':
            manager.view_events()
        elif choice == '3':
            index = int(input("Enter event index to delete: ")) - 1
            manager.delete_event(index)
        elif choice == '4':
            print("Exiting Event Manager.")
            break
        else:
            print("Invalid choice. Please try again.")


if __name__ == "__main__":
    main()
