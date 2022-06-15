

class TArray:
    def __init__(self, length: int):
        self.size = length
        self.array = [0 for i in range (self.size)]
        self.fill_array()

    def __str__(self):
        pass

    def increase(self, value):
        for i in range(self.size):
            self.array[i] += value

    def decrease(self, value):
        for i in range(self.size):
            self.array[i] -= value

    def fill_array(self):
        pass