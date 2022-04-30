// Como trabajar con objetos.
// Como llamar a los metodos.
// Dia 4.
// Febrero-24-1997.


class TestString {
  public static void main (String args[]) {
    String str = "Now is the winter of our discontent ";
    
    System.out.println("\n\n\tThe string is: " + str);
    // imprime el contenido de la cadena


    System.out.println("\n\tLength of this string: " + str.length());
    // Da el total de caracteres de la cadena
  

    System.out.println("\n\tThe character at position 5: " + str.charAt(5));
    // muestra el caracter en la posicion 5 del arreglo.


    System.out.println("\n\tThe substring from 11 to 17: " + str.substring(11, 17));
    // muestra los caracteres de la posicion 11 a 17 del arreglo.


    System.out.println("\n\tThe index of the character w: " + str.indexOf('w'));
    // muesra en que posicion se encuentra "d" en el arreglo


    System.out.print("\n\tThe index of the beginning of the ");
    // indica en que posicion comineza los caracteres wintwer..

    System.out.println("substring \"winter\": " + str.indexOf("winter"));


    System.out.println("\n\tThe string in upper case: " + str.toUpperCase());
    // convierte los caracteres del arrenglo en mayusculas.

  }
}
