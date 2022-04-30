import inputs;
public class bailey
{
   static DataInputStream n;
   public static double F(double x)
    {
      return(x*x+4*x-5);
    }
    public static double f(double x)
    {
      return(2*x+4);
    }
    public static double ff(double x)
    {
      return(2);
    }
   public static void main(String args[])
    {
      double Xn,XnM1=0;
      System.out.println("Escribe un numero a");
      Xn=inputs.readDob;
         for(int i=0;i<100;i++)
            {
	     XnM1=Xn-(F(Xn)/(f(Xn)-(F(Xn)*ff(Xn)/(2*f(Xn)))));
             if(((XnM1-Xn)<0.000001)&&((XnM1-Xn)>-0.000001))
              {
               System.out.println("La Raiz es:"+XnM1);
               System.out.println("El numero de iteraciones es:"+i);
               return; 
	      }
	     System.out.println(XnM1+"  inter:"+i);
	     Xn=XnM1;
            }            
      System.out.println("faltaron interaciones la aproximacion es: "+XnM1);
      System.out.println(XnM1);
      return;
    }
}
