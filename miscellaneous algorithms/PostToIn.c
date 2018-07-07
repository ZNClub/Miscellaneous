#include <stdio.h>
#include <stdlib.h>
#define SIZE 50



typedef struct{								//Stack
	char c[SIZE][SIZE];
	int tos;
}Stack;


void push(Stack *s,char str){				//method push
	if(s->tos==SIZE-1){
		printf("FULL STACK\n");
	}
	else{
		s->tos++;
		s->c[s->tos][]=str;
	}
}

char pop(Stack *s){						//method pop
	if(s->tos==-1){
		return("Stack EMPTY");
	}
	else{
		char ret=s->c[s->tos][];
		s->tos--;
		return ret;
	}
}


void convert(Stack *s,char *post){
	while(*post!=NULL){
		char op=*post;
		if(isalnum(op)){
			push(s,op);
		}
		else{
			char n2[SIZE]=pop(s);
			char n1[SIZE]=pop(s);
			char str[SIZE]={n1,op,n2};
			push(s,str);
		}
		post++;
	}
	str=pop(s);
	printf("Infix Expression is_",str);
}

int main(){
	Stack s;
	s.tos=-1;
	char post[];
	printf("Enter Your Postfix Expression_");
	scanf("%s",post);
	convert(&s,post);
	return 0;
}
