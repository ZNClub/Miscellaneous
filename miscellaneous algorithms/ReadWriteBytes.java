import java.io.*;

//package my.io:

public class ReadWriteBytes {

//method to read 1 byte at a time from i/p file and writes it into o/p file and to the screen

//integer var is used to read i/p , EOF indicateed by -1 for int

		public void readBytes1(String fInName,String fOutName)throws IOException{
  																											//   public static void main(String[] args){

        FileInputStream fIn=new FileInputStream(fInName);
        FileOutputStream fOut=new FileOutputStream(fOutName);
        int i;
        while((i=fIn.read())!=-1){
            System.out.println((char)i+" ");		//display character
            System.out.println(i+" ");				//display ASCII values
            fOut.write(i);
		}
		fIn.close();
		fout.close();
       																							//  System.out.println("");
     }
//same method is used with a buffer for eficiency
	public void readBytes2(String fIn,String fOut)throws IOException{
	  																											//   public static void main(String[] args){

	        BufferedInputStream fIn=new BufferedInputStream(new FileInputStream(fInName));
	        BufferedOutputStream fOut=new BufferedOutputStream(new FileOutputStream(fOutNameS));
	        int i;
	        while((i=fIn.read())!=-1){
	            System.out.println((char)i+" ");		//display character
	            System.out.println(i+" ");				//display ASCII values
	            fOut.write(i);
			}
			fIn.close();
			fout.close();
	       																							//  System.out.println("");
     }

}

class ReadLines{

//to read 1 line at a time
	public void readLines(String fIn,String fOut)throws IOException{
		  																											//   public static void main(String[] args){

		        BufferedReader fIn=new BufferedReader(new FileReader(fInName));
		        PrintWriter fOut=new PrintWriter(new FileWriter(fOutName));
		        int i;
//EOF detected by null for string
		        while((s=fIn.readLine())!=null){
		            System.out.println(s);		//display character
		            //System.out.println(i+" ");				//display ASCII values
		            fOut.println(s);
				}
				fIn.close();
				fout.close();
		       																							//  System.out.println("");
     }
}






































