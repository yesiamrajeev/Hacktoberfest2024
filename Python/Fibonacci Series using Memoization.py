memo = {}
def fibonacci(n):
    if n in memo:
        return memo[n]
    if n==1 or n==0:
        return n
    else:
        value = fibonacci(n-1) + fibonacci(n-2)
    memo[n] = value
    return value

for i in range(200):
    print(i, fibonacci(i))
