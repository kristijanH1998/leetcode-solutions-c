#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structs_exercise.h"

//typedef struct Dog Doberman;

typedef struct Dog {
    int age;
    char name[20];
} Dog;

struct Cat {
    int age;
    char name[20];
};

struct Animal2 {
    int age;
};

struct Fish {
    struct Animal2 *p;
    struct Animal {
        char* species;
    };
    
};

int main() {
    // struct TestStruct ts;
    // ts.a = 1;
    // ts.b = 3;
    // printf("%d\n", ts.a);
    
    // struct TestStruct tss;
    // tss = malloc(sizeof(TestStruct));
    // tss->a = 1;
    // tss->b = 3;

    // TestStruct *tss = malloc(sizeof(TestStruct));
    // tss->a = 4;
    // typedef struct Dog {
    //     int age;
    //     // char name[20];
    // } Doberman;
    // Doberman dog1;
    //struct Dog dog1;
    
    //stored on the stack:
    Dog dog1;
    Dog dog2; 
    struct Cat cat1;

    //stored on the heap:
    Dog *dog3 = malloc(sizeof(Dog));
    dog3->age = 5;
    strcpy(dog3->name, "Oto");
    printf("%d\n", dog3->age);
    free(dog3);
    dog3 = NULL;

    struct Cat *cat2 = malloc(sizeof(struct Cat));
    cat2->age = 2;
    strcpy(cat2->name, "Navi");
    printf("%s\n", cat2->name);

    dog1.age = 10;
    strcpy(dog1.name, "Hana");
    printf("%d %s\n", dog1.age, dog1.name);

    cat1.age = 3;
    strcpy(cat1.name, "Zule");
    printf("%d %s\n", cat1.age, cat1.name);

    struct Fish f1;
    struct Animal2 *a2;
    a2 = malloc(sizeof(struct Animal2));
    f1.p = a2;
    f1.p->age = 11;
    printf("%d\n", f1.p->age);

    return 0;
}