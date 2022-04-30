from module import *

firstName = "first.dat"
secondName = "second.dat"
inputFile(firstName)
showFile(firstName)
createSecondFile(firstName, secondName)
print("Second file: ")
showFile(secondName)
editFile(secondName)
print("\nEdited file: ")
showFile(secondName)

