import inputs;

public class poly
{
   public static void main(String args[])
   { int n;
     int i,j,nminus;
     double h,d,t;
     double eval, temp;

     System.out.println("Enter the number of intervals: ");
     n = inputs.readInt();
     //System.out.println("Enter the initial value h: ");
     //h = inputs.readDob();

     double[] x = new double[n];
     double[] y = new double[n];
     double[] a = new double[n];
     nminus = n-1;   // for array indexing 0-9=10 digits
     h = 1.6875 / n;
  
     for(i=0;i<=nminus;i++)
      { x[i]= i*h;
        y[i]= Math.sin(x[i]);
      }
      
     for(i=0;i<=nminus;i++)
       a[i] = y[i];
         
     for(j=1;j<=n;j++)
       for(i=nminus;i>=j;i--)
       {  a[i]=(a[i]-a[i-1])/(x[i]-x[i-j]);
          System.out.println("a["+i+"] = " +a[i]);
       }

     for (j=0;j<=(4*n-1);j++)
     { t = j*h / 4;
       temp = a[nminus];
       for(i=nminus;i>=1;i--)
        temp = temp * (t - x[i]) + a[i];
       
       eval = temp;
       d = Math.sin(t) - eval;
       System.out.println("**********************************");
       System.out.println("value i = "+j);
       System.out.println("value t = "+t);
       System.out.println("value d = "+d);
     }
   }
}
