from random import *
from t_array import TArray


class IntArray(TArray):
    def get_average(self):
        sum = 0
        for i in self.array:
            sum += i
        return round(sum / self.size, 3)

    def __str__(self):
        return ' '.join([str(x).rjust(3, ' ') for x in self.array])

    def fill_array(self):
        for i in range(self.size):
            self.array[i] = randint(-100, 100)