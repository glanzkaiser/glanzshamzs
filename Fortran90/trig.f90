program trig

      implicit none

      real angrad, angdeg, pi, sinang, cosang
      print *, 'Angle in Degrees?'
      read *, angdeg
 
          pi=asin(1.0)*2.0
        
          angrad=angdeg*pi/180.0
     
      sinang=sin(angrad)
    
      cosang=cos(angrad)

      print *, 'ANGLE =',angdeg,' degrees =',angrad,' radians'
      print *, 'SIN(ANGLE) = ', sinang
      print *, 'COS(ANGLE) = ', cosang

      stop
      end
