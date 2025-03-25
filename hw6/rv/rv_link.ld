ENTRY(_start)

SECTIONS
{
  . = 0x400000;

  . = ALIGN(4);
  .text : {
    *(.text)
  }
  . = ALIGN(4);

  . = ALIGN(4);
  __rodata_start = .;
  .rodata : { 
    *(.rodata) 
  }
  . = ALIGN(4);
  __rodata_end = .;

  . = DATA_SEGMENT_ALIGN (CONSTANT (MAXPAGESIZE), CONSTANT (COMMONPAGESIZE));

  . = ALIGN(4);
  __data_start = .;
  .data : { 
    *(.data) 
  }
  . = ALIGN(4);
  __data_end = .;

  . = ALIGN(4);
  __bss_start = .;
  .bss : { 
    *(.bss) 
  }
  . = ALIGN(4);
  __bss_end = .;

  . = DATA_SEGMENT_END (.);
  
  . = ALIGN(16);
}
