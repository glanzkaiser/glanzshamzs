import java.io.*;
import inputs;
public class secant
{
   public static double F(double x)
    {
      double fx = (x*x + 1)*x*x*x + 3;
      return fx;
    }

   public static void main(String args[]) throws IOException
    {
      int n_max = 25;
      double delta = Math.pow(10,-10);
      double epsi = 0.5*(Math.pow(10,-6));
      double a, b,fa, fb, fp, d, tmp;

      System.out.println("Enter 0th iterate a");
      a = inputs.readDob();
      System.out.println("Enter 1st iterate b"); 
      b = inputs.readDob();
      
      int n = 0;
      fa = F(a); 
      System.out.println("n = "+n);
      System.out.println("a = "+a);
      System.out.println("fa = "+fa);
      n += 1;
      fb = F(b);
      System.out.println("n = "+n);
      System.out.println("a = "+b);
      System.out.println("fb = "+fb);

      for (n=2; n<=n_max; n++)
        { 
          if ( Math.abs(fa) > Math.abs(fb) )
            {  //swap values so smaller fcn value at a
             tmp = a; a = b; b = tmp;
             tmp = fa; fa = fb; fb = tmp;
            }  
          fp = (fb - fa)/(b - a);
          if ( (Math.abs(fp)) < delta )
	    { 
	    System.out.println("Approx. f' too small!");
            System.out.println("a = "+a);
            System.out.println("fa = "+fa);
            System.out.println("fp = "+fp);
            return;
	    }   
          b = a;
          fb = fa;
          d = -fa/fp;
          a += d;
          fa = F(a);
          System.out.println("n = "+n);
          System.out.println("a = "+a);
          System.out.println("fa = "+fa);
          if ( (Math.abs(d)) < epsi) 
            {
              System.out.println("Converges!");
              return;
            } 
       }
      if (n == n_max) System.out.println("n_max reached!");
    }
}


