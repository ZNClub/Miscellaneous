#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

typedef struct{								//String
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

void reverse(char *in,int length){			//method reverse string
	char in_r[length];
	for(i=0,j=length-1;i<length,j>=0;i++,j--){
		in_r[i]=in[j];
	}
	strcpy(in,in_r);
}


void convert(Stack *s,char *pre){
	String str;
	while(*pre!=NULL){
		char op=*post;
		if(isalnum(op)){
			push(s,op);
		}
		else{
			String n2=pop(s);
			String n1=pop(s);
			str=n1,op,n2;
			push(s,str);
		}
		pre++;
	}
	str=pop(s);
	printf("Prefix Expression is_"str);
}


int main(){
	Stack s;
	s.tos=-1;
	char []pre;
	printf("Enter Your Postfix Expression_");
	scanf("%s",pre);
	reverse(pre,strlen(pre));
	convert(&s,pre);
	return 0;
}