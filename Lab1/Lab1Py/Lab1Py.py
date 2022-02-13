from module import *

first = "first.txt"
second = "second.txt"
third = "third.txt"

writeFile(first)
writeFile(second)
print("First file: ")
outFile(first)
print("Second file: ")
outFile(second)
k = createThird(first, second, third)
print("Third file: ")
outFile(third)
print(f"Number of strings: {k}")