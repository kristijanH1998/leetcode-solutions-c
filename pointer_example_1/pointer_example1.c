#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CA_SIZE(a) ((sizeof(a) / sizeof(*a)) - 1)

void delete(void *ptr) {
   //printf("PTR address before delete %p\n", &ptr);

   void **real_ptr = (void**) ptr;
  free(*real_ptr);
  ptr = NULL;
}

int main() { 

  char name1[] = "Kristijan";
  char name2[] = "Lorien";
  printf("%s\n", &name1);
  printf("%i\n", CA_SIZE(name1));
  printf("%i\n", CA_SIZE(name2));
  printf("%i\n", strlen(&name1));

   //1. Pointer adresa
   //2. Adresa onoga na sta pointer pointa
   //3. Vrijednost na adresi onoga na sta pointer pointa
   //4. Pointer na pointer 
   //5. Cast pointera na pointer na pointer

   // heap
   int *number = malloc(sizeof(int));
   *number = 45;

  //  printf("Number address before delete %p\n", &number);

   delete(&number);

   //printf("Number is %i\n", *number);
   //printf("Num;ber is reaally %p\n", number);


   //free(number);
   //*number = 0;

   //printf("Number is %i\n", *number);

  // stack
  //int a = 15;
  //int *pa = &a;

   //printf("Number is %i\n", *pa);
   //printf("Num;ber is reaally %p\n", &pa);
   //printf("Num;ber is reaally %p\n", pa);
   //printf("Num;ber or is it reaally %p\n", &*pa);

  //free(pa);  // undefined behavior

  return 0;
}
