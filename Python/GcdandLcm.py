a, b = map(int, input("Enter two numbers: ").split())
gcd = lambda a, b: a if not b else gcd(b, a % b)
print("GCD:", gcd(a, b))
print("LCM:", a * b // gcd(a, b))
