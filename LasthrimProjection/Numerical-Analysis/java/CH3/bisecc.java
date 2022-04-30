import inputs;
import java.io.*;
public class bisecc
{
   public static double F(double x)
    {
     double fx = (x*x-3)*x+1;
     return fx;
    } 

   public static double G(double x)
    { double gx = x*x*x-2*(Math.sin(x));
      return gx;
    }

  public static void main(String args[])  
    {
      double a, b, c, fa, fb, fc, error;
      int n_max = 50;
      int num, n;
      double epsi = 0.5*(Math.pow(10,-6));

      System.out.println("What function do you wish to use?");
      System.out.println("1.  f(x) = (x*x - 3) * x + 1  or ");
      System.out.println("2.  g(x) = x*x*x - 2sin(x) ");
      System.out.println("Select only 1 or 2");
      num = inputs.readInt();

      System.out.println("Input a number for a");
      a = inputs.readDob();
      System.out.println("Input a number for b");
      b = inputs.readDob();

      if (num == 1)
      { fa = F(a);
        fb = F(b); 
      }
      else
      { fa = G(a);
        fb = G(b);
      } 
      
      if ((fa<0) && (fb<0))
         {  System.out.println("Function has same signs at a and b");
            System.out.println("a = "+a);
            System.out.println("b = "+b);
            System.out.println("fa = "+fa);
            System.out.println("fb = "+fb);
          }
      if ((fa>0) && (fb>0))
         {  System.out.println("Function has same signs at a and b");  
            System.out.println("a = "+a);
            System.out.println("b = "+b);
            System.out.println("fa = "+fa);
            System.out.println("fb = "+fb);
         }  

      error = b - a;

      for(n=0;n<=n_max;n++)
      { error = error / 2;
	c = a + error;
        if (num == 1)
          fc = F(c);
        else 
          fc = G(c);

        System.out.println("n = "+n);
        System.out.println("c = "+c);
        if (num == 1)
          System.out.println("fc = "+fc);
        if (num == 2)
          System.out.println("gc = "+fc);
        System.out.println("error = "+error);

        if (error < epsi)
          { System.out.println("Converges!");
            return;
          }
        if (((fa<0) && (fc>0)) || ((fa>0) && (fc<0)))
          { b = c;
            fb = fc;
          }
        else
          { a = c;
            fa = fc;
          }
       }
      if (n == n_max) System.out.println("n_max reached!");
    }     
}



