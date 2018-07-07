import java.util.*;

class DifferentiatingSpaces{
	public static void main(String[] args)	{

		Scanner in=new Scanner(System.in);
		int _a_size = Integer.parseInt(in.nextLine());      //test cases
        int[] _a = new int[_a_size];                        // array
        int _a_item;
        String next = in.nextLine();
        String[] next_split = next.split(" ");

      	  for(int _a_i = 0; _a_i < _a_size; _a_i++) {
			 System.out.println(" next_split\t"+next_split[_a_i]);
            _a_item = Integer.parseInt(next_split[_a_i]);
            _a[_a_i] = _a_item;
            System.out.println(" _a[_a_i] = _a_item\t"+_a_i+"="+_a_item);
       	 }


	}
}

