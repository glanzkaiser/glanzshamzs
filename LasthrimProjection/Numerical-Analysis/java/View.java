import java.awt.*;
import java.util.*;

public class View extends Canvas
{  
   protected final static double k = 1;
   
   protected Vector cuerpos;
   protected vector campo;
   protected double x0,x1,yo,y1;
   
   View(Vector a,xi,yi,xf,yf)
   { 
     cuerpos=a;
     x0=xi;
     y0=yi;
     x1=xf;
     y1=yf;
   }

   Color calcCol(float r, float a)
   {
     if (r < k)
       return Color.getHSBColor(a/(2*Math.PI), 1.0f, r/k);
     else
       return Color.getHSBColor(a/(2*Math.PI), Math.sqrt(k/r), 1.0f);
   }
   
   public void transfx(int x)
   { 
     Rectangle r=bounds();
     return (x+r.width/2);
   }
   
   public void transfy(int y)
   { 
     Rectangle r=bounds();
     return (r.heigth/2-y);
   }
   
   public void paint(Graphics g)
   {
     Rectangle r = bounds();
     int xp,yp;
     double direccion;
     campo=new vector(0,0)
     for(int x=0;x<r.width;x++)
       for(int y=0;y<r.height;y++)
       {
         for(int i=0;i<cuerpos.size();i++)
         {
           campo=campo.add(campo,cuerpos.elementAt(i).campoEn(new vector(x,y)));
         }
         direccion=Math.atan(campo.e[1]/campo.e[0]);
         if(direccion<0)
           direccion+=2*Math.PI;
         g.setColor(calcCol(campo.abs(),direccion))
         xp=transfx(x);
         xp=transfy(y);
         g.drawLine(xp,yp,xp,yp);
       } 
   }   
}
