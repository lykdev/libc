#ifndef _STDIO_H
#define _STDIO_H 1

#include <stdarg.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct
{
    int _fd;
}
FILE;

extern FILE *stdin;
extern FILE *stdout;

int fprintf(FILE *stream, const char *format, ...);
int fscanf(FILE *stream, const char *format, ...);
int printf(const char *format, ...);
int scanf(const char *format, ...);
int snprintf(char *s, size_t size, const char *format, ...);
int sprintf(char *s, const char *format, ...);
int sscanf(const char *s, const char *format, ...);
int vfprintf(FILE *stream, const char *format, va_list args);
int vfscanf(FILE *stream, const char *format, va_list args);
int vprintf(const char *format, va_list args);
int vscanf(const char *format, va_list args);
int vsnprintf(char *s, size_t size, const char *format, va_list args);
int vsprintf(char *s, const char *format, va_list args);
int vsscanf(const char *s, const char *format, va_list args);

int fgetc(FILE *stream);
char *fgets(char *s, int count, FILE *stream);
int fputc(int c, FILE *stream);
int fputs(const char *s, FILE *stream);
int getc(FILE *stream);
int getchar(void);
char *gets(char *s);
int putc(int c, FILE *stream);
int putchar(int c);
int puts(const char *s);
int ungetc(int c, FILE *stream);

#ifdef __cplusplus
};
#endif

#endif /* _STDIO_H */