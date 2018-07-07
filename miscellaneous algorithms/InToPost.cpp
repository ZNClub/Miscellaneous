
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 50

typedef struct{								//Stack
	char c[SIZE];
	int tos;
}Stack;


void push(Stack *s,char ch){				//method push
	if(s->tos==SIZE-1){
		printf("FULL STACK\n");
		exit(1);
	}
	else{
		s->tos++;
		s->c[s->tos]=ch;
	}
}
char pop(Stack *s){							//method pop
	if(s->tos==-1){
		printf("EMPTY STACK\n");
		exit(1);
	}
	else{
		char ret=s->c[s->tos];
		s->tos--;
		return ret;
	}
}
void put(char ch,char *post){				//method put
	*post=ch;
	post++;
}
void convert(char *in,char *post,Stack *s){	// method infix to postfix
	while(*in!='\0'){
		char ch=*in;
		if(ch=='('){						//'('
			push(s,ch);
		}
		else if(ch=='^'){					//^
			Stack *trace=s;
			while(trace->tos!=-1 && s->c[trace->tos]!='('){ //check presence of '('
				trace--;
			}
			if(s->c[s->tos]=='^' && s->c[trace->tos]!='('){//equal precedence and no '(' in stack
					while(s->tos!=-1){
						char trans=pop(s);
						put(trans,post);
						s->tos--;
					}
					push(s,ch);
			}
			else{								//greater precedence or '('
				push(s,ch);
			}
		}
		else if(ch=='*' || ch=='/' || ch=='%'){	// * / %
			Stack *trace=s;
			while(trace->tos!=-1 && s->c[trace->tos]!='('){ //check presence of '('
				trace--;
			}
			if(s->c[s->tos]=='+' || s->c[s->tos]=='-' || s->c[trace->tos]=='('){ // greater precedence or '('
				push(s,ch);
			}
			else{								// lesser or equal precedence
				while(s->tos!=-1){
					char trans=pop(s);
					put(trans,post);
					s->tos--;
				}
				push(s,ch);
			}
		}
		else if(ch=='+' || ch=='-'){			// + -
			Stack *trace=s;
			while(trace->tos!=-1 && s->c[trace->tos]!='('){ //check presence of '('
				trace--;
			}
			if(s->tos=-1 || s->c[trace->tos]=='('){		//empty stack or '('
				push(s,ch);
			}
			else{								// lesser or equal precedence
				while(s->tos!=-1){
					char trans=pop(s);
					put(trans,post);
					s->tos--;
				}
				push(s,ch);
			}
		}
		else if(ch==')'){						// ')'
			while(s->c[s->tos]!='('){			// pop till '('
				char trans=pop(s);
				put(trans,post);
				s->tos--;
			}
			pop(s);							//discard '('
		}
		else if(isalnum(ch)){					// operand
			put(ch,post);
		}
		else{									// invalid
			printf("Enter valid character only\n");
			exit(1);
		}
		in++;
	}
}


int main(){
	Stack s;
	char in[SIZE],post[SIZE];
	s.tos=-1;									//Stack uninitialized
	printf("Enter Your Infix Expression_\n");
	scanf("%s",in);								//input infix string
	convert(in,post,&s);
	printf("Your Postfix Expression_\n%s",post);//display postfix string
	return 0;
}

