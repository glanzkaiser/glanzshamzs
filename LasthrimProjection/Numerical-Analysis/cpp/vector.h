#ifndef VECMAT
#define VECMAT
/*********************/
/* VECMAT.H          */
/*********************/
/*                   */
/* Classes           */
/* vector and matrix */
/*                   */
/*********************/
//#include "standard.h"                         //incomplete declaration
class   matrix;

class vector {                       // declaration of vector
friend matrix;                       // matrix has access to vector
private:
 int size;
 double *vec;
 int range(int);                                // index check
public:
 vector(int);                                   //init to zero elems
 vector(const vector&);                         //init to given vec
 vector(const double*, int);                    //init to given array
 ~vector()                  {delete vec;}
 double& operator[](int i)  {return vec[range(i)];}
 vector& operator+()        {return *this;}             //unary plus
 vector& operator=(const vector&);
 vector& operator+=(const vector&);
 vector& operator-=(const vector&);
 vector& operator*=(double);                            //mult by double
 vector& operator/=(double);                            //div by double
 int getsize()              {return size;}
 void swap(int, int);
 friend vector operator-(const vector&);                //unary minus
 friend vector operator+(const vector&, const vector&);
 friend vector operator-(const vector&, const vector&);
 friend vector operator*(const vector&, double);
 friend vector operator*(double, const vector&);
 friend vector operator/(const vector&, double);
 friend double scalar(const vector&, const vector&);    //scalar product
 friend double norm(const vector&);                     //Euclidean norm
 friend double norminf(const vector&);                  //infinity norm
 friend vector operator*(const matrix&, const vector&); //v = m.u
 friend vector operator*(const vector&, const matrix&); //v = u.m
 friend matrix operator*(const vector&, const vector&); //m = u.v
 friend matrix operator*(const matrix&, const matrix&); //m = m1.m2
 friend double norm(const matrix&)                      //Euclidean norm
 friend double norminf(const matrix&)                   //infinity norm
 friend ostream& operator<<(ostream&, const vector&);
 friend istream& operator>>(istream&, vector&);

//constructors

//creates a vector, elements initialized to zero
vector::vector(int n)
 {
  size = n;
  vec = new double [size];
  if(!vec)
  error("allocation failure in vector::vector(int)!");
  for (int i = 0; i < size; ++i) vec[i] = 0;
 }

//creates a vector, elements initialized to those of given vector
 vector::vector(const vector &v)
 {
  size = v.size;
  vec = new double [size];
  if (!vec)
  error("allocation failure in vector::vector(vector&)!");
  for (int i =  0; i < size; ++i) vec[i] = v.vec[i];
 }

//creates a vector, elements initialized to those of a given array
 vector::vector(const double *a, int n)
 {
  size = n;
  vec = new double [size];
  if (!vec)
  error("allocation failure in vector::(double*, int)!");
  for (int i = 0; i < size; ++i) vec[i] = a[i];
 }

//destructor
 inline vector::~vector() { delete vec; }

//operators and auxiliary functions

//indexing operator
 inline double& vector::operator[](int i)
 { return vec[range(i)]; }

//(private) function range to check index
//error function from standard.h

 inline int vector::range(int i)
 {
  return (i < 0 || i >= size) ? 
         (error("index out of range in vector::operator[]"), -1) : i; 
 }

//unary plus operator
 inline vector& vector::operator+() { return *this; }

//assignment operator =
 vector& vector::operator=(const vector &v)
 {
  if (size != v.size)
  error("different size in vector& vector::=(const vector&)!");
  for (int i = 0; i < size; ++i) vec[i] = v.vec[i];
  return *this;
 }

//assignment operator +=
 vector& vector::operator+=(const vector &v)
 {
  if (size != v.size)
  error("different size in vector& vector::+=(const vector&)!");
  for (int i = 0; i < size; ++i) vec[i] += v.vec[i];
  return *this;
 }

//assignment operator -=
 vector& vector::operator-=(const vector &v)
 {
  if (size != v.size)
  error("different size in vector& vector::-=(const vector&)!");
  for (int i = 0; i < size; ++i) vec[i] -= v.vec[i];
  return *this;
 }

//assignment operator *=
//multiply a vector by a double
 vector& vector::operator*=(double x)
 {
  for (int i = 0; i < size; ++i)
      vec[i] *= x;
  return *this;
 }

//assignment operator /=
//divide a vector by a double
//error trapping for division by zero dealt with externally
 vector& vector::operator/=(double x)
 {
  for (int i = 0; i < size; ++i)
      vec[i] /= x;
  return *this;
 }

//access size of a vector directly
 inline int vector::getsize() { return size; }

//interchange two elements of a vector
//external range checking unnecessary
 void vector::swap(int i, int j)
 {
  double tmp = vec[range(i)];
  vec[i] = vec[range(j)];
  vec[j] = tmp;
 }

//unary minus
 vector operator-(const vector &v)
 {
  int n = v.size;
  vector u(n);
  for (int i = 0; i < n; ++i)
      u.vec[i] = -v.vec[i];
  return u;
 }

//arithmetic operators

//plus operator
 vector operator+(const vector &v1, const vector &v2)
 {
  int n = v1.size;
  if (v1.size != v2.size) error("different sizes in"
     " vector op+(const vector &v1, const vector &v2)");
  vector v(n);
  for (int i = 0; i < n; ++i)
       v.vec[i] = v1.vec[i] + v2.vec[i];
  return v;
 }

//minus operator
 vector operator-(const vector &v1, const vector &v2)
 {
  int n = v1.size;
  if (v1.size != v2.size) error("different sizes in"
      " vector op-(const vector&, const vector&)");
  vector v(n);
  for (int i = 0; i < n; ++i)
       v.vec[i] = v1.vec[i] - v2.vec[i];
  return v;
 }

//post-multiplicaiton
 vector operator*(const vector &v, double d)
 {
  vector vd = v;
  vd *= d;
  return vd;
 }

//pre-multiplication
 inline vector operator*(double d, vector &v) { return v * d; }

//division operator
 vector operator/(const vector &v, double d)
 {
  vector vd = v;
  vd /= d;
  return vd;
 }

//scalar product of two vectors
 double scalar(const vector &u, const vector &v)
 {
  double t = 0;
  int n = u.size;
  if (u.size != v.size) error("different sizes in"
     " scalar(const vector &u, const vector &v)");
  for (int i = 0; i < n; ++i)
      t += u.vec[i]*v.vec[i];
  return t;
 }

//Euclidean norm of a vector
//action taken to avoid dividing by values near zero
 double norm(const vector &v)
 {
  int n = v.size;
  const double eps = 1.0E-15;  //small number
  double t = fabs(v[0]);
  for (int i = 1; i < n; ++i)
  {
   double vi = fabs(v[i]);
   if (t < eps) t = vi;
   else
   {
    double x = vi/t;
    t *= sqrt(1 + x*x);
   }
  }
  return t;
 }

//Infinity norm
//magnitude of the element of greatest absolute value in a vector
 double norminf(const vector &v)
 {
  int n = v.size;
  double t = 0.0;
  for (int i = 0; i < n; ++i)
  {
   double vi = fabs(v.vec[i]);
   if (vi > t) t = vi;
  }
  return t;
 } 

const long vml = ios::left + ios::fixed;
const int vmp = 4;
const int vmw = 10;

format vmfmt (vml, vmp, vmw), vmrst(0, 0, 0);

//input operator
//formatted using format.h
 ostream& operator<<(ostream &s, const vector &v)
 {
  int n = v.size;
  for (int i = 0; i < n; ++i)
      s << vmfmt << v.vec[i];
  s << vmrst << "\n";
  return s;
 }

//output operator
//formatted using format.h

 istream& operator>>(istream &s, vector &v)
 {
  int n = v.size;
  cout << "enter " << n << " elements:\n";
  for (int i = 0; i < n; ++i)
    {  cout << "[" << i << "] = ";
       s >> v.vec[i];
    }
    return s;
 }

};

