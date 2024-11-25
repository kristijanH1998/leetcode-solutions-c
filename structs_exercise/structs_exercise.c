#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//typedef struct Dog Doberman;

typedef struct Dog {
    int age;
    char name[20];
} Dog;

struct Cat {
    int age;
    char name[20];
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
    return 0;
}