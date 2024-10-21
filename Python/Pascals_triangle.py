def generate_pascals_triangle(rows):
    triangle = []

    for i in range(rows):
        row = [1]  # First element is always 1
        if i > 0:
            for j in range(1, i):
                # Sum of the two numbers directly above the current element
                row.append(triangle[i - 1][j - 1] + triangle[i - 1][j])
            row.append(1)  # Last element is always 1
        triangle.append(row)

    return triangle

def print_pascals_triangle(triangle):
    for row in triangle:
        print(' '.join(map(str, row)).center(2 * len(triangle[-1])))

# Input from the user
num_rows = int(input("Enter the number of rows for Pascal's Triangle: "))
triangle = generate_pascals_triangle(num_rows)
print_pascals_triangle(triangle)
