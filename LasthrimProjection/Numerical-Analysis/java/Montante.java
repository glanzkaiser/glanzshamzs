import matriz;
import inputs;

public class Montante 
{ 
  static double divisor=1.0;
  public static double deter(matriz a,int k,int i, int j)
  {
    double numero;
    numero=(a.arreglo[k][k]*a.arreglo[i][j]-a.arreglo[i][k]*a.arreglo[k][j])/divisor;
    return numero; 
  }
  
//Warning si cualquier elemento de [i][i]
//es igual a cer entonces el metodo no funciona
  public static void main(String args[]) 
  {
    int inc,col;
    System.out.println("Cuantas incognitas son?");
    inc=inputs.readInt();
    col=inc*2+1;
    matriz Aumentada=new matriz(inc,col);
    matriz coef=new matriz(inc,inc);
    matriz resultados=new matriz(inc,1);
    matriz neutra=new matriz(inc,inc);
    matriz inversa=new matriz(inc,inc);
    neutra=neutra.escalar(0);
    for(int i=0;i<inc;i++)
      neutra.arreglo[i][i]=1; 
    coef.leeM("Introduce el coeficiente de la fila:");
    resultados.leeM("Da los resultados de la ecuacion:");
    Aumentada=coef.pegaM(resultados).pegaM(neutra);
    Aumentada.imprimeM();
    //System.out.println(Aumentada.f()+" "+Aumentada.c());
    for(int k=0;k<inc;k++)
      {
	//System.out.println("k"+k);
	for(int i=0;i<inc;i++)
	  {
	    //System.out.println("i"+i);
	    for(int j=0;j<col;j++)
	      {
		// System.out.println("j"+j);
		if(i!=k&&j!=k)
		  Aumentada.arreglo[i][j]=deter(Aumentada,k,i,j);
	      }
	  }
	for(int l=0;l<inc;l++)
	  if(l!=k)
	    Aumentada.arreglo[l][k]=0;
	divisor=Aumentada.arreglo[k][k];
      }
    Aumentada.imprimeM();
    Aumentada=Aumentada.escalar(1/Aumentada.arreglo[0][0]);
    Aumentada.imprimeM();
  }
}
