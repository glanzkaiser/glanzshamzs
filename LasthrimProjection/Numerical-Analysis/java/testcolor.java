// Java Abastrac Windowing Toolkit
// Mayo/12/1997
// Pruebas de color.


import java.awt.*;
import java.awt.image.ColorModel;

public class testcolor extends java.applet.Applet {
  ColorControls rgbcontrols, hsbcontrols;
  Canvas swatch;

  public void init() {
    Color theColor = new Color(0, 0, 0);
    float[] hsb = Color.RGBtoHSB(theColor.getRed(), theColor.getGreen(), 			 theColor.getBlue(), (new float[3]));
      
      setLayout(new GridLayout(1, 3, 10, 10));
    
    // The Color swatch.
    swatch = new Canvas();
    swatch.setBackground(theColor);
    
    // the control panels.
    rgbcontrols = new ColorControls(this, "Red", "Green", "Blue",
	    theColor.getRed(), theColor.getGreen(), theColor.getBlue());

    hsbcontrols = new ColorControls(this, "Tinte", "Saturacion", "Brillo",
	    (int)(hsb[0] * 360), (int)(hsb[1] * 100), (int)(hsb[2] * 100));

    add(swatch);
    add(rgbcontrols);
    add(hsbcontrols);

  }

  void update(ColorControls in) {
    Color c;
    String v1 = in.f1.getText();
    String v2 = in.f2.getText();
    String v3 = in.f3.getText();
    
    if (in == rgbcontrols) {   // change to RGB
      c = new Color(Integer.parseInt(v1), Integer.parseInt(v2),
	    Integer.parseInt(v3));
      swatch.setBackground(c);
      float[] HSB = Color.RGBtoHSB(c.getRed(), c.getGreen(), c.getBlue(),(new float[3]));
      HSB[0] *=360;
      HSB[1] *=100;
      HSB[2] *=100;
      hsbcontrols.f1.setText(String.valueOf((int)HSB[0]));
      hsbcontrols.f2.setText(String.valueOf((int)HSB[1]));
      hsbcontrols.f3.setText(String.valueOf((int)HSB[2]));
    }
    else { // change to HSB
      int f1 = Integer.parseInt(v1);
      int f2 = Integer.parseInt(v2);
      int f3 = Integer.parseInt(v3);
      c = Color.getHSBColor((float)f1 / 360, (float)f2 / 100, (float)f3 / 100);
      swatch.setBackground(c);
      rgbcontrols.f1.setText(String.valueOf(c.getRed()));
      rgbcontrols.f2.setText(String.valueOf(c.getGreen()));
      rgbcontrols.f3.setText(String.valueOf(c.getBlue()));
    }
  }
}


class ColorControls extends Panel {
  TextField f1, f2, f3;
  testcolor outerparent;
  
  ColorControls(testcolor target, String l1, String l2, String l3, int v1,
		int v2, int v3) {

    this.outerparent = target;
    setLayout(new GridLayout(3, 4, 10, 10));

    f1 = new TextField(String.valueOf(v1), 10);
    f2 = new TextField(String.valueOf(v2), 10);
    f3 = new TextField(String.valueOf(v3), 10);
    
    add(new Label(l1, Label.RIGHT));
    add(f1);
    add(new Label(l2, Label.RIGHT));
    add(f2);
    add(new Label(l3, Label.RIGHT));
    add(f3);
  }


  public Insets insets() {
    return new Insets(10, 10, 0, 0);
  }


  public boolean action(Event evt, Object arg) {
    if(evt.target instanceof TextField) {
      outerparent.update(this);
      return true;
    }
    else return false;
  }
}

