ENTRY(_start)

SECTIONS
{
  . = 0x400000;

  . = ALIGN(CONSTANT(MAXPAGESIZE));
  .text : {
    *(.text)
  }

  . = ALIGN(CONSTANT(MAXPAGESIZE));
  __rodata_start = .;
  .rodata : { 
    *(.rodata) 
  }
  __rodata_end = .;

  . = ALIGN(CONSTANT(MAXPAGESIZE));
  __data_start = .;
  .data : { 
    *(.data) 
  }
  __data_end = .;

  . = ALIGN(4);
  __bss_start = .;
  .bss : { 
    *(.bss) 
  }
  __bss_end = .;
  
  . = ALIGN(16);
}
