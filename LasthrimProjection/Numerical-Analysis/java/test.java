import java.io.*;
import inputs;

public class test
{
  public static void main(String[] args) throws IOException
    {
	double x;
	int y;
	float z;
	String S;
	System.out.println("Introduce un Doble");
	x=inputs.readDob();
	System.out.println("Introduce un entero");
	y=inputs.readInt();
	System.out.println("Introduce un Flotante");
	z=inputs.readFlo();
	System.out.println("Introduce un String");
	S=inputs.readStr();
	System.out.println("El String que introduciste es: "+S);
	System.out.println("El Entero multiplicado por 3 es: "+(y*3));
	System.out.println("El flotante multiplicado por 3 es: "+(z*3));
	System.out.println("El doble multiplicado por 3 es: "+(x*3));
    }
}



















































































































