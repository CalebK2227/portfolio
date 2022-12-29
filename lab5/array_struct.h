#ifndef ARRAY_STRUCT_H_
#define ARRAY_STRUCT_H_


#define SIZE 5

struct data_t {

	int age;  /* age of the subject */
	int height;  /* height of subject in inches */
	char subject; 	/* one capital letter id for subject */
	
};

void init_array(struct data_t data[], int index, char id, int years, int inches);
int min_age(struct data_t data[]);
int min_height(struct data_t data[]);
int max_age(struct data_t data[]);
int max_height(struct data_t data[]);
int ave_age(struct data_t data[]);
int ave_height(struct data_t data[]);
void print_one(struct data_t data);

#endif
