#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

class Animal {
   protected:
      double age;
      string name;
   public:
      Animal(string name) : name(name), age(0) { };
      virtual void speak() {
         cout << "I am an Animal named " << name << endl;
      }

      void talk() {
         speak();
      }
}; 

class Cat : public Animal {
      bool isHouseCat;
   public:
      Cat(string catName, bool houseCat): Animal(catName), isHouseCat(houseCat) { };

      virtual void speak() {
         cout << "Meow" << " and I am " << name << " and my housecatness is " << isHouseCat << endl;
      }
};

class Dog : public Animal {
    int age;
public:
    Dog(string dogName, int age): Animal(dogName), age(age) { };

    virtual void speak() {
        cout << "woof" << " My name is " << name << " and my age is " << age << endl;
    }
};


int main() {
    vector<Animal*> animals { };
    Animal animal {"animal"};
    Cat cat {"tiger", false};
    Dog dog {"rover", 1}; 
    animals.push_back(&animal);
    animals.push_back(&cat);
    animals.push_back(&dog);

    for(auto a : animals) {
        a->talk();
    }

    return 0;
}
