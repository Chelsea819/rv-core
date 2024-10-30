ENTRY(_start)
PHDRS { text PT_LOAD; data PT_LOAD; }

MEMORY {
  mrom : ORIGIN = 0x20000000, LENGTH = 4K
  sram : ORIGIN = 0x0f000000, LENGTH = 8K
  flash : ORIGIN = 0x30000000, LENGTH = 16M
}

REGION_ALIAS("REGION_TEXT", flash);
REGION_ALIAS("REGION_RODATA", flash);
REGION_ALIAS("REGION_DATA", sram);
REGION_ALIAS("REGION_BSS", sram);

SECTIONS {
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  /* . = _pmem_start + _entry_offset; */
  . = ORIGIN(flash);
  .text : { 
    *(entry)
    *(.text*)
  } > REGION_TEXT : text 
  etext = .;
  _etext = .;

  .rodata : {
    *(.rodata*)
    rodata_end = .;
  } > REGION_RODATA 

  .data : {
    _data_start = .;
    *(.data*)
  } > REGION_DATA AT> flash : data 
  _data_load_start = LOADADDR(.data);
  edata = .;
  _data = .;
  _data_size = SIZEOF(.data);

  .bss : {
    _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  } > REGION_BSS AT> flash

  _heap_start = 0x0f000000;
  . = _heap_start + 0x10;

  _stack_top = ALIGN(0x1000);
  . = _heap_start + 0x2000;
  _stack_pointer = .;
  end = .;
  _end = .;
}
