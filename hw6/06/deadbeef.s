.section .text
.globl deadbeef 

# int deadbeef();
deadbeef:
  # TODO: return the same as deadbeef.c
hang:
  j hang
