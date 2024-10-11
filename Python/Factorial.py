def factorial(n):
    result = 1
    for i in range(2, n + 1):
        result *= i
    return result

if __name__ == "__main__":
    num = int(input("Enter a number to find its factorial: "))
    print(f"The factorial of {num} is {factorial(num)}")
