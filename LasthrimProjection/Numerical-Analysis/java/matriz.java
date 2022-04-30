import inputs;

public class matriz
{
  private 
	 int columna,fila;
    	 double[][] arreglo;

//Hace con la fila i una matriz-vector y regresa esa matriz    
    	 matriz vfila(int i)  //Calcula el vector fila i
     	  {
     	   matriz afila=new matriz(1,columna); //se almacena el vector fila i
     	   for(int j=0;j<columna;j++)
     	    {
     	     afila.arreglo[0][j]=arreglo[i][j];
     	    }
     	   return afila;
     	  }

//Hace con la columna i una matriz-vector y regresa esa matriz   
         matriz vcolumna(int i)  //Calcula el vector columna i
     	  {
     	   matriz acolumna=new matriz(1,fila); //se almacena el vector columna i
     	   for(int j=0;j<fila;j++)
     	    {
     	     acolumna.arreglo[0][j]=arreglo[j][i];
     	    }
     	   return acolumna;
          }

//Hace el producto punto de dos matrices-vectores
	 double propunto(matriz a, matriz b)
	   {
	     double resultado=0;
	     if ((a.columna!=b.columna)||(a.fila!=b.fila)||(a.fila!=1))
	      {
	      	System.out.println("Error pasando vectores de diferente tamanio");
	     	return 0.0;
	      }
	     else
	      {
	        for(int i=0;i<columna;i++)
	          {
	            resultado+=(a.arreglo[0][i])*(b.arreglo[0][i]);
	          }
	        return resultado;
	      }
	   }

//Esta funcion le agrega la matriz identidad a una matriz cuadrada
	    
	 matriz aumentada()
	   {
	      if (columna!=fila)
          	{
            	 System.out.println("Error pasando matrices de diferente tamanio");
  	    	 return null;
  	  	}
  	      else
	   	{
		 matriz b=new matriz(fila,columna*2);
	          for(int i=0;i<fila;i++)
	   	   for(int j=0;j<columna*2;j++)
	   	    {
	   	     if(j<columna)
	   	       b.arreglo[i][j]=arreglo[i][j];
	   	     else
	   	       if(i+columna==j)
	   	         b.arreglo[i][j]=1.0;
	   	       else 
	   	         b.arreglo[i][j]=0.0;
	   	    }
	   	  return b;
                 }	   
	   }

//Esta funcion pega dos matrices y regresa la matriz unida
//Warning debe de: el numero de filas en las dos matrices ser igual
	matriz pegaM(matriz a)
	 {
	  matriz unida=new matriz(fila,columna+a.columna);
	    for(int i=0;i<fila;i++)
	      for(int j=0;j<unida.columna;j++)
	       {
	        if(j<columna)
	          unida.arreglo[i][j]=arreglo[i][j];
	        else
	          unida.arreglo[i][j]=a.arreglo[i][j-columna];
	       }        	  
	  return unida;
	}
	
//Esta funcion regresa una submatriz que va de la columna x a la columna y
//Warning debe de: 0<=x<=y  ; y<=columna  ;Ampliarse al caso de submatriz de n*m
	matriz submatriz(int x,int y)
	  {
	    matriz sub=new matriz(fila,y-x+1);
	    for(int i=0;i<fila;i++)
	      for(int j=x,k=0;j<=y;j++,k++)
	      	sub.arreglo[i][k]=arreglo[i][j];
	     return sub;
	  }	   
	                
//Esta función es llamada por una matriz de [n,2n] y regresa solamente
//una matriz con los elementos dentro de [n,n]         
	matriz separada() 
	  {
	    matriz b=new matriz(fila,columna/2);
	    for(int i=0;i<fila;i++)
	      for(int j=0;j<columna/2;j++)
	           b.arreglo[i][j]=arreglo[i][j+columna/2];
	    return b;
	  }

  public
  
//constructor

	matriz(){}
	 
//constructor que hace una matriz de [a,b] 
       matriz(int a,int b)
        {
         fila=a;
         columna=b;
         arreglo=new double[fila][columna];	
        }

//Iguala la fila i de la matriz a con la fila j de la matriz b
       void igualfila(matriz a,int i,matriz b,int j)
        {
          for(int k=0;k<a.columna;k++)
            a.arreglo[i][k]=b.arreglo[j][k];
        }

//Lee una matriz y despliega antes el mensaje s        
        void leeM(String s)
        {
	  int x,y;
	  for(int i=0;i<fila;i++)
	   {
	     System.out.println(s + (i+1));
	     for(int j=0;j<columna;j++)
	     {    
                arreglo[i][j]=inputs.readDob();
             }
           }
        }
        
//Imprime una matriz
        void imprimeM()
        {
         if(this==null)
           System.out.println("[]");
         else
         {
          System.out.println("");
          for (int i=0;i<fila;i++)
           {
            System.out.print("[");
            for (int j=0;j<columna;j++)
              System.out.print(arreglo[i][j]+"  ");
            System.out.print("]");
            System.out.flush();
            System.out.println("");
           }
	  System.out.println("");
         }
        }

//Pone el valor c en el elemento          
       void intr(int i,int j,double c)
        {
         arreglo[i][j]=c;
        }
	
//Regresa el elemento i,j de una matriz 	
       double retrive(int i,int j)
        {
         return(arreglo[i][j]);
        }

//Regresa el producto de dos matrices		 
       matriz multi(matriz b)
        {
         if (columna!=b.fila)
          {
            System.out.println("Error pasando matrices de diferente tamanio");
  	    return null;
  	  }
  	 else
	   {
	    matriz resp=new matriz(fila,b.columna);
	    for(int j=0;j<b.columna;j++)
	     for(int i=0;i<fila;i++)
	     {    
               resp.arreglo[i][j]=propunto(this.vfila(i),b.vcolumna(j));
             }
	    return resp;
	   }
        }

//multiplica una matriz por un escalar       
       matriz escalar(double x)
        {
          matriz resp=new matriz(fila,columna);
          for(int i=0;i<fila;i++)
	     for(int j=0;j<columna;j++)
	     {
	      resp.arreglo[i][j]=arreglo[i][j]*x;
	     }
	   return resp;    
        }

//Regresa true si la diferencia entre todos los elementos de dos matrices no 
//sobrepasa la tolerancia tol
	boolean igual(matriz x,double tol)
	{
	  if(fila!=x.fila||columna!=x.columna)
	    return false;
	  else
	   {
	    for(int i=0;i<fila;i++)
	     for(int j=0;j<columna;j++)
	       if(Math.abs(x.arreglo[i][j]-arreglo[i][j])>=tol)
	         return false;   
	   }
	  return true;
	}
//Suma dos matrices        
       matriz suma(matriz x)
        {
          matriz resp=new matriz(fila,columna);
          for(int i=0;i<fila;i++)
	     for(int j=0;j<columna;j++)
	     {
	      resp.arreglo[i][j]=arreglo[i][j]+x.arreglo[i][j];
	     }
	   return resp;    
        }

//Regresa el numero de filas de la matriz que la llama        
       int f()
       {return fila;}
       
//Regresa el numero de columnas de la matriz que la llama
       int c()
       {return columna;} 

//Regresa la matriz inversa de la matriz que lo llama
    matriz inversa()
     {
       matriz inv=new matriz();
       	  inv=this.aumentada();
          for(int ciclo=0;ciclo<inv.f();ciclo++)
	    {
	      inv.igualfila(inv,ciclo,inv.vfila(ciclo).escalar(1/inv.retrive(ciclo,ciclo)),0);
	      for(int j=ciclo+1;j<inv.f();j++)
	         inv.igualfila(inv,j,inv.vfila(j).suma(inv.vfila(ciclo).escalar(-inv.retrive(j,ciclo))),0);
              for(int j=0;j<ciclo;j++)
                 inv.igualfila(inv,j,inv.vfila(j).suma(inv.vfila(ciclo).escalar(-inv.retrive(j,ciclo))),0);
	    }
       inv=inv.separada();
       return inv;
     }

//Regresa la transpuesta de una matriz     
    matriz trans()
    {
      matriz trans=new matriz(columna,fila);
      for(int i=0;i<columna;i++)
      	for(int j=0;j<fila;j++)
      	  trans.arreglo[i][j]=arreglo[j][i];
      return trans;
    }
}
