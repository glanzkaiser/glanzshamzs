import inputs;

public class mincua
{
  static int num;      //Este es el numero de nodos que voy a introducir  
  static double[][] datos;		//tabla de datos
  
  public static void leetablar()
   {
    for(int i=num-1;i>=0;i--)                //en este ciclo se introducen
      {                                         //los datos
        System.out.println("Introduce el dato(x,y) numero:"+(num-i));
        datos[i][0]=inputs.readDob();           //se introducen las "x"
        datos[i][1]=inputs.readDob();           //se introducen las "y" o f(x)
      }
  }

  private static double deter()
  {
   double suma=0.0,temp1=0.0;
   for(int i=0;i<num;i++)
    suma+=(datos[i][0])*(datos[i][0]);
   suma=num*suma;
   for(int i=0;i<num;i++)
    temp1+=datos[i][0];
   temp1*=temp1;
   suma-=temp1;
   return suma;
  }

  public static double calca()
  {
   double a=0.0,tempx=0.0,tempy=0.0;
   for(int i=0;i<num;i++)
     a+=datos[i][0]*datos[i][1];
   a=a*num;
   for(int i=0;i<num;i++)
     tempx+=datos[i][0];
   for(int i=0;i<num;i++)
     tempy+=datos[i][1];
     a=(a-(tempx*tempy))/deter();
   return a;
  }

  public static double calcb()
  {
   double b=0.0,xcuad=0.0,tempy=0.0,tempx=0.0;
   for(int i=0;i<num;i++)      //x al 2
    xcuad+=(datos[i][0])*(datos[i][0]);
   for(int i=0;i<num;i++)       //suma y
     tempy+=datos[i][1];
   b=xcuad*tempy;               // x2*y
   tempy=0.0;
   for(int i=0;i<num;i++)       //x*y
     tempy+=datos[i][0]*datos[i][1];
   for(int i=0;i<num;i++)       //suma x
    tempx+=datos[i][0];
   b=(b-(tempx*tempy))/deter();
   return b;
  }

  public static void errores()
  {
   double a,b,error=0.0;
   a=calca();
   b=calcb();
   for (int i=0;i<num;i++)
   {
    error+=(datos[i][1]-((a*datos[i][0])+b))*(datos[i][1]-((a*datos[i][0])+b));
    System.out.println("error "+ (i+1) + "igual a" + error);
   }
  }
 
 public static void main(String[] args)
   {
    double intra,resultado;		//numero que se desea intrapolar
    System.out.println("Escribe el numero de datos a introducir");
    num=inputs.readInt();
    datos=new double[num][2];            //tabla de datos
    leetablar();
    System.out.println("a es igual: " + calca());
    System.out.println("b es igual: " + calcb());
    System.out.println("los errores son: ");
     errores();
   }
}


