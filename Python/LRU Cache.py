from collections import OrderedDict

class LRUCache:
    def __init__(self, capacity: int):
        self.cache = OrderedDict()  # Stores the cache items
        self.capacity = capacity  # Maximum capacity of the cache

    def get(self, key: int) -> int:
        if key not in self.cache:
            print(f"Key {key} not found in cache.")
            return -1  # Return -1 if the key is not found

        # Move the accessed item to the end to show it was recently used
        self.cache.move_to_end(key)
        print(f"Retrieved {key}: {self.cache[key]}")
        return self.cache[key]

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            # Update the value and move it to the end
            self.cache.move_to_end(key)

        self.cache[key] = value  # Insert/Update the key-value pair

        if len(self.cache) > self.capacity:
            # Remove the oldest (first) item if the capacity is exceeded
            removed_key, removed_value = self.cache.popitem(last=False)
            print(f"Evicted {removed_key}: {removed_value}")

    def display(self):
        print("Cache state:", self.cache)

# Example Usage
if __name__ == "__main__":
    lru = LRUCache(3)  # Cache capacity of 3

    lru.put(1, 100)
    lru.put(2, 200)
    lru.put(3, 300)
    lru.display()

    lru.get(1)  # Access key 1 to make it recently used
    lru.put(4, 400)  # Add key 4, which will evict key 2 (the least recently used)
    lru.display()

    lru.get(2)  # Key 2 is evicted, so this should return -1
    lru.get(3)  # Access key 3
    lru.put(5, 500)  # Add key 5, evicting the least recently used key (1)
    lru.display()
