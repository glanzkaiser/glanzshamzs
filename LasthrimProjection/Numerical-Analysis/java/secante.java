import java.io.*;
public class secante
{
   static DataInputStream n;
   public static double F(double x)
    {
      return(x*x*x*x+x*x*x-34*x*x-4*x+120);
    }
   public static void main(String args[]) throws IOException
    {
      double Xnm1,Xn,XnM1=0;
      n=new DataInputStream(System.in);
      String SXn,SXnm1;
      System.out.println("Escribe un entero a");
      SXnm1=n.readLine();
      System.out.println("Escribe un entero b"); 
      SXn=n.readLine();
      Xnm1=Integer.parseInt(SXnm1);
      Xn=Integer.parseInt(SXn);
      for(int i=0;i<120;i++)
        {
          XnM1=Xn-(F(Xn)*(Xn-Xnm1))/(F(Xn)-F(Xnm1));
          if(((XnM1-Xn)<0.000001) && ((XnM1-Xn)>-0.000001))
            {
             System.out.println("La Raiz es:"+XnM1);
             System.out.println("El numero de iteraciones es:"+i);
             return;
            }                            
          Xn=XnM1;
        }
      System.out.println("faltaron interaciones la aproximacion es: "+XnM1);
      return;
    }
}



























































