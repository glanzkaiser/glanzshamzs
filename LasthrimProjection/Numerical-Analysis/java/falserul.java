import inputs;

public class falserule
{
   public static double F(double x)
    {
      return(x*x*x*x+x*x*x-34*x*x-4*x+120);
    }
   public static void main(String args[])
    {
      double Xnm1,Xn,XnM1=0;
      System.out.println("Escribe un numero a");
      Xnm1=inputs.readDob();
      System.out.println("Escribe un numero b");
      Xn=inputs.readDob();
      if (F(Xnm1)*F(Xn)<0)
        {
	 for(int i=0;i<100;i++)
            {	
	     XnM1=Xnm1-((F(Xnm1)*(Xn-Xnm1))/(F(Xn)-F(Xnm1)));
             if(((XnM1-Xn)<0.000001)&&((XnM1-Xn)>-0.000001))
              {
               System.out.println("La Raiz es:"+XnM1);
	       System.out.println("El numero de iteraciones es:"+i);
               return;
              }                            
	     if (F(XnM1)*F(Xn)<0)
	      {
               Xnm1=XnM1;
	      }
             else
	      {
               Xn=XnM1;
	      }
	    }
       System.out.println("faltaron interaciones la aproximacion es: "+XnM1);
           System.out.println(XnM1);
           return;
        }
       else                                          
 	System.out.println("Dar otros numeros");
   }
}
