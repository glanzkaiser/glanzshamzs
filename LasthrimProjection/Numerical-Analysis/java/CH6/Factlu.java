import matrix;
import inputs;

public class Factlu
{ 
  public static void main(String args[]) 
  {
    int inc;
    double tempfor=0.0;
    System.out.println("How many rows N in your matrix are there?");
    inc=inputs.readInt();
    System.out.print("It will be an " + inc + "x" + inc + " matrix");
    System.out.println(" so input 1 coeffiecient followed by a return ");
    matrix A=new matrix(inc,inc); 
    matrix L=new matrix(inc,inc); 
    matrix U=new matrix(inc,inc);
    A.ReadMatrix("Input the coefficients of row #:");
    for(int i=0;i<inc;i++)
    {
    	L.coeff[i][i]=1.0;
    	U.coeff[i][i]=1.0;
    }
    U.coeff[0][0]=A.coeff[0][0];
    if(L.coeff[0][0]* U.coeff[0][0]==0)
      {
	System.out.println("Can not factorize by LU0");
	return;
      }
    for(int j=1;j<inc;j++)
      {
	U.coeff[0][j]=A.coeff[0][j];
	L.coeff[j][0]=A.coeff[j][0]/U.coeff[0][0];
      }
    for(int i=1;i<inc-1;i++)
      {
	tempfor=0.0;
	for(int k=0;k<=i-1;k++)			//modified k<i-1
	     tempfor+=(L.coeff[i][k]*U.coeff[k][i]);// problems
	U.coeff[i][i]=A.coeff[i][i]-tempfor;
	if(L.coeff[i][i]*U.coeff[i][i]==0.0)
	  {
	  System.out.println("Can not factorize by LU1");
	  return;
	  }
	for(int j=i+1;j<inc;j++)   //dudo del 1 
	  {
	  tempfor=0.0;
	  for(int k=0;k<=i-1;k++)
	  	tempfor+=L.coeff[i][k]*U.coeff[k][j];	//Doubt  i
	  U.coeff[i][j]=(A.coeff[i][j]-tempfor);
	  tempfor=0.0;
	  for(int k=0;k<=i-1;k++)
	  	tempfor+=L.coeff[j][k]*U.coeff[k][i];
	  L.coeff[j][i]=(1/U.coeff[i][i])*(A.coeff[j][i]-tempfor);
	  }
      }
     tempfor=0.0;
     for(int k=0;k<inc-1;k++)
     	tempfor+=L.coeff[inc-1][k]*U.coeff[k][inc-1];
     L.coeff[inc-1][inc-1]=1.0;
     U.coeff[inc-1][inc-1]=A.coeff[inc-1][inc-1]-tempfor;
     if(U.coeff[inc-1][inc-1]*A.coeff[inc-1][inc-1]==0.0)
	  System.out.println("A is singular");
     System.out.println("The Matrix introduced");
     A.printMatrix();
     System.out.println("Matrix L");
     L.printMatrix();
     System.out.println("Matrix U");
     U.printMatrix();
     System.out.println("Matrix L*U");
     L.multi(U).printMatrix();
  }
}
