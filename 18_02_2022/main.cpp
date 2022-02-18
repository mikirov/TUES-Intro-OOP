#include <iostream>

using namespace std;

class Vector
{
    //public methods and variables are accessible outside the class scope
public:

    /*
     * class constructor
     * @name Vector - same as class name
     * @note - constructors are special methods that get called automatically
     * on variable definition
     * @note - default parameter makes 2 overloaded methods - one with and one
     * without capacityToSet defending on if it's supplied in the constructor
     */
    Vector(const int capacityToSet = 7)
    {
        this->capacity = capacityToSet;
        this->size = 0;
        this->array = new int[capacityToSet];
    }
/*
 * @name push_back - adds a value at the end of the dynamic array
 * @return vector& - a reference to the modified vector
 * @param const int& value - the value to add
 */
    Vector& push_back(const int& value)
    {
        if(this->size == this-> capacity)
        {
            this->capacity *= 2;
            int* temp = new int[this->capacity];
            for(int i = 0; i < this->size; i++)
            {
                temp[i] = this->array[i]; // temp[i] == *(temp + i)
            }
            delete this->array;
            this->array = temp;
        }

        this->array[this->size] = value;
        this->size++;

        return *this;
    }

    /*
     * @name pop_back - removes the last value from the dynamic array
     * @return Vector& - a reference to the modified dynamic array
     */
    Vector& pop_back()
    {
        if(this->size > 0)
        {
            this->size--;
        }

        return *this;
    }
    /*
     * @name ~Vector - destructor, called automatically when an instantiated
     * variable of the class type becomes out of scope or delete gets called
     * on a pointer to the class type
     * @note - doesn't have return type, name is always class name with ~ in front
     */
    ~Vector()
    {
        this->capacity = 0;
        this->size = 0;
        delete [] this->array;
        this->array = nullptr;
    }

    /*
     * @name GetSize - example getter - used to return private variables, for encapsulation
     * @return int - the current vector size
     */
    int GetSize()
    {
        return this->size;
    }

    /*
     * @name GetCapacity - example getter - used to return private variables, for encapsulation
     * @return int - the current vector capacity
     */
    int GetCapacity()
    {
        return this->capacity;
    }

    /*
     * @name print - prints all elements of the dynamic array
     */
    void print()
    {
        for(int i = 0; i < this->size; i++)
        {
            cout << this->array[i] << " ";
        }
        cout << endl;
    }

    //private variables are inaccessible outside the scope of the class
private:
    int size;
    int capacity;
    int* array;
};

//functions are like methods, but with global scope
void add(Vector& v, int value)
{
    v.push_back(value);
}

//a function signature consists of it's name and number and types of parameters
//we could have a function with the same name and different parameters
//with different implementation
void DoSomethingWithVector(Vector& v1)
{
    cout << "size: " << v1.GetSize() << "capacity: " << v1.GetCapacity() << endl;
    v1.push_back(10).push_back(5).push_back(34).push_back(324);

    cout << "size: " << v1.GetSize() << "capacity: " << v1.GetCapacity() << endl;

    v1.pop_back().pop_back();
}

void DoSomethingWithVector(Vector* v1)
{
    cout << "size: " << v1->GetSize() << "capacity: " << v1->GetCapacity() << endl;
    v1->push_back(10).push_back(5).push_back(34).push_back(324);

    v1->pop_back().pop_back();

    delete v1;
}

void DoSomethingWithVector()
{
    Vector v1;
    cout << "size: " << v1.GetSize() << "capacity: " << v1.GetCapacity() << endl;
    v1.push_back(10).push_back(5).push_back(34).push_back(324);

    cout << "size: " << v1.GetSize() << "capacity: " << v1.GetCapacity() << endl;

    v1.pop_back().pop_back();
} // destructor gets called

int main() {

    Vector v1(3);

    DoSomethingWithVector(v1);

    DoSomethingWithVector();
    cout << "size: " << v1.GetSize() << "capacity: " << v1.GetCapacity() << endl;

    v1.print();

    //destructor called here

    Vector* v2 = new Vector(3);
    DoSomethingWithVector(v2);
    //add(*v2, 10);

    //v2->push_back(324);
    //v2->print();
    //delete v2; //
    //v2->push_back(324543);
    return 0;
}
