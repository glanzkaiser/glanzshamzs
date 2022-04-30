// vector.java 1.0
// (C) 1997 Alejandro Vázquez C.
// All rights reserved.

public class vector
{
  public double e[];

  public vector(int n)
  { e = new double[n]; }

  public vector(double x, double y)
  {
    e = new double[2];
    e[0] = x;
    e[1] = y;
  }

  public vector(double x, double y, double z)
  { 
    e = new double[3];
    e[0] = x;
    e[1] = y;
    e[2] = z;
  }

  public vector(double x, double y, double z, double t)
  { 
    e = new double[4];
    e[0] = x;
    e[1] = y;
    e[2] = z;
    e[3] = t;
  }

  public static vector rect(double x, double y)
  { return new vector(x, y); }

  public static vector rect(double x, double y, double z)
  { return new vector(x, y, z); }

  public static vector rect(double x, double y, double z, double t)
  { return new vector(x, y, z, t); }

  public static vector polar(double r, double a)
  { return new vector(r*Math.cos(a), r*Math.sin(a)); }

  public static vector polar(double r, double a1, double a2)
  { return new vector(r*Math.cos(a1)*Math.sin(a2),
                      r*Math.sin(a1)*Math.sin(a2),
                      r*Math.cos(a2)); }

  public static vector cylin(double r, double a, double z)
  { return new vector(r*Math.cos(a), r*Math.sin(a), z); }

  public static final vector i = rect(1,0,0);
  public static final vector j = rect(0,1,0);
  public static final vector k = rect(0,0,1);

  public static vector add(vector a, vector b)
    throws ArithmeticException
  {
    if (a.e.length != b.e.length)
      throw new ArithmeticException("vectors of inequal size");

    int length = a.e.length;
    vector c = new vector(length);
    for (int i=0; i<length; i++)
      c.e[i] = a.e[i] + b.e[i];
    return c;
  }

  public vector add(vector a)
  { return add(this, a); }

  public static vector sub(vector a, vector b)
    throws ArithmeticException
  {
    if (a.e.length != b.e.length)
      throw new ArithmeticException("vectors of inequal size");

    int length = a.e.length;
    vector c = new vector(length);
    for (int i=0; i<length; i++)
      c.e[i] = a.e[i] - b.e[i];
    return c;
  }

  public vector sub(vector a)
  { return sub(this, a); }

  public static vector mult(vector a, double b)
  {
    int length = a.e.length;
    vector c = new vector(length);
    for (int i=0; i<length; i++)
      c.e[i] = a.e[i] * b;
    return c;
  }

  public static vector mult(double b, vector a)
  { return mult(a,b); }

  public vector mult(double a)
  { return mult(this, a); }

  public static vector div(vector a, double b)
  {
    int length = a.e.length;
    vector c = new vector(length);
    for (int i=0; i<length; i++)
      c.e[i] = a.e[i]/b;
    return c;
  }

  public vector div(double a)
  { return div(this, a); }

  public static double dot(vector a, vector b)
    throws ArithmeticException
  {
    if (a.e.length != b.e.length)
      throw new ArithmeticException("vectors of inequal size");

    int length = a.e.length;
    double c = 0;
    for (int i=0; i<length; i++)
      c += a.e[i] * b.e[i];
    return c;
  }
    
  public double dot(vector b)
  { return dot(this, b); }

  public static vector cross(vector a, vector b)
    throws ArithmeticException
  {
    if ((a.e.length!=3) || (b.e.length!=3))
      throw new ArithmeticException("Can't cross multiply non-3d vectors");

    return new vector(a.e[1]*b.e[2] - b.e[1]*a.e[2],
                      a.e[2]*b.e[0] - b.e[2]*a.e[0],
                      a.e[0]*b.e[1] - b.e[1]*a.e[0]);
  }

  public vector cross(vector b)
  { return cross(this, b); }

  public static double abs(vector b)
  {
    double d = 0;
    for (int i=0; i<b.e.length; i++)
      d += b.e[i]*b.e[i];
    return Math.sqrt(d);
  }

  public double abs()
  { return abs(this); }

  public static vector uni(vector a)
  { return div(a, abs(a)); }
  
  public vector uni()
  { return uni(this); }

  public static vector homog(vector a, double w)
  {
    int len = a.e.length;
    vector b = new vector(len+1);
    
    for (int i=0; i<len; i++)
      b.e[i] = a.e[i]*w;

    b.e[len] = w;
    return b;
  }

  public vector homog(double w)
  { return homog(this, w); }

  public static vector norm(vector a)
  {
    int len = a.e.length - 1;
    double w = a.e[len];
    vector b = new vector(len);

    for (int i=0; i<len; i++)
      b.e[i] = a.e[i]/w;
    return b;
  }

  public vector norm()
  { return norm(this); }  
}
