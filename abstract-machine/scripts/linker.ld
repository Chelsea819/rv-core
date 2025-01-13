ENTRY(_start)
PHDRS { text PT_LOAD; data PT_LOAD; }

MEMORY {
  /* mrom : ORIGIN = 0x20000000, LENGTH = 4K */
  flash : ORIGIN = 0x30000000, LENGTH = 16M
  psram : ORIGIN = 0x80000000, LENGTH = 4M
}

REGION_ALIAS("REGION_TEXT", flash);
REGION_ALIAS("REGION_RODATA", flash);
REGION_ALIAS("REGION_DATA", psram);
REGION_ALIAS("REGION_BSS", psram);

SECTIONS {
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  /* . = _pmem_start + _entry_offset; */
  . = ORIGIN(flash);
  .text : { 
    *(entry)
    *(.text*)
    . = ALIGN(4);
  } > REGION_TEXT : text 
  
  etext = .;
  _etext = .;
  

  .rodata : {
    *(.rodata*)
    *(.srodata*)
    rodata_end = .;
    . = ALIGN(4);
  } > REGION_RODATA : text 

  .data : {
    _data_start = .;
    *(.data*)
    *(.sdata*)
    _data_end = .;
    . = ALIGN(4);
  } > REGION_DATA AT> flash : data 
  _data_load_start = LOADADDR(.data);
  edata = .;
  _data = .;
  _data_size = SIZEOF(.data);


  /* .bss : {
    _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    _bss_end = .;
  } > REGION_BSS : data  */
  .bss : {
    _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    . = ALIGN(4);
    _bss_end = .;
  } > REGION_BSS

  /*
    2M = 2^20 * 2 = 16^5 * 2 = 0x200000
  */
  . = ALIGN(4);
  _heap_start = .;
  . =  . + 0x200000;
  _heap_end = .;
  
  . = ALIGN(4);
  . = . + 0x200000; /* 根据需要调整大小 */
  _stack_top = .;
  _stack_pointer = _stack_top;
  end = .;
  _end = .;
}
