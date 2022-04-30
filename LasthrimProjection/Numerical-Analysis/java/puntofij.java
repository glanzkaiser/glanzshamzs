import inputs;

public class puntofijo
{
   public static double F(double x)    //esta es la transformacion
    {					//la ec. es x^2-2x-3
      return(3/(x+2));
    }
   public static void main(String args[])
    {
      double Xn,XnM1=0;
      System.out.println("Escribe un numero a");
      Xn=inputs.readDob();
      Xn=Integer.parseInt(SXn); 
         for(int i=0;i<100;i++)
            {
             XnM1=F(Xn);
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

