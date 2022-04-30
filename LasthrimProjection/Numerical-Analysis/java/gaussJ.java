import inputs;
import matriz;

public class gaussJ
{
   public static void main(String[] args)
    {
    	int num_var;
    	System.out.println("Cuantas variable tienes?");
    	num_var=inputs.readInt();
    	matriz exten=new matriz(num_var,(num_var+1));
    	exten.leeM("Escriba la ecuacion #:  ");
	for(int ciclo=0;ciclo<exten.f();ciclo++)
	{
	   exten.igualfila(exten,ciclo,exten.vfila(ciclo).escalar(1/exten.retrive(ciclo,ciclo)),0);
	   for(int j=ciclo+1;j<exten.f();j++)
	    {  
	     exten.igualfila(exten,j,exten.vfila(j).suma(exten.vfila(ciclo).escalar(-exten.retrive(j,ciclo))),0);
	    }
           for(int j=0;j<ciclo;j++)
           {
            //exten.igualfila(exten,j,exten.vfila(ciclo).suma(exten.vfila(ciclo).escalar)
            exten.igualfila(exten,j,exten.vfila(j).suma(exten.vfila(ciclo).escalar(-exten.retrive(j,ciclo))),0);
           }
	}
        exten.imprimeM();	
    }
}
