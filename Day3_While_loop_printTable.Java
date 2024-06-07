class Geeks {
    static void printTable (int n) 
    {
           int multiplier=10;
           int a = 1 ;
           while(multiplier>0)
           {
               a = n * multiplier;
               System.out.print(a + " ");
               multiplier--;
           }
           System.out.println();
    }

}