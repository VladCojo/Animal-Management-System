#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <string>
#include <exception>
#include <cstdlib>
#include <fstream>

using namespace std;

// Base class for Animal
class Animal{
protected:
    string breed;
    string name;
public:
    Animal(){};
    virtual void getData(istream& in) = 0;
    virtual void displayData(ostream& out) = 0;
    virtual void saveToFile(ofstream& file) const = 0;
    string getName() const{
        return name;
    }
    virtual ~Animal() {};
};

// Derived class for Dog
class Dog: public Animal{
    int age;
public:
    Dog(){};

    void getData(istream& in){
        cin>>*this;
    }
    void displayData(ostream& out){
        cout<<*this;
    }

    void saveToFile(ofstream& file) const override {
        file << "Dog\n";
        file << "Breed: " << breed << endl;
        file << "Name: " << name << endl;
        file << "Age: " << age << endl;
    }

    friend istream& operator>>(istream&, Dog&);
    friend ostream& operator<<(ostream&,const Dog&);
    ~Dog(){};
};

// Overloaded extraction operator for input of Dog
istream& operator>>(istream& in, Dog& obj){
    cout<<"Enter data for dog\n";
    cout<<"Enter breed: ";
    getline(in, obj.breed);
    cout<<"Enter name: ";
    getline(in, obj.name);
    
    while(true){
        try{
            cout<<"Enter age: ";
            in>>obj.age;

            if(obj.age < 0)
                throw runtime_error("Age must be non-negative");
            break;
        } catch(const exception& e){
            cout<<"Error: "<<e.what()<<". Try again.\n";
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return in;
   
}

// Overloaded insertion operator for output of Dog
ostream& operator<<(ostream& out,const Dog& obj){
    cout<<"Dog\n";
    cout<<"Breed: "<<obj.breed<<endl;
    cout<<"Name: "<<obj.name<<endl;
    cout<<"Age: "<<obj.age<<endl;
    return out;
}

// Derived class for Cat
class Cat: public Animal{
    string color;
public:
    Cat(){};
    void getData(istream& in){
        cin>>*this;
    }
    void displayData(ostream& out){
        cout<<*this;
    }

    void saveToFile(ofstream& file) const override {
        file << "Cat\n";
        file << "Breed: " << breed << endl;
        file << "Name: " << name << endl;
        file << "Color: " << color << endl;
    }

    friend istream& operator>>(istream&, Cat&);
    friend ostream& operator<<(ostream&,const Cat&);
    ~Cat(){};
};

// Overloaded extraction operator for input of Cat
istream& operator>>(istream& in, Cat& obj){
    cout<<"Enter data for cat\n";
    cout<<"Enter breed: ";
    getline(in, obj.breed);
    cout<<"Enter name: ";
    getline(in, obj.name);
    cout<<"Enter color: ";
    getline(in, obj.color);
    

    return in;
   
}

// Overloaded insertion operator for output of Cat
ostream& operator<<(ostream& out,const Cat& obj){
    cout<<"Cat\n";
    cout<<"Breed: "<<obj.breed<<endl;
    cout<<"Name: "<<obj.name<<endl;
    cout<<"Color: "<<obj.color<<endl;
    return out;
}

// Function to write animals data to a file
void writeAnimalsToFile(const vector<Animal*>& animals, const string& filename) {
    ofstream outFile(filename, ios::out | ios::trunc);

    if (!outFile.is_open()) {
        cerr << "Error: Unable to open file for writing.\n";
        return;
    }

    for (const auto& animal : animals) {
        animal->saveToFile(outFile);
        outFile << "\n";
    }

    outFile.close();
    cout << "Animals data has been written to the file: " << filename << endl;
}

int main(){
    vector<Animal*> animals;
    Animal *newanimal;
    int opt;
    string filename, deleteName;
    auto it = animals.begin();
    do{
        cout<<"0. Exit"<<endl;
        cout<<"1. Add a dog"<<endl;
        cout<<"2. Add a cat"<<endl;
        cout<<"3. Display vector of animals"<<endl;
        cout<<"4. Sort by name(ascending order)"<<endl;
        cout<<"5. Delete animal by name"<<endl;
        cout<<"6. Create file and add current vector to it"<<endl;
        cout<<"Choose an option: ";
        cin>>opt;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(opt){
            case 0:
                exit(1);
            break;

            case 1:
                newanimal = new Dog;
                newanimal->getData(cin);
                animals.push_back(newanimal);
            break;

            case 2:
                newanimal = new Cat;
                newanimal->getData(cin);
                animals.push_back(newanimal);
            break;

            case 3:
                for(auto& it: animals){
                    it->displayData(cout);
                    cout<<"\n";
                }
            break;

            case 4:
                sort(animals.begin(), animals.end(), [](const Animal* a1, const Animal* a2) {
                    return a1->getName() < a2->getName();
                });

                
                cout << "Sorted by name (ascending order):" << endl;
                for (auto& it : animals) {
                    it->displayData(cout);
                    cout << "\n";
                }
                break;
            
            case 5:
                cout<<"Enter name you want to delete: ";
                getline(cin, deleteName);

                it = animals.begin();
                while (it != animals.end()) {
                    it = find_if(it, animals.end(), [deleteName](const Animal* a) {
                        return a->getName() == deleteName;
                    });

                    if (it != animals.end()) {
                        // Animal found, delete it
                        delete *it;
                        it = animals.erase(it);
                        cout << "Animal with name '" << deleteName << "' has been deleted.\n";
                    }
                }
            break;

            case 6:
                cout<<"Enter file name: ";
                getline(cin, filename);
                writeAnimalsToFile(animals, filename);
            break;

            default:
                cout<<"Invalid option\n";
            break;
        }


    }while(opt!=0);


    return 0;
}