// these are necessary so this program can find
// the Applet stuff and Graphics stuff
import java.applet.Applet;
import java.awt.Graphics;

public class Simple extends Applet{

  // buffer is a StringBuffer variable (a string that can change)
  StringBuffer buffer;

  // Applet provides the methods init(), start(), stop() and destroy()
  // but I want to change what they do.

  public void init(){
    // buffer needs to be initialized with a constructor
    buffer = new StringBuffer(); // now we can use it
    addItem("initializing... ");  // we let addItem do the work
  }

  public void start(){
    // add some stuff to the buffer, again use addItem
    addItem("starting.... ");
  }

  public void stop(){
    // add some stuff to the buffer, again use addItem
    addItem("stopping.... ");
  }

  public void destroy(){
    // add some stuff to the buffer, again use addItem
    addItem("destroying.... ");
  }

  public void repaint(){
    
  }

  // helper program to do less work
  public void addItem(String s){
    System.out.println(s);
    buffer.append(s);
    repaint();
  }

  // overriding paint defined in java.awt.Component
  public void paint(Graphics g) {
    // Draw a Rectangle around the applet's display area.
    g.drawRect(0, 0, size().width - 1, size().height - 1);

    // Draw the current string inside the rectangle.
    g.drawString(buffer.toString(), 5, 15);
  }
}