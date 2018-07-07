#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

typedef struct{								//Stack
	char charac[SIZE];
}String;

typedef struct{								//Stack
	String c[SIZE];
	int tos;
}Stack;


void push(Stack *s,String str){				//method push
	if(s->tos==SIZE-1){
		printf("FULL STACK\n");
	}
	else{
		s->tos++;
		s->c[s->tos]=ch;
	}
}

String pop(Stack *s){							//method pop
	if(s->tos==-1){
		return("Stack EMPTY");
	}
	else{
		String ret=s->c[s->tos];
		s->tos--;
		return ret;
	}
}


void convert(Stack *s,char *post){
	String str;
	while(*post!=NULL){
		char op=*post;
		if(isalnum(op)){
			push(s,op);
		}
		else{
			String n2=pop(s);
			String n1=pop(s);
			str=op,n1,n2;
			push(s,str);
		}
		post++;
	}
	str=pop(s);
	printf("Prefix Expression is_"str);
}

int main(){
	Stack s;
	s.tos=-1;
	char []post;
	printf("Enter Your Postfix Expression_");
	scanf("%s",post);
	convert(&s,post);
	return 0;
}
