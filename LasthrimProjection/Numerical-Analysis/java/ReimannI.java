import inputs;

public class ReimannI
{
  public static double F(double x)
  {
    return(x);
  } 
  public static void main(String args[])  
  {
    double a,b,sumatoria=0.0,delta;
    int n;
    System.out.println("Escribe el numero de intervalos:");
    n=inputs.readInt();
    System.out.println("Escribe desde donde quieres integrar:");
    a=inputs.readDob();
    System.out.println("Escribe hasta donde integrar:");
    b=inputs.readDob();
    delta=(b-a)/n;
    for(int i=0;i<n;i++)
      {
	sumatoria+=F(a+(i*delta));
      }
    sumatoria*=delta;
    System.out.println("La integral numerica es:"+sumatoria);
  }
}
