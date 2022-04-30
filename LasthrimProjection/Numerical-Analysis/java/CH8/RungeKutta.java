public class RungeKutta
{
   public static double f(double t,double x)
    {
      return(2 + (Math.pow((x-t-1),2)));
    } 
    
   public static void main(String args[])
    {
      double a,b,h,x,ti;
      double[] F = new double[4];
      int n,i;

      System.out.println("Enter the number of intervals n: ");
      n = inputs.readInt();
      System.out.println("Enter the lower limit a: ");
      a = inputs.readDob();
      System.out.println("Enter the upper limit b: ");
      b = inputs.readDob();
      System.out.println("Enter your initial condition x: ");
      x = inputs.readDob();
      
      h=(b-a)/n;
      ti=a;    
      for(i=1;i<=n;i++)
	{ ti=a+h*i;
	  F[0] = h * f(ti,x);
	  F[1] = h * f(ti + h/2,x + F[0]/2);
	  F[2] = h * f(ti + h/2,x + F[1]/2);
	  F[3] = h * f(ti + h,x + F[2]);
	  x = x + ((F[0] + 2*F[1] + 2*F[2] + F[3]) / 6);
	  System.out.println("t="+ ti +"  x="+ x +"   i="+i);
	}
    }
}			
