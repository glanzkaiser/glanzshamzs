import inputs;

public class Simpson
{
   public static double F(double x)
    {
      return(x);
    } 
  public static void main(String args[])  
    {
      double a,b,sumatoria,delta;
      int n;
      System.out.println("Escribe el numero de intervalos:");
      n=inputs.readInt();
      System.out.println("Escribe desde donde quieres integrar:");
      a=inputs.readDob();
      System.out.println("Escribe hasta donde integrar:");
      b=inputs.readDob();
      delta=(b-a)/n;
      sumatoria=F(a)+F(b);
      System.out.println("3/2="+(3/2));
      for(int i=1;i<=(n/2)-1;i++)
	sumatoria+=2*F(a+2*i*delta);
      for(int i=1;i<=(n/2);i++)
	sumatoria+=4*F(a+((2*i)-1)*delta);
      sumatoria*=delta/3;
      System.out.println("La integral numerica es:"+sumatoria);
    }
}
