def writeFile(name):
    print("Type 1 if you want to create a new file.")
    print("Type 2 if you want to expand the file.")
    value = int(input())
    key = chr(7)
    if value == 1:
        with open(name, 'w') as file:
            str = input("Enter the strings.\n" + "Press ENTER to start a new line.\n" + "Press CTRL + G to end the file.'\n")
            while str[0] != key:
                file.write(str + '\n')
                str = input()


    elif value == 2:
        with open(name, 'a') as file:
            str = input("Enter the strings.\n" + "Press ENTER to start a new line.\n" + "Press CTRL + G to end the file.\n")
            while str[0] != key:
                file.write(str + '\n')
                str = input()

          
def outFile(name):
    with open(name, 'r') as file:
        print(file.read()) 


def createThird(fname, sname, tname):
    with open(fname, 'r') as first, open (sname, 'r') as second, open(tname, 'w') as third:
        k = 0
        for line in second:
            hasCopy = False
            first.seek(0)
            for sline in first:
                if line == sline:
                    hasCopy = True
                    break
            if not hasCopy:
                third.write(line)
                k = k + 1
    return k