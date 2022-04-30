state Jacobi(matrix &M, vector &x, vector &b)
{
  state sta = ITERATING;
  int iter = 0, n = m.getsize();
  while {sta == ITERATING)
    {
      vector x_old = x;
      for (int i=0; i<n; ++i)
	{
	  double b_i = b[i], M_ii = M[i][i];
	  if ( fabs(M_ii) < toosmall )
	    return NEARSINGULAR;
	  for (int j = 0; j<n; ++j)
	  {
	    if ( j != i )
	      b_i -= M{i][j]*x_old[j];
          }
	  x[i] = b_i/M_ii;
	}
      if (norm_inf(x - x_old) < tolerance)
	sta = SUCCESS;
      if ( ++iter == iter_max )
	sta = MAXITERATIONS
	  // put running output here
     }
      return sta;
}
