import inputs;
public class newtonr
{
   public static double F(double x)
    {
      return(x*x*x*x+x*x*x-34*x*x-4*x+120);
    }
    public static double f(double x)
    {
      return(4*x*x*x+3*x*x-68*x-4);
    }
   public static void main(String args[])
    {
      double Xn,XnM1=0;
      System.out.println("Escribe un numero a");
      Xn=inputs.readDob();
         for(int i=0;i<100;i++)
            {
             XnM1=Xn-(F(Xn)/f(Xn));
             if(((XnM1-Xn)<0.000001)&&((XnM1-Xn)>-0.000001))
              {
               System.out.println("La Raiz es:"+XnM1);
               System.out.println("El numero de iteraciones es:"+i);
               return; 
	      }
	     Xn=XnM1;
            }            
      System.out.println("faltaron interaciones la aproximacion es: "+XnM1);
      System.out.println(XnM1);
      return;
    }
}
