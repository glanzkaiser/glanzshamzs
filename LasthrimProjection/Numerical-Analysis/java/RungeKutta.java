public class RungeKutta
{
   public static double F(double t,double w)
    {
      return(w-t*t+1);
    } 
    
   public static void main(String args[])
    {
      double a,b,sumatoria,h,Wi,Wimas1,ti;
      double[] k=new double[4];
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
      ti=a;    
      for(int i=1;i<=n;i++)
	{
	ti=a+h*i;
	k[0]=h*F(ti,Wi);
	k[1]=h*F(ti+h/2,Wi+k[0]/2);
	k[2]=h*F(ti+h/2,Wi+k[1]/2);
	k[3]=h*F(ti+h,Wi+k[3]);
	Wimas1=Wi+(k[0]+2*k[1]+2*k[2]+k[3])/6;
	System.out.println("ti:"+ti+" wi:"+Wi);
	Wi=Wimas1;
	}
    }
}			