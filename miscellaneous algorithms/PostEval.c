#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

typedef struct{								//Stack
	double c[SIZE];
	int tos;
}Stack;


void push(Stack *s,double ch){				//method push
	if(s->tos==SIZE-1){
		printf("FULL STACK\n");
	}
	else{
		s->tos++;
		s->c[s->tos]=ch;
	}
}
double pop(Stack *s){						//method pop
	if(s->tos==-1){
		printf("EMPTY STACK\n");
		return -1.0;
	}
	else{
		double ret=s->c[s->tos];
		s->tos--;
		return ret;
	}
}

double convert(op){							//char to double
	switch(op){
				case '0' : return 0.0;

				case '1' : return 1.0;

				case '2' : return 2.0;

				case '3' : return 3.0;

				case '4' : return 4.0;

				case '5' : return 5.0;

				case '6' : return 6.0;

				case '7' : return 7.0;

				case '8' : return 8.0;

				case '9' : return 9.0;

	}
}

double cal(double n1,char op,double n2){
	switch(op){
		case '+':return(n1+n2);
		case '-':return(n1-n2);
		case '*':return(n1*n2);
		case '/':return(n1/n2);
		case '%':return(n1%n2);
		case '^':return(n1^n2);
	}
}

double eval(Stack *s,char *post){			//evalutation
	double op;
	while(*post!=NULL){
		op=*post;
		if(isnum(op)){						//operand
			 op=convert(op);
			 push(&s,op);
		}
		else{								//operator
			double n2=pop(&s);
			double n1=pop(&s);
			double result=cal(n1,op,n2);
			push(&s,result);
		}
	post++;
	}
	result=pop(&s);
	return result;
}

int main(){
	Stack s;
	s.tos=-1;								//Stack uninitialized
	char []post;
	printf("Enter Your Postfix Expression_");
	scanf("%s",post);
	double result=eval(&s,post);
	printf("R E S U L T_",result);
	return 0;
}




