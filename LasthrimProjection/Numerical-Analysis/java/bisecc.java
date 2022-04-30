import inputs;

public class bisecc
{
   public static double F(double x)
    {
      return(x*x-7x+12);
    } 
  public static void main(String args[])  
    {
      double a,b,c=0,d=5.0;
      System.out.println("Escribe un numero a");
      a=inputs.readDob();
      System.out.println("Escribe un numero b");
      b=inputs.readDob();
    
      if (F(a)*F(b)<0)
        {
           for(int i=0;i<100;i++)
	    {
	      c=(a+b)/2;
               if(F(c)<0.0000001&&F(c)>-0.0000001)
                  {
                    System.out.println("La raiz es:"+c);
		    System.out.println("Numero de iteraciones:"+i);
                    return;
                  }
               if (F(a)*F(c)<0)
                 b=c;
               else
	         a=c;
            }
	   System.out.print("faltaron iteraciones la aproximacion es: "+c);
	   return;	
        }        
       else
     System.out.println("Dar otros numeros");
   }
}

















