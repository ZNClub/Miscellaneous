import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class AlternatingChar {

    public static void main(String[] args) {
        int i,j,t;

        Scanner sc=new Scanner(System.in);
        t=sc.nextInt();
        String[] c=new String[t];
        int[] del=new int[t];
        for(i=0;i<t;i++){
            c[i]=sc.nextLine();
        }

        for(i=0;i<t;i++){
            del[i]=0;
            for(j=0;j<c[i].length();j++){
            char ch=c[i].charAt(j);
            if(ch==c[i].charAt(j+1)){
                del[i]++;
            }
            }

        }
        for(i=0;i<t;i++){
            System.out.println(del[i]);
        }


        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}