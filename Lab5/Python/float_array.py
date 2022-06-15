from random import *
from t_array import TArray


class FloatArray(TArray):
    def get_average(self):
        sum = 0
        for i in self.array:
            sum += i
            return round(sum / self.size, 2)

    def __str__(self):
        return ' '.join(['{:.2f}'.format(x).rjust(6, ' ') for x in self.array])

    def fill_array(self):
        for i in range(self.size):
            self.array[i] = round(random() + randint(-100, 100), 2)