import matriz;

public class testmatriz
{
   public static void main(String []args)
   {
     int f1,f2,c1,c2;
     matriz resultado=new matriz();
     System.out.println("Escribe el numero de filas de la matriz q");
     f1=inputs.readInt();
     System.out.println("Escribe el numero de columnas de la matriz q");
     c1=inputs.readInt();
     matriz q=new matriz(f1,c1);
     q.leeM("introduce la fila #:");
     
     System.out.println("Escribe el numero de filas de la matriz r");
     f2=inputs.readInt();
     System.out.println("Escribe el numero de columnas de la matriz r");
     c2=inputs.readInt();
     matriz r=new matriz(f2,c2);
     r.leeM("introduce la fila #:");
     System.out.println("escribe la matriz b");
     matriz b=new matriz(3,1);
     b.leeM("escribe fila:");
     System.out.println("La matriz b");
     System.out.println("La matriz q");
     q.imprimeM();
     System.out.println("La matriz r");
     r.imprimeM();
     resultado=q.inversa().multi(b);
     resultado.imprimeM();
     q.inversa().imprimeM();
/*
     System.out.println("a*b");
     try
     {
     resultado.imprimeM();
     }
     catch (NullPointerException e)
     {
       System.out.println("no se puede multiplicar");
     }
     System.out.println("la transpuesta de a");
     a.trans().imprimeM();
     System.out.println("la matriz a entre dos");
     a.escalar(.5).imprimeM();
     System.out.println("La inversa de a:");
     a.inversa().imprimeM();
     System.out.println("La inversa por a(derecha e izquierda):");
     a.multi(a.inversa()).imprimeM();
     a.inversa().multi(a).imprimeM();
     System.out.println(a.igual(b,.0001));*/
   }
}  

