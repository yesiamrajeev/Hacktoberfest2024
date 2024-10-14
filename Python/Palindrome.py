value = input("Enter a string or number: ")
print("Palindrome" if value == value[::-1] else "Not a palindrome")
