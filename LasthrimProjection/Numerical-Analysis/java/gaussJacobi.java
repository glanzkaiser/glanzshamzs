import matriz;
import inputs;

public class gaussJacob 
{ 
  public static void main(String args[]) 
    {
      int inc;
      System.out.println("Cuantas incognitas son?");
      inc=inputs.readInt();
      matriz A=new matriz(inc,inc); 
      matriz XnM1=new matriz(inc,1);
      matriz Xn=new matriz(inc,1);
      matriz D=new matriz(inc,inc);
      matriz DInv=new matriz(inc,inc); 
      matriz L=new matriz(inc,inc); 
      matriz U=new matriz(inc,inc);
      matriz LmasU=new matriz(inc,inc);
      matriz B=new matriz(inc,1);
      A.leeM("Introduce el coeficiente de la fila:");
      B.leeM("Da el resultado de la ecuación ");
      Xn.leeM("Primera aproximación para la variable x");
      D=A.escalar(0);			   //Pone en la matriz D solo ceros
      //Este for pone en la diagonal mayor de D los elementos de la diagonal mayor de A
      for(int i=0,j=0;i<inc;i++,j=i)  
         D.arreglo[i][j]=A.arreglo[i][j];
      U=A;
      U=U.escalar(-1);
      for (int i=0;i<inc;i++)
        for(int j=0;j<=i;j++)
          U.arreglo[i][j]=0.0;
      L=A;
      L=A.escalar(-1);
      for (int i=0;i<inc;i++)
        for(int j=i;j<inc;j++)
          L.arreglo[i][j]=0.0;
      DInv=D.inversa();
      LmasU=L.suma(U);
      inc=0;
      for(int i=0;i<300;i++)
        {
         XnM1=DInv.multi(LmasU.multi(Xn)).suma(DInv.multi(B));
         if(Xn.igual(XnM1,.000000001))break;
         Xn=XnM1;
         inc++;
        }
      XnM1.imprimeM();
      if(inc==300) System.out.println("No fueron suficientes las iteraciones");
      System.out.println("iteraciones: "+ inc);    
    }
}
