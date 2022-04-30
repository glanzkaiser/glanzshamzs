import inputs;

public class Trapecios
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
      for(int i=1;i<=n-1;i++)
	sumatoria+=2*F(a+i*delta);
      sumatoria*=delta/2;
      System.out.println("La integral numerica es:"+sumatoria);
    }
}

