import java.awt.*;
import java.utils.*;

public class Viewer extends Canvas
{
   protected Vector cuerpos;
   protected vector pos;
   protected vector width;
   
   public Viewer(Vector c, vector a, vector b)
   { cuerpos = c; pos = a; width = b; }
   
   public void paint(Graphic g)
   {
     
     for (int j=0; j<height; j++)
     {
       double x = x0;
       for (int i=0; i<width; i++)
       {
          vector ef = new vector(0,0);
          for (Enumeration e = cuerpos.elements(); e.hasMoreElements(); )
            ef = ef.add(((CuerpoCargado)e.nextElement()).CargaEn(new vector(x,y)));

          double dir = Math.atan2(ef.elems[1], ef.elems[0])/(2*Math.PI);
          double mag = ef.abs();
 
          Color.getHSBColor((float)dir,           
          x += dx;
       }
       y += dy;
     }
   }
   
}			