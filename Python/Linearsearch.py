arr = list(map(int, input("Enter array elements: ").split()))
target = int(input("Enter target element: "))
print(arr.index(target) if target in arr else -1)
