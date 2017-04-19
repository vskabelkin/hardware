int main()
{
  //Enable port E clocking
  *(unsigned long*)(0x4002104C) |= 0x10;
   
  //little delay for GPIOE get ready
  volatile unsigned long i=0;
  i++; i++; i++; i=0;

  //Set PE8 as General purpose output 
  *(unsigned long*)(0x48001000) = (*(unsigned long*)(0x48001000)& (~0x00030000)) | (0x00010000);
  
  while(1)
  {
    //Turn LED ON
    *(unsigned long*)(0x48001014) |= 0x00000100;
    //Delay
    for( i=0; i<1000000 ;++i );
    //Turn LED OFF
    *(unsigned long*)(0x48001014) &= ~0x00000100;
    //Delay
    for( i=0; i<1000000 ;++i );
  }
}
