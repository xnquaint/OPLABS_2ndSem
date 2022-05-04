import pickle
import os


def inputFile(name):
    product = {}
    while True:
        mode = int(input("Enter 1 if u want to create a new file. \nEnter 2 if you want to append the file.\n"))
        if mode == 1:
            file = open(name, "wb")
            break
        elif mode == 2:
            file = open(name, "ab")
            break
    number = int(input("Enter number of products: "))
    while number <= 0:
        number = int(input("Enter number of products: "))
    for i in range(number):
        product["name"] = input("Name: ")
        product["type"] = input("Type: ")
        product["color"] = input("Color: ")
        product["price"] = int(input("Price: "))
        product["amount"] = int(input("Amount: "))
        print("\n")
        pickle.dump(product, file)

    file.close()


def showFile(name):
    file = open(name, "rb")
    filesize = file.seek(0, 2)
    file.seek(0)

    while file.tell() < filesize:
        product = pickle.load(file)
        print("\nName: ", product["name"])
        print("Type: ", product["type"])
        print("Color: ", product["color"])
        print("Price: ", product["price"])
        print("Amount: ", product["amount"])

    file.close()


def createSecondFile(first_name, second_name):
    requested_name = input("Enter the name of products you'd like to add to new file: ")
    requested_type = input("Enter the type of that product you'd like to add to new file: ")
    first_file = open(first_name, "rb")
    second_file = open(second_name, "wb")
    filesize = first_file.seek(0, 2)
    first_file.seek(0)
    while first_file.tell() < filesize:
        product = pickle.load(first_file)
        if product["name"] == requested_name and product["type"] == requested_type and product["amount"] > 0:
            pickle.dump(product, second_file)
    first_file.close()
    second_file.close()


def editFile(name):
    temp_name = "third.dat"
    file = open(name, "rb")
    temp_file = open(temp_name, "wb")
    filesize = file.seek(0, 2)
    file.seek(0)
    while file.tell() < filesize:
        product = pickle.load(file)
        if product["price"] < 300 or product["price"] > 500:
            pickle.dump(product, temp_file)
    file.close()
    temp_file.close()
    os.remove(name)
    os.rename(temp_name, name)
