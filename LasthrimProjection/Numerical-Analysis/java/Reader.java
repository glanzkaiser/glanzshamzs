package KenStuff;

import java.io.DataInputStream;
import java.lang.Integer;
import java.io.IOException;

public class Reader
{
  static DataInputStream in = new DataInputStream(System.in);
  static int x = 0;
  static String s;
  static boolean success = false;
	
  public static int readInt(String message)
  {
    success = false;
    while(success == false)
      {		
	System.out.print(message);
	System.out.flush();
			
	success = true;
	try 
	  {
	    s = in.readLine();
	  }
	catch (IOException e) 
	  {
	    success = false; // what to do here?
	  }
	
	try 
	  {
	    x = Integer.parseInt(s);
	  }
	catch (NumberFormatException e) 
	  {
	    System.out.println("Not a 32-bit number, try again.");
	    success = false; // what to do here?
	  }
      }
    return x;
  }

	
  // this is only for testing purposes
public static void main(String[] args)
  {
    int i;
    i = readInt("Enter a number: ");
    System.out.println("You entered: " + i);
  }
}













