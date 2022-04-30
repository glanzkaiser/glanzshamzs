import inputs;
import matrix;

public class gauss
{ public static void main(String[] args)
   { int inc,n,i,j,k,y;
     double tempfor=0.0;
     double sum,xmult;

     System.out.println("Enter the number of iterations");
     inc=inputs.readInt();
   //System.out.print("It will be an " + inc + "x" + inc + " matrix");
   //System.out.println(" so input 1 coeffiecient followed by a return");
     matrix A=new matrix(inc,inc);
     n=inc;

     double[] b = new double[inc];
     double[] x = new double[inc];
    
     for(y=4;y<=inc-1;y++)
     { for(i=1;i<=n-1;i++)
        { for(j=1;j<=n-1;j++)
             A.coeff[i][j]=Math.pow(i+1,j-1);
          b[i]=((Math.pow(i+1,n-1))-1)/i;
        }
       for(k=1;k<=n-1;k++)
        {  for(i=k+1;i<=n-1;i++)
           { xmult = A.coeff[i][k] / A.coeff[k][k];
             A.coeff[i][k] = xmult;
             for(j=k+1;j<=n-1;j++)
               A.coeff[i][j]=A.coeff[i][j] - xmult * A.coeff[k][j];
             b[i] = b[i] - xmult * b[k];
            }
        }
        x[n-1]=b[n-1] / A.coeff[n-1][n-1];
        for(i=n-1;i>=1;i--)
        { sum = b[i];
          for(j=i+1;j<=n-1;j++)
            sum = sum - A.coeff[i][j] * x[j];
          x[i] = sum / A.coeff[i][i];
        }
       System.out.println("******************************");
       System.out.println("iterations n = "+y);
       System.out.println("value x["+y+"] = "+x[y]);
     }
   }
}
