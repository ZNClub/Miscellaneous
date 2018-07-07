
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Loveletter {

    public static void main(String[] args) {
        int t,diff;												//test case

        Scanner sc=new Scanner(System.in);
        t=sc.nextInt();

        String[] pal=new String[t];				             // strings
        String[] rev_pal=new String[t];
        int[] edit=new int[t];								//no of operations

        for(int i=0;i<t;i++){
            pal[i]=new String(sc.next());				//original
            StringBuffer sb=new StringBuffer(pal[i]);
            rev_pal[i]=new String(sb.reverse()); 		//reversed

        }
                                                        //evaluate
        for(int i=0;i<t;i++){
          edit[i]=0;
                                                        //if palindrome then continue
          if((rev_pal[i].equals(pal[i]))){
              continue;
		  }
		  else{																	//outer else

              char[] ch=pal[i].toCharArray();
			  int key1=0;
              int key2=0;
              int max=0;
              /*                                          //search max char	check
			  while(key1<ch.length){
				int val=Character.codePointAt(ch,key1);
				if(val>max){
                    max=val;
                    key2=key1;
                    //System.out.println("key2="+key2+"\tchar="+pal[i].charAt(key2));
                 }
				key1++;
			  }	*/
			 // System.out.println("\t\t"+key2);

              int f=0,l=pal[i].length()-1;
            /*  if(key2<(ch.length)/2){                 */                         //key < mid	dcba		//inner IF else

				while(f<=(ch.length)/2 && l>=(ch.length)/2){
					if(pal[i].charAt(f)=='a'){
						continue;
					}


                    diff=Math.abs(((int)(pal[i].charAt(f))-(int)(pal[i].charAt(l)))) ;
                   	if(diff==0)			{continue;}
					edit[i]+=diff;
					char[] charVal={pal[i].charAt(l)};
					String cv=new String(charVal);
					StringBuffer s=new StringBuffer(pal[i]);
					s.replace(f,f+1,cv);
					pal[i]=new String(s);
					StringBuffer sb=new StringBuffer(pal[i]);
                	rev_pal[i]=new String(sb.reverse());
					if((rev_pal[i].equals(pal[i]))){
						break;
	                }
	                f++;l--;diff=0;
				}
           /*   }																					//inner IF else
              else{															//key>mid abcd	//inner if ELSE
				  while(f<=(ch.length)/2 && l>=(ch.length)/2){
				  					if(pal[i].charAt(l)=='a'){
				  						continue;
				  					}


				                    diff=Math.abs(((pal[i].charAt(f))-(pal[i].charAt(l)))) ;
				                    if(diff==0)			{continue;}
				  					edit[i]+=diff;
				  					char[] charVal={pal[i].charAt(f)};
				  					String cv=new String(charVal);
				  					StringBuffer s=new StringBuffer(pal[i]);
				  					s.replace(l,l+1,cv);
				  					pal[i]=new String(s);
				  					StringBuffer sb=new StringBuffer(pal[i]);
                					rev_pal[i]=new String(sb.reverse());
				  					if((rev_pal[i].equals(pal[i]))){
				  						break;
				  	                }
				  	                f++;l--;diff=0;

					}
				}																						//inner if ELSE
          }			*/																					//outer if ELSE
        }}
                                                        //output
         for(int i=0;i<t;i++){

            System.out.println(edit[i]);
        }

        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}

