import matriz;
import inputs;

public class factlu
{ 
  public static void main(String args[]) 
  {
    int inc;
    double tempfor=0.0;
    System.out.println("Cuantas incognitas son?");
    inc=inputs.readInt();
    matriz A=new matriz(inc,inc); 
    matriz L=new matriz(inc,inc); 
    matriz U=new matriz(inc,inc);
    A.leeM("Introduce el coeficiente de la fila:");
    for(int i=0;i<inc;i++)
    {
    	L.arreglo[i][i]=1.0;
    	U.arreglo[i][i]=1.0;
    }
    U.arreglo[0][0]=A.arreglo[0][0];
    if(L.arreglo[0][0]* U.arreglo[0][0]==0)
      {
	System.out.println("No se pude factorizar por LU0");
	return;
      }
    for(int j=1;j<inc;j++)
      {
	U.arreglo[0][j]=A.arreglo[0][j];
	L.arreglo[j][0]=A.arreglo[j][0]/U.arreglo[0][0];
      }
    for(int i=1;i<inc-1;i++)
      {
	tempfor=0.0;
	for(int k=0;k<=i-1;k++)			//modifique k<i-1
	     tempfor+=(L.arreglo[i][k]*U.arreglo[k][i]);//aqui hay problema
	U.arreglo[i][i]=A.arreglo[i][i]-tempfor;
	if(L.arreglo[i][i]*U.arreglo[i][i]==0.0)
	  {
	  System.out.println("no se puedefactorizar por LU1");
	  return;
	  }
	for(int j=i+1;j<inc;j++)   //dudo del 1 
	  {
	  tempfor=0.0;
	  for(int k=0;k<=i-1;k++)
	  	tempfor+=L.arreglo[i][k]*U.arreglo[k][j];	//Dudosa la i
	  U.arreglo[i][j]=(A.arreglo[i][j]-tempfor);
	  tempfor=0.0;
	  for(int k=0;k<=i-1;k++)
	  	tempfor+=L.arreglo[j][k]*U.arreglo[k][i];
	  L.arreglo[j][i]=(1/U.arreglo[i][i])*(A.arreglo[j][i]-tempfor);
	  }
      }
     tempfor=0.0;
     for(int k=0;k<inc-1;k++)
     	tempfor+=L.arreglo[inc-1][k]*U.arreglo[k][inc-1];
     L.arreglo[inc-1][inc-1]=1.0;
     U.arreglo[inc-1][inc-1]=A.arreglo[inc-1][inc-1]-tempfor;
     if(U.arreglo[inc-1][inc-1]*A.arreglo[inc-1][inc-1]==0.0)
	  System.out.println("A es singular");
     System.out.println("La matriz introducida");
     A.imprimeM();
     System.out.println("La matriz L");
     L.imprimeM();
     System.out.println("La matriz U");
     U.imprimeM();
     System.out.println("La matriz L*U");
     L.multi(U).imprimeM();
  }
}