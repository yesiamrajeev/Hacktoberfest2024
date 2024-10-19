def is_perfect_number(n):
    """Check if a number is a perfect number."""
    if n < 1:
        return False
    
    divisors_sum = sum(i for i in range(1, n) if n % i == 0)
    return divisors_sum == n

def main():
    print("Perfect Number Checker")
    number = int(input("Enter a number: "))
    
    if is_perfect_number(number):
        print(f"{number} is a perfect number.")
    else:
        print(f"{number} is not a perfect number.")

if __name__ == "__main__":
    main()
