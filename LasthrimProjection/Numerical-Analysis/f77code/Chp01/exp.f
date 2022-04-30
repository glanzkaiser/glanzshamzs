C
C PAGE 11-12: NUMERICAL MATHEMATICS AND COMPUTING, CHENEY/KINCAID, 1985
C
C FILE: EXP.FOR
C
C FIRST PROGRAMMING EXPERIMENT
C 
      DATA  N/25/, H/1.0/, X/0.5/     
      F = SIN(X)  
      G = COS(X)  
      DO 2 I = 1,N
        H = 0.25*H
        D = SIN(X + H) - F  
        Q = D/H   
        E = ABS(G - Q)      
        PRINT *,H,D,Q,E     
   2  CONTINUE    
      STOP
      END 
