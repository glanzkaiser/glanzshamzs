import java.io.DataInputStream;
import java.lang.Integer;
import java.io.*;

public class inputs
{
  static DataInputStream in = new DataInputStream(System.in);
  static String s;
  static boolean success = false;
	
  public static double readDob()
  {
    double x=0.0;
    success = false;
    while(success == false)
      {					
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
            Double Fx=new Double(s);
            x=Fx.doubleValue(); 	
	  }
	catch (NumberFormatException e) 
	  {
	    System.out.println("Not a double, try again.");
	    success = false; // what to do here?
	  }
      }
    return x;
  }
   public static float readFlo()
  {
    float x=0;
    success = false;
    while(success == false)
      {
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
            Float Fx=new Float(s);
            x=Fx.floatValue();
          }
        catch (NumberFormatException e) 
	  {
            System.out.println("Not a float, try again.");
            success = false; // what to do here?
          }
      }
    return x;
  } 
  public static int readInt()
  {
    int x=0;
    success = false;
    while(success == false)
      {
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
            x=Integer.parseInt(s);
          }
        catch (NumberFormatException e)
	  {
            System.out.println("Not a integer, try again.");
            success = false; // what to do here?
          }
      }
    return x;
  }

   public static String readStr() throws IOException
  { 
    return(in.readLine()); 
  }
}
