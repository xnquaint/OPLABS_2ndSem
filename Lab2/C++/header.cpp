#include "header.h"

void input_file(const char* name){
    ofstream file;
    catalog product{};
    int mode = 0;
    int number;
    do {
        cout << "Select the mode: \n 1 - create new file. \n 2 - append file.\n";
        cin >> mode;
    }while(mode != 1 && mode != 2);
    if (mode == 1)
        file.open(name, ios::binary );
    else if (mode == 2)
        file.open(name, ios::binary | ios::app);
    if(!file.is_open()) {
        cout << "Cant open the file!";
        exit(0);
    }
    do {
        cout << "Enter number of products: ";
        cin >> number;
    }while(number <= 0);
    for (int i = 0; i < number; ++i) {
        cout << "Enter name of product: "; cin >> product.name;
        cout << "Enter type of product: "; cin >> product.type;
        cout << "Enter color of product: ";cin >> product.color;
        cout << "Enter price of product: ";cin >> product.price;
        cout << "Enter amount of product: ";cin >> product.amount;
        cout << endl;
        file.write((char*)&product, sizeof(catalog));
    }
    file.close();
}
void output_file(const char* name){
    catalog product{};
    ifstream file(name, ios::binary);
    while(file.read((char*)&product, sizeof(catalog))){
        cout << "Name: " << product.name << endl;
        cout << "Type: " << product.type << endl;
        cout << "Color: " << product.color << endl;
        cout << "Price: " << product.price << endl;
        cout << "Amount: " << product.amount << endl;
        cout << endl;
    }
    file.close();
}
void create_second_file(const char*first_name, const char* second_name){
    ifstream first_file(first_name, ios::binary);
    ofstream second_file(second_name, ios::binary);
    catalog product{};
    char new_name[40];
    char kind[40];
    cout << "Enter the name of products you'd like to add to new file: ";cin >> new_name;
    cout << "Enter the type of " << new_name << " you'd like to add to new file: "; cin >> kind;

    while(first_file.read((char*)&product, sizeof(catalog))){
        if(strcmp(product.name, new_name) == 0 && strcmp(product.type, kind) == 0 && product.amount > 0){
            second_file.write((char*)&product, sizeof(catalog));
        }
    }
    first_file.close();
    second_file.close();
}
void edit_file(const char* name) {
    catalog product{};
    const char* temp_file_name = "third.dat";
    ifstream file(name, ios::binary);
    ofstream temp_file(temp_file_name, ios::binary);
    int min = 300;
    int max = 500;
    while (file.read((char *) &product, sizeof(catalog))) {
        if (product.price < min || product.price > max) {
            temp_file.write((char*)&product, sizeof(catalog));
        }
    }
    file.close();
    temp_file.close();
    remove(name);
    rename(temp_file_name, name);
}