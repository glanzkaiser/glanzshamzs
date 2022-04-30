import inputs;

public class spline
{
   public static void main(String args[])
   {
     int n;
     double a=0;
     double b=1.6875;

     int i,j;
     double d,h,x,tmp,eval;

     System.out.println("Enter the number of intervals: ");
     n = inputs.readInt();

     double[] t = new double[n];
     double[] y = new double[n];
     double[] z = new double[n];

     double[] harr = new double[n-1];
     double[] barr = new double[n-1];
     double[] uarr = new double[n-1];
     double[] varr = new double[n-1];

     h = (b-a)/n;
 
     for(i=0;i<=n;i++)
      {  t[i]= a + i*h;
         y[i]= Math.sin(t[i]);
      }

     for(i=0;i<=n-1;i++)
      {  harr[i]= t[i+1] - t[i];
         barr[i]= (y[i+1] - y[i]) / harr[i];
      }

     uarr[1] = 2 * (harr[0] + harr[1]);
     varr[1] = 6 * (barr[1] - barr[0]);
 
     for(i=2;i<=n-1;i++)
      { uarr[i] = 2 * (harr[i] + harr[i-1]) - (Math.pow(harr[i-1],2) / uarr[i-1]);
        varr[i] = 6 * (barr[i] - barr[i-1]) - harr[i-1] * varr[i-1] / uarr[i-1];
      }

     z[n-1] = 0;
  
     for(i=n-1;i>=1;i--)
       z[i] = (varr[i] - harr[i] * z[i+1]) / uarr[i];

     z[0] = 0;

     for(i=0;i<=4*n;i++)
     {   x = a + i*h / 4;
         for(j=n-1;j>=1;j--)
           if ((x - t[j]) >= 0) {
              System.out.println("ERROR");
              j = 0;   //exit loop
            }
         h = t[i+1] - t[i];
         tmp = (z[i]/2) + (x-t[i]) * (z[i+1] - z[i]) / (6*h);
         tmp = -(h/6) * (z[i+1] + 2 * z[i]) + (y[i+1] - y[i]) / h + (x - t[i]) * tmp;
         eval = y[i] + (x - t[i]) * tmp;
         d = Math.sin(x) - eval;
         System.out.println("********************************");
         System.out.println("iteration i = "+i);
         System.out.println("value x = "+x);
         System.out.println("deviation = "+d);
     }
   }
}
