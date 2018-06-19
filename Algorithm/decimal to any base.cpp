int decimal_base(int num,int base)
{
   int r = 0,power = 1;
   while(num>0)
   { 
       r += (num%base)*power;
       power *= 10;
       num /=base;
   }
    return r;
}