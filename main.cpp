#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <string>
#include <exception>
#include <cstdlib>

using namespace std;

class Animal{
protected:
    string breed;
    string name;
public:
    Animal(){};
    virtual void getData(istream& in) = 0;
    virtual void displayData(ostream& out) = 0;

    virtual ~Animal() {};
};

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

    friend istream& operator>>(istream&, Dog&);
    friend ostream& operator<<(ostream&,const Dog&);
    ~Dog(){};
};

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

ostream& operator<<(ostream& out,const Dog& obj){
    cout<<"Dog\n";
    cout<<"Breed: "<<obj.breed<<endl;
    cout<<"Name: "<<obj.name<<endl;
    cout<<"Age: "<<obj.age<<endl;
    return out;
}

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

    friend istream& operator>>(istream&, Cat&);
    friend ostream& operator<<(ostream&,const Cat&);
    ~Cat(){};
};
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

ostream& operator<<(ostream& out,const Cat& obj){
    cout<<"Dog\n";
    cout<<"Breed: "<<obj.breed<<endl;
    cout<<"Name: "<<obj.name<<endl;
    cout<<"Color: "<<obj.color<<endl;
    return out;
}


int main(){
    vector<Animal*> animals;
    Animal *newanimal;
    int opt;

    do{
        cout<<"0. Exit"<<endl;
        cout<<"1. Add a dog"<<endl;
        cout<<"2. Add a cat"<<endl;
        cout<<"3. Display vector of animals"<<endl;
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

        }


    }while(opt!=0);


    return 0;
}