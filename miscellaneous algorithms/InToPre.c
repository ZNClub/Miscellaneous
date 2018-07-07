
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

typedef struct{								//Stack
	char c[SIZE];
	int tos;
}Stack;


void push(Stack *s,char ch){				//method push
	if(s->tos==SIZE-1){
		printf("FULL STACK\n");
	}
	else{
		s->.tos++;
		s-c[s->tos]=ch;
	}
}
char pop(Stack *s){							//method pop
	if(s->tos==-1){
		printf("EMPTY STACK\n");
	}
	else{
		char ret=s->c[s->tos];
		s->tos--;
		return ret;
	}
}
void put(char ch,char *pre){				//method put
	*pre=ch;
	pre++;
}
void reverse(char *in,int length){			//method reverse string
	char in_r[length];
	for(i=0,j=length-1;i<length,j>=0;i++,j--){
		in_r[i]=in[j];
	}
	strcpy(in,in_r);
}
void convert(char *in,char *pre,Stack *s){// method infix to prefix
	while(*in!=NULL){
		if(ch==')'){						// ')'
			push(&s,ch);
		}
		else if(ch=='^'){					// ^
			push(&s,ch);
		}
		else if(ch=='*' || ch=='/' || ch=='%'){		// * / %
			int *trace=s->tos;
			while(*trace!=-1 && s->c[*trace]!='('){ //check presence of '('
				trace--;
			}
			if(s->c[s->tos]=='^' && s->c[*trace]!=')'){// lesser precedence or ')'
					char trans=pop(&s);
					put(trans,pre);
					push(&s,ch)
			}
			else{ 								// greater precedence or '('
				push(&s,ch);
			}
		}
		else if(ch=='+' || ch=='-'){				// + -
			int *trace=s->top;
			while(*trace!=-1 && s->c[*trace]!='('){ //check presence of '('
				trace--;
			}

			if(s->top=-1 || *trace=='('){			//empty stack or '('
				push(&s,ch);
			}
			else{									// lesser or equal precedence
				char trans=pop(s);
				put(trans,pre);
				push(&s,ch);
			}
		}
		else if(ch=='('){							// '('
			while(s->c[s->tos]!=')'){				//pop till ')'
				char trans=pop(s);
				put(trans,pre);
				s->tos--;
			}
			pop(&s);
		}
		else if(isalnum(ch)){						// operand
			put(ch,pre);
		}
		else{										// invalid
			printf("Enter valid character only\n");
			exit(1);
		}
		in++;
	}
}


int main(){
	Stack s;
	char in[SIZE],pre[SIZE];
	s.tos=-1;									//Stack uninitialized
	printf("Enter Your Infix Expression_");
	scanf("%s",in);
	reverse(in,strlen(in));							//reverse infix string
	convert(in,pre,&s);
	reverse(pre,strlen(pre));						//reverse prefix string
	printf("Your Prefix Expression_\n%s",pre);
	return 0;
}
