#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <limits.h>
#include <cstdint>

#define DUMP

#ifdef DUMP
	#define CHECK_ERR(cond) if((cond)) return err;
#else
	#define CHECK_ERR(cond)
#endif

typedef int Elem_t;
extern const char* Elem_out;
const size_t MIN_SIZE_DATA = 8; 

enum poisons
{
	POISON      = INT_MIN,
	POISON_DATA =  0,
	POISON_SIZE = SIZE_MAX,
};

typedef struct
{
	Elem_t elem;
	size_t next;
	size_t prev;
} elem;

#ifdef DUMP

#endif

typedef struct
{	
	elem* data;
	size_t  size;
} list;

#define data_of(ind) ls->data[ind].elem
#define next_of(ind) ls->data[ind].next
#define prev_of(ind) ls->data[ind].prev
#define SIZE ls->size - 1

#define data_of_new(ind) new_ls->data[ind].elem
#define next_of_new(ind) new_ls->data[ind].next
#define prev_of_new(ind) new_ls->data[ind].prev
#define NEW_SIZE new_ls->size - 1

list*  list_ctor   	         (size_t size);
size_t list_pop 	         (list* ls,      Elem_t* returned_val);
size_t list_insert_head      (list** ls_ptr, Elem_t val, size_t* returned_num);
size_t list_insert_tail      (list** ls_ptr, Elem_t val, size_t* returned_num);
size_t list_insert_after_ind (list** ls_ptr, size_t ind, Elem_t val, size_t* returned_num);
size_t list_insert_before_ind(list** ls_ptr, size_t ind, Elem_t val, size_t* returned_num);

size_t  list_up_size  (list* ls, list** returned_ls);
size_t  list_sort     (list* ls);
size_t  list_linear_sort (list** ls_ptr);
int     list_compare  (const void* a, const void* b);
void    list_dtor     (list* ls);

size_t find_ind_by_num (const list* ls, Elem_t val, size_t* returned_ind);
size_t find_logical_ind(const list* ls, size_t ind, size_t* returned_serial_num);
size_t at_list         (const list* ls, size_t ind, size_t* returned_ip);

#endif