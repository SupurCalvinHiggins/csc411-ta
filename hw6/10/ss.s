.section .text
.globl ms 
.globl ss 

# int ms(const char *s, const char *p);
ms:
  # TODO: return the same as ss.c
  j hang

# char *ss(const char *s, const char *p);
ss:
  # TODO: return the same as ss.c
  j hang

hang:
  j hang
