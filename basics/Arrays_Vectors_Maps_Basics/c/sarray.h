#ifndef PROJECT_ARRAY_H
#define PROJECT_ARRAY_H

#include <stdbool.h>
#include <assert.h>

cont int kMinCapacity = 16;
cont int kGrowthFactor = 2;
cont int kShrinkFactor = 4;

typedef struct ss {
  int size;
  int capacity;
  int *data;
} sArray;


sArray* sarray_new(int capacity);
void sarray_destory(sArray *arptr);

// Checks to see if resizing is needed to support the candidate_size
// and resizes to accommodate.
void sarray_resize_for_size(sarray *arrptr, int candidate_size);
// Determines the actual capacity (in terms of the power of growth factor)
// required to accomodate a given capacity.
int sarray_determine_capacity(int capacity);
// Increases the array size to size determined by growth factor
void sarray_upsize(sarray *arrptr);
// Decreases the array size to size determined by growth factor
void sarray_downsize(sarray *arrptr);
// Returns the number of elements managed in the array.
int sarray_size(sarray *arrptr);
// Appends the given item to the end of the array.
void sarray_push(sarray *arrptr, int item);
// Prints public information about the array for debug purposes.
void sarray_print(sarray *arrptr);
// Returns the actual capacity the array can accommodate.
int sarray_capacity(sarray *arrptr);
// Returns the value stored at the given index.
int sarray_at(sarray *arrptr, int index);
// Returns true if array is empty.
bool sarray_is_empty(sarray *arrptr);
// Inserts the given value at the given index, shifting
// current and trailing elements to the right.
void sarray_insert(sarray *arrptr, int index, int value);
// Prepends the given value to the array, shifting trailing
// elements to the right.
void sarray_prepend(sarray *arrptr, int value);
// Removes the last item from the array and returns its value.
int sarray_pop(sarray *arrptr);
// Deletes the item stored at the given index, shifting trailing
// elements to the left.
void sarray_delete(sarray *arrptr, int index);
// Removes the given value from the array, even if it appears more than once.
void sarray_remove(sarray *arrptr, int value);
// Returns the index of the first occurrence of the given value in the array.
int sarray_find(sarray *arrptr, int value);
// Checks to see if given value is valid for memory, and exits if so
void check_address(void *p);
