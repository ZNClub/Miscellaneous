import java.util.*;

class BirthDay{

		private static Hashtable<String,String> person=new Hashtable();
		private String name;
		private String bdate;

		public void setBday(String name,String dt){
			this.name=name;
			this.bdate=dt;

		}

		public String getBdayDate(){
					return this.bdate;
		}

		public String getBdayName(){
				return this.name;
		}

		public void readBday(String name,String dt){

			setBday(name,dt);

			person.put(getBdayName(),getBdayDate());

		}

		public void displayBday(){

			Enumeration e=person.keys();
			while(e.hasMoreElements()){

				String str=(String)e.nextElement();
				StringBuffer rev_date=new StringBuffer(person.get(str));
				rev_date.reverse();
				System.out.println("Name:\t"+str+"\nBirthDate:\t"+rev_date);

				}
		}

		public void diffDate(){
			String dd=this.bdate.substring(0,1)
			String mm=this.bdate.substring(2,3);
			String yyyy=this.bdate.substring(4,7);



			}







	//	System.out.println("");




}


public class Hbd{
	public static void main(String[] args){
		Scanner sin=new Scanner(System.in);
		boolean yes=false;

		do{
		System.out.println("Welcome_\nEnter the name_");
		String name=sin.nextLine();

		System.out.println("Enter the birthdate as DD-MM-YYYY");
		StringBuffer buffdate=new StringBuffer(sin.nextLine());

		buffdate.reverse();
		String date=new String(buffdate);

		BirthDay bdae=new BirthDay();

		bdae.readBday(name,date);

		bdae.displayBday();
		System.out.println("Do you want to Enter more?_\nYES\tNO");

		String decision=sin.nextLine();
		if("YES".equalsIgnoreCase(decision))	{yes=true;}
		else if("NO".equalsIgnoreCase(decision)){yes=false;}
		else									{System.out.println("INVALID OPTION");}

		}
		while(yes==true);

	}
}


