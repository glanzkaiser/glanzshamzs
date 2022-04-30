import inputs;

public class ReimannD
{
  public static double F(double x)
  {
    return(x);
  } 
  public static void main(String args[])  
  {
    double a,b,sumation=0.0,delta;
    int n;
    System.out.println("Enter the number of intervals:");
    n=inputs.readInt();
    System.out.println("Enter the start of the integral:");
    a=inputs.readDob();
    System.out.println("Enter the end of the integral:");
    b=inputs.readDob();
    delta=(b-a)/n;
    for(int i=1;i<=n;i++)
      {
	sumation+=F(a+(i*delta));
      }
    sumation*=delta;
    System.out.println("The numerical integral is: "+sumation);
  }
}
