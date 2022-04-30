import inputs;

public class EulerM
{
   public static double F(double w,double t)
    {
      return(w-t*t+1);
    } 
  public static void main(String args[])  
    {
      double a,b,sumatoria,h,Wi,Wimas1,ti;
      int n;
      System.out.println("Escribe el numero de intervalos:");
      n=inputs.readInt();
      System.out.println("Escribe desde donde quieres integrar:");
      a=inputs.readDob();
      System.out.println("Escribe hasta donde integrar:");
      b=inputs.readDob();
	System.out.println("Escribe tu condicion inicial");
	Wi=inputs.readDob();
	h=(b-a)/n;
      for(int i=0;i<=n;i++)
	{
	ti=a+h*i;
	Wimas1=Wi+(h/2)*(F(Wi,ti)+F(Wi+h*F(Wi,ti),ti+h));
	System.out.println("ti:"+ti+" wi:"+Wi);
	Wi=Wimas1;
	}
    }
}

