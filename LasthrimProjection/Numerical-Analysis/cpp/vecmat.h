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



class matrix {                   // declaration of matrix
private:
 int numrows;
 int numcols;
 vector **mat;
 int range(int);                                    //row index check
public:
 matrix(int, int);                                  //rectangular matrix
 matrix(int);                                       //square matrix
 matrix(const matrix&);                             //unit to given matrix
 ~matrix();
 vector& operator[](int i) {return *mat[range(i)];}
 matrix& operator+() {return *this;}                 //unary plus
 matrix& operator=(const matrix&);
 matrix& operator+=(const matrix&);
 matrix& operator-=(const matrix&);
 matrix& operator*=(double);
 matrix& operator/=(double);
 int getnumrows() {return numrows;}
 int getnumcols() {return numcols;}
 int getsize();                                      //square matrix only!
 void swap(int, int);                                  
 matrix transpose();                                 //transpose matrix
 friend matrix operator-(const matrix&);             //unary minus
 friend matrix operator+(const matrix&, const matrix&);
 friend matrix operator-(const matrix&, const matrix&);
 friend matrix operator*(const matrix&, const matrix&); //m = m1.m2
 friend matrix operator*(const matrix&, double);        //m = m1.d
 friend matrix operator*(double, const matrix&);        //m = d.m1
 friend matrix operator/(const matrix&, double);        //m = m1/d
 friend vector operator*(const matrix&, const vector&); //v = m.u
 friend vector operator*(const vector&, const matrix&); //v = u.m
 friend matrix operator*(const vector&, const vector&); //m = u.v
 friend double norm(const matrix&);                  //Euclidean norm
 friend double norminf(const matrix&);               //infinity norm
 friend ostream& operator<<(ostream&; const matrix&);
 friend istream& operator>>(istream&; matrix&);

// constructors

// constructors for rectangular matrix
 matrix::matrix(int nrows, int ncols)
 {
  numrows = nrows; numcols = ncols;
  mat = new vector* [numrows];
  if (!mat) error("row allocation failure"
                  " in matrix::matrix(int, int)");
  for (int i = 0; i < numrows; ++i)
  {
   mat[i] = new vector(numcols);
   if (!mat[i]) error("column allocation failure"
                      " in matrix::matrix(int, int)");
  }
 } 

//constructor for a square matrix
 matrix::matrix(int n)
 {
  numrows =  numcols = n;
  mat = new vector* [numrows];
  if (!mat) error("row allocation failure"
                  " in matrix::matrix(int, int)");
  for (int i = 0; i < numrows; ++i)
  {
   mat[i] = new vector(numcols);
   if (!mat[i]) error("column allocation failure"
                      " in matrix::matrix(int, int)");
  }
 } 

//copy of matrix
 matrix::matrix(const matrix &m)
 {
  numrows = m.numrows; numcols = m.numcols;
  mat = new vector* [numrows];
  if (!mat) error("row allocation failure"
                  " in matrix::matrix(matrix&)");
  for (int i = 0; i < numcols; ++i)
  {
   mat[i] = new vector(numcols);
   if (!mat[i]) error("column allocation failure"
                      " in matrix::matrix(matrix&)");
  }
  for (i = 0; i < numrows: ++ii) *mat[i] = *m.mat[i];
 }

//matrix destructor
 matrix::~matrix()
 {
  for (int i = numrows; i > 0; --i)
      delete mat[i-1];
  delete mat;
 }

//matrix indexing operator
 inline vector& matrix::operator[](int i)
 {
  return *mat[range(i)];
 }

//matrix range function
 int matrix::range(int i)
 {
  return (i<0 || i>=numrows) ? 
         (error("matrix row index out of range!"), -1) : i; 
 }

//matrix assignment operator =
 matrix& matrix::operator=(const matrix &m)
 {
  if (m.numrows != numrows || m.numcols != numcols)
   error("different sizes in"
         " matrix& matrix::op=(const matrix&, const matrix&)!");
  for (int i = 0; i < numrows; ++i)
      *mat[i] = *m.mat[i];
  return *this;
 }

//matrix assignment operator +=
 matrix& matrix::operator+=(const matrix &m)
 {
  if (m.numrows != numrows || m.numcols != numcols)
   error("different sizes in"
         " matrix& matrix::op+=(const matrix&, const matrix&)!");
  for (int i = 0; i < numrows; ++i)
      *mat[i] += *m.mat[i];
  return *this;
 }

//matrix assignment operator -=
 matrix& matrix::operator-=(const matrix &m)
 {
  if (m.numrows != numrows || m.numcols != numcols)
   error("different sizes in"
         " matrix& matrix::op-=(const matrix&, const matrix&)!");
  for (int i = 0; i < numrows; ++i)
      *mat[i] -= *m.mat[i];
  return *this;
 }

//matrix assignment operator *=
 matrix& matrix::operator*=(const matrix &m)
 {
  if (m.numrows != numrows || m.numcols != numcols)
   error("different sizes in"
         " matrix& matrix::op*=(const matrix&, const matrix&)!");
  for (int i = 0; i < numrows; ++i)
      *mat[i] *= *m.mat[i];
  return *this;
 }

//matrix assignment operator /=
 matrix& matrix::operator/=(const matrix &m)
 {
  if (m.numrows != numrows || m.numcols != numcols)
   error("different sizes in"
         " matrix& matrix::op/=(const matrix&, const matrix&)!");
  for (int i = 0; i < numrows; ++i)
      *mat[i] /= *m.mat[i];
  return *this;
 }

//to access data memembers numrows and numcols
 inline int matrix::getnumrows() { return numrows; }
 inline int matrix::getnumcols() { return numcols; }

//to access numcols/numcols for square matrix
 int matrix::getsize()
 {
  if (numrows != numcols)
    error("getsize() requires square matrix");
  return numrows;
 }

//interchange two row vectors
//interchange pointers to the row vectors concerned
 void matrix::swap(int i, int j)
 { 
  vector *tmp = mat[range(i)];
  mat[i] = mat[range(j)];
  mat[j] = tmp;
 }

//transpose a matrix
 matrix matrix::transpose()
 {
  int  p = numrows; q = numcols;
  matrix mt(q, p);  //create transpose matrix
  for (int i = 0; i< q; ++i)
  {
   for (int j = 0; j < p; ++j)
       mt.mat[i]->vec[j] = mat[j]->vec[i];
  } 

//unary plus operator ??????
 inline matrix& matrix::operator+() { return *this; }

//unary minus ????????
 matrix operator-(const matrix &m)
 {
  int n = m.size;
  vector m(n);
  for (int i = 0; i < n; ++i)
      m.mat[i] = -m.mat[i];
  return m;
 }

//binary addition
 matrix operator+(const matrix &m1, const matrix &m2)
 {
  if (m1.numrows != m2.numrows || m1.numcols != m2.numcols)
    error("different sizes in matrix op+(const matrix&, const matrix&)!");
  matrix mt = m1;
  mt += m2;
  return mt;
 }

//subtraction operator
 matrix operator-(const matrix &m1, const matrix &m2)
 {
  if (m1.numrows != m2.numrows || m1.numcols != m2.numcols)
    error("different sizes in matrix op+(const matrix&, const matrix&)!");
  matrix mt = m1;
  mt -= m2;
  return mt;
 }

//multiplicaiton operator by a floating point number ?????
// use assignment operators already defined
//extremely simple

//division operator by a floating point number ????????
// use assignment operators already defined
//extremely simple

//Euclidean Norm
 double norm(matrix &m)
 {
  double t = 0;
  int nr = m.numrows, nc = m.numcols;
  for (int i = 0; i < nr; ++i)
  {
   for (int j = 0; j < nc; ++j)
   {
    double mij = m[i][j];
    t += mij * mij;
   }
  }
  return sqrt(t);
 }

//Infinity Norm
 double norminf(matrix &m)
 {
  double t = 0;
  int nr = m.numrows, nc = m.numcols;
  for (int i = 0; i < nr; ++i)
  {
   double s = 0;
   for (int j = 0; j < nc; ++j)
       s += fabs(m.mat->vec[j]);
   if (s > t) t = s;
  }
  return t;
 }

//output operator
 ostream& operator<<(ostream &s, const matrix &m)
 {
  int nr = m.numrows;
  for (int i = 0; i < nr; ++i)
      s << *m.mat[i];
  return s;
 }

//input operator
 istream operator>>(istream &s, matrix &m)
 {
  int nr = m.numrows;
  cout << "\nEnter " << nr << "row vectors\n\n";
  for (int i = 0; i < nr; ++i)
  {
   cout << "Enter row vector " << i << "\n";
   s >> *m.mat[i];
  }
 return s;
 }

// inline functions

 inline int vector::range(int i)
 { 
  if(i<0 || i>=size) error("vector index out of range!");
  return i;
 }

 inline int matrix::range(int i)
 {
  if(i<0 || i>=numrows) error("matrix row index out of range!");
  return i;
 }

 inline vector operator*(double d, const vector &v)
 { 
  return v*d;
 }

 inline matrix operator*(double d, const matrix &m)
 {
  return m*d;
 }

//operations in linear algebra

//returns a (column) vector obtained 
//by multiplying a (column) vector by a matrix
vector operator*(const matrix &m, const vector &v)
{ 
 int nr = m.numrows;
 if (m.numcols != v.size)
 error("different sizes in vector op*(const matrix&, const vector&)!");
 vector u(nr);
 for (int i = 0; i < nr; ++i)
     u[i] = scalar(*m.mat[i], v);
 return u;
} 

//transpose of above
//multiples a row vector by a matrix to obtain a row vector
vector operator*(const vector &v, const matrix &m)
{ 
 int nr = m.numrows, nc = m.numcols;
 if (v.size != nr)
 error("different sizes in vector op*(const vector&, const matrix&)!");
 vector u(nc);
 for (int i = 0; i < nc; ++i)
 {
  double t = 0;
  for (int j = 0; j < nr; ++j)
      t += v.vec[j] * m.mat[j]->vec[i];
  u.vec[i] = t;
 }
 return u;
}

//multiples a column vector by a row vector to produce a matrix
matrix operator*(const vector &u, const vector &v)
{
 int nr = u.size, nc = v.size;
 matrix m(nr, nc);
 for (int i = 0; i < nr; ++i)
 { 
  for (int j = 0; j < nr; ++j)  
  m.mat[i][j] = u[i] * v[j];
 }
 return m;
}

};
 
#endif   //VECMAT
