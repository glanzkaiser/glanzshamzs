public class Spline
{
  private int n;
  private double[] x;
  private double[] y;
  private double[][] S;

  int size()
  {
	return n;
  }
  Spline()
  {
	n=0;
	x=new double[1];
	y=new double[1];
	S=new double[4][0];
  }

  void AgregarPunto(double px,double py)
  {
	int i;
	n++;
	double[] tempx=new double[n];
	double[] tempy=new double[n];
	if(n==1)
	{
	 tempx[0]=px;
	 tempy[0]=py;
	}
	else
	{
		for(i=0;i<n-1&&px>x[i];i++)
		{
		 tempx[i]=x[i];
		 tempy[i]=y[i];
		}
		if(px==x[i])
		  return;
		tempx[i]=px;
		tempy[i]=py;
		for(i=i+1;i<n;i++)
		{
		 tempx[i]=x[i-1];
		 tempy[i]=y[i-1];
		}
	}
	x=tempx;
	y=tempy;

  }
  void Interpolar()
  {
	double h[]=new double[n];
	double l[]=new double[n];
	double u[]=new double[n];
	double z[]=new double[n];
	double a[]=new double[n];
	S=new double[4][n-1];
	n=n-1;

	int i,j;
	for(i=0;i<=n;i++) S[0][i]=y[i];
	for(i=0;i<=n-1;i++) h[i] = x[i+1] - x[i];
	for(i=1;i<=n-1;i++) a[i] = (3.0/h[i]*(S[0][i+1]-S[0][i])) - (3.0/h[i-1]*(S[0][i]-S[0][i-1]));

	l[0] = 1; u[0] = 0; z[0] = 0;

	for(i=1;i<=n-1;i++){
		l[i] = 2*(x[i+1]-x[i-1]) - h[i-1]*u[i-1];
		u[i] = h[i]/l[i];
		z[i] = (a[i] - h[i-1]*z[i-1])/l[i];
	}

	l[n] = 1; z[n] = 0; S[2][n] = 0;

	for(j=n-1;j>=0;j--){
		S[2][j] = z[j] - u[j]*S[2][j+1];
		S[1][j] = (S[0][j+1]-S[0][j])/h[j] - h[j]*(S[2][j+1]+2.0*S[2][j])/3.0;
		S[3][j] = (S[2][j+1] - S[2][j])/(3.0*h[j]);
		}
  n++;
  }
  double[][] DevolverFuncion(int m)
  {
	 double h=(x[n]-x[0])/m;
	 double[][] xy=new double[m][2];
	 int cont=0;
	 for(int i=0;i<n-1;n++)
		for(double px=x[i];px<x[i+1];px+=h)
		 {
		  xy[cont][0]=px;
		  xy[cont][1]=0;
		  for(int k=0;k<4;k++)
			 xy[cont][1]+=S[i][k]*Math.pow(px-x[i],k);//Esto debe ser equivalente a pow()
		  cont++;
		 }
	 return xy;
  }
}