ENTRY(_start)
PHDRS {
    text PT_LOAD;
    rodata PT_LOAD;
    data PT_LOAD;
    bootloader PT_LOAD;
}

MEMORY {
  /* mrom : ORIGIN = 0x20000000, LENGTH = 4K */
  flash : ORIGIN = 0x30000000, LENGTH = 16M
  psram : ORIGIN = 0x80000000, LENGTH = 4M
  sram : ORIGIN = 0x0f000000, LENGTH = 8K
  sdram : ORIGIN = 0xa0000000, LENGTH = 32M
}

REGION_ALIAS("REGION_TEXT", sdram);
REGION_ALIAS("REGION_RODATA", sdram);
REGION_ALIAS("REGION_DATA", sdram);
REGION_ALIAS("REGION_BSS", sdram);
REGION_ALIAS("REGION_BOOTLOADER", flash);

SECTIONS {
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  /* . = _pmem_start + _entry_offset; */
  . = ORIGIN(flash);
  _start_addr = .;
  

.bootloader : {
    _bootloader_start = .;
    *(entry)  
    *(.bootloader.text*)
    . = ALIGN(4);
    _bootloader_end = .;
  } > REGION_BOOTLOADER : bootloader
  ebootloader = .;
  _ebootloader = .;

  .text : { 
    _text_start = .; 
    *(.text*)
    . = ALIGN(4);
  } > REGION_TEXT AT> flash : text 
  _text_load_start = LOADADDR(.text);
  etext = .;
  _etext = .;
  _text_size = SIZEOF(.text);
  

  .rodata : {
    _rodata_start = .;
    *(.rodata*)
    *(.srodata*)
    . = ALIGN(4);
  } > REGION_RODATA AT> flash : rodata 
  _rodata_load_start = LOADADDR(.rodata);
  _rodata_size = SIZEOF(.rodata);

  .data : {
    _data_start = .;
    *(.data*)
    *(.sdata*)
    
     /* section information for finsh shell */
    __fsymtab_start = .;
    KEEP(*(FSymTab))
    __fsymtab_end = .;
    . = ALIGN(8);
    __vsymtab_start = .;
    KEEP(*(VSymTab))
    __vsymtab_end = .;
    . = ALIGN(8);

    /* section information for initial. */
    . = ALIGN(8);
    __rt_init_start = .;
    KEEP(*(SORT(.rti_fn*)))
    __rt_init_end = .;
    . = ALIGN(8);

    __rt_utest_tc_tab_start = .;
    KEEP(*(UtestTcTab))
    __rt_utest_tc_tab_end = .;

    . = ALIGN(8);
    __am_apps_data_start = .;
    *(__am_apps.data*)
    *(__am_apps.sdata*)
    __am_apps_data_end = .;
    . = ALIGN(8);

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
    . = ALIGN(8);
    __am_apps_bss_start = .;
    *(__am_apps.bss*)
    *(__am_apps.sbss*)
    *(__am_apps.scommon*)
    __am_apps_bss_end = .;
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

  . = 0x0f000000;
  . = . + 0x2000; /* 根据需要调整大小 */
  _stack_top = .;
  _stack_pointer = _stack_top;
  end = .;
  _end = .;


  
}
