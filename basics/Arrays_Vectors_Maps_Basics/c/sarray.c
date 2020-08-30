#include <string.h>
//Vector in C
sArray* sarray_new(int capacity){
  int true_capacity = sarray_determine_capacity(capacity);

  sArray *tmp = malloc(sizeof(sArray));
  check_address(tmp);

  tmp->size = 0;
  tmp->capacity = true_capacity;
  tmp->data = (int *)malloc(sizeof(int) * true_capacity);
  check_address(arr->data);

  return tmp;
}
void sarray_destroy(sArray *arptr){
  free(arptr->data);
  free(arptr);
}


void sarray_resize_for_size(sArray *arrptr, int candidate_size){

  if(arrptr->size < candidate_size){ // Growing factor
    if(arrptr->size == arrptr->capacity){
      sarray_upsize(arrptr);
    }
  }else if(arrptr->size > candidate_size){ // Shrinking Factor
    if(arrptr->size == arrptr->capacity){
      sarray_downsize(arrptr);
    }
  } // if equal sit back and do nothing
}

int sarray_determine_capacity(int capacity){
  const int kMinInitCap = 1;
  int true_capacity = kMinCapacity;
  if(capacity < kMinCapacity){
    exit(EXIT_FAILURE);
  }
  while(capacity < true_capacity/kGrowthFactor){
    capacity *= kGrowthFactor;
  }
  return true_capacity;
}


void sarray_upsize(sArray *arrptr){
  int old_cap = arrptr->capacity;
  int new_cap = sarray_determine_capacity(old_cap);

  int *new_dat = (int *)realloc(arrptr->data,sizeof(int)*new_cap);
  arrptr->data = new_data;
  arrptr->capacity = new_cap;
}

void sarray_downsize(sArray *arrptr){
  int old_cap = arrptr->capacity;
  int new_cap = arrptr->capacity/kGrowthFactor;

  if(new_cap < kMinCapacity){
    new_cap = kMinCapacity;
  }
  if(new_cap != old_cap){
    int *new_dat = (int *)realloc(arrptr->data,sizeof(int)*new_cap);
    check_address(new_dat);
    arrptr->capacity = new_cap;
    arrptr->data = new_dat;
  }
}

int sarray_size(sArray *arrptr){
  return arrptr->size;
}

void sarray_push(sArray *arrptr, int item){
sarray_resize_for_size(arrptr, arrptr->size + 1);
*(arrptr->data + arrptr->size) = item;
++(arrptr->size);
}

void sarray_print(sArray *arrptr){
  printf("Size: %d\n",arrptr->size);
  printf("capacity: %d\n",arrptr->capacity);

  printf("Values are - \n");

  for(int i = 0;i<arrptr->size ; i++){

    printf("%d at %d \n",*(arrptr->data+i),i);
  }
  printf("-----------------\n");
}

int sarray_capacity(sArray *arrptr){

  return arrptr->capacity;
}

int sarray_at(sArray *arrptr, int index){
  if(index < 0 || index > arrptr->size - 1){
    exit(EXIT_FAILURE);
  }
  return *(arrptr->data + index);
}

bool sarray_is_empty(sArray *arrptr){
  return arrptr->size == 0;
}

void sarray_insert(sArray *arrptr, int index, int value){
  if(index < 0 || index > arrptr->size - 1){
    exit(EXIT_FAILURE);
  }
  sarray_resize_for_size(arrptr,arrptr->size+1);
  //shift things to right and insert element at base
  memmove(arrptr->data + index + 1,arrptr->data + index, (arrptr->size-index)*sizeof(int));
  *(arrptr->data + index) = value;
  ++(arrptr->size);
}

void sarray_prepend(sArray *arrptr, int value){
  sarray_insert(arrptr,0,value);
}

int sarray_pop(sArray *arrptr){
  if(arrptr->size == 0){
    exit(EXIT_FAILURE);
  }
  sarray_resize_for_size(arrptr,arrptr->size - 1);
  int pop = *(arrptr->data + arrptr + size - 1);
  --(arrptr->size);
  return pop;
}

void sarray_delete(sArray *arrptr, int index){
  if (index < 0 || index > arrptr->size - 1){
    exit(EXIT_FAILURE);
  }
  sarray_resize_for_size(arrptr,arrptr->size - 1);

  memmove(arrptr->data + index, arrptr->data + index + 1, (arrptr->size - index) * sizeof(int));
  --arrptr->size;
}

void sarray_remove(sArray *arrptr, int value){

  for(int i = 0;i<arrptr->size;i++){
  int check_val = *(arrptr->data + i);
  if(check_val == value){
    sarray_delete(arrptr,i);
    --i; // to re-check index
  }
  }
}

int sarray_find(sArray *arrptr, int value){
  int idx = -1;
  for(int i = 0;i<arrptr->size;++i){
    if(*(arrptr->data + i) == value){
      idx = i;
      break;
    }
  }
  return idx;
}

void check_address(void *p){
  if (p==NULL){
    printf("Memory Allocation Failed \n");
    exit(EXIT_FAILURE);
  }
}

// ------------------------TESTS ------------------------------//
void run_all_tests() {
  test_size_init();
  test_append();
  test_empty();
  test_resize();J
  test_at();
  test_insert();
  test_prepend();
  test_pop();
  test_remove();
  test_find_exists();
  test_find_not_exists();
}

void test_size_init() {
  sArray *aptr = sarray_new(5);
  int initial_size = sarray_size(aptr);
  assert(initial_size == 0);
  sarray_destroy(aptr);
}

void test_append() {
  sArray *aptr = sarray_new(2);
  sarray_push(aptr, 2);
  sarray_push(aptr, 12);
  int new_size = sarray_size(aptr);
  assert(new_size == 2);
  sarray_destroy(aptr);
}

void test_resize() {
  sArray *aptr = sarray_new(2);

  int old_capacity = sarray_capacity(aptr);
  assert(old_capacity == 16);

  // forces a resize up
  for (int i = 0; i < 18; ++i) {
    sarray_push(aptr, i + 1);
  }

  assert(sarray_capacity(aptr) == 32);

  // forces a resize down
  for (int j = 0; j < 15; ++j) {
    sarray_pop(aptr);
  }

  assert(sarray_capacity(aptr) == 16);

  sarray_destroy(aptr);
}

void test_empty() {
  sArray *aptr = sarray_new(2);
  bool empty = sarray_is_empty(aptr);
  assert(empty == 1);
  sarray_push(aptr, 1);
  empty = sarray_is_empty(aptr);
  assert(empty == 0);
  sarray_destroy(aptr);
}

void test_at() {
  sArray *aptr = sarray_new(12);
  for (int i = 0; i < 12; ++i) {
    sarray_push(aptr, i + 3);
  }
  assert(sarray_at(aptr, 6) == 9);
  sarray_destroy(aptr);
}

void test_insert() {
  sArray *aptr = sarray_new(5);
  for (int i = 0; i < 5; ++i) {
    sarray_push(aptr, i + 5);
  }
  sarray_insert(aptr, 2, 47);
  assert(sarray_at(aptr, 2) == 47);
  assert(sarray_at(aptr, 3) == 7);
  sarray_destroy(aptr);
}

void test_prepend() {
  sArray *aptr = sarray_new(5);
  for (int i = 0; i < 3; ++i) {
    sarray_push(aptr, i + 1);
  }
  sarray_prepend(aptr, 15);
  assert(sarray_at(aptr, 0) == 15);
  assert(sarray_at(aptr, 1) == 1);
  sarray_destroy(aptr);
}

void test_pop() {
  sArray *aptr = sarray_new(5);
  for (int i = 0; i < 3; ++i) {
    sarray_push(aptr, i + 1);
  }
  assert(aptr->size == 3);
  for (int j = 0; j < 3; ++j) {
    sarray_pop(aptr);
  }
  assert(sarray_is_empty(aptr) == 1);
  sarray_destroy(aptr);
}

void test_remove() {
  sArray *aptr = sarray_new(5);
  sarray_push(aptr, 12);
  sarray_push(aptr, 3);
  sarray_push(aptr, 41);
  sarray_push(aptr, 12);
  sarray_push(aptr, 12);
  sarray_remove(aptr, 12);
  assert(sarray_size(aptr) == 2);
  sarray_destroy(aptr);
}

void test_find_exists() {
  sArray *aptr = sarray_new(5);
  sarray_push(aptr, 1);
  sarray_push(aptr, 2);
  sarray_push(aptr, 3);
  sarray_push(aptr, 4);
  sarray_push(aptr, 5);
  assert(sarray_find(aptr, 1) == 0);
  assert(sarray_find(aptr, 4) == 3);
  assert(sarray_find(aptr, 5) == 4);
  sarray_destroy(aptr);
}

void test_find_not_exists() {
  sArray *aptr = sarray_new(3);
  sarray_push(aptr, 1);
  sarray_push(aptr, 2);
  sarray_push(aptr, 3);
  assert(sarray_find(aptr, 7) == -1);
  sarray_destroy(aptr);
}
