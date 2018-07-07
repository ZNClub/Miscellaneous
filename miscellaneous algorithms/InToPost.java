class Convert{
	Char[] infix;
	Char[] postfix;
	Convert(Char[] in){
		for(int i:in){
			infix[i]=in[i];
		}
}
class Stack{
	int[] st=new int[10];
	int tos;
	Stack(){
		int tos=-1;
	}
	public void push(int element){
		if(s.tos==10){
			System.out.println("Stack overflow");
		}
		else{
			s.st[++s.tos]=element;
	public void display(){
		for(int i:st){
			System.out.println(st[i]);
		}
	}
}
class xInToPost{
	public static void main(String[] args){
		Stack s=new Stack();
		s.push(10);
		s.display();
		s.push(33);
		s.display();

	}
}