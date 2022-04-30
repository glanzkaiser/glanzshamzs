import inputs;

public class simpson
{
   public static double f(double x)
    { double denom,numerator;
      double e = 2.718281828;
      numerator = Math.cos(2*x);
      denom = Math.pow(e,x);
      x = numerator / denom;
      return x;
    } 

//**********************************************************************************
public static double simpsonf(double a,double b,double epsi,int level,int level_max)
    { level = level + 1;
      double h = b-a;
      double c = (a + b)/2;
      double simp_result;

      double one_simpson = (h * (f(a) + 4 * f(c) + f(b))) / 6;
   
      double d = (a + c)/2;
      double e = (c + b)/2;
     
double two_simpson = (h * (f(a) + 4 * f(d) + 2 * f(c) + 4 * f(e) + f(b))) / 12;
      
     if (level > level_max)
       {  simp_result = two_simpson;
          System.out.println("Error occurred!!");
       }
     else if ((Math.abs(two_simpson-one_simpson)) < (15 * epsi))
         {   simp_result = two_simpson;
             System.out.println("simpson result = "+simp_result + " at level:"+level);
         }
       else 
           { double left_simp = simpsonf(a,c,epsi/2,level,level_max);
             double right_simp = simpsonf(c,b,epsi/2,level,level_max);
             simp_result = left_simp + right_simp;
             System.out.println("simpson result = "+simp_result + " at level:"+level);
           }
      return simp_result;
    }

//**********************************************************************************  
 public static void main(String args[])  
    {
      double a,b,c,e,h,simp_result,one_simpson,two_simpson;
      double left_simp,right_simp;
      double epsi = 0.5 * (Math.pow(10,-4));
      double pi = 3.14159;
      int level_max;
      int level = 0;
      //double simp_result=0;

      System.out.println("Enter the number of intervals: ");
      level_max=inputs.readInt();
      System.out.println("Enter the lower limit a:");
      a=inputs.readDob();
      System.out.println("Enter the upper limit b: ");
      b=inputs.readDob();
      
      simpsonf(a,b,epsi,level,level_max);
    }
}
