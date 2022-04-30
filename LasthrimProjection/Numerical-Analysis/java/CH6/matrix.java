import inputs;

public class matrix
{
  private 
	 int column,row;
    	 double[][] coeff;

//with row 'i' a matrix-vector y is made and returns that new matrix
    	 matrix vrow(int i)  //Calculates the row vector i
     	  {
     	   matrix arow=new matrix(1,column);//se almacena el vector row i
     	   for(int j=0;j<column;j++)
     	    {
     	     arow.coeff[0][j]=coeff[i][j];
     	    }
     	   return arow;
     	  }

//with column 'i' a matrix-vector y is made and returns that new matrix
         matrix vcolumn(int i)  //Calculates the vector column i
     	  {
     	   matrix acolumn=new matrix(1,row);//se almacena el vectorcolumn i
     	   for(int j=0;j<row;j++)
     	    {
     	     acolumn.coeff[0][j]=coeff[j][i];
     	    }
     	   return acolumn;
          }

//the point product of 2 matrices-vectors is calculated
	 double pointprod(matrix a, matrix b)
	   {
	     double result=0;
	     if ((a.column!=b.column)||(a.row!=b.row)||(a.row!=1))
	      {
	    System.out.println("Error passing vectors of different size");
	     	return 0.0;
	      }
	     else
	      {
	        for(int i=0;i<column;i++)
	          {
	            result+=(a.coeff[0][i])*(b.coeff[0][i]);
	          }
	        return result;
	      }
	   }

//this function adds to the identified matrix a matrix squared	    
	 matrix augmented()
	   {
	      if (column!=row)
          	{
           System.out.println("Error passsing matrices of different size");
  	    	 return null;
  	  	}
  	      else
	   	{
		 matrix b=new matrix(row,column*2);
	          for(int i=0;i<row;i++)
	   	   for(int j=0;j<column*2;j++)
	   	    {
	   	     if(j<column)
	   	       b.coeff[i][j]=coeff[i][j];
	   	     else
	   	       if(i+column==j)
	   	         b.coeff[i][j]=1.0;
	   	       else 
	   	         b.coeff[i][j]=0.0;
	   	    }
	   	  return b;
                 }	   
	   }

//This fucntion joins 2 matrices and returns the matrix 
//Warning: the number of rows in the 2 matrices need to be equal
	matrix joinMatrix(matrix a)
	 {
	  matrix united=new matrix(row,column+a.column);
	    for(int i=0;i<row;i++)
	      for(int j=0;j<united.column;j++)
	       {
	        if(j<column)
	          united.coeff[i][j]=coeff[i][j];
	        else
	          united.coeff[i][j]=a.coeff[i][j-column];
	       }        	  
	  return united;
	}
	
//This function returns a submatrix going from column x to column y
//Warning: 0<=x<=y  ; y<=column  ;Ampliarse al caso de submatrix de n*m
	matrix submatrix(int x,int y)
	  {
	    matrix sub=new matrix(row,y-x+1);
	    for(int i=0;i<row;i++)
	      for(int j=x,k=0;j<=y;j++,k++)
	      	sub.coeff[i][k]=coeff[i][j];
	     return sub;
	  }	   
	                
//This function is called by a mtrix of [n,2n] and only returns a matrix
//with those elements inside of [n,n]    
	matrix separate() 
	  {
	    matrix b=new matrix(row,column/2);
	    for(int i=0;i<row;i++)
	      for(int j=0;j<column/2;j++)
	           b.coeff[i][j]=coeff[i][j+column/2];
	    return b;
	  }

  public
  
//constructor

	matrix(){}
	 
//constructs a matrix from [a,b]
       matrix(int a,int b)
        {
         row=a;
         column=b;
         coeff=new double[row][column];	
        }

//the row 'i' of a matrix with the row 'j' of the matrix b are equal
       void samerow(matrix a,int i,matrix b,int j)
        {
          for(int k=0;k<a.column;k++)
            a.coeff[i][k]=b.coeff[j][k];
        }

//reads a matrix and displays a message in string s
        void ReadMatrix(String s)
        {
	  int x,y;
	  for(int i=0;i<row;i++)
	   {
	     System.out.println(s + (i+1));
	     for(int j=0;j<column;j++)
	     {    
                coeff[i][j]=inputs.readDob();
             }
           }
        }
        
//prints the matrix
        void printMatrix()
        {
         if(this==null)
           System.out.println("[]");
         else
         {
          System.out.println("");
          for (int i=0;i<row;i++)
           {
            System.out.print("[");
            for (int j=0;j<column;j++)
              System.out.print(coeff[i][j]+"  ");
            System.out.print("]");
            System.out.flush();
            System.out.println("");
           }
	  System.out.println("");
         }
        }

//puts the value 'c' in the elements
       void intr(int i,int j,double c)
        {
         coeff[i][j]=c;
        }
	
//returns the element i,j of a matrix
       double retrieve(int i,int j)
        {
         return(coeff[i][j]);
        }

//returns the product of 2 matrices
       matrix multi(matrix b)
        {
         if (column!=b.row)
          {
          System.out.println("Error passing matrices of different size");
  	    return null;
  	  }
  	 else
	   {
	    matrix resp=new matrix(row,b.column);
	    for(int j=0;j<b.column;j++)
	     for(int i=0;i<row;i++)
	     {    
               resp.coeff[i][j]=pointprod(this.vrow(i),b.vcolumn(j));
             }
	    return resp;
	   }
        }

//multiplies a matrix with a scalar
       matrix scalar(double x)
        {
          matrix resp=new matrix(row,column);
          for(int i=0;i<row;i++)
	     for(int j=0;j<column;j++)
	     {
	      resp.coeff[i][j]=coeff[i][j]*x;
	     }
	   return resp;    
        }

//returns true if the differece between all the elements of 2 matrice dont
//go beyond the tolerance of tol
	boolean similar(matrix x,double tol)
	{
	  if(row!=x.row||column!=x.column)
	    return false;
	  else
	   {
	    for(int i=0;i<row;i++)
	     for(int j=0;j<column;j++)
	       if(Math.abs(x.coeff[i][j]-coeff[i][j])>=tol)
	         return false;   
	   }
	  return true;
	}
//adds 2 matrices
       matrix sum(matrix x)
        {
          matrix resp=new matrix(row,column);
          for(int i=0;i<row;i++)
	     for(int j=0;j<column;j++)
	     {
	      resp.coeff[i][j]=coeff[i][j]+x.coeff[i][j];
	     }
	   return resp;    
        }

//returns the number of rows in a matrix
       int f()
       {return row;}
       
//returns the number of columns of a matrix
       int c()
       {return column;} 

//returns the inverse of a matrix
    matrix inverse()
     {
       matrix inv=new matrix();
       	  inv=this.augmented();
          for(int ciclo=0;ciclo<inv.f();ciclo++)
	    { inv.samerow(inv,ciclo,inv.vrow(ciclo).scalar(1/inv.retrieve(ciclo,ciclo)),0);
	      for(int j=ciclo+1;j<inv.f();j++)
              inv.samerow(inv,j,inv.vrow(j).sum(inv.vrow(ciclo).scalar(-inv.retrieve(j,ciclo))),0);
              for(int j=0;j<ciclo;j++)
              inv.samerow(inv,j,inv.vrow(j).sum(inv.vrow(ciclo).scalar(-inv.retrieve(j,ciclo))),0);
	    }
       inv=inv.separate();
       return inv;
     }

//returns the transposing of a matrix
    matrix trans()
    {
      matrix trans=new matrix(column,row);
      for(int i=0;i<column;i++)
      	for(int j=0;j<row;j++)
      	  trans.coeff[i][j]=coeff[j][i];
      return trans;
    }
}
