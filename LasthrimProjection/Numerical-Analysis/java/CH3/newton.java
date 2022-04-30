//Here is a modified Newton.java
//Please note that it goes better with the book (Page 95-96)
import inputs;
public class newton
{
   public static double F(double x)
    {
      double fx = ((x-2)*x+1)*x-3;
      return fx;
    }
    public static double FP(double x)
    {
      double fp = (3*x-4)*x+1;
      return fp;
    }

   public static void main(String args[])
    {
      int n_max = 15;
      double delta = 0.5*(Math.pow(10,-10));
      double epsi = Math.pow(10,-6);
      int n = 0;
      System.out.println("Newton's Method");
      System.out.println("Input starting value x");
      double x = inputs.readDob();
      double fx = F(x);
      System.out.println("Iteration n = "+n);
      System.out.println(" x = "+x);
      System.out.println(" f(x) = "+fx);
      for (n=1; n<=n_max; n++)
      { 
	double fp = FP(x);
	if( Math.abs(fp) < delta )
        {
	  System.out.println("f'(x) too small!");
	  System.out.println(" x = "+x);
	  System.out.println(" f(x) = "+fx);
	  System.out.println(" f'(x) = "+fp);
          return; 
	}
	double d = -(fx)/fp;
        x += d;
	fx = F(x);
        System.out.println("Iteration n = "+n);
        System.out.println(" x = "+x);
        System.out.println(" f(x) = "+fx);
        if( Math.abs(d) < epsi ) 
	  {
	    System.out.println("Convergence!");
	    return;
	  }	    
      }            
      if( n==n_max ) System.out.println("n_max reached!");  
    }
}






