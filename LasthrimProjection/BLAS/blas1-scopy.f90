program copy_main
  real x(100), y(100)
  integer n, incx, incy, i
  n = 5
  incx = 1
  incy = 1
	do i = 1, 100
	  x(i) = i
	end do
  print*, 'X = ', (x(i), i = 1, n)
  call scopy (n, x, incx, y, incy)
  print*, 'Y = ', (y(i), i = 1, n)
end
