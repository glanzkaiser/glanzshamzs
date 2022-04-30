import inputs;
import java.io.*;

public class runge
{ public static void main(String args[])
   { int n=3;
     int i,k,j;
     int nsteps;
     double a =0;
     double b = 1;
     double h;
     double[] x = new double[n];
     double[] y = new double[n];
     double[][] F = new double[n][4];

     System.out.println("Enter the number of intervals n: ");
     nsteps = inputs.readInt();

     h=(b-a)/nsteps;
   
     x[0]=0.0;
     x[1]=1.0;
     x[2]=0.0;
   

   for(k=1;k<=nsteps;k++)
   {  F[0][0] = 1;
      F[1][0] = x[1] - x[2] + x[0] * (2 - x[0]*(1 + x[0]));
      F[2][0] = x[1] + x[2] - (x[0] * x[0]) * (4 - x[0]);
      
      for(i=0;i<=n-1;i++)
        y[i] = x[i] + 0.5 * h * F[i][0];
  
      F[0][1] = 1;
      F[1][1] = y[1] - y[2] + y[0] * (2 - y[0]*(1 + y[0]));
      F[2][1] = y[1] + y[2] - (y[0] * y[0]) * (4 - y[0]); 

      for(i=0;i<=n-1;i++)
        y[i] = x[i] + 0.5 * h * F[i][1];

      F[0][2] = 1;
      F[1][2] = y[1] - y[2] + y[0] * (2 - y[0]*(1 + y[0]));
      F[2][2] = y[1] + y[2] - (y[0] * y[0]) * (4 - y[0]);

      for(i=0;i<=n-1;i++)
        y[i] = x[i] + 0.5 * h * F[i][2];

      F[0][3] = 1;
      F[1][3] = y[1] - y[2] + y[0] * (2 - y[0]*(1 + y[0]));
      F[2][3] = y[1] + y[2] - (y[0] * y[0]) * (4 - y[0]);

      System.out.println("iterations k = "+k);

      for(i=0;i<=n-1;i++)
      { x[i] = x[i] + (h/6) * (F[i][0] + 2*F[i][1] + 2*F[i][2] +F[i][3]);
        System.out.println("value x["+i+"] = "+x[i]);
      }
    }
  }
}
