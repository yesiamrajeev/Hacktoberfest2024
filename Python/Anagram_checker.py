def are_anagrams(str1, str2):
    # Remove spaces and convert to lowercase
    str1 = str1.replace(" ", "").lower()
    str2 = str2.replace(" ", "").lower()

    # Check if both strings have the same length
    if len(str1) != len(str2):
        return False

    # Use dictionaries to store character frequencies
    freq1 = {}
    freq2 = {}

    # Count characters in both strings
    for char in str1:
        freq1[char] = freq1.get(char, 0) + 1
    for char in str2:
        freq2[char] = freq2.get(char, 0) + 1

    # Compare the frequency dictionaries
    return freq1 == freq2

# Example usage:
str1 = input("Enter the first string: ")
str2 = input("Enter the second string: ")

if are_anagrams(str1, str2):
    print(f'"{str1}" and "{str2}" are anagrams.')
else:
    print(f'"{str1}" and "{str2}" are not anagrams.')
