import inputs;

public class trapezoid
{
   public static double f(double x)
    { double e = 2.718281828;
      x = Math.pow(x,2);
      e = Math.pow(e,x);
      x = 1 / e;
      return x;
    } 
  public static void main(String args[])  
    {
      double a;
      double b;
      double h,sum,x;
      int n;
      int i;
      
      System.out.println("Enter the number of intervals: ");
      n = inputs.readInt();
      System.out.println("Enter the number you wish to integrate from: ");
      a = inputs.readDob();
      System.out.println("Enter the number you wish to integrate to: ");
      b = inputs.readDob();
      
      h = (b-a)/n;
      sum = 0.5 * (f(a) + f(b));
      
      for(i=1;i<=n-1;i++)
      {   x = a + i * h;
          sum = sum + f(x);
      }
      
      sum = sum * h;
      System.out.println("The numerical integral is: "+sum);
    }
}

