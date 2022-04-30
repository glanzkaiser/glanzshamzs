import inputs;
import matriz;

public class regresionP
{
 static int num,grado;	//numero de puntos a introducir y grado del Pol.
 static matriz puntos=new matriz();
 static matriz coef=new matriz();
 
 public static double calculaCoef(int i,int j)
 {
   double suma=0.0,multi=1.0;
   for(int k=0;k<num;k++)	//Este for suma el total de puntos
   {
     for(int l=0;l<j+i;l++)	//Este for eleva a la potencia cada x
       multi*=puntos.arreglo[k][0];
     suma+=multi;
     multi=1.0; 
   }
   return suma;   
 }
 
 public static double calculaRes(int i)
 {
   double suma=0.0,multi=1.0;
   for(int k=0;k<num;k++)
   {
     multi=1.0;
     for(int l=0;l<i;l++)	//for para las x's
       {
        multi*=puntos.arreglo[k][0];
       }
     suma+=multi*puntos.arreglo[k][1];
   }
   return suma;
 }
 
 public static void main(String[] args)
   {
    System.out.println("Escribe el numero de datos a introducir");    
    num=inputs.readInt();
    System.out.println("Escribe el grado del polinomio al que deseas aproximar");
    grado=inputs.readInt();
    matriz res=new matriz(grado+1,1);
    puntos=new matriz(num,2);
    matriz polinomio=new matriz();
    coef=new matriz(grado+1,grado+1);
    puntos.leeM("Introduce el dato(x,y) numero:");
    for(int i=0;i<=grado;i++)
      for(int j=0;j<=grado;j++)
          coef.arreglo[i][j]=calculaCoef(i,j);
    for(int i=0;i<=grado;i++)
    	res.arreglo[i][0]=calculaRes(i);
    polinomio=coef.inversa().multi(res);
    System.out.println("Los coeficientes del polinomio");
    polinomio.imprimeM();
   }
}