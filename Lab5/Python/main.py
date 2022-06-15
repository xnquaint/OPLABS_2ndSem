
from int_array import *
from float_array import *


def print_arrays(header: str, arrays: list[TArray]):
    print(header)
    for array in arrays:
        print(array)
    print("      ")

def get_max_average(int_arrays: list[IntArray], float_arrays: list[FloatArray] ):
    max_average = int_arrays[0].get_average()
    type = "int"
    index = 0
    array = []
    for i in range(len(int_arrays)):
        if int_arrays[i].get_average() >= max_average:
            max_average = int_arrays[i].get_average()
            index = i
            array = int_arrays[i]
    for j in range(len(float_arrays)):
        if float_arrays[j].get_average() >= max_average:
            max_average = float_arrays[j].get_average()
            type = "float"
            index = j
            array = float_arrays[j]
    return array, type, index, max_average


def main():
    int_arrays = []
    float_arrays = []
    m = 0
    while m <= 0:
        m = int(input("Enter m: "))
    for i in range(m):
        int_arrays.append(IntArray(5))
        float_arrays.append(FloatArray(5))
    print_arrays('Int arrays: ', int_arrays)
    print_arrays('Float arrays: ', float_arrays)

    value = int(input("Enter the value: "))
    for i in range(m):
        int_arrays[i].increase(value)
        float_arrays[i].decrease(value)
    print_arrays('Int arrays after operations: ', int_arrays)
    print_arrays('Float arrays after operations: ', float_arrays)
    array, kind, index, max_average = get_max_average(int_arrays, float_arrays)
    print(f'Max average: {max_average} \nType: {kind}. Index: {index+1}.\nArray: {array}')


if __name__ == '__main__':
    main()


