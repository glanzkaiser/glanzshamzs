import inputs;
public class newtonrM
{
   public static double F(double x)  //Funcion que se quiere encontrar raices
    {
      return(x*x*x*x+x*x*x-34*x*x-4*x+120);
    }
    public static double f(double x)  //derivada de la funcion
    {
      return(4*x*x*x+3*x*x-68*x-4);
    }
   public static void main(String args[])
    {
      double Xn,XnM1=0,X0;
      System.out.println("Escribe un numero a");   //primera aproximacion
      Xn=inputs.readDob();
      X0=Xn;         // X0 por si f(Xn) es igual a cero entonces tomar f(X0)
      if(f(Xn)==0)       //la derivada del valor introducido es igual a cero
       {
        System.out.println("Introduce otro numero");
	return;
       } 
      else
        {	 
         for(int i=0;i<100;i++)       //ciclo de evaluaciones
           {	
	    if(f(Xn)!=0)             //si la derivada es diferente de cero
	     {	
              XnM1=Xn-(F(Xn)/f(Xn));
              if(((XnM1-Xn)<0.0000001)&&((XnM1-Xn)>-0.0000001))  //tolerancia
                {
                 System.out.println("La Raiz es:"+XnM1);       //Raiz
                 System.out.println("El numero de iteraciones es:"+i);
                 return; 
	        };
	       Xn=XnM1;//no ha llegado a la raiz por lo que cambia Xn por XnM1
	      }
	     else    //si la derivada de f(x) es cero entonces tomar f(x0)
	      {
		Xn=X0;
		i--;
	      } 	
            }            
       System.out.println("faltaron interaciones la aproximacion es: "+XnM1);
       System.out.println(XnM1);
       return;
      }	
    }
}


