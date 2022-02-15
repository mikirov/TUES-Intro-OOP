#include <iostream>

using namespace std;

//keyword class is used to declare it, we can later use it like structs as a variable type
class Vector
{
    //private member variables can only be accessed inside the class, from the class methods
private:
    //pointer to array of dynamically allocated integers
    int* array;
    //number of elements filled with data
    int size;
    //number of allocated elements
    int capacity;

//public variables or methods can be accessed outside of the class.
// It's a design principle to keep all the data we don't need to show the user as private
// and only expose what they need to use
public:

    int GetSize()
    {
        return this->size;
    }
/**
 * @name GetCapacity - example getter for the current capacity
 * @return int - current capacity of the vector
 */
    int GetCapacity()
    {
        return this->capacity;
    }
/**
 * @name SetCapacity - example setter, used to access private member variables, for encapsulation
 * @param capacityToSet
 */
//    void SetCapacity(int capacityToSet)
//    {
//        this->capacity = capacityToSet;
//    }

// default constructor
//    Vector()
//    {
//        this->size = 7;
//        this->capacity = 0;
//        this->array = new int[size];
//    }


// constructor with parameter
//    Vector(int capacityToSet)
//    {
//        this->size = 0;
//        this->capacity = capacityToSet;
//        this->array = new int[size];
//    }

    /**
     * @name Vector - constructor with default parameter, same as the above 2
     * @note - it doesn't have a return type
     * @note - same name as class name
     */
    Vector(int capacityToSet = 7) // default value for parameter capacityToSet, if we don't specify it as an argument
    {
        this->size = 0;
        this->capacity = capacityToSet;
        this->array = new int[this->capacity];

        for(int i = 0; i < this->capacity; i++)
        {
            this->array[i] = 0;
        }
    }

    /**
     * @name ~Vector - default destructor
     * @note - same name as class name with ~ beforehand
     * called when we call delete on a Vector* or automatically when an instance goes out of scope
     */
    ~Vector()
    {
        delete [] this->array;
        this->array = nullptr;
        this->size = 0;
        this->capacity = 0;
    }
    /**
     * @name add - Adds a value to the dynamic array
     * @param value - value to add to the dynamic array
     * @returns void
     */
    void add(int value)
    {
        //if we want to add more values than we've allocated memory for, allocate 2x as much and copy values over the new array
        if(this->capacity == this->size)
        {
            this->capacity *= 2;
            int* temp = new int[this->capacity];

            for(int i = 0; i < this->size; i++)
            {
                temp[i] = this->array[i];
            }

            delete[] this->array;
            this->array = temp;
        }

        this->array[this->size] = value;
        this->size++;
    }
    /**
     * @name - modify - Modifies element at given position
     * @param pos - position of element to modify
     * @param value - new value to set
     * @returns void
     */
    void modify(unsigned int pos, int value)
    {
        //make sure the position we want to modify element at is valid
        //early out if it's not
        if(pos >= this->size)
        {
            return;
        }

        this->array[pos] = value;
    }

    /**
     * @name print - prints all elements in our dynamic array
     * @returns void
     * note we didn't need to pass it any parameters, since all the info we need is stored inside the class as member variables
     */
    void print()
    {
        for(int i = 0; i < this->size; i++)
        {
            cout << this->array[i] << " ";
        }
        cout << endl; // same as "\n"
    }

};

/**
 * @name Malloc - example implementation of C Malloc with C++ constructs
 * @param size - of the allocated array
 * @return int* - starting address of the allocated array
 */
int* Malloc(int size)
{
    return new int[size];
}
/**
 *
 * @param v - reference to vector, it modifies the vector itself
 */
void DoStuffWithVector(Vector& v)
{
    cout << "vector size: " << v.GetSize() << "vector capacity: " << v.GetCapacity() << endl;

    v.add(10);
    v.add(1034);
    v.add(140);
    v.add(60);
    v.modify(1, 235);
    cout << "vector size: " << v.GetSize() << "vector capacity: " << v.GetCapacity() << endl;
    v.print();
}
/**
 *
 * @param v - reference to vector, it modifies the vector itself
 * @note - we can overload functions and methods with the same name since the signature of the function/method
 * consists of the name and the number and type of parameters
 */
void DoStuffWithVector(Vector* vptr)
{
    vptr->add(10);
    vptr->add(1034);
    vptr->add(140);
    vptr->add(60);
    vptr->modify(1, 235);
    vptr->print();
}



int main(int argc, char** argv) {

    int a = 10;
    int* pa = &a;
    cout << "address of pointer: " << (void*) pa << " value: " << *pa << endl;
    int& ra = a; // must be initialized, can't change what it points to, auto derefferencing; aka allias
    //int& ra; // invalid
    //ra = &pa; //invalid
    cout << "address of reference: " << (void*) &ra << " value: " << ra << endl;

    Vector* vptr = new Vector(3); // allocates memory and automatically calls constructor
    DoStuffWithVector(vptr);
    delete vptr; // destructor was called on delete, freed up memory and reset our size and capacity counters
    //it's not safe to use a ptr after it was deleted
    //cout << "vector size: " << vptr->GetSize() << "vector capacity: " << vptr->GetCapacity() << endl;

    Vector v(3);
    //we modify the vector itself inside this function
    DoStuffWithVector(v);
    cout << "vector size: " << v.GetSize() << "vector capacity: " << v.GetCapacity() << endl;

    return 0;
}
