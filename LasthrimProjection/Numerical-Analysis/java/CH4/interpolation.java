//ch 4 pg.157
import inputs;
import java.io.*;

public class interpolation
{  public static double f(double x)
   { double fx;
     fx = Math.sin(x);
     return fx;
   }

   public static void main(String args[])
   { int n;
     int i,j;
     double h,x;
     double pi = 3.14159;

     System.out.println("Enter the number of intervals: ");
     n = inputs.readInt();
     System.out.println("Enter the initial number x: ");
     x = inputs.readDob();
     System.out.println("Enter the initial value h: ");
     h = inputs.readDob();

     double[][] d = new double[n][n];
     x = pi/3;

     for (i=0;i<=n-1;i++)
     {
       d[i][0] =(f(x+h) - f(x-h)) / (2*h);
       
       for(j=0;j<=(i-1);j++)
        d[i][j+1]=d[i][j] + (d[i][j] - d[i-1][j]) / (Math.pow(4,(j+1))-1);
        
       h = h/2;
       System.out.println("d["+i+"]["+j+"] = " +d[i][j]);
     }   
   }
}
