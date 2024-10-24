import itertools

def TSP(distance_matrix):
    num_cities = len(dist_mat)
    memo = {} #Memoization table
    
    def explore(curr_city, visited):
        # If all cities have been visited
        if visited == (1 << num_cities) - 1:
            return distance_matrix[curr_city][0]  # Return to starting city

        if (curr_city, visited) in memo:
            return memo[(curr_city, visited)]

        min_cost = float('inf')
        for next_city in range(num_cities):
            if (visited >> next_city) & 1 == 0:  # If next_city has not been visited
                cost = distance_matrix[curr_city][next_city] + explore(next_city, visited | (1 << next_city))
                min_cost = min(min_cost, cost)

        memo[(curr_city, visited)] = min_cost
        return min_cost

    return explore(0, 1)  # Start from the first city with only it visited

dist_mat = [
    [0, 10, 15, 20],
    [10, 0, 35, 25],
    [15, 35, 0, 30],
    [20, 25, 30, 0]
]

print("Minimum cost of visiting all cities:", TSP(dist_mat))
