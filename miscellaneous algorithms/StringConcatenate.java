import java.io.*;
import java.util.*;
import java.lang.*;
/*
class A{
	int[] a=new int[10];						//RTerrif no "new int[10]" -> NULLPointerException
	A(int[] a){
		for(int i=0;i<a.length;i++){   			//RTTerr for(int i:a) -> ArrayOutOfBoundIndex : 5 %depending how many u send via main()%
			this.a[i]=a[i];						// for(int;boolean;int)	;i<a.length;==boolean	;a[];!=boolean but int
		}
	}
	void display(){
		for(int i:a){							// o/p {1,2,3} = 2 3 0 1 1 1 1 1 1 1 1
			System.out.println(a[i]);
		}
	}
}

class Emp{
	String name;
	char[] id=new char[10];
	Emp(){
		name="ABSTRACT";
		id[0]='\0';
	}
	Emp(String name,char[] id){
		this.name=name;
		this.id=id.toString(id);
		}
	}
	void display(int n){
		for(int i=0;i<n;i++){
			System.out.println(name);
			System.out.println(id);
		}
	}
}

class test1{
	public static void main(String[] args){						// no "String[] args" = NoSuchMethodError
		int[] a={1,2,3};
		A a1=new A(a);
		a1.display();
		Emp e=new Emp();
		Emp f=new Emp("1st",ab12);
		e.display(1);
		f.display(1);
	}
}



class test1{
	public static void main(String[] args){
		Character a='A';
		System.out.println(a);
		System.out.println(a.isLetter(a));
		System.out.println(a.isDigit(a));
		System.out.println(a.isUpperCase(a));
		System.out.println(a.isLowerCase(a));
		System.out.println(a.isWhitespace(a));
		System.out.println(a.toUpperCase(a));
		System.out.println(a.toLowerCase(a));
		System.out.println(a.toString(a));
	}
}



class test1{
	public static void main(String[] args){
	Integer i=10;
											//System.out.println(i.doubleValue(i));
	System.out.println(i.compareTo(i-10));
}
}


	class DateReg	extends Date											//membership joining date
	{
		int d;
		int m;
		int y;
		DateReg(int d,int m,int y)
		{
			this.d=d;
			this.m=m;
			this.y=y;
		}

		public void display()
		{
			DateReg dr=new DateReg(d,m,y);
			System.out.println("DATE OF REGISTRATION_");
			System.out.println(d+"/"+m+"/"+y);
		}
	}


class test1{
	public static void main(String[] args){
			DateReg dr=new DateReg(2,3,2001);
			dr.display();
			Date date=new Date();
			Date date1=new Date();
			System.out.println("Today:"+date);
			date1=dr;

		}
}


class test1{
	public static void main(String[] args){
		String s1=new String("NevZz");
		System.out.println(s1.length());
		System.out.println("UparCase_"+s1.toUpperCase());
		System.out.println("LoverCase_"+s1.toLowerCase());
		System.out.println(s1.substring(3));
		System.out.println(s1.substring(1,4));
		System.out.println(s1.concat(" Dsouza"));
		System.out.println(s1.replace('z','i'));
		s1+=" Dsouza";
		System.out.println(s1);
		char[] a=new char[10];
		System.out.println(s1.charAt(0));
		s1.getChars(1,10,a,0);
		System.out.println(a);
		System.out.println(s1.getBytes());
		System.out.println(s1.toCharArray());
		System.out.println(s1.equals("sw"));
		System.out.println(s1.equalsIgnoreCase("sw"));
		System.out.println(s1.indexOf('z'));
		System.out.println(s1.lastIndexOf('z'));
		System.out.println(s1.compareTo("Nevzz Dsouza"));

	}
}

class P{
	String name;int age;
	P(String name,int age){
		this.name=name;
		this.age=age;
	}
	void display(){
		System.out.print(name+" "+age);
	}
}
class E extends P{
	int id;
	E(String name,int age,int id){
		super(name,age);
		this.id=id;
	}
	void display(){
		super.display();
		System.out.print(" "+id);
	}
}
class M extends E{
	float sal;
	M(String name,int age,int id,float sal){
		super(name,age,id);
		this.sal=sal;
	}
	void display(){
		super.display();
		System.out.println(" "+sal);
	}
}

class test1{
	public static void main(String[] args){
		M m=new M("Nevil",19,120045,100000);
		m.display();
	}
}

interface Stack{
	final int size=10;
	void push(int item);
	int pop();
}
class Stat implements Stack{
	int[] a=new int[size];
	int tos=-1;
	public void push(int item){
		a[++tos]=item;
	}
	public int pop(){
		return(a[tos--]);
	}
	void display(){
		System.out.println(a[tos]);
	}
}
class test1{
	public static void main(String[] args){

		Stat s=new Stat();
		for(int i=0;i<s.size;i++){
			s.push(i);
			s.display();
		}
		System.out.println();
		for(int i=0;i<s.size;i++){
			System.out.println(s.pop());
		}
	}
}

class test1{
	public static void main(String[] args){
		while(true){
		Scanner sc=new Scanner(System.in);
		System.out.println("enter string_");
		String s=sc.nextLine();
		char[] c=new char[s.length()];
		int count=0;
		first: for(int i=0;i<s.length();i++){
		second:for(int j=0;j<s.length();j++){
                    System.out.println(s.charAt(i)+" "+s.charAt(j));
					if(s.charAt(i)==s.charAt(j)){
						for(int k=j;k<i;k++){
							if(c[k]==s.charAt(i))
							break second;
						}
                        c[i]=s.charAt(i);
						System.out.println("	"+c[i]+" "+i);
						break;
                    }
				}
				}
		String s1=new String(c);
		System.out.println(s1);
        for(int i=0;i<s1.length();i++){
            count=0;
            for(int j=0;j<s1.length();j++){
                if(s1.charAt(i)==s.chatAt(j)){
                    count++;
                }
            }
		System.out.print(s1.charAt(i)+" "+count);
        }
	}
	}
}



class test1{
	public static void main(String[] args){

	}
}

*/


public class StringConcatenate{
   public static void main(String[] args){
      long startTime = System.currentTimeMillis();
      for(int i=0;i<5000;i++){
         String result = "This is"
         + "testing the"
         + "difference"+ "between"
         + "String"+ "and"+ "StringBuffer";
      }
      long endTime = System.currentTimeMillis();
      System.out.println("Time taken for string"
      + "concatenation using + operator : "
      + (endTime - startTime)+ " ms");
      long startTime1 = System.currentTimeMillis();
      for(int i=0;i<5000;i++){
         StringBuffer result = new StringBuffer();
         result.append("This is");
         result.append("testing the");
         result.append("difference");
         result.append("between");
         result.append("String");
         result.append("and");
         result.append("StringBuffer");
      }
      long endTime1 = System.currentTimeMillis();
      System.out.println("Time taken for String concatenation"
      + "using StringBuffer : "
      + (endTime1 - startTime1)+ " ms");
   }
}































