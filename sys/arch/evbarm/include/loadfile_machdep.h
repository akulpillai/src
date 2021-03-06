
#if defined(__aarch64__)
#define BOOT_ELF64
#else
#define BOOT_ELF32
#endif

#define LOAD_KERNEL	(LOAD_ALL & ~LOAD_TEXTA)
#define COUNT_KERNEL	(COUNT_ALL & ~COUNT_TEXTA)

#if defined(__aarch64__)
#define LOADADDR(a)		((((u_long)(a)) + offset) & 0x3fffffffff)
#else
#define LOADADDR(a)		(((u_long)(a)))
#endif
#define ALIGNENTRY(a)		((u_long)(a))
#define READ(f, b, c)		read((f), (void*)LOADADDR(b), (c))
#define BCOPY(s, d, c)		memmove((void*)LOADADDR(d), (void*)(s), (c))
#define BZERO(d, c)		memset((void*)LOADADDR(d), 0, (c))
#define	WARN(a)			do { \
					(void)printf a; \
					if (errno) \
						(void)printf(": %s\n", \
						             strerror(errno)); \
					else \
						(void)printf("\n"); \
				} while(/* CONSTCOND */0)
#define PROGRESS(a)		(void)printf a
#define ALLOC(a)		alloc(a)
#define DEALLOC(a, b)		dealloc(a, b)
#define OKMAGIC(a)		((a) == ZMAGIC)
