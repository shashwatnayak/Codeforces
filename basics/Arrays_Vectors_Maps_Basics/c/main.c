#include<stdio.h> // for io
#include<stdlib.h> // for malloc
#include "sarray.h" // header file for vec
#include "sarray.c" // functions file for vec

void run_example();

int main(){

  run_all_tests();
  run_example();

}

void run_example(){

  int capacity = 0;
  printf("Enter as many as Numbers you want\n");
  scanf("%d ", &capacity);

  //Initialise Vector

  sArray* ptr = sarray_new(capacity);

  for(int i = 0;i<capacity;++i){
    sarray_push(ptr,i);
  }

  int insert_val = 999;
  printf("---- Inserting %d value at %d position -------\n" ,&insert_val,capacity-1);
  sarray_insert(ptr,capacity - 1,insert_val);
}
