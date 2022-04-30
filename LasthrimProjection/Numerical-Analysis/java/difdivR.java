import inputs;
public class difdivR		//tres maneras pensadas
{ 
  static int num;      //Este es el numero de nodos que voy a introducir  
  static double[][] coef;		//tabla de datos
  
  private static double F(int x,int y)  //calcula los valores de la tabla
   {
    if(x==y)
   	return(coef[x][1]);
    else
   	return((F(x+1,y)-F(x,y-1))/(coef[y][0]-coef[x][0]));	    
   }
  
  private static double product(int j,double x)  
   {		//Regresa el valor de los terminos pora mult. los coef.
     double multi=1;
     for(int i=0;i<j;i++)	
     	    multi*=((x-coef[i][0]));	  
     return(multi);
   }
  
  public static double poli(double x)	//esta funcion calcula la 
   {					//interpolacion segun el polinomio		
    double suma=0;
    for(int j=0;j<num;j++)
	suma+=(F(0,j)*product(j,x))  ;
    return (suma);
   }
   
  public static void leetablar()
   {
    for(int i=num-1;i>=0;i--)                //en este ciclo se introducen
      {                                         //los datos
        System.out.println("Introduce el dato(x,y) numero:"+(num-i));
        coef[i][0]=inputs.readDob();           //se introducen las "x"
        coef[i][1]=inputs.readDob();           //se introducen las "y" o f(x)
      }
  }
    
  public static void main(String args[])  
  {					//numero de muestras
    double intra,resultado;		//numero que se desea intrapolar
    System.out.println("Escribe el numero de datos a introducir");
    num=inputs.readInt();
    coef=new double[num][2];		//tabla de datos
    leetablar();
    System.out.println("Introduce el numero a intrapolar");	
    intra=inputs.readDob();
    if(intra>coef[0][0]||intra<coef[num-1][0])
      System.out.println("CUIDADO, CON EL COLERA ESTAS EXTRAPOLANDO");
    resultado=poli(intra);
    System.out.println("El valor encontrado es: "+resultado);
  }
}