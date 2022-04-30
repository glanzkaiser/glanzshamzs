//Euler CH. 8 pg.328
import inputs;

public class Euler
{
   public static double f(double t,double x)
    {  double fxy;
       x = Math.pow(x,2);
       t = t*t*t;
       fxy = 1 + x + t;
       return fxy;
    } 
  public static void main(String args[])  
    {
      double a;
      double b;
      double x;

      int n;
      int k;
      double h,t;
  
    System.out.println("Enter the number of intervals n: ");
    n = inputs.readInt();
    System.out.println("Enter the number 'a' you wish to integrate from: ");
    a = inputs.readDob();
    System.out.println("Enter the number 'b' you wish to integrate to: ");
    b = inputs.readDob();
    System.out.println("Enter your initial condition x");
    x = inputs.readDob();
    
      h = (b-a)/n;
      t = a;
 
      System.out.println("The value t = "+t);
      System.out.println("The value x = "+x);
  
      for(k=1;k<=n;k++)
	{ x = x + h * f(t,x); 
          t = t + h;
          System.out.println("---------------------------------");
          System.out.println("The value k = "+k);
          System.out.println("The value t = "+t);
          System.out.println("The value x = "+x);
	}
    }
}

