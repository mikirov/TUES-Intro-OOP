#include <iostream>
using namespace std;

class Animal
{
private:
    bool isAnimal; // not accessible outside
protected: // protected is less restrictive than private. member variables and methods can be called in derived classes as well
    int age;

public:

    Animal(int age = 0)
    {
        isAnimal = true;
        this->age = age;
        cout << "animal constructor called" << endl;
    }

    int getAge()
    {
        cout << "getAge called" << endl;
        return this->age; // same as return age;
    }

    bool getIsAnimal() // however we can still access private booleans through
    {
        return this->isAnimal
    }
};

//there are 3 types of inheritance
//public inheritance makes public member variables and methods public in the derived class, protected ones are protected
//protected inheritance makes public member variables and methods protected in the derived class, protected ones are protected
//private inheritance makes public member variables and methods private in the derived class, protected ones are private

class Cow : public Animal
{
protected:
    bool isMale;
public:
    Cow(int age, bool isMale) : Animal(age)
    {
        this->isMale = isMale;
        //isAnimal = false; // illegal since we are trying to access private member outside of class scope
        cout << "cow constructor called" << endl;
    }

    bool getMale()
    {
        cout << "Cow::isMale called" << endl;
        return this->isMale;
    }
};

//factory pattern
Animal* createAnimal(int age, bool isCow, bool isMale = false)
{
    Cow tempCow(age, isMale); // allocated on the stack, will get destroyed at the end of the function scope
    if(isCow)
    {
        return new Cow(age, isMale);
    }

    return new Animal(age);
} // tempCow no longer exists

int main() {

    //Animal* animal = new Animal();

    Animal* animal = createAnimal(40, false, false);
    Animal* animal3 = createAnimal(8, false, true);

    Animal* animal2 = createAnimal(23, true);
    Animal* animal4 = createAnimal(43, false);

    Cow* cow = new Cow(25, true);

    cout << cow->getMale() << endl;
    //cout << animal3->getMale() << endl; //can't get it since we are implicitly casting to the base class
    //std::cout << animal->getAge() << std::endl;

    //don't forget to delete the pointers at the end or we get a memory leak
    delete animal;
    delete animal2;
    delete animal3;
    delete animal4;
    delete cow;

    return 0;
}
