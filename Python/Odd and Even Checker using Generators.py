# In this program we will print series of odd and even number using generator

def odd_even_checker(number_range):
    for i in range(1, number_range):
        if i % 2 == 0:
            yield f"{i} is even"
        else:
            yield f"{i} is odd"

data = odd_even_checker(20)

for values in data:
    print(values)
