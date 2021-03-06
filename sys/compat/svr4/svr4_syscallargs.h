/* $NetBSD: svr4_syscallargs.h,v 1.90 2018/08/10 21:47:16 pgoyette Exp $ */

/*
 * System call argument lists.
 *
 * DO NOT EDIT-- this file is automatically generated.
 * created from	NetBSD: syscalls.master,v 1.62 2013/11/07 19:37:19 njoly Exp
 */

#ifndef _SVR4_SYS_SYSCALLARGS_H_
#define	_SVR4_SYS_SYSCALLARGS_H_

/* Forward declaration */
struct lwp;

#define	SVR4_SYS_MAXSYSARGS	8

#undef	syscallarg
#define	syscallarg(x)							\
	union {								\
		register_t pad;						\
		struct { x datum; } le;					\
		struct { /* LINTED zero array dimension */		\
			int8_t pad[  /* CONSTCOND */			\
				(sizeof (register_t) < sizeof (x))	\
				? 0					\
				: sizeof (register_t) - sizeof (x)];	\
			x datum;					\
		} be;							\
	}

#undef check_syscall_args
#define check_syscall_args(call) /*LINTED*/ \
	typedef char call##_check_args[sizeof (struct call##_args) \
		<= SVR4_SYS_MAXSYSARGS * sizeof (register_t) ? 1 : -1];

struct sys_exit_args;

struct sys_read_args;

struct sys_write_args;

struct svr4_sys_open_args {
	syscallarg(const char *) path;
	syscallarg(int) flags;
	syscallarg(int) mode;
};
check_syscall_args(svr4_sys_open)

struct sys_close_args;

struct svr4_sys_wait_args {
	syscallarg(int *) status;
};
check_syscall_args(svr4_sys_wait)

struct svr4_sys_creat_args {
	syscallarg(const char *) path;
	syscallarg(int) mode;
};
check_syscall_args(svr4_sys_creat)

struct sys_link_args;

struct sys_unlink_args;

struct svr4_sys_execv_args {
	syscallarg(const char *) path;
	syscallarg(char **) argp;
};
check_syscall_args(svr4_sys_execv)

struct sys_chdir_args;

struct svr4_sys_time_args {
	syscallarg(svr4_time_t *) t;
};
check_syscall_args(svr4_sys_time)

struct svr4_sys_mknod_args {
	syscallarg(const char *) path;
	syscallarg(int) mode;
	syscallarg(int) dev;
};
check_syscall_args(svr4_sys_mknod)

struct sys_chmod_args;

struct sys___posix_chown_args;

struct svr4_sys_break_args {
	syscallarg(void *) nsize;
};
check_syscall_args(svr4_sys_break)

struct svr4_sys_stat_args {
	syscallarg(const char *) path;
	syscallarg(struct svr4_stat *) ub;
};
check_syscall_args(svr4_sys_stat)

struct compat_43_sys_lseek_args;

struct sys_setuid_args;

struct svr4_sys_alarm_args {
	syscallarg(unsigned) sec;
};
check_syscall_args(svr4_sys_alarm)

struct svr4_sys_fstat_args {
	syscallarg(int) fd;
	syscallarg(struct svr4_stat *) sb;
};
check_syscall_args(svr4_sys_fstat)

struct svr4_sys_utime_args {
	syscallarg(const char *) path;
	syscallarg(struct svr4_utimbuf *) ubuf;
};
check_syscall_args(svr4_sys_utime)

struct svr4_sys_access_args {
	syscallarg(const char *) path;
	syscallarg(int) flags;
};
check_syscall_args(svr4_sys_access)

struct svr4_sys_nice_args {
	syscallarg(int) prio;
};
check_syscall_args(svr4_sys_nice)

struct svr4_sys_kill_args {
	syscallarg(int) pid;
	syscallarg(int) signum;
};
check_syscall_args(svr4_sys_kill)

struct svr4_sys_pgrpsys_args {
	syscallarg(int) cmd;
	syscallarg(int) pid;
	syscallarg(int) pgid;
};
check_syscall_args(svr4_sys_pgrpsys)

struct sys_dup_args;

struct svr4_sys_times_args {
	syscallarg(struct tms *) tp;
};
check_syscall_args(svr4_sys_times)

struct sys_setgid_args;

struct svr4_sys_signal_args {
	syscallarg(int) signum;
	syscallarg(svr4_sig_t) handler;
};
check_syscall_args(svr4_sys_signal)
#ifdef SYSVMSG

struct svr4_sys_msgsys_args {
	syscallarg(int) what;
	syscallarg(int) a2;
	syscallarg(int) a3;
	syscallarg(int) a4;
	syscallarg(int) a5;
};
check_syscall_args(svr4_sys_msgsys)
#else
#endif

struct svr4_sys_sysarch_args {
	syscallarg(int) op;
	syscallarg(void *) a1;
};
check_syscall_args(svr4_sys_sysarch)
#ifdef SYSVSHM

struct svr4_sys_shmsys_args {
	syscallarg(int) what;
	syscallarg(int) a2;
	syscallarg(int) a3;
	syscallarg(int) a4;
};
check_syscall_args(svr4_sys_shmsys)
#else
#endif
#ifdef SYSVSEM

struct svr4_sys_semsys_args {
	syscallarg(int) what;
	syscallarg(int) a2;
	syscallarg(int) a3;
	syscallarg(int) a4;
	syscallarg(int) a5;
};
check_syscall_args(svr4_sys_semsys)
#else
#endif

struct svr4_sys_ioctl_args {
	syscallarg(int) fd;
	syscallarg(u_long) com;
	syscallarg(void *) data;
};
check_syscall_args(svr4_sys_ioctl)

struct svr4_sys_utssys_args {
	syscallarg(void *) a1;
	syscallarg(void *) a2;
	syscallarg(int) sel;
	syscallarg(void *) a3;
};
check_syscall_args(svr4_sys_utssys)

struct sys_fsync_args;

struct svr4_sys_execve_args {
	syscallarg(const char *) path;
	syscallarg(char **) argp;
	syscallarg(char **) envp;
};
check_syscall_args(svr4_sys_execve)

struct sys_umask_args;

struct sys_chroot_args;

struct svr4_sys_fcntl_args {
	syscallarg(int) fd;
	syscallarg(int) cmd;
	syscallarg(char *) arg;
};
check_syscall_args(svr4_sys_fcntl)

struct svr4_sys_ulimit_args {
	syscallarg(int) cmd;
	syscallarg(long) newlimit;
};
check_syscall_args(svr4_sys_ulimit)

struct sys_rmdir_args;

struct sys_mkdir_args;

struct svr4_sys_getdents_args {
	syscallarg(int) fd;
	syscallarg(char *) buf;
	syscallarg(int) nbytes;
};
check_syscall_args(svr4_sys_getdents)

struct svr4_sys_getmsg_args {
	syscallarg(int) fd;
	syscallarg(struct svr4_strbuf *) ctl;
	syscallarg(struct svr4_strbuf *) dat;
	syscallarg(int *) flags;
};
check_syscall_args(svr4_sys_getmsg)

struct svr4_sys_putmsg_args {
	syscallarg(int) fd;
	syscallarg(struct svr4_strbuf *) ctl;
	syscallarg(struct svr4_strbuf *) dat;
	syscallarg(int) flags;
};
check_syscall_args(svr4_sys_putmsg)

struct sys_poll_args;

struct svr4_sys_lstat_args {
	syscallarg(const char *) path;
	syscallarg(struct svr4_stat *) ub;
};
check_syscall_args(svr4_sys_lstat)

struct sys_symlink_args;

struct sys_readlink_args;

struct sys_getgroups_args;

struct sys_setgroups_args;

struct sys_fchmod_args;

struct sys___posix_fchown_args;

struct svr4_sys_sigprocmask_args {
	syscallarg(int) how;
	syscallarg(const svr4_sigset_t *) set;
	syscallarg(svr4_sigset_t *) oset;
};
check_syscall_args(svr4_sys_sigprocmask)

struct svr4_sys_sigsuspend_args {
	syscallarg(const svr4_sigset_t *) set;
};
check_syscall_args(svr4_sys_sigsuspend)

struct svr4_sys_sigaltstack_args {
	syscallarg(const struct svr4_sigaltstack *) nss;
	syscallarg(struct svr4_sigaltstack *) oss;
};
check_syscall_args(svr4_sys_sigaltstack)

struct svr4_sys_sigaction_args {
	syscallarg(int) signum;
	syscallarg(const struct svr4_sigaction *) nsa;
	syscallarg(struct svr4_sigaction *) osa;
};
check_syscall_args(svr4_sys_sigaction)

struct svr4_sys_sigpending_args {
	syscallarg(int) what;
	syscallarg(svr4_sigset_t *) set;
};
check_syscall_args(svr4_sys_sigpending)

struct svr4_sys_context_args {
	syscallarg(int) func;
	syscallarg(struct svr4_ucontext *) uc;
};
check_syscall_args(svr4_sys_context)

struct svr4_sys_statvfs_args {
	syscallarg(const char *) path;
	syscallarg(struct svr4_statvfs *) fs;
};
check_syscall_args(svr4_sys_statvfs)

struct svr4_sys_fstatvfs_args {
	syscallarg(int) fd;
	syscallarg(struct svr4_statvfs *) fs;
};
check_syscall_args(svr4_sys_fstatvfs)

struct svr4_sys_waitsys_args {
	syscallarg(int) grp;
	syscallarg(int) id;
	syscallarg(union svr4_siginfo *) info;
	syscallarg(int) options;
};
check_syscall_args(svr4_sys_waitsys)

struct svr4_sys_hrtsys_args {
	syscallarg(int) cmd;
	syscallarg(int) fun;
	syscallarg(int) sub;
	syscallarg(void *) rv1;
	syscallarg(void *) rv2;
};
check_syscall_args(svr4_sys_hrtsys)

struct svr4_sys_pathconf_args {
	syscallarg(const char *) path;
	syscallarg(int) name;
};
check_syscall_args(svr4_sys_pathconf)

struct svr4_sys_mmap_args {
	syscallarg(void *) addr;
	syscallarg(svr4_size_t) len;
	syscallarg(int) prot;
	syscallarg(int) flags;
	syscallarg(int) fd;
	syscallarg(svr4_off_t) pos;
};
check_syscall_args(svr4_sys_mmap)

struct sys_mprotect_args;

struct sys_munmap_args;

struct svr4_sys_fpathconf_args {
	syscallarg(int) fd;
	syscallarg(int) name;
};
check_syscall_args(svr4_sys_fpathconf)

struct sys_fchdir_args;

struct sys_readv_args;

struct sys_writev_args;

struct svr4_sys_xstat_args {
	syscallarg(int) two;
	syscallarg(const char *) path;
	syscallarg(struct svr4_xstat *) ub;
};
check_syscall_args(svr4_sys_xstat)

struct svr4_sys_lxstat_args {
	syscallarg(int) two;
	syscallarg(const char *) path;
	syscallarg(struct svr4_xstat *) ub;
};
check_syscall_args(svr4_sys_lxstat)

struct svr4_sys_fxstat_args {
	syscallarg(int) two;
	syscallarg(int) fd;
	syscallarg(struct svr4_xstat *) sb;
};
check_syscall_args(svr4_sys_fxstat)

struct svr4_sys_xmknod_args {
	syscallarg(int) two;
	syscallarg(char *) path;
	syscallarg(svr4_mode_t) mode;
	syscallarg(svr4_dev_t) dev;
};
check_syscall_args(svr4_sys_xmknod)

struct svr4_sys_setrlimit_args {
	syscallarg(int) which;
	syscallarg(const struct svr4_rlimit *) rlp;
};
check_syscall_args(svr4_sys_setrlimit)

struct svr4_sys_getrlimit_args {
	syscallarg(int) which;
	syscallarg(struct svr4_rlimit *) rlp;
};
check_syscall_args(svr4_sys_getrlimit)

struct sys___posix_lchown_args;

struct svr4_sys_memcntl_args {
	syscallarg(void *) addr;
	syscallarg(svr4_size_t) len;
	syscallarg(int) cmd;
	syscallarg(void *) arg;
	syscallarg(int) attr;
	syscallarg(int) mask;
};
check_syscall_args(svr4_sys_memcntl)

struct sys___posix_rename_args;

struct svr4_sys_uname_args {
	syscallarg(struct svr4_utsname *) name;
	syscallarg(int) dummy;
};
check_syscall_args(svr4_sys_uname)

struct sys_setegid_args;

struct svr4_sys_sysconfig_args {
	syscallarg(int) name;
};
check_syscall_args(svr4_sys_sysconfig)

struct compat_50_sys_adjtime_args;

struct svr4_sys_systeminfo_args {
	syscallarg(int) what;
	syscallarg(char *) buf;
	syscallarg(long) len;
};
check_syscall_args(svr4_sys_systeminfo)

struct sys_seteuid_args;

struct svr4_sys__lwp_info_args {
	syscallarg(struct svr4_lwpinfo *) lwpinfo;
};
check_syscall_args(svr4_sys__lwp_info)

struct sys_fchroot_args;

struct svr4_sys_utimes_args {
	syscallarg(const char *) path;
	syscallarg(struct timeval50 *) tptr;
};
check_syscall_args(svr4_sys_utimes)

struct svr4_sys_gettimeofday_args {
	syscallarg(struct timeval50 *) tp;
};
check_syscall_args(svr4_sys_gettimeofday)

struct compat_50_sys_getitimer_args;

struct compat_50_sys_setitimer_args;

struct svr4_sys__lwp_create_args {
	syscallarg(svr4_ucontext_t *) uc;
	syscallarg(unsigned long) flags;
	syscallarg(svr4_lwpid_t *) lwpid;
};
check_syscall_args(svr4_sys__lwp_create)

struct svr4_sys__lwp_suspend_args {
	syscallarg(svr4_lwpid_t) lwpid;
};
check_syscall_args(svr4_sys__lwp_suspend)

struct svr4_sys__lwp_continue_args {
	syscallarg(svr4_lwpid_t) lwpid;
};
check_syscall_args(svr4_sys__lwp_continue)

struct svr4_sys__lwp_kill_args {
	syscallarg(svr4_lwpid_t) lwpid;
	syscallarg(int) signum;
};
check_syscall_args(svr4_sys__lwp_kill)

struct svr4_sys__lwp_setprivate_args {
	syscallarg(void *) buffer;
};
check_syscall_args(svr4_sys__lwp_setprivate)

struct svr4_sys__lwp_wait_args {
	syscallarg(svr4_lwpid_t) wait_for;
	syscallarg(svr4_lwpid_t *) departed_lwp;
};
check_syscall_args(svr4_sys__lwp_wait)

struct svr4_sys_pread_args {
	syscallarg(int) fd;
	syscallarg(void *) buf;
	syscallarg(size_t) nbyte;
	syscallarg(svr4_off_t) off;
};
check_syscall_args(svr4_sys_pread)

struct svr4_sys_pwrite_args {
	syscallarg(int) fd;
	syscallarg(const void *) buf;
	syscallarg(size_t) nbyte;
	syscallarg(svr4_off_t) off;
};
check_syscall_args(svr4_sys_pwrite)

struct svr4_sys_llseek_args {
	syscallarg(int) fd;
	syscallarg(long) offset1;
	syscallarg(long) offset2;
	syscallarg(int) whence;
};
check_syscall_args(svr4_sys_llseek)

struct svr4_sys_acl_args {
	syscallarg(char *) path;
	syscallarg(int) cmd;
	syscallarg(int) num;
	syscallarg(struct svr4_aclent *) buf;
};
check_syscall_args(svr4_sys_acl)

struct svr4_sys_auditsys_args {
	syscallarg(int) code;
	syscallarg(int) a1;
	syscallarg(int) a2;
	syscallarg(int) a3;
	syscallarg(int) a4;
	syscallarg(int) a5;
};
check_syscall_args(svr4_sys_auditsys)

struct compat_50_sys_nanosleep_args;

struct svr4_sys_facl_args {
	syscallarg(int) fd;
	syscallarg(int) cmd;
	syscallarg(int) num;
	syscallarg(struct svr4_aclent *) buf;
};
check_syscall_args(svr4_sys_facl)

struct sys_setreuid_args;

struct sys_setregid_args;

struct svr4_sys_schedctl_args {
	syscallarg(unsigned int) x;
	syscallarg(int) y;
	syscallarg(void **) z;
};
check_syscall_args(svr4_sys_schedctl)

struct svr4_sys_resolvepath_args {
	syscallarg(const char *) path;
	syscallarg(char *) buf;
	syscallarg(size_t) bufsiz;
};
check_syscall_args(svr4_sys_resolvepath)

struct svr4_sys_getdents64_args {
	syscallarg(int) fd;
	syscallarg(struct svr4_dirent64 *) dp;
	syscallarg(int) nbytes;
};
check_syscall_args(svr4_sys_getdents64)

struct svr4_sys_mmap64_args {
	syscallarg(void *) addr;
	syscallarg(svr4_size_t) len;
	syscallarg(int) prot;
	syscallarg(int) flags;
	syscallarg(int) fd;
	syscallarg(svr4_off64_t) pos;
};
check_syscall_args(svr4_sys_mmap64)

struct svr4_sys_stat64_args {
	syscallarg(const char *) path;
	syscallarg(struct svr4_stat64 *) sb;
};
check_syscall_args(svr4_sys_stat64)

struct svr4_sys_lstat64_args {
	syscallarg(const char *) path;
	syscallarg(struct svr4_stat64 *) sb;
};
check_syscall_args(svr4_sys_lstat64)

struct svr4_sys_fstat64_args {
	syscallarg(int) fd;
	syscallarg(struct svr4_stat64 *) sb;
};
check_syscall_args(svr4_sys_fstat64)

struct svr4_sys_statvfs64_args {
	syscallarg(const char *) path;
	syscallarg(struct svr4_statvfs64 *) fs;
};
check_syscall_args(svr4_sys_statvfs64)

struct svr4_sys_fstatvfs64_args {
	syscallarg(int) fd;
	syscallarg(struct svr4_statvfs64 *) fs;
};
check_syscall_args(svr4_sys_fstatvfs64)

struct svr4_sys_setrlimit64_args {
	syscallarg(int) which;
	syscallarg(const struct svr4_rlimit64 *) rlp;
};
check_syscall_args(svr4_sys_setrlimit64)

struct svr4_sys_getrlimit64_args {
	syscallarg(int) which;
	syscallarg(struct svr4_rlimit64 *) rlp;
};
check_syscall_args(svr4_sys_getrlimit64)

struct svr4_sys_pread64_args {
	syscallarg(int) fd;
	syscallarg(void *) buf;
	syscallarg(size_t) nbyte;
	syscallarg(svr4_off64_t) off;
};
check_syscall_args(svr4_sys_pread64)

struct svr4_sys_pwrite64_args {
	syscallarg(int) fd;
	syscallarg(const void *) buf;
	syscallarg(size_t) nbyte;
	syscallarg(svr4_off64_t) off;
};
check_syscall_args(svr4_sys_pwrite64)

struct svr4_sys_creat64_args {
	syscallarg(char *) path;
	syscallarg(int) mode;
};
check_syscall_args(svr4_sys_creat64)

struct svr4_sys_open64_args {
	syscallarg(char *) path;
	syscallarg(int) flags;
	syscallarg(int) mode;
};
check_syscall_args(svr4_sys_open64)

struct svr4_sys_socket_args {
	syscallarg(int) domain;
	syscallarg(int) type;
	syscallarg(int) protocol;
};
check_syscall_args(svr4_sys_socket)

struct sys_socketpair_args;

struct sys_bind_args;

struct sys_listen_args;

struct compat_43_sys_accept_args;

struct sys_connect_args;

struct sys_shutdown_args;

struct compat_43_sys_recv_args;

struct compat_43_sys_recvfrom_args;

struct compat_43_sys_recvmsg_args;

struct compat_43_sys_send_args;

struct compat_43_sys_sendmsg_args;

struct sys_sendto_args;

struct compat_43_sys_getpeername_args;

struct compat_43_sys_getsockname_args;

struct sys_getsockopt_args;

struct sys_setsockopt_args;
#if defined(NTP) || !defined(_KERNEL)

struct sys_ntp_adjtime_args;
#else
#endif

/*
 * System call prototypes.
 */

int	sys_nosys(struct lwp *, const void *, register_t *);

int	sys_exit(struct lwp *, const struct sys_exit_args *, register_t *);

int	sys_fork(struct lwp *, const void *, register_t *);

int	sys_read(struct lwp *, const struct sys_read_args *, register_t *);

int	sys_write(struct lwp *, const struct sys_write_args *, register_t *);

int	svr4_sys_open(struct lwp *, const struct svr4_sys_open_args *, register_t *);

int	sys_close(struct lwp *, const struct sys_close_args *, register_t *);

int	svr4_sys_wait(struct lwp *, const struct svr4_sys_wait_args *, register_t *);

int	svr4_sys_creat(struct lwp *, const struct svr4_sys_creat_args *, register_t *);

int	sys_link(struct lwp *, const struct sys_link_args *, register_t *);

int	sys_unlink(struct lwp *, const struct sys_unlink_args *, register_t *);

int	svr4_sys_execv(struct lwp *, const struct svr4_sys_execv_args *, register_t *);

int	sys_chdir(struct lwp *, const struct sys_chdir_args *, register_t *);

int	svr4_sys_time(struct lwp *, const struct svr4_sys_time_args *, register_t *);

int	svr4_sys_mknod(struct lwp *, const struct svr4_sys_mknod_args *, register_t *);

int	sys_chmod(struct lwp *, const struct sys_chmod_args *, register_t *);

int	sys___posix_chown(struct lwp *, const struct sys___posix_chown_args *, register_t *);

int	svr4_sys_break(struct lwp *, const struct svr4_sys_break_args *, register_t *);

int	svr4_sys_stat(struct lwp *, const struct svr4_sys_stat_args *, register_t *);

int	compat_43_sys_lseek(struct lwp *, const struct compat_43_sys_lseek_args *, register_t *);

int	sys_getpid(struct lwp *, const void *, register_t *);

int	sys_setuid(struct lwp *, const struct sys_setuid_args *, register_t *);

int	sys_getuid_with_euid(struct lwp *, const void *, register_t *);

int	svr4_sys_alarm(struct lwp *, const struct svr4_sys_alarm_args *, register_t *);

int	svr4_sys_fstat(struct lwp *, const struct svr4_sys_fstat_args *, register_t *);

int	svr4_sys_pause(struct lwp *, const void *, register_t *);

int	svr4_sys_utime(struct lwp *, const struct svr4_sys_utime_args *, register_t *);

int	svr4_sys_access(struct lwp *, const struct svr4_sys_access_args *, register_t *);

int	svr4_sys_nice(struct lwp *, const struct svr4_sys_nice_args *, register_t *);

int	sys_sync(struct lwp *, const void *, register_t *);

int	svr4_sys_kill(struct lwp *, const struct svr4_sys_kill_args *, register_t *);

int	svr4_sys_pgrpsys(struct lwp *, const struct svr4_sys_pgrpsys_args *, register_t *);

int	sys_dup(struct lwp *, const struct sys_dup_args *, register_t *);

int	sys_pipe(struct lwp *, const void *, register_t *);

int	svr4_sys_times(struct lwp *, const struct svr4_sys_times_args *, register_t *);

int	sys_setgid(struct lwp *, const struct sys_setgid_args *, register_t *);

int	sys_getgid_with_egid(struct lwp *, const void *, register_t *);

int	svr4_sys_signal(struct lwp *, const struct svr4_sys_signal_args *, register_t *);

#ifdef SYSVMSG
int	svr4_sys_msgsys(struct lwp *, const struct svr4_sys_msgsys_args *, register_t *);

#else
#endif
int	svr4_sys_sysarch(struct lwp *, const struct svr4_sys_sysarch_args *, register_t *);

#ifdef SYSVSHM
int	svr4_sys_shmsys(struct lwp *, const struct svr4_sys_shmsys_args *, register_t *);

#else
#endif
#ifdef SYSVSEM
int	svr4_sys_semsys(struct lwp *, const struct svr4_sys_semsys_args *, register_t *);

#else
#endif
int	svr4_sys_ioctl(struct lwp *, const struct svr4_sys_ioctl_args *, register_t *);

int	svr4_sys_utssys(struct lwp *, const struct svr4_sys_utssys_args *, register_t *);

int	sys_fsync(struct lwp *, const struct sys_fsync_args *, register_t *);

int	svr4_sys_execve(struct lwp *, const struct svr4_sys_execve_args *, register_t *);

int	sys_umask(struct lwp *, const struct sys_umask_args *, register_t *);

int	sys_chroot(struct lwp *, const struct sys_chroot_args *, register_t *);

int	svr4_sys_fcntl(struct lwp *, const struct svr4_sys_fcntl_args *, register_t *);

int	svr4_sys_ulimit(struct lwp *, const struct svr4_sys_ulimit_args *, register_t *);

int	sys_rmdir(struct lwp *, const struct sys_rmdir_args *, register_t *);

int	sys_mkdir(struct lwp *, const struct sys_mkdir_args *, register_t *);

int	svr4_sys_getdents(struct lwp *, const struct svr4_sys_getdents_args *, register_t *);

int	svr4_sys_getmsg(struct lwp *, const struct svr4_sys_getmsg_args *, register_t *);

int	svr4_sys_putmsg(struct lwp *, const struct svr4_sys_putmsg_args *, register_t *);

int	sys_poll(struct lwp *, const struct sys_poll_args *, register_t *);

int	svr4_sys_lstat(struct lwp *, const struct svr4_sys_lstat_args *, register_t *);

int	sys_symlink(struct lwp *, const struct sys_symlink_args *, register_t *);

int	sys_readlink(struct lwp *, const struct sys_readlink_args *, register_t *);

int	sys_getgroups(struct lwp *, const struct sys_getgroups_args *, register_t *);

int	sys_setgroups(struct lwp *, const struct sys_setgroups_args *, register_t *);

int	sys_fchmod(struct lwp *, const struct sys_fchmod_args *, register_t *);

int	sys___posix_fchown(struct lwp *, const struct sys___posix_fchown_args *, register_t *);

int	svr4_sys_sigprocmask(struct lwp *, const struct svr4_sys_sigprocmask_args *, register_t *);

int	svr4_sys_sigsuspend(struct lwp *, const struct svr4_sys_sigsuspend_args *, register_t *);

int	svr4_sys_sigaltstack(struct lwp *, const struct svr4_sys_sigaltstack_args *, register_t *);

int	svr4_sys_sigaction(struct lwp *, const struct svr4_sys_sigaction_args *, register_t *);

int	svr4_sys_sigpending(struct lwp *, const struct svr4_sys_sigpending_args *, register_t *);

int	svr4_sys_context(struct lwp *, const struct svr4_sys_context_args *, register_t *);

int	svr4_sys_statvfs(struct lwp *, const struct svr4_sys_statvfs_args *, register_t *);

int	svr4_sys_fstatvfs(struct lwp *, const struct svr4_sys_fstatvfs_args *, register_t *);

int	svr4_sys_waitsys(struct lwp *, const struct svr4_sys_waitsys_args *, register_t *);

int	svr4_sys_hrtsys(struct lwp *, const struct svr4_sys_hrtsys_args *, register_t *);

int	svr4_sys_pathconf(struct lwp *, const struct svr4_sys_pathconf_args *, register_t *);

int	svr4_sys_mmap(struct lwp *, const struct svr4_sys_mmap_args *, register_t *);

int	sys_mprotect(struct lwp *, const struct sys_mprotect_args *, register_t *);

int	sys_munmap(struct lwp *, const struct sys_munmap_args *, register_t *);

int	svr4_sys_fpathconf(struct lwp *, const struct svr4_sys_fpathconf_args *, register_t *);

int	sys_vfork(struct lwp *, const void *, register_t *);

int	sys_fchdir(struct lwp *, const struct sys_fchdir_args *, register_t *);

int	sys_readv(struct lwp *, const struct sys_readv_args *, register_t *);

int	sys_writev(struct lwp *, const struct sys_writev_args *, register_t *);

int	svr4_sys_xstat(struct lwp *, const struct svr4_sys_xstat_args *, register_t *);

int	svr4_sys_lxstat(struct lwp *, const struct svr4_sys_lxstat_args *, register_t *);

int	svr4_sys_fxstat(struct lwp *, const struct svr4_sys_fxstat_args *, register_t *);

int	svr4_sys_xmknod(struct lwp *, const struct svr4_sys_xmknod_args *, register_t *);

int	svr4_sys_setrlimit(struct lwp *, const struct svr4_sys_setrlimit_args *, register_t *);

int	svr4_sys_getrlimit(struct lwp *, const struct svr4_sys_getrlimit_args *, register_t *);

int	sys___posix_lchown(struct lwp *, const struct sys___posix_lchown_args *, register_t *);

int	svr4_sys_memcntl(struct lwp *, const struct svr4_sys_memcntl_args *, register_t *);

int	sys___posix_rename(struct lwp *, const struct sys___posix_rename_args *, register_t *);

int	svr4_sys_uname(struct lwp *, const struct svr4_sys_uname_args *, register_t *);

int	sys_setegid(struct lwp *, const struct sys_setegid_args *, register_t *);

int	svr4_sys_sysconfig(struct lwp *, const struct svr4_sys_sysconfig_args *, register_t *);

int	compat_50_sys_adjtime(struct lwp *, const struct compat_50_sys_adjtime_args *, register_t *);

int	svr4_sys_systeminfo(struct lwp *, const struct svr4_sys_systeminfo_args *, register_t *);

int	sys_seteuid(struct lwp *, const struct sys_seteuid_args *, register_t *);

int	svr4_sys__lwp_info(struct lwp *, const struct svr4_sys__lwp_info_args *, register_t *);

int	sys_fchroot(struct lwp *, const struct sys_fchroot_args *, register_t *);

int	svr4_sys_utimes(struct lwp *, const struct svr4_sys_utimes_args *, register_t *);

int	svr4_sys_vhangup(struct lwp *, const void *, register_t *);

int	svr4_sys_gettimeofday(struct lwp *, const struct svr4_sys_gettimeofday_args *, register_t *);

int	compat_50_sys_getitimer(struct lwp *, const struct compat_50_sys_getitimer_args *, register_t *);

int	compat_50_sys_setitimer(struct lwp *, const struct compat_50_sys_setitimer_args *, register_t *);

int	svr4_sys__lwp_create(struct lwp *, const struct svr4_sys__lwp_create_args *, register_t *);

int	svr4_sys__lwp_exit(struct lwp *, const void *, register_t *);

int	svr4_sys__lwp_suspend(struct lwp *, const struct svr4_sys__lwp_suspend_args *, register_t *);

int	svr4_sys__lwp_continue(struct lwp *, const struct svr4_sys__lwp_continue_args *, register_t *);

int	svr4_sys__lwp_kill(struct lwp *, const struct svr4_sys__lwp_kill_args *, register_t *);

int	svr4_sys__lwp_self(struct lwp *, const void *, register_t *);

int	svr4_sys__lwp_getprivate(struct lwp *, const void *, register_t *);

int	svr4_sys__lwp_setprivate(struct lwp *, const struct svr4_sys__lwp_setprivate_args *, register_t *);

int	svr4_sys__lwp_wait(struct lwp *, const struct svr4_sys__lwp_wait_args *, register_t *);

int	svr4_sys_pread(struct lwp *, const struct svr4_sys_pread_args *, register_t *);

int	svr4_sys_pwrite(struct lwp *, const struct svr4_sys_pwrite_args *, register_t *);

int	svr4_sys_llseek(struct lwp *, const struct svr4_sys_llseek_args *, register_t *);

int	svr4_sys_acl(struct lwp *, const struct svr4_sys_acl_args *, register_t *);

int	svr4_sys_auditsys(struct lwp *, const struct svr4_sys_auditsys_args *, register_t *);

int	compat_50_sys_nanosleep(struct lwp *, const struct compat_50_sys_nanosleep_args *, register_t *);

int	svr4_sys_facl(struct lwp *, const struct svr4_sys_facl_args *, register_t *);

int	sys_setreuid(struct lwp *, const struct sys_setreuid_args *, register_t *);

int	sys_setregid(struct lwp *, const struct sys_setregid_args *, register_t *);

int	svr4_sys_schedctl(struct lwp *, const struct svr4_sys_schedctl_args *, register_t *);

int	svr4_sys_resolvepath(struct lwp *, const struct svr4_sys_resolvepath_args *, register_t *);

int	svr4_sys_getdents64(struct lwp *, const struct svr4_sys_getdents64_args *, register_t *);

int	svr4_sys_mmap64(struct lwp *, const struct svr4_sys_mmap64_args *, register_t *);

int	svr4_sys_stat64(struct lwp *, const struct svr4_sys_stat64_args *, register_t *);

int	svr4_sys_lstat64(struct lwp *, const struct svr4_sys_lstat64_args *, register_t *);

int	svr4_sys_fstat64(struct lwp *, const struct svr4_sys_fstat64_args *, register_t *);

int	svr4_sys_statvfs64(struct lwp *, const struct svr4_sys_statvfs64_args *, register_t *);

int	svr4_sys_fstatvfs64(struct lwp *, const struct svr4_sys_fstatvfs64_args *, register_t *);

int	svr4_sys_setrlimit64(struct lwp *, const struct svr4_sys_setrlimit64_args *, register_t *);

int	svr4_sys_getrlimit64(struct lwp *, const struct svr4_sys_getrlimit64_args *, register_t *);

int	svr4_sys_pread64(struct lwp *, const struct svr4_sys_pread64_args *, register_t *);

int	svr4_sys_pwrite64(struct lwp *, const struct svr4_sys_pwrite64_args *, register_t *);

int	svr4_sys_creat64(struct lwp *, const struct svr4_sys_creat64_args *, register_t *);

int	svr4_sys_open64(struct lwp *, const struct svr4_sys_open64_args *, register_t *);

int	svr4_sys_socket(struct lwp *, const struct svr4_sys_socket_args *, register_t *);

int	sys_socketpair(struct lwp *, const struct sys_socketpair_args *, register_t *);

int	sys_bind(struct lwp *, const struct sys_bind_args *, register_t *);

int	sys_listen(struct lwp *, const struct sys_listen_args *, register_t *);

int	compat_43_sys_accept(struct lwp *, const struct compat_43_sys_accept_args *, register_t *);

int	sys_connect(struct lwp *, const struct sys_connect_args *, register_t *);

int	sys_shutdown(struct lwp *, const struct sys_shutdown_args *, register_t *);

int	compat_43_sys_recv(struct lwp *, const struct compat_43_sys_recv_args *, register_t *);

int	compat_43_sys_recvfrom(struct lwp *, const struct compat_43_sys_recvfrom_args *, register_t *);

int	compat_43_sys_recvmsg(struct lwp *, const struct compat_43_sys_recvmsg_args *, register_t *);

int	compat_43_sys_send(struct lwp *, const struct compat_43_sys_send_args *, register_t *);

int	compat_43_sys_sendmsg(struct lwp *, const struct compat_43_sys_sendmsg_args *, register_t *);

int	sys_sendto(struct lwp *, const struct sys_sendto_args *, register_t *);

int	compat_43_sys_getpeername(struct lwp *, const struct compat_43_sys_getpeername_args *, register_t *);

int	compat_43_sys_getsockname(struct lwp *, const struct compat_43_sys_getsockname_args *, register_t *);

int	sys_getsockopt(struct lwp *, const struct sys_getsockopt_args *, register_t *);

int	sys_setsockopt(struct lwp *, const struct sys_setsockopt_args *, register_t *);

#if defined(NTP) || !defined(_KERNEL)
int	sys_ntp_adjtime(struct lwp *, const struct sys_ntp_adjtime_args *, register_t *);

#else
#endif
#endif /* _SVR4_SYS_SYSCALLARGS_H_ */
