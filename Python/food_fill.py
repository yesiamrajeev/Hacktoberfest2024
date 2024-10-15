def flood_fill(screen, x, y, new_color):
    # Get the starting pixel's original color
    original_color = screen[x][y]

    # If the original color is already the same as the new color, return
    if original_color == new_color:
        return

    # Define a helper function to perform the recursive flood fill
    def fill(x, y):
        # Check boundaries of the matrix
        if x < 0 or x >= len(screen) or y < 0 or y >= len(screen[0]):
            return
        # If the current cell is not of the original color, return
        if screen[x][y] != original_color:
            return
        
        # Change the color of the current pixel
        screen[x][y] = new_color

        # Recursively call fill for all 4 adjacent pixels (up, down, left, right)
        fill(x + 1, y)  # Down
        fill(x - 1, y)  # Up
        fill(x, y + 1)  # Right
        fill(x, y - 1)  # Left

    # Start the flood fill from the given starting point
    fill(x, y)

# Test the algorithm
screen = [
    [1, 1, 1, 2, 2],
    [1, 1, 0, 2, 2],
    [0, 0, 1, 2, 2],
    [1, 0, 1, 1, 2],
]

print("Before Flood-Fill:")
for row in screen:
    print(row)

# Apply flood fill starting at (1, 1) with new color 3
flood_fill(screen, 1, 1, 3)

print("\nAfter Flood-Fill:")
for row in screen:
    print(row)
