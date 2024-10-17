def is_prime(num):
    if num <= 1:
        return False  # Prime numbers are greater than 1
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False  # Divisible by a number other than 1 and itself
    return True

# Input from user
number = int(input("Enter a number to check if it is prime: "))

# Output the result
if is_prime(number):
    print(f"{number} is a prime number.")
else:
    print(f"{number} is not a prime number.")
