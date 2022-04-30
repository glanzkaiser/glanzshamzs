public class Sifter
{
  static int[] original={1,2,3,4,5,6,7,8,9,10};
  public static void main(String arg[])
  {
      int[] odds=new int[10];
      int[] evens=new int[10];
      int nextodd=0;
      int nextevens=0;
      for(int i=0; i<10;i++)
      {
    if (original[i]%2==1)
    {
    odds[nextodd]=original[i];
    System.out.println(odds[nextodd]);
    nextodd++;
    }
  else
  {
    evens[nextevens]=original[i];
    System.out.println(evens[nextevens]); 
    nextevens++;}
    //  System.out.println(evens[nexteven]);
    //  System.out.println(odds[nextodd]);
  }
 }
}