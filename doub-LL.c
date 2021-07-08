#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node* prev_ptr;
	struct node* next_ptr;
}node_t;

char action;
node_t * head_ptr = NULL;

void linefeed(char c){
	for(int i = 0; i< 40; i++) printf("%c",c);
	
	printf("\n");
}

int is_last_item(node_t * list_item_ptr){
	if(NULL == list_item_ptr->next_ptr) return 1;
	else return 0;
}

node_t * get_last_item_ptr(node_t * cur_item_ptr){
	while(!is_last_item(cur_item_ptr)) cur_item_ptr = cur_item_ptr->next_ptr;
	return cur_item_ptr;
}


node_t * return_new_node_ptr(){
	node_t * new_node_ptr = malloc(sizeof(*new_node_ptr));
	printf("new Node created at %p!\n",(void*)new_node_ptr);
	return new_node_ptr;
}
void push_back(node_t * head_of_list_ptr, node_t * new_item_ptr){
	node_t * current_last_ptr = get_last_item_ptr(head_of_list_ptr);
	current_last_ptr->next_ptr = new_item_ptr;
	current_last_ptr->next_ptr->prev_ptr = current_last_ptr;
	current_last_ptr->next_ptr->next_ptr = NULL;
}

int list_item_ptrs_from(node_t * cur_item_ptr){
	int counter = 1;
	while(NULL!=cur_item_ptr){
		printf("Item Number %i at %p\n",counter,(void*)cur_item_ptr);
		cur_item_ptr = cur_item_ptr->next_ptr;
		counter++;
	}
	return counter;
}


int main(){
	printf("----------------------------------\n");
	printf("Willkommen im Linked-List Programm\n");
	head_ptr = malloc(sizeof(*head_ptr));
	printf("First Item created at %p",(void*)head_ptr); 
	if (NULL == head_ptr) return 1;
	head_ptr->next_ptr = NULL;

	linefeed(' ');
	
	while(1){
		printf("n = new node; l = list nodes; q = quit: ");
		scanf(" %c",&action);
		if('n' == action)      push_back(head_ptr, return_new_node_ptr());
		else if('l' == action) list_item_ptrs_from(head_ptr);
		else if('q' == action) break;
		else printf("Keine Aktion für Buchstabe = %c!\n",action);
	}
	return 0;
}
