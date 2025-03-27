int ms(const char *s, const char *p) {
  if (*p == 0)
    return 1;
  if (*s == 0 || *s != *p)
    return 0;
  return ms(s + 1, p + 1);
}

char *ss(const char *s, const char *p) {
  if (ms(s, p))
    return s;
  if (*s == 0)
    return 0;
  return ss(s + 1, p);
}
