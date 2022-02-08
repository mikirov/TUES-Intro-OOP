#include <stdio.h>
#include <stdlib.h>

struct point_t
{
    float x, y;
};

struct vector_t
{
    //pointer to array of dynamically allocated integers
    int* array;
    //number of allocated elements
    int size;
    //number of elements filled with data
    int capacity;
};

typedef struct vector_t vector;

typedef struct point_t point;

void print_array(int* arr, int size)
{
    //early return if we don't have access to this resource
    if(arr == NULL)
    {
        return;
    }

    for(int i = 0; i < size; i++)
    {
        printf("%d:%d\n", i, arr[i]);
    }
}

void initialize_array(int* arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        arr[i] = i * 5;
    }
}

void create_vector(vector* v, int size)
{
    v->size = 7;
    v->capacity = 0;
    (*v).array = (int*) malloc(size * sizeof(int));
}

void initialize_vector(vector* v)
{
    for(int i = 0; i < v->size; i++)
    {
        v->array[i] = 0;
    }
}

void add_element(vector* v, int value)
{
    if(v->capacity == v->size)
    {
        v->array = (int*) realloc(v->array, v->size * 2);
    }
    v->array[v->capacity] = value;
    v->capacity++;


}

void modify_vector(vector* v, unsigned int pos, int value)
{
    //early return if we are trying to access position we haven't allocated in memory
    if(pos >= v->size)
    {
        return;
    }

    v->array[pos] = value;
}

void delete_vector(vector * v)
{
    free(v->array);
    v->array = NULL;
    v->size = 0;
    v->capacity = 0;
}

//we can give command line arguments to our program entry point function
// argc -> number of arguments
// argv -> array of char* (strings) of arguments
int main(int argc, char** argv) {
    int a = 5, b = -10;
    char* c = "a";
    printf("%s\n", c);


    int array[3] = {5, 10 -20};
    printf("%d at address: %p\n", array[0], &array /* array also gives us the starting address*/);
    printf("%d at address: %p\n", *(array + 1) /* same as array[1] */, &(array[1]));


    point p;
    p.x = 10.0f;
    p.y = 20.0f;

    printf("P(%f, %f)\n", p.x, p.y);

    point* p2 = &p;

    printf("P2(%f, %f) at address: %p\n",p2->x, (*p2).y /* same as p->y */,  p2);

    point p3;
    p3.x = 5.0f;
    p3.y = -4.5f;

    p2 = &p3;

    printf("P3(%f, %f) at address: %p\n",p2->x, (*p2).y,  p2);


    //dynamically allocate memory
    int* d = (int*) malloc(5 * sizeof(int));
    for(int i = 0; i < 5; i++)
    {
       d[i] = i * 5;
    }

//    for(int i = 0; i < 5; i++)
//    {
//        printf("%d:%d\n", i, d[i]);
//    }


    //dynamically reallocate memory
    d = (int*)realloc((int*)d, 10 * sizeof (int));
    for(int i = 0; i < 10; i++)
    {
        d[i] = i * 5;
    }

//    for(int i = 0; i < 10; i++)
//    {
//        printf("%d:%d\n", i, d[i]);
//    }

    int temp = 25;
    for(int i = 0; i < 10; i++)
    {
        if(d[i] == temp)
        {
            d[i] = 0;
        }
    }

    //free memory
    free(d);
    d = NULL;

    //this should early-out
    print_array(d, 10);


    //we can declare it like this:
    struct vector_t v1;

    //or like this
    vector v;
    const VECTOR_SIZE = 7;
    create_vector(&v, VECTOR_SIZE);
    initialize_vector(&v);

    modify_vector(&v, 2, 515);
    modify_vector(&v, 3, 43564);
    //initialize_array(v.array, v.size);
    print_array(v.array, v.size);

    add_element(&v, 10);
    add_element(&v, 4346);
    add_element(&v, 65);
    add_element(&v, 564);
    add_element(&v, 654);

    modify_vector(&v, 3, 43564);
    print_array(v.array, v.capacity);

    delete_vector(&v);

    print_array(v.array, v.capacity);

    return 0;
}
