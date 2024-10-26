import random
import curses

class Game2048:
    def __init__(self, size=4):
        self.size = size  # Size of the grid (4x4)
        self.grid = [[0] * size for _ in range(size)]  # Initialize empty grid
        self.score = 0  # Initialize score
        self.spawn_tile()
        self.spawn_tile()

    def spawn_tile(self):
        """Spawn a 2 or 4 randomly in an empty cell."""
        empty_cells = [(i, j) for i in range(self.size) for j in range(self.size) if self.grid[i][j] == 0]
        if empty_cells:
            i, j = random.choice(empty_cells)
            self.grid[i][j] = random.choice([2, 4])

    def compress(self, row):
        """Shift non-zero elements to the left."""
        new_row = [num for num in row if num != 0]
        new_row += [0] * (self.size - len(new_row))
        return new_row

    def merge(self, row):
        """Merge adjacent equal elements."""
        for i in range(self.size - 1):
            if row[i] == row[i + 1] and row[i] != 0:
                row[i] *= 2
                self.score += row[i]
                row[i + 1] = 0
        return row

    def move_left(self):
        """Handle left move."""
        for i in range(self.size):
            self.grid[i] = self.compress(self.merge(self.compress(self.grid[i])))

    def move_right(self):
        """Handle right move."""
        for i in range(self.size):
            self.grid[i] = self.compress(self.merge(self.compress(self.grid[i][::-1])))[::-1]

    def move_up(self):
        """Handle up move."""
        self.grid = list(zip(*self.grid))  # Transpose the grid
        self.move_left()
        self.grid = list(map(list, zip(*self.grid)))  # Transpose back

    def move_down(self):
        """Handle down move."""
        self.grid = list(zip(*self.grid))  # Transpose the grid
        self.move_right()
        self.grid = list(map(list, zip(*self.grid)))  # Transpose back

    def is_game_over(self):
        """Check if there are no valid moves left."""
        for i in range(self.size):
            for j in range(self.size):
                if self.grid[i][j] == 0:
                    return False  # There are empty cells
                if j < self.size - 1 and self.grid[i][j] == self.grid[i][j + 1]:
                    return False  # Adjacent horizontal cells can be merged
                if i < self.size - 1 and self.grid[i][j] == self.grid[i + 1][j]:
                    return False  # Adjacent vertical cells can be merged
        return True

    def display(self, stdscr):
        """Display the game grid using curses."""
        stdscr.clear()
        stdscr.addstr(f"Score: {self.score}\n")
        for row in self.grid:
            stdscr.addstr("+----" * self.size + "+\n")
            stdscr.addstr("|".join(f"{num:^4}" if num != 0 else "    " for num in row) + "|\n")
        stdscr.addstr("+----" * self.size + "+\n")
        stdscr.refresh()

    def play(self, stdscr):
        """Main game loop."""
        key_actions = {
            curses.KEY_LEFT: self.move_left,
            curses.KEY_RIGHT: self.move_right,
            curses.KEY_UP: self.move_up,
            curses.KEY_DOWN: self.move_down,
        }

        while True:
            self.display(stdscr)
            if self.is_game_over():
                stdscr.addstr("Game Over! Press 'q' to quit.\n")
                stdscr.refresh()
                if stdscr.getch() == ord('q'):
                    break
            key = stdscr.getch()
            if key == ord('q'):
                break
            elif key in key_actions:
                key_actions[key]()  # Perform the corresponding move
                self.spawn_tile()  # Spawn a new tile after each move

def main(stdscr):
    game = Game2048()
    game.play(stdscr)

if __name__ == "__main__":
    curses.wrapper(main)
