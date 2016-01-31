
mercurial

    log
    graph
    tags
    branches

    changeset
    browse

    file
    latest
    diff
    annotate
    file log
    raw

    help

solaris~on-src
view usr/src/cmd/ls/ls.c @ 13149:b23a4dab3d50

6973228 Cannot download firmware 2.103.x.x on Emulex FCoE HBAs
6960289 fiber side of emulex cna does not connect to the storage
6950462 Emulex HBA permanently DESTROYED, if the firmware upgrade is interrupted
6964513 COMSTAR - Emulex LP9002 fail to return a SCSI Inquiry correctly to a VMware 4 Initiator
author 	Sukumar Swaminathan <Sukumar.Swaminathan@Sun.COM>
date 	Wed, 18 Aug 2010 15:52:48 -0600 (2010-08-19)
parents 	3e221269daa8
children 	
 line source
     1 /*
     2  * CDDL HEADER START
     3  *
     4  * The contents of this file are subject to the terms of the
     5  * Common Development and Distribution License (the "License").
     6  * You may not use this file except in compliance with the License.
     7  *
     8  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
     9  * or http://www.opensolaris.org/os/licensing.
    10  * See the License for the specific language governing permissions
    11  * and limitations under the License.
    12  *
    13  * When distributing Covered Code, include this CDDL HEADER in each
    14  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
    15  * If applicable, add the following below this CDDL HEADER, with the
    16  * fields enclosed by brackets "[]" replaced with your own identifying
    17  * information: Portions Copyright [yyyy] [name of copyright owner]
    18  *
    19  * CDDL HEADER END
    20  */
    21 
    22 /*
    23  * Copyright (c) 1988, 2010, Oracle and/or its affiliates. All rights reserved.
    24  */
    25 
    26 /*
    27  * Copyright 2009 Jason King.  All rights reserved.
    28  * Use is subject to license terms.
    29  */
    30 
    31 /*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
    32 /*	  All Rights Reserved  	*/
    33 
    34 /*	Copyright (c) 1987, 1988 Microsoft Corporation	*/
    35 /*	  All Rights Reserved	*/
    36 
    37 /*
    38  * List files or directories
    39  */
    40 
    41 #include <sys/param.h>
    42 #include <sys/types.h>
    43 #include <sys/mkdev.h>
    44 #include <sys/stat.h>
    45 #include <sys/acl.h>
    46 
    47 #include <wchar.h>
    48 #include <stdio.h>
    49 #include <ctype.h>
    50 #include <dirent.h>
    51 #include <string.h>
    52 #include <locale.h>
    53 #include <curses.h>
    54 #include <term.h>
    55 #include <termios.h>
    56 #include <stdlib.h>
    57 #include <widec.h>
    58 #include <locale.h>
    59 #include <wctype.h>
    60 #include <pwd.h>
    61 #include <grp.h>
    62 #include <limits.h>
    63 #include <fcntl.h>
    64 #include <unistd.h>
    65 #include <libgen.h>
    66 #include <errno.h>
    67 #include <aclutils.h>
    68 #include <libnvpair.h>
    69 #include <libcmdutils.h>
    70 #include <attr.h>
    71 #include <getopt.h>
    72 #include <inttypes.h>
    73 
    74 #ifndef STANDALONE
    75 #define	TERMINFO
    76 #endif
    77 
    78 /*
    79  * -DNOTERMINFO can be defined on the cc command line to prevent
    80  * the use of terminfo.  This should be done on systems not having
    81  * the terminfo feature(pre 6.0 systems ?).
    82  * As a result, columnar listings assume 80 columns for output,
    83  * unless told otherwise via the COLUMNS environment variable.
    84  */
    85 #ifdef NOTERMINFO
    86 #undef TERMINFO
    87 #endif
    88 
    89 #include <term.h>
    90 
    91 #define	BFSIZE	16
    92 /* this bit equals 1 in lflags of structure lbuf if *namep is to be used */
    93 #define	ISARG	0100000
    94 
    95 /*
    96  * this flag has been added to manipulate the display of S instead of 'l' when
    97  * the file is not a regular file and when group execution bit is off
    98  */
    99 #define	LS_NOTREG	010000
   100 
   101 
   102 /*
   103  * Date and time formats
   104  *
   105  * b --- abbreviated month name
   106  * e --- day number
   107  * Y --- year in the form ccyy
   108  * H --- hour(24-hour version)
   109  * M --- minute
   110  * F --- yyyy-mm-dd
   111  * T --- hh:mm:ss
   112  * z --- time zone as hours displacement from UTC
   113  * note that %F and %z are from the ISO C99 standard and are
   114  * not present in older C libraries
   115  */
   116 #define	FORMAT_OLD	" %b %e  %Y "
   117 #define	FORMAT_NEW	" %b %e %H:%M "
   118 #define	FORMAT_LONG	" %b %e %T %Y "
   119 #define	FORMAT_ISO_FULL	" %%F %%T.%.09ld %%z "
   120 #define	FORMAT_ISO_LONG	" %F %R "
   121 #define	FORMAT_ISO_NEW	" %m-%d %H:%M "
   122 #define	FORMAT_ISO_OLD	" %F "
   123 
   124 #undef BUFSIZ
   125 #define	BUFSIZ 4096
   126 #define	NUMBER_WIDTH 40
   127 #define	FMTSIZE 50
   128 
   129 struct ditem {
   130 	dev_t	dev;			/* directory items device number */
   131 	ino_t	ino;			/* directory items inode number */
   132 	struct ditem *parent;		/* dir items ptr to its parent's info */
   133 };
   134 /* Holds boolean extended system attributes */
   135 struct attrb {
   136 	char		*name;
   137 };
   138 /* Holds timestamp extended system attributes */
   139 struct attrtm {
   140 	char		*name;
   141 	uint64_t	stm;
   142 	uint64_t	nstm;
   143 };
   144 
   145 #define	LSA_NONE	(0)
   146 #define	LSA_BOLD	(1L << 0)
   147 #define	LSA_UNDERSCORE	(1L << 1)
   148 #define	LSA_BLINK	(1L << 2)
   149 #define	LSA_REVERSE	(1L << 3)
   150 #define	LSA_CONCEALED	(1L << 4)
   151 
   152 /* these should be ordered most general to most specific */
   153 typedef enum LS_CFTYPE {
   154 	LS_NORMAL,
   155 	LS_FILE,
   156 	LS_EXEC,
   157 	LS_DIR,
   158 	LS_LINK,
   159 	LS_FIFO,
   160 	LS_SOCK,
   161 	LS_DOOR,
   162 	LS_BLK,
   163 	LS_CHR,
   164 	LS_PORT,
   165 	LS_STICKY,
   166 	LS_ORPHAN,
   167 	LS_SETGID,
   168 	LS_SETUID,
   169 	LS_OTHER_WRITABLE,
   170 	LS_STICKY_OTHER_WRITABLE,
   171 	LS_PAT
   172 } ls_cftype_t;
   173 
   174 typedef struct {
   175 	char		*sfx;
   176 	ls_cftype_t	ftype;
   177 	int		attr;
   178 	int		fg;
   179 	int		bg;
   180 } ls_color_t;
   181 
   182 struct	lbuf	{
   183 	union	{
   184 		char	lname[MAXNAMLEN]; /* used for filename in a directory */
   185 		char	*namep;		/* for name in ls-command; */
   186 	} ln;
   187 	char	ltype;		/* filetype */
   188 	ino_t	lnum;		/* inode number of file */
   189 	mode_t	lflags; 	/* 0777 bits used as r,w,x permissions */
   190 	nlink_t	lnl;		/* number of links to file */
   191 	uid_t	luid;
   192 	gid_t	lgid;
   193 	off_t	lsize;		/* filesize or major/minor dev numbers */
   194 	blkcnt_t	lblocks;	/* number of file blocks */
   195 	timestruc_t	lmtime;
   196 	timestruc_t	lat;
   197 	timestruc_t	lct;
   198 	timestruc_t	lmt;
   199 	char	*flinkto;	/* symbolic link contents */
   200 	char 	acl;		/* indicate there are additional acl entries */
   201 	int	cycle;		/* cycle detected flag */
   202 	struct ditem *ancinfo;	/* maintains ancestor info */
   203 	acl_t *aclp;		/* ACL if present */
   204 	struct attrb *exttr;	/* boolean extended system attributes */
   205 	struct attrtm *extm;	/* timestamp extended system attributes */
   206 	ls_color_t	*color;	/* color for entry */
   207 	ls_color_t	*link_color;	/* color for symlink */
   208 };
   209 
   210 struct dchain {
   211 	char *dc_name;		/* path name */
   212 	int cycle_detected;	/* cycle detected visiting this directory */
   213 	struct ditem *myancinfo;	/* this directory's ancestry info */
   214 	struct dchain *dc_next;	/* next directory in the chain */
   215 };
   216 
   217 /*
   218  * A numbuf_t is used when converting a number to a string representation
   219  */
   220 typedef char numbuf_t[NUMBER_WIDTH];
   221 
   222 static struct dchain *dfirst;	/* start of the dir chain */
   223 static struct dchain *cdfirst;	/* start of the current dir chain */
   224 static struct dchain *dtemp;	/* temporary - used for linking */
   225 static char *curdir;		/* the current directory */
   226 
   227 static int	first = 1;	/* true if first line is not yet printed */
   228 static int	nfiles = 0;	/* number of flist entries in current use */
   229 static int	nargs = 0;	/* number of flist entries used for arguments */
   230 static int	maxfils = 0;	/* number of flist/lbuf entries allocated */
   231 static int	maxn = 0;	/* number of flist entries with lbufs asigned */
   232 static int	quantn = 64;	/* allocation growth quantum */
   233 
   234 static struct lbuf	*nxtlbf;	/* ptr to next lbuf to be assigned */
   235 static struct lbuf	**flist;	/* ptr to list of lbuf pointers */
   236 static struct lbuf	*gstat(char *, int, struct ditem *);
   237 static char		*getname(uid_t);
   238 static char		*getgroup(gid_t);
   239 static char		*makename(char *, char *);
   240 static void		pentry(struct lbuf *);
   241 static void		column(void);
   242 static void		pmode(mode_t aflag);
   243 static void		selection(int *);
   244 static void		new_line(void);
   245 static void		rddir(char *, struct ditem *);
   246 static int		strcol(unsigned char *);
   247 static void		pem(struct lbuf **, struct lbuf **, int);
   248 static void		pdirectory(char *, int, int, int, struct ditem *);
   249 static struct cachenode *findincache(struct cachenode **, long);
   250 static void		csi_pprintf(unsigned char *);
   251 static void		pprintf(char *, char *);
   252 static int		compar(struct lbuf **pp1, struct lbuf **pp2);
   253 static char 		*number_to_scaled_string(numbuf_t buf,
   254 			    unsigned long long number,
   255 			    long scale);
   256 static void		record_ancestry(char *, struct stat *, struct lbuf *,
   257 			    int, struct ditem *);
   258 static void		ls_color_init(void);
   259 static ls_color_t	*ls_color_find(const char *, mode_t);
   260 static void		ls_start_color(ls_color_t *);
   261 static void		ls_end_color(void);
   262 
   263 static int		aflg;
   264 static int		atflg;
   265 static int		bflg;
   266 static int		cflg;
   267 static int		dflg;
   268 static int		eflg;
   269 static int		fflg;
   270 static int		gflg;
   271 static int		hflg;
   272 static int		iflg;
   273 static int		lflg;
   274 static int		mflg;
   275 static int		nflg;
   276 static int		oflg;
   277 static int		pflg;
   278 static int		qflg;
   279 static int		rflg = 1; /* init to 1 for special use in compar */
   280 static int		sflg;
   281 static int		tflg;
   282 static int		uflg;
   283 static int		Uflg;
   284 static int		wflg;
   285 static int		xflg;
   286 static int		Aflg;
   287 static int		Bflg;
   288 static int		Cflg;
   289 static int		Eflg;
   290 static int		Fflg;
   291 static int		Hflg;
   292 static int		Lflg;
   293 static int		Rflg;
   294 static int		Sflg;
   295 static int		vflg;
   296 static int		Vflg;
   297 static int		saflg;		/* boolean extended system attr. */
   298 static int		sacnt;		/* number of extended system attr. */
   299 static int		copt;
   300 static int		vopt;
   301 static int		tmflg;		/* create time ext. system attr. */
   302 static int		ctm;
   303 static int		atm;
   304 static int		mtm;
   305 static int		crtm;
   306 static int		alltm;
   307 static long		hscale;
   308 static mode_t		flags;
   309 static int		err = 0;	/* Contains return code */
   310 static int		colorflg;
   311 static int		file_typeflg;
   312 
   313 static uid_t		lastuid	= (uid_t)-1;
   314 static gid_t		lastgid = (gid_t)-1;
   315 static char		*lastuname = NULL;
   316 static char		*lastgname = NULL;
   317 
   318 /* statreq > 0 if any of sflg, (n)lflg, tflg, Sflg, colorflg are on */
   319 static int		statreq;
   320 
   321 static uint64_t		block_size = 1;
   322 static char		*dotp = ".";
   323 
   324 static u_longlong_t 	tblocks; /* number of blocks of files in a directory */
   325 static time_t		year, now;
   326 
   327 static int		num_cols = 80;
   328 static int		colwidth;
   329 static int		filewidth;
   330 static int		fixedwidth;
   331 static int		nomocore;
   332 static int		curcol;
   333 
   334 static struct	winsize	win;
   335 
   336 /* if time_fmt_new is left NULL, time_fmt_old is used for all times */
   337 static const char	*time_fmt_old = FORMAT_OLD;	/* non-recent files */
   338 static const char	*time_fmt_new = FORMAT_NEW;	/* recent files */
   339 static int		time_custom;	/* != 0 if a custom format */
   340 static char	time_buf[FMTSIZE];	/* array to hold day and time */
   341 
   342 static int		lsc_debug;
   343 static ls_color_t	*lsc_match;
   344 static ls_color_t	*lsc_colors;
   345 static size_t		lsc_ncolors;
   346 static char		*lsc_bold;
   347 static char		*lsc_underline;
   348 static char		*lsc_blink;
   349 static char		*lsc_reverse;
   350 static char		*lsc_concealed;
   351 static char		*lsc_none;
   352 static char		*lsc_setfg;
   353 static char		*lsc_setbg;
   354 static ls_color_t	*lsc_orphan;
   355 
   356 #define	NOTWORKINGDIR(d, l)	(((l) < 2) || \
   357 				    (strcmp((d) + (l) - 2, "/.") != 0))
   358 
   359 #define	NOTPARENTDIR(d, l)	(((l) < 3) || \
   360 				    (strcmp((d) + (l) - 3, "/..") != 0))
   361 /* Extended system attributes support */
   362 static int get_sysxattr(char *, struct lbuf *);
   363 static void set_sysattrb_display(char *, boolean_t, struct lbuf *);
   364 static void set_sysattrtm_display(char *, struct lbuf *);
   365 static void format_time(time_t, time_t);
   366 static void print_time(struct lbuf *);
   367 static void format_attrtime(struct lbuf *);
   368 static void *xmalloc(size_t, struct lbuf *);
   369 static void free_sysattr(struct lbuf *);
   370 static nvpair_t *pair;
   371 static nvlist_t	*response;
   372 static int acl_err;
   373 
   374 const struct option long_options[] = {
   375 	{ "all", no_argument, NULL, 'a' },
   376 	{ "almost-all", no_argument, NULL, 'A' },
   377 	{ "escape", no_argument, NULL, 'b' },
   378 	{ "classify", no_argument, NULL, 'F' },
   379 	{ "human-readable", no_argument, NULL, 'h' },
   380 	{ "dereference", no_argument, NULL, 'L' },
   381 	{ "dereference-command-line", no_argument, NULL, 'H' },
   382 	{ "ignore-backups", no_argument, NULL, 'B' },
   383 	{ "inode", no_argument, NULL, 'i' },
   384 	{ "numeric-uid-gid", no_argument, NULL, 'n' },
   385 	{ "no-group", no_argument, NULL, 'o' },
   386 	{ "hide-control-chars", no_argument, NULL, 'q' },
   387 	{ "reverse", no_argument, NULL, 'r' },
   388 	{ "recursive", no_argument, NULL, 'R' },
   389 	{ "size", no_argument, NULL, 's' },
   390 	{ "width", required_argument, NULL, 'w' },
   391 
   392 	/* no short options for these */
   393 	{ "block-size", required_argument, NULL, 0 },
   394 	{ "full-time", no_argument, NULL, 0 },
   395 	{ "si", no_argument, NULL, 0 },
   396 	{ "color", optional_argument, NULL, 0 },
   397 	{ "colour", optional_argument, NULL, 0},
   398 	{ "file-type", no_argument, NULL, 0 },
   399 	{ "time-style", required_argument, NULL, 0 },
   400 
   401 	{0, 0, 0, 0}
   402 };
   403 
   404 int
   405 main(int argc, char *argv[])
   406 {
   407 	int		c;
   408 	int		i;
   409 	int		width;
   410 	int		amino = 0;
   411 	int		opterr = 0;
   412 	int		option_index = 0;
   413 	struct lbuf	*ep;
   414 	struct lbuf	lb;
   415 	struct ditem	*myinfo;
   416 
   417 	(void) setlocale(LC_ALL, "");
   418 #if !defined(TEXT_DOMAIN)	/* Should be defined by cc -D */
   419 #define	TEXT_DOMAIN "SYS_TEST"	/* Use this only if it weren't */
   420 #endif
   421 	(void) textdomain(TEXT_DOMAIN);
   422 #ifdef STANDALONE
   423 	if (argv[0][0] == '\0')
   424 		argc = getargv("ls", &argv, 0);
   425 #endif
   426 
   427 	lb.lmtime.tv_sec = time(NULL);
   428 	lb.lmtime.tv_nsec = 0;
   429 	year = lb.lmtime.tv_sec - 6L*30L*24L*60L*60L; /* 6 months ago */
   430 	now = lb.lmtime.tv_sec + 60;
   431 	if (isatty(1)) {
   432 		Cflg = 1;
   433 		mflg = 0;
   434 	}
   435 
   436 	while ((c = getopt_long(argc, argv,
   437 	    "+aAbBcCdeEfFghHiklLmnopqrRsStuUw:x1@vV/:%:", long_options,
   438 	    &option_index)) != -1)
   439 		switch (c) {
   440 		case 0:
   441 			/* non-short options */
   442 			if (strcmp(long_options[option_index].name,
   443 			    "color") == 0 ||
   444 			    strcmp(long_options[option_index].name,
   445 			    "colour") == 0) {
   446 				if (optarg == NULL ||
   447 				    strcmp(optarg, "always") == 0 ||
   448 				    strcmp(optarg, "yes") == 0 ||
   449 				    strcmp(optarg, "force") == 0) {
   450 					colorflg++;
   451 					statreq++;
   452 					continue;
   453 				}
   454 
   455 				if (strcmp(optarg, "auto") == 0 ||
   456 				    strcmp(optarg, "tty") == 0 ||
   457 				    strcmp(optarg, "if-tty") == 0) {
   458 					if (isatty(1) == 1) {
   459 						colorflg++;
   460 						statreq++;
   461 					}
   462 					continue;
   463 				}
   464 
   465 				if (strcmp(optarg, "never") == 0 ||
   466 				    strcmp(optarg, "no") == 0 ||
   467 				    strcmp(optarg, "none") == 0) {
   468 					colorflg = 0;
   469 					continue;
   470 				}
   471 				(void) fprintf(stderr,
   472 				    gettext("Invalid argument '%s' for "
   473 				    "--color\n"), optarg);
   474 				++opterr;
   475 				continue;
   476 			}
   477 
   478 			if (strcmp(long_options[option_index].name,
   479 			    "si") == 0) {
   480 				hflg++;
   481 				hscale = 1000;
   482 				continue;
   483 			}
   484 
   485 			if (strcmp(long_options[option_index].name,
   486 			    "block-size") == 0) {
   487 				size_t scale_len = strlen(optarg);
   488 				uint64_t scale = 1;
   489 				uint64_t kilo = 1024;
   490 				char scale_c;
   491 
   492 				if (scale_len == 0) {
   493 					(void) fprintf(stderr, gettext(
   494 					    "Invalid block size \'%s\'\n"),
   495 					    optarg);
   496 					exit(1);
   497 				}
   498 
   499 				scale_c = optarg[scale_len - 1];
   500 				if (scale_c == 'B') {
   501 					/* need at least digit, scale, B */
   502 					if (scale_len < 3) {
   503 						(void) fprintf(stderr, gettext(
   504 						    "Invalid block size "
   505 						    "\'%s\'\n"), optarg);
   506 						exit(1);
   507 					}
   508 					kilo = 1000;
   509 					scale_c = optarg[scale_len - 2];
   510 					if (isdigit(scale_c)) {
   511 						(void) fprintf(stderr,
   512 						    gettext("Invalid block size"
   513 						    " \'%s\'\n"), optarg);
   514 						exit(1);
   515 					}
   516 					/*
   517 					 * make optarg[scale_len - 1] point to
   518 					 * the scale factor
   519 					 */
   520 					--scale_len;
   521 				}
   522 
   523 				switch (scale_c) {
   524 				case 'y':
   525 				case 'Y':
   526 					scale *= kilo;
   527 					/*FALLTHROUGH*/
   528 				case 'Z':
   529 				case 'z':
   530 					scale *= kilo;
   531 					/*FALLTHROUGH*/
   532 				case 'E':
   533 				case 'e':
   534 					scale *= kilo;
   535 					/*FALLTHROUGH*/
   536 				case 'P':
   537 				case 'p':
   538 					scale *= kilo;
   539 					/*FALLTHROUGH*/
   540 				case 'T':
   541 				case 't':
   542 					scale *= kilo;
   543 					/*FALLTHROUGH*/
   544 				case 'G':
   545 				case 'g':
   546 					scale *= kilo;
   547 					/*FALLTHROUGH*/
   548 				case 'M':
   549 				case 'm':
   550 					scale *= kilo;
   551 					/*FALLTHROUGH*/
   552 				case 'K':
   553 				case 'k':
   554 					scale *= kilo;
   555 					break;
   556 				default:
   557 					if (!isdigit(scale_c)) {
   558 						(void) fprintf(stderr,
   559 						    gettext("Invalid character "
   560 						    "following block size in "
   561 						    "\'%s\'\n"), optarg);
   562 						exit(1);
   563 					}
   564 				}
   565 
   566 				/* NULL out scale constant if present */
   567 				if (scale > 1 && !isdigit(scale_c))
   568 					optarg[scale_len - 1] = '\0';
   569 
   570 				/* Based on testing, this is what GNU ls does */
   571 				block_size = strtoll(optarg, NULL, 0) * scale;
   572 				if (block_size < 1) {
   573 					(void) fprintf(stderr,
   574 					    gettext("Invalid block size "
   575 					    "\'%s\'\n"), optarg);
   576 					exit(1);
   577 				}
   578 				continue;
   579 			}
   580 
   581 			if (strcmp(long_options[option_index].name,
   582 			    "file-type") == 0) {
   583 				file_typeflg++;
   584 				Fflg++;
   585 				statreq++;
   586 				continue;
   587 			}
   588 
   589 
   590 			if (strcmp(long_options[option_index].name,
   591 			    "full-time") == 0) {
   592 				Eflg++;
   593 				statreq++;
   594 				eflg = 0;
   595 				time_fmt_old = FORMAT_ISO_FULL;
   596 				time_fmt_new = FORMAT_ISO_FULL;
   597 				continue;
   598 			}
   599 
   600 			if (strcmp(long_options[option_index].name,
   601 			    "time-style") == 0) {
   602 				/* like -E, but doesn't imply -l */
   603 				if (strcmp(optarg, "full-iso") == 0) {
   604 					Eflg++;
   605 					statreq++;
   606 					eflg = 0;
   607 					time_fmt_old = FORMAT_ISO_FULL;
   608 					time_fmt_new = FORMAT_ISO_FULL;
   609 					continue;
   610 				}
   611 				if (strcmp(optarg, "long-iso") == 0) {
   612 					statreq++;
   613 					Eflg = 0;
   614 					eflg = 0;
   615 					time_fmt_old = FORMAT_ISO_LONG;
   616 					time_fmt_new = FORMAT_ISO_LONG;
   617 					continue;
   618 				}
   619 				if (strcmp(optarg, "iso") == 0) {
   620 					statreq++;
   621 					Eflg = 0;
   622 					eflg = 0;
   623 					time_fmt_old = FORMAT_ISO_OLD;
   624 					time_fmt_new = FORMAT_ISO_NEW;
   625 					continue;
   626 				}
   627 				/* should be the default */
   628 				if (strcmp(optarg, "locale") == 0) {
   629 					time_fmt_old = FORMAT_OLD;
   630 					time_fmt_new = FORMAT_NEW;
   631 					continue;
   632 				}
   633 				if (optarg[0] == '+') {
   634 					char	*told, *tnew;
   635 					char	*p;
   636 					size_t	timelen = strlen(optarg);
   637 
   638 					p = strchr(optarg, '\n');
   639 					if (p != NULL)
   640 						*p++ = '\0';
   641 
   642 					/*
   643 					 * Time format requires a leading and
   644 					 * trailing space
   645 					 * Add room for 3 spaces + 2 nulls
   646 					 * The + in optarg is replaced with
   647 					 * a space.
   648 					 */
   649 					timelen += 2 + 3;
   650 					told = malloc(timelen);
   651 					if (told == NULL) {
   652 						perror("Out of memory");
   653 						exit(1);
   654 					}
   655 
   656 					(void) memset(told, 0, timelen);
   657 					told[0] = ' ';
   658 					(void) strlcat(told, &optarg[1],
   659 					    timelen);
   660 					(void) strlcat(told, " ", timelen);
   661 
   662 					if (p != NULL) {
   663 						size_t tnew_len;
   664 
   665 						tnew = told + strlen(told) + 1;
   666 						tnew_len = timelen -
   667 						    strlen(told) - 1;
   668 
   669 						tnew[0] = ' ';
   670 						(void) strlcat(tnew, p,
   671 						    tnew_len);
   672 						(void) strlcat(tnew, " ",
   673 						    tnew_len);
   674 						time_fmt_new =
   675 						    (const char *)tnew;
   676 					} else {
   677 						time_fmt_new =
   678 						    (const char *)told;
   679 					}
   680 
   681 					time_fmt_old = (const char *)told;
   682 					time_custom = 1;
   683 					continue;
   684 				}
   685 				continue;
   686 			}
   687 
   688 			continue;
   689 
   690 		case 'a':
   691 			aflg++;
   692 			continue;
   693 		case 'A':
   694 			Aflg++;
   695 			continue;
   696 		case 'b':
   697 			bflg = 1;
   698 			qflg = 0;
   699 			continue;
   700 		case 'B':
   701 			Bflg = 1;
   702 			continue;
   703 		case 'c':
   704 			uflg = 0;
   705 			atm = 0;
   706 			ctm = 0;
   707 			mtm = 0;
   708 			crtm = 0;
   709 			cflg++;
   710 			continue;
   711 		case 'C':
   712 			Cflg = 1;
   713 			mflg = 0;
   714 #ifdef XPG4
   715 			lflg = 0;
   716 #endif
   717 			continue;
   718 		case 'd':
   719 			dflg++;
   720 			continue;
   721 		case 'e':
   722 			eflg++;
   723 			lflg++;
   724 			statreq++;
   725 			Eflg = 0;
   726 			time_fmt_old = FORMAT_LONG;
   727 			time_fmt_new = FORMAT_LONG;
   728 			continue;
   729 		case 'E':
   730 			Eflg++;
   731 			lflg++;
   732 			statreq++;
   733 			eflg = 0;
   734 			time_fmt_old = FORMAT_ISO_FULL;
   735 			time_fmt_new = FORMAT_ISO_FULL;
   736 			continue;
   737 		case 'f':
   738 			fflg++;
   739 			continue;
   740 		case 'F':
   741 			Fflg++;
   742 			statreq++;
   743 			continue;
   744 		case 'g':
   745 			gflg++;
   746 			lflg++;
   747 			statreq++;
   748 			continue;
   749 		case 'h':
   750 			hflg++;
   751 			hscale = 1024;
   752 			continue;
   753 		case 'H':
   754 			Hflg++;
   755 			/* -H and -L are mutually exclusive */
   756 			Lflg = 0;
   757 			continue;
   758 		case 'i':
   759 			iflg++;
   760 			continue;
   761 		case 'k':
   762 			block_size = 1024;
   763 			continue;
   764 		case 'l':
   765 			lflg++;
   766 			statreq++;
   767 			Cflg = 0;
   768 			xflg = 0;
   769 			mflg = 0;
   770 			atflg = 0;
   771 			continue;
   772 		case 'L':
   773 			Lflg++;
   774 			/* -H and -L are mutually exclusive */
   775 			Hflg = 0;
   776 			continue;
   777 		case 'm':
   778 			Cflg = 0;
   779 			mflg = 1;
   780 #ifdef XPG4
   781 			lflg = 0;
   782 #endif
   783 			continue;
   784 		case 'n':
   785 			nflg++;
   786 			lflg++;
   787 			statreq++;
   788 			Cflg = 0;
   789 			xflg = 0;
   790 			mflg = 0;
   791 			atflg = 0;
   792 			continue;
   793 		case 'o':
   794 			oflg++;
   795 			lflg++;
   796 			statreq++;
   797 			continue;
   798 		case 'p':
   799 			pflg++;
   800 			statreq++;
   801 			continue;
   802 		case 'q':
   803 			qflg = 1;
   804 			bflg = 0;
   805 			continue;
   806 		case 'r':
   807 			rflg = -1;
   808 			continue;
   809 		case 'R':
   810 			Rflg++;
   811 			statreq++;
   812 			continue;
   813 		case 's':
   814 			sflg++;
   815 			statreq++;
   816 			continue;
   817 		case 'S':
   818 			tflg = 0;
   819 			Uflg = 0;
   820 			Sflg++;
   821 			statreq++;
   822 			continue;
   823 		case 't':
   824 			Sflg = 0;
   825 			Uflg = 0;
   826 			tflg++;
   827 			statreq++;
   828 			continue;
   829 		case 'U':
   830 			Sflg = 0;
   831 			tflg = 0;
   832 			Uflg++;
   833 			continue;
   834 		case 'u':
   835 			cflg = 0;
   836 			atm = 0;
   837 			ctm = 0;
   838 			mtm = 0;
   839 			crtm = 0;
   840 			uflg++;
   841 			continue;
   842 		case 'V':
   843 			Vflg++;
   844 			/*FALLTHROUGH*/
   845 		case 'v':
   846 			vflg++;
   847 #if !defined(XPG4)
   848 			if (lflg)
   849 				continue;
   850 #endif
   851 			lflg++;
   852 			statreq++;
   853 			Cflg = 0;
   854 			xflg = 0;
   855 			mflg = 0;
   856 			continue;
   857 		case 'w':
   858 			wflg++;
   859 			num_cols = atoi(optarg);
   860 			continue;
   861 		case 'x':
   862 			xflg = 1;
   863 			Cflg = 1;
   864 			mflg = 0;
   865 #ifdef XPG4
   866 			lflg = 0;
   867 #endif
   868 			continue;
   869 		case '1':
   870 			Cflg = 0;
   871 			continue;
   872 		case '@':
   873 #if !defined(XPG4)
   874 			/*
   875 			 * -l has precedence over -@
   876 			 */
   877 			if (lflg)
   878 				continue;
   879 #endif
   880 			atflg++;
   881 			lflg++;
   882 			statreq++;
   883 			Cflg = 0;
   884 			xflg = 0;
   885 			mflg = 0;
   886 			continue;
   887 		case '/':
   888 			saflg++;
   889 			if (optarg != NULL) {
   890 				if (strcmp(optarg, "c") == 0) {
   891 					copt++;
   892 					vopt = 0;
   893 				} else if (strcmp(optarg, "v") == 0) {
   894 					vopt++;
   895 					copt = 0;
   896 				} else
   897 					opterr++;
   898 			} else
   899 				opterr++;
   900 			lflg++;
   901 			statreq++;
   902 			Cflg = 0;
   903 			xflg = 0;
   904 			mflg = 0;
   905 			continue;
   906 		case '%':
   907 			tmflg++;
   908 			if (optarg != NULL) {
   909 				if (strcmp(optarg, "ctime") == 0) {
   910 					ctm++;
   911 					atm = 0;
   912 					mtm = 0;
   913 					crtm = 0;
   914 				} else if (strcmp(optarg, "atime") == 0) {
   915 					atm++;
   916 					ctm = 0;
   917 					mtm = 0;
   918 					crtm = 0;
   919 					uflg = 0;
   920 					cflg = 0;
   921 				} else if (strcmp(optarg, "mtime") == 0) {
   922 					mtm++;
   923 					atm = 0;
   924 					ctm = 0;
   925 					crtm = 0;
   926 					uflg = 0;
   927 					cflg = 0;
   928 				} else if (strcmp(optarg, "crtime") == 0) {
   929 					crtm++;
   930 					atm = 0;
   931 					ctm = 0;
   932 					mtm = 0;
   933 					uflg = 0;
   934 					cflg = 0;
   935 				} else if (strcmp(optarg, "all") == 0) {
   936 					alltm++;
   937 					atm = 0;
   938 					ctm = 0;
   939 					mtm = 0;
   940 					crtm = 0;
   941 				} else
   942 					opterr++;
   943 			} else
   944 				opterr++;
   945 
   946 			Sflg = 0;
   947 			statreq++;
   948 			mflg = 0;
   949 			continue;
   950 		case '?':
   951 			opterr++;
   952 			continue;
   953 		}
   954 
   955 	if (opterr) {
   956 		(void) fprintf(stderr, gettext(
   957 		    "usage: ls -aAbBcCdeEfFghHiklLmnopqrRsStuUwxvV1@/%[c | v]"
   958 		    "%%[atime | crtime | ctime | mtime | all]"
   959 		    " [files]\n"));
   960 		exit(2);
   961 	}
   962 
   963 	if (fflg) {
   964 		aflg++;
   965 		lflg = 0;
   966 		sflg = 0;
   967 		tflg = 0;
   968 		Sflg = 0;
   969 		statreq = 0;
   970 	}
   971 
   972 	fixedwidth = 2;
   973 	if (pflg || Fflg)
   974 		fixedwidth++;
   975 	if (iflg)
   976 		fixedwidth += 11;
   977 	if (sflg)
   978 		fixedwidth += 5;
   979 
   980 	if (lflg) {
   981 		if (!gflg && !oflg)
   982 			gflg = oflg = 1;
   983 		else
   984 		if (gflg && oflg)
   985 			gflg = oflg = 0;
   986 		Cflg = mflg = 0;
   987 	}
   988 
   989 	if (!wflg && (Cflg || mflg)) {
   990 		char *clptr;
   991 		if ((clptr = getenv("COLUMNS")) != NULL)
   992 			num_cols = atoi(clptr);
   993 #ifdef TERMINFO
   994 		else {
   995 			if (ioctl(1, TIOCGWINSZ, &win) != -1)
   996 				num_cols = (win.ws_col == 0 ? 80 : win.ws_col);
   997 		}
   998 #endif
   999 	}
  1000 
  1001 	if (num_cols < 20 || num_cols > 1000)
  1002 		/* assume it is an error */
  1003 		num_cols = 80;
  1004 
  1005 	/* allocate space for flist and the associated	*/
  1006 	/* data structures (lbufs)			*/
  1007 	maxfils = quantn;
  1008 	if (((flist = malloc(maxfils * sizeof (struct lbuf *))) == NULL) ||
  1009 	    ((nxtlbf = malloc(quantn * sizeof (struct lbuf))) == NULL)) {
  1010 		perror("ls");
  1011 		exit(2);
  1012 	}
  1013 	if ((amino = (argc-optind)) == 0) {
  1014 					/*
  1015 					 * case when no names are given
  1016 					 * in ls-command and current
  1017 					 * directory is to be used
  1018 					 */
  1019 		argv[optind] = dotp;
  1020 	}
  1021 
  1022 	for (i = 0; i < (amino ? amino : 1); i++) {
  1023 
  1024 		/*
  1025 		 * If we are recursing, we need to make sure we don't
  1026 		 * get into an endless loop.  To keep track of the inodes
  1027 		 * (actually, just the directories) visited, we
  1028 		 * maintain a directory ancestry list for a file
  1029 		 * hierarchy.  As we go deeper into the hierarchy,
  1030 		 * a parent directory passes its directory list
  1031 		 * info (device id, inode number, and a pointer to
  1032 		 * its parent) to each of its children.  As we
  1033 		 * process a child that is a directory, we save
  1034 		 * its own personal directory list info.  We then
  1035 		 * check to see if the child has already been
  1036 		 * processed by comparing its device id and inode
  1037 		 * number from its own personal directory list info
  1038 		 * to that of each of its ancestors.  If there is a
  1039 		 * match, then we know we've detected a cycle.
  1040 		 */
  1041 		if (Rflg) {
  1042 			/*
  1043 			 * This is the first parent in this lineage
  1044 			 * (first in a directory hierarchy), so
  1045 			 * this parent's parent doesn't exist.  We
  1046 			 * only initialize myinfo when we are
  1047 			 * recursing, otherwise it's not used.
  1048 			 */
  1049 			if ((myinfo = (struct ditem *)malloc(
  1050 			    sizeof (struct ditem))) == NULL) {
  1051 				perror("ls");
  1052 				exit(2);
  1053 			} else {
  1054 				myinfo->dev = 0;
  1055 				myinfo->ino = 0;
  1056 				myinfo->parent = NULL;
  1057 			}
  1058 		}
  1059 
  1060 		if (Cflg || mflg) {
  1061 			width = strcol((unsigned char *)argv[optind]);
  1062 			if (width > filewidth)
  1063 				filewidth = width;
  1064 		}
  1065 		if ((ep = gstat((*argv[optind] ? argv[optind] : dotp),
  1066 		    1, myinfo)) == NULL) {
  1067 			if (nomocore)
  1068 				exit(2);
  1069 			err = 2;
  1070 			optind++;
  1071 			continue;
  1072 		}
  1073 		ep->ln.namep = (*argv[optind] ? argv[optind] : dotp);
  1074 		ep->lflags |= ISARG;
  1075 		optind++;
  1076 		nargs++;	/* count good arguments stored in flist */
  1077 		if (acl_err)
  1078 			err = 2;
  1079 	}
  1080 	colwidth = fixedwidth + filewidth;
  1081 	if (!Uflg)
  1082 		qsort(flist, (unsigned)nargs, sizeof (struct lbuf *),
  1083 		    (int (*)(const void *, const void *))compar);
  1084 	for (i = 0; i < nargs; i++) {
  1085 		if (flist[i]->ltype == 'd' && dflg == 0 || fflg)
  1086 			break;
  1087 	}
  1088 
  1089 	if (colorflg)
  1090 		ls_color_init();
  1091 
  1092 	pem(&flist[0], &flist[i], 0);
  1093 	for (; i < nargs; i++) {
  1094 		pdirectory(flist[i]->ln.namep, Rflg ||
  1095 		    (amino > 1), nargs, 0, flist[i]->ancinfo);
  1096 		if (nomocore)
  1097 			exit(2);
  1098 		/* -R: print subdirectories found */
  1099 		while (dfirst || cdfirst) {
  1100 			/* Place direct subdirs on front in right order */
  1101 			while (cdfirst) {
  1102 				/* reverse cdfirst onto front of dfirst */
  1103 				dtemp = cdfirst;
  1104 				cdfirst = cdfirst -> dc_next;
  1105 				dtemp -> dc_next = dfirst;
  1106 				dfirst = dtemp;
  1107 			}
  1108 			/* take off first dir on dfirst & print it */
  1109 			dtemp = dfirst;
  1110 			dfirst = dfirst->dc_next;
  1111 			pdirectory(dtemp->dc_name, 1, nargs,
  1112 			    dtemp->cycle_detected, dtemp->myancinfo);
  1113 			if (nomocore)
  1114 				exit(2);
  1115 			free(dtemp->dc_name);
  1116 			free(dtemp);
  1117 		}
  1118 	}
  1119 
  1120 	return (err);
  1121 }
  1122 
  1123 /*
  1124  * pdirectory: print the directory name, labelling it if title is
  1125  * nonzero, using lp as the place to start reading in the dir.
  1126  */
  1127 static void
  1128 pdirectory(char *name, int title, int lp, int cdetect, struct ditem *myinfo)
  1129 {
  1130 	struct dchain *dp;
  1131 	struct lbuf *ap;
  1132 	char *pname;
  1133 	int j;
  1134 
  1135 	filewidth = 0;
  1136 	curdir = name;
  1137 	if (title) {
  1138 		if (!first)
  1139 			(void) putc('\n', stdout);
  1140 		pprintf(name, ":");
  1141 		new_line();
  1142 	}
  1143 	/*
  1144 	 * If there was a cycle detected, then notify and don't report
  1145 	 * further.
  1146 	 */
  1147 	if (cdetect) {
  1148 		if (lflg || sflg) {
  1149 			curcol += printf(gettext("total %d"), 0);
  1150 			new_line();
  1151 		}
  1152 		(void) fprintf(stderr, gettext(
  1153 		    "ls: cycle detected for %s\n"), name);
  1154 		return;
  1155 	}
  1156 
  1157 	nfiles = lp;
  1158 	rddir(name, myinfo);
  1159 	if (nomocore)
  1160 		return;
  1161 	if (fflg == 0 && Uflg == 0)
  1162 		qsort(&flist[lp], (unsigned)(nfiles - lp),
  1163 		    sizeof (struct lbuf *),
  1164 		    (int (*)(const void *, const void *))compar);
  1165 	if (Rflg) {
  1166 		for (j = nfiles - 1; j >= lp; j--) {
  1167 			ap = flist[j];
  1168 			if (ap->ltype == 'd' && strcmp(ap->ln.lname, ".") &&
  1169 			    strcmp(ap->ln.lname, "..")) {
  1170 				dp = malloc(sizeof (struct dchain));
  1171 				if (dp == NULL) {
  1172 					perror("ls");
  1173 					exit(2);
  1174 				}
  1175 				pname = makename(curdir, ap->ln.lname);
  1176 				if ((dp->dc_name = strdup(pname)) == NULL) {
  1177 					perror("ls");
  1178 					exit(2);
  1179 				}
  1180 				dp->cycle_detected = ap->cycle;
  1181 				dp->myancinfo = ap->ancinfo;
  1182 				dp->dc_next = dfirst;
  1183 				dfirst = dp;
  1184 			}
  1185 		}
  1186 	}
  1187 	if (lflg || sflg) {
  1188 		curcol += printf(gettext("total %llu"), tblocks);
  1189 		new_line();
  1190 	}
  1191 	pem(&flist[lp], &flist[nfiles], lflg||sflg);
  1192 }
  1193 
  1194 /*
  1195  * pem: print 'em. Print a list of files (e.g. a directory) bounded
  1196  * by slp and lp.
  1197  */
  1198 static void
  1199 pem(struct lbuf **slp, struct lbuf **lp, int tot_flag)
  1200 {
  1201 	long row, nrows, i;
  1202 	int col, ncols;
  1203 	struct lbuf **ep;
  1204 
  1205 	if (Cflg || mflg) {
  1206 		if (colwidth > num_cols) {
  1207 			ncols = 1;
  1208 		} else {
  1209 			ncols = num_cols / colwidth;
  1210 		}
  1211 	}
  1212 
  1213 	if (ncols == 1 || mflg || xflg || !Cflg) {
  1214 		for (ep = slp; ep < lp; ep++)
  1215 			pentry(*ep);
  1216 		new_line();
  1217 		return;
  1218 	}
  1219 	/* otherwise print -C columns */
  1220 	if (tot_flag) {
  1221 		slp--;
  1222 		row = 1;
  1223 	}
  1224 	else
  1225 		row = 0;
  1226 
  1227 	nrows = (lp - slp - 1) / ncols + 1;
  1228 	for (i = 0; i < nrows; i++, row++) {
  1229 		for (col = 0; col < ncols; col++) {
  1230 			ep = slp + (nrows * col) + row;
  1231 			if (ep < lp)
  1232 				pentry(*ep);
  1233 		}
  1234 		new_line();
  1235 	}
  1236 }
  1237 
  1238 /*
  1239  * print one output entry;
  1240  * if uid/gid is not found in the appropriate
  1241  * file(passwd/group), then print uid/gid instead of
  1242  * user/group name;
  1243  */
  1244 static void
  1245 pentry(struct lbuf *ap)
  1246 {
  1247 	struct lbuf *p;
  1248 	numbuf_t hbuf;
  1249 	char *dmark = "";	/* Used if -p or -F option active */
  1250 	char *cp;
  1251 	char *str;
  1252 
  1253 	p = ap;
  1254 	column();
  1255 	if (iflg)
  1256 		if (mflg && !lflg)
  1257 			curcol += printf("%llu ", (long long)p->lnum);
  1258 		else
  1259 			curcol += printf("%10llu ", (long long)p->lnum);
  1260 	if (sflg)
  1261 		curcol += printf((mflg && !lflg) ? "%lld " :
  1262 		    (p->lblocks < 10000) ? "%4lld " : "%lld ",
  1263 		    (p->ltype != 'b' && p->ltype != 'c') ?
  1264 		    p->lblocks : 0LL);
  1265 	if (lflg) {
  1266 		(void) putchar(p->ltype);
  1267 		curcol++;
  1268 		pmode(p->lflags);
  1269 
  1270 		/* ACL: additional access mode flag */
  1271 		(void) putchar(p->acl);
  1272 		curcol++;
  1273 
  1274 		curcol += printf("%3lu ", (ulong_t)p->lnl);
  1275 		if (oflg)
  1276 			if (!nflg) {
  1277 				cp = getname(p->luid);
  1278 				curcol += printf("%-8s ", cp);
  1279 			} else
  1280 				curcol += printf("%-8lu ", (ulong_t)p->luid);
  1281 		if (gflg)
  1282 			if (!nflg) {
  1283 				cp = getgroup(p->lgid);
  1284 				curcol += printf("%-8s ", cp);
  1285 			} else
  1286 				curcol += printf("%-8lu ", (ulong_t)p->lgid);
  1287 		if (p->ltype == 'b' || p->ltype == 'c') {
  1288 			curcol += printf("%3u, %2u",
  1289 			    (uint_t)major((dev_t)p->lsize),
  1290 			    (uint_t)minor((dev_t)p->lsize));
  1291 		} else if (hflg && (p->lsize >= hscale)) {
  1292 			curcol += printf("%7s",
  1293 			    number_to_scaled_string(hbuf, p->lsize, hscale));
  1294 		} else {
  1295 			uint64_t bsize = p->lsize / block_size;
  1296 
  1297 			/*
  1298 			 * Round up only when using blocks > 1 byte, otherwise
  1299 			 * 'normal' sizes display 1 byte too large.
  1300 			 */
  1301 			if (p->lsize % block_size != 0)
  1302 				bsize++;
  1303 
  1304 			curcol += printf("%7" PRIu64, bsize);
  1305 		}
  1306 		format_time(p->lmtime.tv_sec, p->lmtime.tv_nsec);
  1307 		/* format extended system attribute time */
  1308 		if (tmflg && crtm)
  1309 			format_attrtime(p);
  1310 
  1311 		curcol += printf("%s", time_buf);
  1312 
  1313 	}
  1314 	/*
  1315 	 * prevent both "->" and trailing marks
  1316 	 * from appearing
  1317 	 */
  1318 
  1319 	if (pflg && p->ltype == 'd')
  1320 		dmark = "/";
  1321 
  1322 	if (Fflg && !(lflg && p->flinkto)) {
  1323 		if (p->ltype == 'd')
  1324 			dmark = "/";
  1325 		else if (p->ltype == 'D')
  1326 			dmark = ">";
  1327 		else if (p->ltype == 'p')
  1328 			dmark = "|";
  1329 		else if (p->ltype == 'l')
  1330 			dmark = "@";
  1331 		else if (p->ltype == 's')
  1332 			dmark = "=";
  1333 		else if (!file_typeflg &&
  1334 		    (p->lflags & (S_IXUSR|S_IXGRP|S_IXOTH)))
  1335 			dmark = "*";
  1336 		else
  1337 			dmark = "";
  1338 	}
  1339 
  1340 	if (colorflg)
  1341 		ls_start_color(p->color);
  1342 
  1343 	if (p->lflags & ISARG)
  1344 		str = p->ln.namep;
  1345 	else
  1346 		str = p->ln.lname;
  1347 
  1348 	if (qflg || bflg) {
  1349 		csi_pprintf((unsigned char *)str);
  1350 
  1351 		if (lflg && p->flinkto) {
  1352 			if (colorflg)
  1353 				ls_end_color();
  1354 			csi_pprintf((unsigned char *)" -> ");
  1355 			if (colorflg)
  1356 				ls_start_color(p->link_color);
  1357 			csi_pprintf((unsigned char *)p->flinkto);
  1358 		} else {
  1359 			csi_pprintf((unsigned char *)dmark);
  1360 		}
  1361 	} else {
  1362 		(void) printf("%s", str);
  1363 		curcol += strcol((unsigned char *)str);
  1364 
  1365 		if (lflg && p->flinkto) {
  1366 			if (colorflg)
  1367 				ls_end_color();
  1368 			str = " -> ";
  1369 			(void) printf("%s", str);
  1370 			curcol += strcol((unsigned char *)str);
  1371 			if (colorflg)
  1372 				ls_start_color(p->link_color);
  1373 			(void) printf("%s", p->flinkto);
  1374 			curcol += strcol((unsigned char *)p->flinkto);
  1375 		} else {
  1376 			(void) printf("%s", dmark);
  1377 			curcol += strcol((unsigned char *)dmark);
  1378 		}
  1379 	}
  1380 
  1381 	if (colorflg)
  1382 		ls_end_color();
  1383 
  1384 	/* Display extended system attributes */
  1385 	if (saflg) {
  1386 		int i;
  1387 
  1388 		new_line();
  1389 		(void) printf("	\t{");
  1390 		if (p->exttr != NULL) {
  1391 			int k = 0;
  1392 			for (i = 0; i < sacnt; i++) {
  1393 				if (p->exttr[i].name != NULL)
  1394 					k++;
  1395 			}
  1396 			for (i = 0; i < sacnt; i++) {
  1397 				if (p->exttr[i].name != NULL) {
  1398 					(void) printf("%s", p->exttr[i].name);
  1399 					k--;
  1400 					if (vopt && (k != 0))
  1401 						(void) printf(",");
  1402 				}
  1403 			}
  1404 		}
  1405 		(void) printf("}\n");
  1406 	}
  1407 	/* Display file timestamps and extended system attribute timestamps */
  1408 	if (tmflg && alltm) {
  1409 		new_line();
  1410 		print_time(p);
  1411 		new_line();
  1412 	}
  1413 	if (vflg) {
  1414 		new_line();
  1415 		if (p->aclp) {
  1416 			acl_printacl(p->aclp, num_cols, Vflg);
  1417 		}
  1418 	}
  1419 	/* Free extended system attribute lists */
  1420 	if (saflg || tmflg)
  1421 		free_sysattr(p);
  1422 }
  1423 
  1424 /* print various r,w,x permissions */
  1425 static void
  1426 pmode(mode_t aflag)
  1427 {
  1428 	/* these arrays are declared static to allow initializations */
  1429 	static int	m0[] = { 1, S_IRUSR, 'r', '-' };
  1430 	static int	m1[] = { 1, S_IWUSR, 'w', '-' };
  1431 	static int	m2[] = { 3, S_ISUID|S_IXUSR, 's', S_IXUSR,
  1432 	    'x', S_ISUID, 'S', '-' };
  1433 	static int	m3[] = { 1, S_IRGRP, 'r', '-' };
  1434 	static int	m4[] = { 1, S_IWGRP, 'w', '-' };
  1435 	static int	m5[] = { 4, S_ISGID|S_IXGRP, 's', S_IXGRP,
  1436 				'x', S_ISGID|LS_NOTREG, 'S',
  1437 #ifdef XPG4
  1438 		S_ISGID, 'L', '-'};
  1439 #else
  1440 		S_ISGID, 'l', '-'};
  1441 #endif
  1442 	static int	m6[] = { 1, S_IROTH, 'r', '-' };
  1443 	static int	m7[] = { 1, S_IWOTH, 'w', '-' };
  1444 	static int	m8[] = { 3, S_ISVTX|S_IXOTH, 't', S_IXOTH,
  1445 	    'x', S_ISVTX, 'T', '-'};
  1446 
  1447 	static int *m[] = { m0, m1, m2, m3, m4, m5, m6, m7, m8};
  1448 
  1449 	int **mp;
  1450 
  1451 	flags = aflag;
  1452 	for (mp = &m[0]; mp < &m[sizeof (m) / sizeof (m[0])]; mp++)
  1453 		selection(*mp);
  1454 }
  1455 
  1456 static void
  1457 selection(int *pairp)
  1458 {
  1459 	int n;
  1460 
  1461 	n = *pairp++;
  1462 	while (n-->0) {
  1463 		if ((flags & *pairp) == *pairp) {
  1464 			pairp++;
  1465 			break;
  1466 		} else {
  1467 			pairp += 2;
  1468 		}
  1469 	}
  1470 	(void) putchar(*pairp);
  1471 	curcol++;
  1472 }
  1473 
  1474 /*
  1475  * column: get to the beginning of the next column.
  1476  */
  1477 static void
  1478 column(void)
  1479 {
  1480 	if (curcol == 0)
  1481 		return;
  1482 	if (mflg) {
  1483 		(void) putc(',', stdout);
  1484 		curcol++;
  1485 		if (curcol + colwidth + 2 > num_cols) {
  1486 			(void) putc('\n', stdout);
  1487 			curcol = 0;
  1488 			return;
  1489 		}
  1490 		(void) putc(' ', stdout);
  1491 		curcol++;
  1492 		return;
  1493 	}
  1494 	if (Cflg == 0) {
  1495 		(void) putc('\n', stdout);
  1496 		curcol = 0;
  1497 		return;
  1498 	}
  1499 	if ((curcol / colwidth + 2) * colwidth > num_cols) {
  1500 		(void) putc('\n', stdout);
  1501 		curcol = 0;
  1502 		return;
  1503 	}
  1504 	do {
  1505 		(void) putc(' ', stdout);
  1506 		curcol++;
  1507 	} while (curcol % colwidth);
  1508 }
  1509 
  1510 static void
  1511 new_line(void)
  1512 {
  1513 	if (curcol) {
  1514 		first = 0;
  1515 		(void) putc('\n', stdout);
  1516 		curcol = 0;
  1517 	}
  1518 }
  1519 
  1520 /*
  1521  * read each filename in directory dir and store its
  1522  * status in flist[nfiles]
  1523  * use makename() to form pathname dir/filename;
  1524  */
  1525 static void
  1526 rddir(char *dir, struct ditem *myinfo)
  1527 {
  1528 	struct dirent *dentry;
  1529 	DIR *dirf;
  1530 	int j;
  1531 	struct lbuf *ep;
  1532 	int width;
  1533 
  1534 	if ((dirf = opendir(dir)) == NULL) {
  1535 		(void) fflush(stdout);
  1536 		perror(dir);
  1537 		err = 2;
  1538 		return;
  1539 	} else {
  1540 		tblocks = 0;
  1541 		for (;;) {
  1542 			errno = 0;
  1543 			if ((dentry = readdir(dirf)) == NULL)
  1544 				break;
  1545 			if (aflg == 0 && dentry->d_name[0] == '.' &&
  1546 			    (Aflg == 0 ||
  1547 			    dentry->d_name[1] == '\0' ||
  1548 			    dentry->d_name[1] == '.' &&
  1549 			    dentry->d_name[2] == '\0'))
  1550 				/*
  1551 				 * check for directory items '.', '..',
  1552 				 *  and items without valid inode-number;
  1553 				 */
  1554 				continue;
  1555 
  1556 			/* skip entries ending in ~ if -B was given */
  1557 			if (Bflg &&
  1558 			    dentry->d_name[strlen(dentry->d_name) - 1] == '~')
  1559 				continue;
  1560 			if (Cflg || mflg) {
  1561 				width = strcol((unsigned char *)dentry->d_name);
  1562 				if (width > filewidth)
  1563 					filewidth = width;
  1564 			}
  1565 			ep = gstat(makename(dir, dentry->d_name), 0, myinfo);
  1566 			if (ep == NULL) {
  1567 				if (nomocore)
  1568 					exit(2);
  1569 				continue;
  1570 			} else {
  1571 				ep->lnum = dentry->d_ino;
  1572 				for (j = 0; dentry->d_name[j] != '\0'; j++)
  1573 					ep->ln.lname[j] = dentry->d_name[j];
  1574 				ep->ln.lname[j] = '\0';
  1575 			}
  1576 		}
  1577 		if (errno) {
  1578 			int sav_errno = errno;
  1579 
  1580 			(void) fprintf(stderr,
  1581 			    gettext("ls: error reading directory %s: %s\n"),
  1582 			    dir, strerror(sav_errno));
  1583 		}
  1584 		(void) closedir(dirf);
  1585 		colwidth = fixedwidth + filewidth;
  1586 	}
  1587 }
  1588 
  1589 /*
  1590  * Attaching a link to an inode's ancestors.  Search
  1591  * through the ancestors to check for cycles (an inode which
  1592  * we have already tracked in this inodes ancestry).  If a cycle
  1593  * is detected, set the exit code and record the fact so that
  1594  * it is reported at the right time when printing the directory.
  1595  * In addition, set the exit code.  Note:  If the -a flag was
  1596  * specified, we don't want to check for cycles for directories
  1597  * ending in '/.' or '/..' unless they were specified on the
  1598  * command line.
  1599  */
  1600 static void
  1601 record_ancestry(char *file, struct stat *pstatb, struct lbuf *rep,
  1602     int argfl, struct ditem *myparent)
  1603 {
  1604 	size_t		file_len;
  1605 	struct ditem	*myinfo;
  1606 	struct ditem	*tptr;
  1607 
  1608 	file_len = strlen(file);
  1609 	if (!aflg || argfl || (NOTWORKINGDIR(file, file_len) &&
  1610 	    NOTPARENTDIR(file, file_len))) {
  1611 		/*
  1612 		 * Add this inode's ancestry
  1613 		 * info and insert it into the
  1614 		 * ancestry list by pointing
  1615 		 * back to its parent.  We save
  1616 		 * it (in rep) with the other info
  1617 		 * we're gathering for this inode.
  1618 		 */
  1619 		if ((myinfo = malloc(
  1620 		    sizeof (struct ditem))) == NULL) {
  1621 			perror("ls");
  1622 			exit(2);
  1623 		}
  1624 		myinfo->dev = pstatb->st_dev;
  1625 		myinfo->ino = pstatb->st_ino;
  1626 		myinfo->parent = myparent;
  1627 		rep->ancinfo = myinfo;
  1628 
  1629 		/*
  1630 		 * If this node has the same device id and
  1631 		 * inode number of one of its ancestors,
  1632 		 * then we've detected a cycle.
  1633 		 */
  1634 		if (myparent != NULL) {
  1635 			for (tptr = myparent; tptr->parent != NULL;
  1636 			    tptr = tptr->parent) {
  1637 				if ((tptr->dev == pstatb->st_dev) &&
  1638 				    (tptr->ino == pstatb->st_ino)) {
  1639 					/*
  1640 					 * Cycle detected for this
  1641 					 * directory.  Record the fact
  1642 					 * it is a cycle so we don't
  1643 					 * try to process this
  1644 					 * directory as we are
  1645 					 * walking through the
  1646 					 * list of directories.
  1647 					 */
  1648 					rep->cycle = 1;
  1649 					err = 2;
  1650 					break;
  1651 				}
  1652 			}
  1653 		}
  1654 	}
  1655 }
  1656 
  1657 /*
  1658  * Do re-calculate the mode for group for ACE_T type of acls.
  1659  * This is because, if the server's FS happens to be UFS, supporting
  1660  * POSIX ACL's, then it does a special calculation of group mode
  1661  * to be the bitwise OR of CLASS_OBJ and GROUP_OBJ (see PSARC/2001/717.)
  1662  *
  1663  * This algorithm is from the NFSv4 ACL Draft. Here a part of that
  1664  * algorithm is used for the group mode calculation only.
  1665  * What is modified here from the algorithm is that only the
  1666  * entries with flags ACE_GROUP are considered. For each entry
  1667  * with ACE_GROUP flag, the first occurance of a specific access
  1668  * is checked if it is allowed.
  1669  * We are not interested in perms for user and other, as they
  1670  * were taken from st_mode value.
  1671  * We are not interested in a_who field of ACE, as we need just
  1672  * unix mode bits for the group.
  1673  */
  1674 
  1675 #define	OWNED_GROUP	(ACE_GROUP | ACE_IDENTIFIER_GROUP)
  1676 #define	IS_TYPE_ALLOWED(type)	((type) == ACE_ACCESS_ALLOWED_ACE_TYPE)
  1677 
  1678 int
  1679 grp_mask_to_mode(struct lbuf *p)
  1680 {
  1681 	int mode = 0, seen = 0;
  1682 	int acecnt;
  1683 	int flags;
  1684 	ace_t *ap;
  1685 	acl_t *acep = p->aclp;
  1686 
  1687 	acecnt = acl_cnt(acep);
  1688 	for (ap = (ace_t *)acl_data(acep); acecnt--; ap++) {
  1689 
  1690 		if (ap->a_type != ACE_ACCESS_ALLOWED_ACE_TYPE &&
  1691 		    ap->a_type != ACE_ACCESS_DENIED_ACE_TYPE)
  1692 			continue;
  1693 
  1694 		if (ap->a_flags & ACE_INHERIT_ONLY_ACE)
  1695 			continue;
  1696 
  1697 		/*
  1698 		 * if it is first group@ or first everyone@
  1699 		 * for each of read, write and execute, then
  1700 		 * that will be the group mode bit.
  1701 		 */
  1702 		flags = ap->a_flags & ACE_TYPE_FLAGS;
  1703 		if (flags == OWNED_GROUP || (flags == ACE_IDENTIFIER_GROUP &&
  1704 		    ap->a_who == p->lgid) || flags == ACE_EVERYONE) {
  1705 			if (ap->a_access_mask & ACE_READ_DATA) {
  1706 				if (!(seen & S_IRGRP)) {
  1707 					seen |= S_IRGRP;
  1708 					if (IS_TYPE_ALLOWED(ap->a_type))
  1709 						mode |= S_IRGRP;
  1710 				}
  1711 			}
  1712 			if (ap->a_access_mask & ACE_WRITE_DATA) {
  1713 				if (!(seen & S_IWGRP)) {
  1714 					seen |= S_IWGRP;
  1715 					if (IS_TYPE_ALLOWED(ap->a_type))
  1716 						mode |= S_IWGRP;
  1717 				}
  1718 			}
  1719 			if (ap->a_access_mask & ACE_EXECUTE) {
  1720 				if (!(seen & S_IXGRP)) {
  1721 					seen |= S_IXGRP;
  1722 					if (IS_TYPE_ALLOWED(ap->a_type))
  1723 						mode |= S_IXGRP;
  1724 				}
  1725 			}
  1726 		}
  1727 	}
  1728 	return (mode);
  1729 }
  1730 
  1731 /*
  1732  * get status of file and recomputes tblocks;
  1733  * argfl = 1 if file is a name in ls-command and = 0
  1734  * for filename in a directory whose name is an
  1735  * argument in the command;
  1736  * stores a pointer in flist[nfiles] and
  1737  * returns that pointer;
  1738  * returns NULL if failed;
  1739  */
  1740 static struct lbuf *
  1741 gstat(char *file, int argfl, struct ditem *myparent)
  1742 {
  1743 	struct stat statb, statb1;
  1744 	struct lbuf *rep;
  1745 	char buf[BUFSIZ];
  1746 	ssize_t cc;
  1747 	int (*statf)() = ((Lflg) || (Hflg && argfl)) ? stat : lstat;
  1748 	int aclcnt;
  1749 	int error;
  1750 	aclent_t *tp;
  1751 	o_mode_t groupperm, mask;
  1752 	int grouppermfound, maskfound;
  1753 
  1754 	if (nomocore)
  1755 		return (NULL);
  1756 
  1757 	if (nfiles >= maxfils) {
  1758 		/*
  1759 		 * all flist/lbuf pair assigned files, time to get some
  1760 		 * more space
  1761 		 */
  1762 		maxfils += quantn;
  1763 		if (((flist = realloc(flist,
  1764 		    maxfils * sizeof (struct lbuf *))) == NULL) ||
  1765 		    ((nxtlbf = malloc(quantn *
  1766 		    sizeof (struct lbuf))) == NULL)) {
  1767 			perror("ls");
  1768 			nomocore = 1;
  1769 			return (NULL);
  1770 		}
  1771 	}
  1772 
  1773 	/*
  1774 	 * nfiles is reset to nargs for each directory
  1775 	 * that is given as an argument maxn is checked
  1776 	 * to prevent the assignment of an lbuf to a flist entry
  1777 	 * that already has one assigned.
  1778 	 */
  1779 	if (nfiles >= maxn) {
  1780 		rep = nxtlbf++;
  1781 		flist[nfiles++] = rep;
  1782 		maxn = nfiles;
  1783 	} else {
  1784 		rep = flist[nfiles++];
  1785 	}
  1786 
  1787 	/* Initialize */
  1788 
  1789 	rep->lflags = (mode_t)0;
  1790 	rep->flinkto = NULL;
  1791 	rep->cycle = 0;
  1792 	rep->lat.tv_sec = time(NULL);
  1793 	rep->lat.tv_nsec = 0;
  1794 	rep->lct.tv_sec = time(NULL);
  1795 	rep->lct.tv_nsec = 0;
  1796 	rep->lmt.tv_sec = time(NULL);
  1797 	rep->lmt.tv_nsec = 0;
  1798 	rep->exttr = NULL;
  1799 	rep->extm = NULL;
  1800 	rep->color = NULL;
  1801 	rep->link_color = NULL;
  1802 
  1803 	if (argfl || statreq) {
  1804 		int doacl;
  1805 
  1806 		if (lflg)
  1807 			doacl = 1;
  1808 		else
  1809 			doacl = 0;
  1810 
  1811 		if ((*statf)(file, &statb) < 0) {
  1812 			if (argfl || errno != ENOENT ||
  1813 			    (Lflg && lstat(file, &statb) == 0)) {
  1814 				/*
  1815 				 * Avoid race between readdir and lstat.
  1816 				 * Print error message in case of dangling link.
  1817 				 */
  1818 				perror(file);
  1819 				err = 2;
  1820 			}
  1821 			nfiles--;
  1822 			return (NULL);
  1823 		}
  1824 
  1825 		/*
  1826 		 * If -H was specified, and the file linked to was
  1827 		 * not a directory, then we need to get the info
  1828 		 * for the symlink itself.
  1829 		 */
  1830 		if ((Hflg) && (argfl) &&
  1831 		    ((statb.st_mode & S_IFMT) != S_IFDIR)) {
  1832 			if (lstat(file, &statb) < 0) {
  1833 				perror(file);
  1834 				err = 2;
  1835 			}
  1836 		}
  1837 
  1838 		rep->lnum = statb.st_ino;
  1839 		rep->lsize = statb.st_size;
  1840 		rep->lblocks = statb.st_blocks;
  1841 		if (colorflg)
  1842 			rep->color = ls_color_find(file, statb.st_mode);
  1843 
  1844 		switch (statb.st_mode & S_IFMT) {
  1845 		case S_IFDIR:
  1846 			rep->ltype = 'd';
  1847 			if (Rflg) {
  1848 				record_ancestry(file, &statb, rep,
  1849 				    argfl, myparent);
  1850 			}
  1851 			break;
  1852 		case S_IFBLK:
  1853 			rep->ltype = 'b';
  1854 			rep->lsize = (off_t)statb.st_rdev;
  1855 			break;
  1856 		case S_IFCHR:
  1857 			rep->ltype = 'c';
  1858 			rep->lsize = (off_t)statb.st_rdev;
  1859 			break;
  1860 		case S_IFIFO:
  1861 			rep->ltype = 'p';
  1862 			break;
  1863 		case S_IFSOCK:
  1864 			rep->ltype = 's';
  1865 			rep->lsize = 0;
  1866 			break;
  1867 		case S_IFLNK:
  1868 			/* symbolic links may not have ACLs, so elide acl() */
  1869 			if ((Lflg == 0) || (Hflg == 0) ||
  1870 			    ((Hflg) && (!argfl))) {
  1871 				doacl = 0;
  1872 			}
  1873 			rep->ltype = 'l';
  1874 			if (lflg || colorflg) {
  1875 				cc = readlink(file, buf, BUFSIZ);
  1876 				if (cc < 0)
  1877 					break;
  1878 
  1879 				/*
  1880 				 * follow the symbolic link
  1881 				 * to generate the appropriate
  1882 				 * Fflg marker for the object
  1883 				 * eg, /bin -> /sym/bin/
  1884 				 */
  1885 				error = 0;
  1886 				if (Fflg || pflg || colorflg)
  1887 					error = stat(file, &statb1);
  1888 
  1889 				if (colorflg) {
  1890 					if (error >= 0)
  1891 						rep->link_color =
  1892 						    ls_color_find(file,
  1893 						    statb1.st_mode);
  1894 					else
  1895 						rep->link_color =
  1896 						    lsc_orphan;
  1897 				}
  1898 
  1899 				if ((Fflg || pflg) && error >= 0) {
  1900 					switch (statb1.st_mode & S_IFMT) {
  1901 					case S_IFDIR:
  1902 						buf[cc++] = '/';
  1903 						break;
  1904 					case S_IFSOCK:
  1905 						buf[cc++] = '=';
  1906 						break;
  1907 					case S_IFDOOR:
  1908 						buf[cc++] = '>';
  1909 						break;
  1910 					case S_IFIFO:
  1911 						buf[cc++] = '|';
  1912 						break;
  1913 					default:
  1914 						if ((statb1.st_mode & ~S_IFMT) &
  1915 						    (S_IXUSR|S_IXGRP| S_IXOTH))
  1916 							buf[cc++] = '*';
  1917 						break;
  1918 					}
  1919 				}
  1920 				buf[cc] = '\0';
  1921 				rep->flinkto = strdup(buf);
  1922 				break;
  1923 			}
  1924 
  1925 			/*
  1926 			 * ls /sym behaves differently from ls /sym/
  1927 			 * when /sym is a symbolic link. This is fixed
  1928 			 * when explicit arguments are specified.
  1929 			 */
  1930 
  1931 #ifdef XPG6
  1932 			/* Do not follow a symlink when -F is specified */
  1933 			if ((!argfl) || (argfl && Fflg) ||
  1934 			    (stat(file, &statb1) < 0))
  1935 #else
  1936 			/* Follow a symlink when -F is specified */
  1937 			if (!argfl || stat(file, &statb1) < 0)
  1938 #endif /* XPG6 */
  1939 				break;
  1940 			if ((statb1.st_mode & S_IFMT) == S_IFDIR) {
  1941 				statb = statb1;
  1942 				rep->ltype = 'd';
  1943 				rep->lsize = statb1.st_size;
  1944 				if (Rflg) {
  1945 					record_ancestry(file, &statb, rep,
  1946 					    argfl, myparent);
  1947 				}
  1948 			}
  1949 			break;
  1950 		case S_IFDOOR:
  1951 			rep->ltype = 'D';
  1952 			break;
  1953 		case S_IFREG:
  1954 			rep->ltype = '-';
  1955 			break;
  1956 		case S_IFPORT:
  1957 			rep->ltype = 'P';
  1958 			break;
  1959 		default:
  1960 			rep->ltype = '?';
  1961 			break;
  1962 		}
  1963 		rep->lflags = statb.st_mode & ~S_IFMT;
  1964 
  1965 		if (!S_ISREG(statb.st_mode))
  1966 			rep->lflags |= LS_NOTREG;
  1967 
  1968 		rep->luid = statb.st_uid;
  1969 		rep->lgid = statb.st_gid;
  1970 		rep->lnl = statb.st_nlink;
  1971 		if (uflg || (tmflg && atm))
  1972 			rep->lmtime = statb.st_atim;
  1973 		else if (cflg || (tmflg && ctm))
  1974 			rep->lmtime = statb.st_ctim;
  1975 		else
  1976 			rep->lmtime = statb.st_mtim;
  1977 		rep->lat = statb.st_atim;
  1978 		rep->lct = statb.st_ctim;
  1979 		rep->lmt = statb.st_mtim;
  1980 
  1981 		/* ACL: check acl entries count */
  1982 		if (doacl) {
  1983 
  1984 			error = acl_get(file, 0, &rep->aclp);
  1985 			if (error) {
  1986 				(void) fprintf(stderr,
  1987 				    gettext("ls: can't read ACL on %s: %s\n"),
  1988 				    file, acl_strerror(error));
  1989 				rep->acl = ' ';
  1990 				acl_err++;
  1991 				return (rep);
  1992 			}
  1993 
  1994 			rep->acl = ' ';
  1995 
  1996 			if (rep->aclp &&
  1997 			    ((acl_flags(rep->aclp) & ACL_IS_TRIVIAL) == 0)) {
  1998 				rep->acl = '+';
  1999 				/*
  2000 				 * Special handling for ufs aka aclent_t ACL's
  2001 				 */
  2002 				if (acl_type(rep->aclp) == ACLENT_T) {
  2003 					/*
  2004 					 * For files with non-trivial acls, the
  2005 					 * effective group permissions are the
  2006 					 * intersection of the GROUP_OBJ value
  2007 					 * and the CLASS_OBJ (acl mask) value.
  2008 					 * Determine both the GROUP_OBJ and
  2009 					 * CLASS_OBJ for this file and insert
  2010 					 * the logical AND of those two values
  2011 					 * in the group permissions field
  2012 					 * of the lflags value for this file.
  2013 					 */
  2014 
  2015 					/*
  2016 					 * Until found in acl list, assume
  2017 					 * maximum permissions for both group
  2018 					 * a nd mask.  (Just in case the acl
  2019 					 * lacks either value for some reason.)
  2020 					 */
  2021 					groupperm = 07;
  2022 					mask = 07;
  2023 					grouppermfound = 0;
  2024 					maskfound = 0;
  2025 					aclcnt = acl_cnt(rep->aclp);
  2026 					for (tp =
  2027 					    (aclent_t *)acl_data(rep->aclp);
  2028 					    aclcnt--; tp++) {
  2029 						if (tp->a_type == GROUP_OBJ) {
  2030 							groupperm = tp->a_perm;
  2031 							grouppermfound = 1;
  2032 							continue;
  2033 						}
  2034 						if (tp->a_type == CLASS_OBJ) {
  2035 							mask = tp->a_perm;
  2036 							maskfound = 1;
  2037 						}
  2038 						if (grouppermfound && maskfound)
  2039 							break;
  2040 					}
  2041 
  2042 
  2043 					/* reset all the group bits */
  2044 					rep->lflags &= ~S_IRWXG;
  2045 
  2046 					/*
  2047 					 * Now set them to the logical AND of
  2048 					 * the GROUP_OBJ permissions and the
  2049 					 * acl mask.
  2050 					 */
  2051 
  2052 					rep->lflags |= (groupperm & mask) << 3;
  2053 
  2054 				} else if (acl_type(rep->aclp) == ACE_T) {
  2055 					int mode;
  2056 					mode = grp_mask_to_mode(rep);
  2057 					rep->lflags &= ~S_IRWXG;
  2058 					rep->lflags |= mode;
  2059 				}
  2060 			}
  2061 
  2062 			if (!vflg && !Vflg && rep->aclp) {
  2063 				acl_free(rep->aclp);
  2064 				rep->aclp = NULL;
  2065 			}
  2066 
  2067 			if (atflg && pathconf(file, _PC_XATTR_EXISTS) == 1)
  2068 				rep->acl = '@';
  2069 
  2070 		} else
  2071 			rep->acl = ' ';
  2072 
  2073 		/* mask ISARG and other file-type bits */
  2074 
  2075 		if (rep->ltype != 'b' && rep->ltype != 'c')
  2076 			tblocks += rep->lblocks;
  2077 
  2078 		/* Get extended system attributes */
  2079 
  2080 		if ((saflg || (tmflg && crtm) || (tmflg && alltm)) &&
  2081 		    (sysattr_support(file, _PC_SATTR_EXISTS) == 1)) {
  2082 			int i;
  2083 
  2084 			sacnt = attr_count();
  2085 			/*
  2086 			 * Allocate 'sacnt' size array to hold extended
  2087 			 * system attribute name (verbose) or respective
  2088 			 * symbol represenation (compact).
  2089 			 */
  2090 			rep->exttr = xmalloc(sacnt * sizeof (struct attrb),
  2091 			    rep);
  2092 
  2093 			/* initialize boolean attribute list */
  2094 			for (i = 0; i < sacnt; i++)
  2095 				rep->exttr[i].name = NULL;
  2096 			if (get_sysxattr(file, rep) != 0) {
  2097 				(void) fprintf(stderr,
  2098 				    gettext("ls:Failed to retrieve "
  2099 				    "extended system attribute from "
  2100 				    "%s\n"), file);
  2101 				rep->exttr[0].name = xmalloc(2, rep);
  2102 				(void) strlcpy(rep->exttr[0].name, "?", 2);
  2103 			}
  2104 		}
  2105 	}
  2106 	return (rep);
  2107 }
  2108 
  2109 /*
  2110  * returns pathname of the form dir/file;
  2111  * dir and file are null-terminated strings.
  2112  */
  2113 static char *
  2114 makename(char *dir, char *file)
  2115 {
  2116 	/*
  2117 	 * PATH_MAX is the maximum length of a path name.
  2118 	 * MAXNAMLEN is the maximum length of any path name component.
  2119 	 * Allocate space for both, plus the '/' in the middle
  2120 	 * and the null character at the end.
  2121 	 * dfile is static as this is returned by makename().
  2122 	 */
  2123 	static char dfile[PATH_MAX + 1 + MAXNAMLEN + 1];
  2124 	char *dp, *fp;
  2125 
  2126 	dp = dfile;
  2127 	fp = dir;
  2128 	while (*fp)
  2129 		*dp++ = *fp++;
  2130 	if (dp > dfile && *(dp - 1) != '/')
  2131 		*dp++ = '/';
  2132 	fp = file;
  2133 	while (*fp)
  2134 		*dp++ = *fp++;
  2135 	*dp = '\0';
  2136 	return (dfile);
  2137 }
  2138 
  2139 
  2140 #include <pwd.h>
  2141 #include <grp.h>
  2142 #include <utmpx.h>
  2143 
  2144 struct	utmpx utmp;
  2145 
  2146 #define	NMAX	(sizeof (utmp.ut_name))
  2147 #define	SCPYN(a, b)	(void) strncpy(a, b, NMAX)
  2148 
  2149 
  2150 struct cachenode {		/* this struct must be zeroed before using */
  2151 	struct cachenode *lesschild;	/* subtree whose entries < val */
  2152 	struct cachenode *grtrchild;	/* subtree whose entries > val */
  2153 	long val;			/* the uid or gid of this entry */
  2154 	int initted;			/* name has been filled in */
  2155 	char name[NMAX+1];		/* the string that val maps to */
  2156 };
  2157 static struct cachenode *names, *groups;
  2158 
  2159 static struct cachenode *
  2160 findincache(struct cachenode **head, long val)
  2161 {
  2162 	struct cachenode **parent = head;
  2163 	struct cachenode *c = *parent;
  2164 
  2165 	while (c != NULL) {
  2166 		if (val == c->val) {
  2167 			/* found it */
  2168 			return (c);
  2169 		} else if (val < c->val) {
  2170 			parent = &c->lesschild;
  2171 			c = c->lesschild;
  2172 		} else {
  2173 			parent = &c->grtrchild;
  2174 			c = c->grtrchild;
  2175 		}
  2176 	}
  2177 
  2178 	/* not in the cache, make a new entry for it */
  2179 	c = calloc(1, sizeof (struct cachenode));
  2180 	if (c == NULL) {
  2181 		perror("ls");
  2182 		exit(2);
  2183 	}
  2184 	*parent = c;
  2185 	c->val = val;
  2186 	return (c);
  2187 }
  2188 
  2189 /*
  2190  * get name from cache, or passwd file for a given uid;
  2191  * lastuid is set to uid.
  2192  */
  2193 static char *
  2194 getname(uid_t uid)
  2195 {
  2196 	struct passwd *pwent;
  2197 	struct cachenode *c;
  2198 
  2199 	if ((uid == lastuid) && lastuname)
  2200 		return (lastuname);
  2201 
  2202 	c = findincache(&names, uid);
  2203 	if (c->initted == 0) {
  2204 		if ((pwent = getpwuid(uid)) != NULL) {
  2205 			SCPYN(&c->name[0], pwent->pw_name);
  2206 		} else {
  2207 			(void) sprintf(&c->name[0], "%-8u", (int)uid);
  2208 		}
  2209 		c->initted = 1;
  2210 	}
  2211 	lastuid = uid;
  2212 	lastuname = &c->name[0];
  2213 	return (lastuname);
  2214 }
  2215 
  2216 /*
  2217  * get name from cache, or group file for a given gid;
  2218  * lastgid is set to gid.
  2219  */
  2220 static char *
  2221 getgroup(gid_t gid)
  2222 {
  2223 	struct group *grent;
  2224 	struct cachenode *c;
  2225 
  2226 	if ((gid == lastgid) && lastgname)
  2227 		return (lastgname);
  2228 
  2229 	c = findincache(&groups, gid);
  2230 	if (c->initted == 0) {
  2231 		if ((grent = getgrgid(gid)) != NULL) {
  2232 			SCPYN(&c->name[0], grent->gr_name);
  2233 		} else {
  2234 			(void) sprintf(&c->name[0], "%-8u", (int)gid);
  2235 		}
  2236 		c->initted = 1;
  2237 	}
  2238 	lastgid = gid;
  2239 	lastgname = &c->name[0];
  2240 	return (lastgname);
  2241 }
  2242 
  2243 /* return >0 if item pointed by pp2 should appear first */
  2244 static int
  2245 compar(struct lbuf **pp1, struct lbuf **pp2)
  2246 {
  2247 	struct lbuf *p1, *p2;
  2248 
  2249 	p1 = *pp1;
  2250 	p2 = *pp2;
  2251 	if (dflg == 0) {
  2252 /*
  2253  * compare two names in ls-command one of which is file
  2254  * and the other is a directory;
  2255  * this portion is not used for comparing files within
  2256  * a directory name of ls-command;
  2257  */
  2258 		if (p1->lflags&ISARG && p1->ltype == 'd') {
  2259 			if (!(p2->lflags&ISARG && p2->ltype == 'd'))
  2260 				return (1);
  2261 		} else {
  2262 			if (p2->lflags&ISARG && p2->ltype == 'd')
  2263 				return (-1);
  2264 		}
  2265 	}
  2266 	if (tflg) {
  2267 		if (p2->lmtime.tv_sec > p1->lmtime.tv_sec)
  2268 			return (rflg);
  2269 		else if (p2->lmtime.tv_sec < p1->lmtime.tv_sec)
  2270 			return (-rflg);
  2271 		/* times are equal to the sec, check nsec */
  2272 		if (p2->lmtime.tv_nsec > p1->lmtime.tv_nsec)
  2273 			return (rflg);
  2274 		else if (p2->lmtime.tv_nsec < p1->lmtime.tv_nsec)
  2275 			return (-rflg);
  2276 		/* if times are equal, fall through and sort by name */
  2277 	} else if (Sflg) {
  2278 		/*
  2279 		 * The size stored in lsize can be either the
  2280 		 * size or the major minor number (in the case of
  2281 		 * block and character special devices).  If it's
  2282 		 * a major minor number, then the size is considered
  2283 		 * to be zero and we want to fall through and sort
  2284 		 * by name.  In addition, if the size of p2 is equal
  2285 		 * to the size of p1 we want to fall through and
  2286 		 * sort by name.
  2287 		 */
  2288 		off_t	p1size = (p1->ltype == 'b') ||
  2289 		    (p1->ltype == 'c') ? 0 : p1->lsize;
  2290 		off_t	p2size = (p2->ltype == 'b') ||
  2291 		    (p2->ltype == 'c') ? 0 : p2->lsize;
  2292 		if (p2size > p1size) {
  2293 			return (rflg);
  2294 		} else if (p2size < p1size) {
  2295 			return (-rflg);
  2296 		}
  2297 		/* Sizes are equal, fall through and sort by name. */
  2298 	}
  2299 	return (rflg * strcoll(
  2300 	    p1->lflags & ISARG ? p1->ln.namep : p1->ln.lname,
  2301 	    p2->lflags&ISARG ? p2->ln.namep : p2->ln.lname));
  2302 }
  2303 
  2304 static void
  2305 pprintf(char *s1, char *s2)
  2306 {
  2307 	csi_pprintf((unsigned char *)s1);
  2308 	csi_pprintf((unsigned char *)s2);
  2309 }
  2310 
  2311 static void
  2312 csi_pprintf(unsigned char *s)
  2313 {
  2314 	unsigned char *cp;
  2315 	char	c;
  2316 	int	i;
  2317 	int	c_len;
  2318 	int	p_col;
  2319 	wchar_t	pcode;
  2320 
  2321 	if (!qflg && !bflg) {
  2322 		for (cp = s; *cp != '\0'; cp++) {
  2323 			(void) putchar(*cp);
  2324 			curcol++;
  2325 		}
  2326 		return;
  2327 	}
  2328 
  2329 	for (cp = s; *cp; ) {
  2330 		if (isascii(c = *cp)) {
  2331 			if (!isprint(c)) {
  2332 				if (qflg) {
  2333 					c = '?';
  2334 				} else {
  2335 					curcol += 3;
  2336 					(void) putc('\\', stdout);
  2337 					c = '0' + ((*cp >> 6) & 07);
  2338 					(void) putc(c, stdout);
  2339 					c = '0' + ((*cp >> 3) & 07);
  2340 					(void) putc(c, stdout);
  2341 					c = '0' + (*cp & 07);
  2342 				}
  2343 			}
  2344 			curcol++;
  2345 			cp++;
  2346 			(void) putc(c, stdout);
  2347 			continue;
  2348 		}
  2349 
  2350 		if ((c_len = mbtowc(&pcode, (char *)cp, MB_LEN_MAX)) <= 0) {
  2351 			c_len = 1;
  2352 			goto not_print;
  2353 		}
  2354 
  2355 		if ((p_col = wcwidth(pcode)) > 0) {
  2356 			(void) putwchar(pcode);
  2357 			cp += c_len;
  2358 			curcol += p_col;
  2359 			continue;
  2360 		}
  2361 
  2362 not_print:
  2363 		for (i = 0; i < c_len; i++) {
  2364 			if (qflg) {
  2365 				c = '?';
  2366 			} else {
  2367 				curcol += 3;
  2368 				(void) putc('\\', stdout);
  2369 				c = '0' + ((*cp >> 6) & 07);
  2370 				(void) putc(c, stdout);
  2371 				c = '0' + ((*cp >> 3) & 07);
  2372 				(void) putc(c, stdout);
  2373 				c = '0' + (*cp & 07);
  2374 			}
  2375 			curcol++;
  2376 			(void) putc(c, stdout);
  2377 			cp++;
  2378 		}
  2379 	}
  2380 }
  2381 
  2382 static int
  2383 strcol(unsigned char *s1)
  2384 {
  2385 	int	w;
  2386 	int	w_col;
  2387 	int	len;
  2388 	wchar_t	wc;
  2389 
  2390 	w = 0;
  2391 	while (*s1) {
  2392 		if (isascii(*s1)) {
  2393 			w++;
  2394 			s1++;
  2395 			continue;
  2396 		}
  2397 
  2398 		if ((len = mbtowc(&wc, (char *)s1, MB_LEN_MAX)) <= 0) {
  2399 			w++;
  2400 			s1++;
  2401 			continue;
  2402 		}
  2403 
  2404 		if ((w_col = wcwidth(wc)) < 0)
  2405 			w_col = len;
  2406 		s1 += len;
  2407 		w += w_col;
  2408 	}
  2409 	return (w);
  2410 }
  2411 
  2412 /*
  2413  * Convert an unsigned long long to a string representation and place the
  2414  * result in the caller-supplied buffer.
  2415  *
  2416  * The number provided is a size in bytes.  The number is first
  2417  * converted to an integral multiple of 'scale' bytes.  This new
  2418  * number is then scaled down until it is small enough to be in a good
  2419  * human readable format, i.e.  in the range 0 thru scale-1.  If the
  2420  * number used to derive the final number is not a multiple of scale, and
  2421  * the final number has only a single significant digit, we compute
  2422  * tenths of units to provide a second significant digit.
  2423  *
  2424  * The value "(unsigned long long)-1" is a special case and is always
  2425  * converted to "-1".
  2426  *
  2427  * A pointer to the caller-supplied buffer is returned.
  2428  */
  2429 static char *
  2430 number_to_scaled_string(
  2431 			numbuf_t buf,		/* put the result here */
  2432 			unsigned long long number, /* convert this number */
  2433 			long scale)
  2434 {
  2435 	unsigned long long save;
  2436 	/* Measurement: kilo, mega, giga, tera, peta, exa */
  2437 	char *uom = "KMGTPE";
  2438 
  2439 	if ((long long)number == (long long)-1) {
  2440 		(void) strlcpy(buf, "-1", sizeof (numbuf_t));
  2441 		return (buf);
  2442 	}
  2443 
  2444 	save = number;
  2445 	number = number / scale;
  2446 
  2447 	/*
  2448 	 * Now we have number as a count of scale units.
  2449 	 * If no further scaling is necessary, we round up as appropriate.
  2450 	 *
  2451 	 * The largest value number could have had entering the routine is
  2452 	 * 16 Exabytes, so running off the end of the uom array should
  2453 	 * never happen.  We check for that, though, as a guard against
  2454 	 * a breakdown elsewhere in the algorithm.
  2455 	 */
  2456 	if (number < (unsigned long long)scale) {
  2457 		if ((save % scale) >= (unsigned long long)(scale / 2)) {
  2458 			if (++number == (unsigned long long)scale) {
  2459 				uom++;
  2460 				number = 1;
  2461 			}
  2462 		}
  2463 	} else {
  2464 		while ((number >= (unsigned long long)scale) && (*uom != 'E')) {
  2465 			uom++; /* next unit of measurement */
  2466 			save = number;
  2467 			/*
  2468 			 * If we're over half way to the next unit of
  2469 			 * 'scale' bytes (which means we should round
  2470 			 * up), then adding half of 'scale' prior to
  2471 			 * the division will push us into that next
  2472 			 * unit of scale when we perform the division
  2473 			 */
  2474 			number = (number + (scale / 2)) / scale;
  2475 		}
  2476 	}
  2477 
  2478 	/* check if we should output a decimal place after the point */
  2479 	if ((save / scale) < 10) {
  2480 		/* snprintf() will round for us */
  2481 		float fnum = (float)save / scale;
  2482 		(void) snprintf(buf, sizeof (numbuf_t), "%2.1f%c",
  2483 		    fnum, *uom);
  2484 	} else {
  2485 		(void) snprintf(buf, sizeof (numbuf_t), "%4llu%c",
  2486 		    number, *uom);
  2487 	}
  2488 	return (buf);
  2489 }
  2490 
  2491 /* Get extended system attributes and set the display */
  2492 
  2493 int
  2494 get_sysxattr(char *fname, struct lbuf *rep)
  2495 {
  2496 	boolean_t	value;
  2497 	data_type_t	type;
  2498 	int		error;
  2499 	char		*name;
  2500 	int		i;
  2501 
  2502 	if ((error = getattrat(AT_FDCWD, XATTR_VIEW_READWRITE, fname,
  2503 	    &response)) != 0) {
  2504 		perror("ls:getattrat");
  2505 		return (error);
  2506 	}
  2507 
  2508 	/*
  2509 	 * Allocate 'sacnt' size array to hold extended timestamp
  2510 	 * system attributes and initialize the array.
  2511 	 */
  2512 	rep->extm = xmalloc(sacnt * sizeof (struct attrtm), rep);
  2513 	for (i = 0; i < sacnt; i++) {
  2514 		rep->extm[i].stm = 0;
  2515 		rep->extm[i].nstm = 0;
  2516 		rep->extm[i].name = NULL;
  2517 	}
  2518 	while ((pair = nvlist_next_nvpair(response, pair)) != NULL) {
  2519 		name = nvpair_name(pair);
  2520 		type = nvpair_type(pair);
  2521 		if (type == DATA_TYPE_BOOLEAN_VALUE) {
  2522 			error = nvpair_value_boolean_value(pair, &value);
  2523 			if (error) {
  2524 				(void) fprintf(stderr,
  2525 				    gettext("nvpair_value_boolean_value "
  2526 				    "failed: error = %d\n"), error);
  2527 				continue;
  2528 			}
  2529 			if (name != NULL)
  2530 				set_sysattrb_display(name, value, rep);
  2531 			continue;
  2532 		} else if (type == DATA_TYPE_UINT64_ARRAY) {
  2533 			if (name != NULL)
  2534 				set_sysattrtm_display(name, rep);
  2535 			continue;
  2536 		}
  2537 	}
  2538 	nvlist_free(response);
  2539 	return (0);
  2540 }
  2541 
  2542 /* Set extended system attribute boolean display */
  2543 
  2544 void
  2545 set_sysattrb_display(char *name, boolean_t val, struct lbuf *rep)
  2546 {
  2547 	f_attr_t	fattr;
  2548 	const char	*opt;
  2549 	size_t		len;
  2550 
  2551 	fattr = name_to_attr(name);
  2552 	if (fattr != F_ATTR_INVAL && fattr < sacnt) {
  2553 		if (vopt) {
  2554 			len = strlen(name);
  2555 			if (val) {
  2556 				rep->exttr[fattr].name = xmalloc(len + 1, rep);
  2557 				(void) strlcpy(rep->exttr[fattr].name, name,
  2558 				    len + 1);
  2559 			} else {
  2560 				rep->exttr[fattr].name = xmalloc(len + 3, rep);
  2561 				(void) snprintf(rep->exttr[fattr].name, len + 3,
  2562 				    "no%s", name);
  2563 			}
  2564 		} else {
  2565 			opt = attr_to_option(fattr);
  2566 			if (opt != NULL) {
  2567 				len = strlen(opt);
  2568 				rep->exttr[fattr].name = xmalloc(len + 1, rep);
  2569 				if (val)
  2570 					(void) strlcpy(rep->exttr[fattr].name,
  2571 					    opt, len + 1);
  2572 				else
  2573 					(void) strlcpy(rep->exttr[fattr].name,
  2574 					    "-", len + 1);
  2575 			}
  2576 		}
  2577 	}
  2578 }
  2579 
  2580 /* Set extended system attribute timestamp display */
  2581 
  2582 void
  2583 set_sysattrtm_display(char *name, struct lbuf *rep)
  2584 {
  2585 	uint_t		nelem;
  2586 	uint64_t	*value;
  2587 	int		i;
  2588 	size_t		len;
  2589 
  2590 	if (nvpair_value_uint64_array(pair, &value, &nelem) == 0) {
  2591 		if (*value != NULL) {
  2592 			len = strlen(name);
  2593 			i = 0;
  2594 			while (rep->extm[i].stm != 0 && i < sacnt)
  2595 				i++;
  2596 			rep->extm[i].stm = value[0];
  2597 			rep->extm[i].nstm = value[1];
  2598 			rep->extm[i].name = xmalloc(len + 1, rep);
  2599 			(void) strlcpy(rep->extm[i].name, name, len + 1);
  2600 		}
  2601 	}
  2602 }
  2603 
  2604 void
  2605 format_time(time_t sec, time_t nsec)
  2606 {
  2607 	const char *fstr = time_fmt_new;
  2608 	char fmt_buf[FMTSIZE];
  2609 
  2610 	if (Eflg) {
  2611 		(void) snprintf(fmt_buf, FMTSIZE, fstr, nsec);
  2612 		(void) strftime(time_buf, sizeof (time_buf), fmt_buf,
  2613 		    localtime(&sec));
  2614 		return;
  2615 	}
  2616 
  2617 	if (sec < year || sec > now)
  2618 		fstr = time_fmt_old;
  2619 
  2620 	/* if a custom time was specified, shouldn't be localized */
  2621 	(void) strftime(time_buf, sizeof (time_buf),
  2622 	    (time_custom == 0) ? dcgettext(NULL, fstr, LC_TIME) : fstr,
  2623 	    localtime(&sec));
  2624 }
  2625 
  2626 void
  2627 format_attrtime(struct lbuf *p)
  2628 {
  2629 	int tmattr = 0;
  2630 	int i;
  2631 
  2632 	if (p->extm != NULL) {
  2633 		for (i = 0; i < sacnt; i++) {
  2634 			if (p->extm[i].name != NULL) {
  2635 				tmattr = 1;
  2636 				break;
  2637 			}
  2638 		}
  2639 	}
  2640 
  2641 	if (tmattr) {
  2642 		const char *old_save = time_fmt_old;
  2643 		const char *new_save = time_fmt_new;
  2644 
  2645 		/* Eflg always sets format to FORMAT_ISO_FULL */
  2646 		if (!Eflg && !time_custom) {
  2647 			time_fmt_old = FORMAT_OLD;
  2648 			time_fmt_new = FORMAT_NEW;
  2649 		}
  2650 
  2651 		format_time((time_t)p->extm[i].stm, (time_t)p->extm[i].nstm);
  2652 
  2653 		time_fmt_old = old_save;
  2654 		time_fmt_new = new_save;
  2655 	}
  2656 }
  2657 
  2658 void
  2659 print_time(struct lbuf *p)
  2660 {
  2661 	const char *old_save = time_fmt_old;
  2662 	const char *new_save = time_fmt_new;
  2663 
  2664 	int i = 0;
  2665 
  2666 	if (!Eflg) {
  2667 		time_fmt_old = FORMAT_LONG;
  2668 		time_fmt_new = FORMAT_LONG;
  2669 	}
  2670 
  2671 	new_line();
  2672 	format_time(p->lat.tv_sec, p->lat.tv_nsec);
  2673 	(void) printf("         timestamp: atime        %s\n", time_buf);
  2674 	format_time(p->lct.tv_sec, p->lct.tv_nsec);
  2675 	(void) printf("         timestamp: ctime        %s\n", time_buf);
  2676 	format_time(p->lmt.tv_sec, p->lmt.tv_nsec);
  2677 	(void) printf("         timestamp: mtime        %s\n", time_buf);
  2678 	if (p->extm != NULL) {
  2679 		while (p->extm[i].nstm != 0 && i < sacnt) {
  2680 			format_time(p->extm[i].stm, p->extm[i].nstm);
  2681 			if (p->extm[i].name != NULL) {
  2682 				(void) printf("         timestamp:"
  2683 				    " %s        %s\n",
  2684 				    p->extm[i].name, time_buf);
  2685 			}
  2686 			i++;
  2687 		}
  2688 	}
  2689 
  2690 	time_fmt_old = old_save;
  2691 	time_fmt_new = new_save;
  2692 }
  2693 
  2694 /*
  2695  * Check if color definition applies to entry, returns 1 if yes, 0 if no
  2696  */
  2697 static int
  2698 color_match(const char *fname, mode_t mode, ls_color_t *color)
  2699 {
  2700 	switch (color->ftype) {
  2701 	case LS_PAT:
  2702 	{
  2703 		size_t	fname_len, sfx_len;
  2704 
  2705 		fname_len = strlen(fname);
  2706 		sfx_len = strlen(color->sfx);
  2707 		if (sfx_len > fname_len)
  2708 			return (0);
  2709 
  2710 		if (strcmp(color->sfx, fname + fname_len - sfx_len) == 0)
  2711 			return (1);
  2712 		else
  2713 			return (0);
  2714 	}
  2715 
  2716 	case LS_NORMAL:
  2717 		return (1);
  2718 
  2719 	case LS_FILE:
  2720 		return (S_ISREG(mode));
  2721 
  2722 	case LS_DIR:
  2723 		return (S_ISDIR(mode));
  2724 
  2725 	case LS_LINK:
  2726 		return (S_ISLNK(mode));
  2727 
  2728 	case LS_FIFO:
  2729 		return (S_ISFIFO(mode));
  2730 
  2731 	case LS_SOCK:
  2732 		return (S_ISSOCK(mode));
  2733 
  2734 	case LS_DOOR:
  2735 		return (S_ISDOOR(mode));
  2736 
  2737 	case LS_BLK:
  2738 		return (S_ISBLK(mode));
  2739 
  2740 	case LS_CHR:
  2741 		return (S_ISCHR(mode));
  2742 
  2743 	case LS_PORT:
  2744 		return (S_ISPORT(mode));
  2745 
  2746 	case LS_ORPHAN:
  2747 		/* this is tested for by gstat */
  2748 		return (0);
  2749 
  2750 	case LS_SETUID:
  2751 		return (!S_ISLNK(mode) && (mode & S_ISUID));
  2752 
  2753 	case LS_SETGID:
  2754 		return (!S_ISLNK(mode) && (mode & S_ISGID));
  2755 
  2756 	case LS_STICKY_OTHER_WRITABLE:
  2757 		return (!S_ISLNK(mode) && (mode & (S_IWOTH|S_ISVTX)));
  2758 
  2759 	case LS_OTHER_WRITABLE:
  2760 		return (!S_ISLNK(mode) && (mode & S_IWOTH));
  2761 
  2762 	case LS_STICKY:
  2763 		return (!S_ISLNK(mode) && (mode & S_ISVTX));
  2764 
  2765 	case LS_EXEC:
  2766 		return (!S_ISLNK(mode) && (mode & (S_IXUSR|S_IXGRP|S_IXOTH)));
  2767 	}
  2768 
  2769 	return (0);
  2770 }
  2771 
  2772 static void
  2773 dump_color(ls_color_t *c)
  2774 {
  2775 	if (c == NULL)
  2776 		return;
  2777 
  2778 	(void) printf("\n\ttype: ");
  2779 	switch (c->ftype) {
  2780 	case LS_NORMAL:
  2781 		(void) printf("LS_NORMAL");
  2782 		break;
  2783 	case LS_FILE:
  2784 		(void) printf("LS_FILE");
  2785 		break;
  2786 	case LS_EXEC:
  2787 		(void) printf("LS_EXEC");
  2788 		break;
  2789 	case LS_DIR:
  2790 		(void) printf("LS_DIR");
  2791 		break;
  2792 	case LS_LINK:
  2793 		(void) printf("LS_LINK");
  2794 		break;
  2795 
  2796 	case LS_FIFO:
  2797 		(void) printf("LS_FIFO");
  2798 		break;
  2799 
  2800 	case LS_SOCK:
  2801 		(void) printf("LS_SOCK");
  2802 		break;
  2803 
  2804 	case LS_DOOR:
  2805 		(void) printf("LS_DOOR");
  2806 		break;
  2807 
  2808 	case LS_BLK:
  2809 		(void) printf("LS_BLK");
  2810 		break;
  2811 
  2812 	case LS_CHR:
  2813 		(void) printf("LS_CHR");
  2814 		break;
  2815 
  2816 	case LS_PORT:
  2817 		(void) printf("LS_PORT");
  2818 		break;
  2819 
  2820 	case LS_STICKY:
  2821 		(void) printf("LS_STICKY");
  2822 		break;
  2823 
  2824 	case LS_ORPHAN:
  2825 		(void) printf("LS_ORPHAN");
  2826 		break;
  2827 
  2828 	case LS_SETGID:
  2829 		(void) printf("LS_SETGID");
  2830 		break;
  2831 
  2832 	case LS_SETUID:
  2833 		(void) printf("LS_SETUID");
  2834 		break;
  2835 
  2836 	case LS_OTHER_WRITABLE:
  2837 		(void) printf("LS_OTHER_WRITABLE");
  2838 		break;
  2839 
  2840 	case LS_STICKY_OTHER_WRITABLE:
  2841 		(void) printf("LS_STICKY_OTHER_WRITABLE");
  2842 		break;
  2843 
  2844 	case LS_PAT:
  2845 		(void) printf("LS_PAT\n");
  2846 		(void) printf("\tpattern: %s", c->sfx);
  2847 		break;
  2848 	}
  2849 	(void) printf("\n");
  2850 	(void) printf("\tattr: %d\n", c->attr);
  2851 	(void) printf("\tfg: %d\n", c->fg);
  2852 	(void) printf("\tbg: %d\n", c->bg);
  2853 	(void) printf("\t");
  2854 }
  2855 
  2856 static ls_color_t *
  2857 ls_color_find(const char *fname, mode_t mode)
  2858 {
  2859 	int i;
  2860 
  2861 	/*
  2862 	 * Colors are sorted from most general lsc_colors[0] to most specific
  2863 	 * lsc_colors[lsc_ncolors - 1] by ls_color_init().  Start search with
  2864 	 * most specific color rule and work towards most general.
  2865 	 */
  2866 	for (i = lsc_ncolors - 1; i >= 0; --i)
  2867 		if (color_match(fname, mode, &lsc_colors[i]))
  2868 			return (&lsc_colors[i]);
  2869 
  2870 	return (NULL);
  2871 }
  2872 
  2873 static void
  2874 ls_tprint(char *str, long int p1, long int p2, long int p3, long int p4,
  2875     long int p5, long int p6, long int p7, long int p8, long int p9)
  2876 {
  2877 	char *s;
  2878 
  2879 	if (str == NULL)
  2880 		return;
  2881 
  2882 	s = tparm(str, p1, p2, p3, p4, p5, p6, p7, p8, p9);
  2883 
  2884 	if (s != NULL)
  2885 		(void) putp(s);
  2886 }
  2887 
  2888 static void
  2889 ls_start_color(ls_color_t *c)
  2890 {
  2891 	if (c == NULL)
  2892 		return;
  2893 
  2894 	if (lsc_debug)
  2895 		lsc_match = c;
  2896 
  2897 	if (c->attr & LSA_BOLD)
  2898 		ls_tprint(lsc_bold, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  2899 	if (c->attr & LSA_UNDERSCORE)
  2900 		ls_tprint(lsc_underline, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  2901 	if (c->attr & LSA_BLINK)
  2902 		ls_tprint(lsc_blink, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  2903 	if (c->attr & LSA_REVERSE)
  2904 		ls_tprint(lsc_reverse, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  2905 	if (c->attr & LSA_CONCEALED)
  2906 		ls_tprint(lsc_concealed, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  2907 	if (c->attr == LSA_NONE)
  2908 		ls_tprint(lsc_none, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  2909 
  2910 	if (c->fg != -1)
  2911 		ls_tprint(lsc_setfg, c->fg, 0, 0, 0, 0, 0, 0, 0, 0);
  2912 	if (c->bg != -1)
  2913 		ls_tprint(lsc_setbg, c->bg, 0, 0, 0, 0, 0, 0, 0, 0);
  2914 }
  2915 
  2916 static void
  2917 ls_end_color()
  2918 {
  2919 	ls_tprint(lsc_none, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  2920 	if (lsc_debug)
  2921 		dump_color(lsc_match);
  2922 }
  2923 
  2924 static void
  2925 new_color_entry(char *colorstr)
  2926 {
  2927 	static const struct {
  2928 		const char	*s;
  2929 		ls_cftype_t	stype;
  2930 	} type_map[] = {
  2931 		{ "no", LS_NORMAL },
  2932 		{ "fi", LS_FILE },
  2933 		{ "di", LS_DIR },
  2934 		{ "ln", LS_LINK },
  2935 		{ "pi", LS_FIFO },
  2936 		{ "so", LS_SOCK },
  2937 		{ "do", LS_DOOR },
  2938 		{ "bd", LS_BLK },
  2939 		{ "cd", LS_CHR },
  2940 		{ "or", LS_ORPHAN },
  2941 		{ "su", LS_SETUID },
  2942 		{ "sg", LS_SETGID },
  2943 		{ "tw", LS_STICKY_OTHER_WRITABLE },
  2944 		{ "ow", LS_OTHER_WRITABLE },
  2945 		{ "st", LS_STICKY },
  2946 		{ "ex", LS_EXEC },
  2947 		{ "po", LS_PORT },
  2948 		{ NULL, LS_NORMAL }
  2949 	};
  2950 
  2951 	char		*p, *lasts;
  2952 	int		i;
  2953 	int		color, attr;
  2954 
  2955 	p = strtok_r(colorstr, "=", &lasts);
  2956 	if (p == NULL) {
  2957 		colorflg = 0;
  2958 		return;
  2959 	}
  2960 
  2961 	if (p[0] == '*') {
  2962 		lsc_colors[lsc_ncolors].ftype = LS_PAT;
  2963 		/* don't include the * in the suffix */
  2964 		if ((lsc_colors[lsc_ncolors].sfx = strdup(p + 1)) == NULL) {
  2965 			colorflg = 0;
  2966 			return;
  2967 		}
  2968 	} else {
  2969 		lsc_colors[lsc_ncolors].sfx = NULL;
  2970 
  2971 		for (i = 0; type_map[i].s != NULL; ++i) {
  2972 			if (strncmp(type_map[i].s, p, 2) == 0)
  2973 				break;
  2974 		}
  2975 
  2976 		/* ignore unknown file types */
  2977 		if (type_map[i].s == NULL)
  2978 			return;
  2979 
  2980 		lsc_colors[lsc_ncolors].ftype = type_map[i].stype;
  2981 	}
  2982 
  2983 	attr = LSA_NONE;
  2984 	lsc_colors[lsc_ncolors].fg = -1;
  2985 	lsc_colors[lsc_ncolors].bg = -1;
  2986 	for (p = strtok_r(NULL, ";", &lasts); p != NULL;
  2987 	    p = strtok_r(NULL, ";", &lasts)) {
  2988 		color = strtol(p, NULL, 10);
  2989 
  2990 		if (color < 10) {
  2991 			switch (color) {
  2992 			case 0:
  2993 				attr = LSA_NONE;
  2994 				continue;
  2995 			case 1:
  2996 				attr |= LSA_BOLD;
  2997 				continue;
  2998 			case 4:
  2999 				attr |= LSA_UNDERSCORE;
  3000 				continue;
  3001 			case 5:
  3002 				attr |= LSA_BLINK;
  3003 				continue;
  3004 			case 7:
  3005 				attr |= LSA_REVERSE;
  3006 				continue;
  3007 			case 8:
  3008 				attr |= LSA_CONCEALED;
  3009 				continue;
  3010 			default:
  3011 				continue;
  3012 			}
  3013 		}
  3014 
  3015 		if (color < 40)
  3016 			lsc_colors[lsc_ncolors].fg = color - 30;
  3017 		else
  3018 			lsc_colors[lsc_ncolors].bg = color - 40;
  3019 	}
  3020 
  3021 	lsc_colors[lsc_ncolors].attr = attr;
  3022 	++lsc_ncolors;
  3023 }
  3024 
  3025 static int
  3026 ls_color_compare(const void *p1, const void *p2)
  3027 {
  3028 	const ls_color_t *c1 = (const ls_color_t *)p1;
  3029 	const ls_color_t *c2 = (const ls_color_t *)p2;
  3030 
  3031 	int ret = c1->ftype - c2->ftype;
  3032 
  3033 	if (ret != 0)
  3034 		return (ret);
  3035 
  3036 	if (c1->ftype != LS_PAT)
  3037 		return (ret);
  3038 
  3039 	return (strcmp(c1->sfx, c2->sfx));
  3040 }
  3041 
  3042 static void
  3043 ls_color_init()
  3044 {
  3045 	static char *default_colorstr = "no=00:fi=00:di=01;34:ln=01;36:po=01;35"
  3046 	    ":pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01"
  3047 	    ":su=37;41:sg=30;43:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31"
  3048 	    ":*.tgz=01;31:*.arj=01;31:*.taz=01;31:*.lzh=01;31:*.zip=01;31"
  3049 	    ":*.z=01;31:*.Z=01;31:*.gz=01;31:*.bz2=01;31:*.deb=01;31"
  3050 	    ":*.rpm=01;31:*.jar=01;31:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35"
  3051 	    ":*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35"
  3052 	    ":*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35"
  3053 	    ":*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.avi=01;35:*.fli=01;35"
  3054 	    ":*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.flac=01;35"
  3055 	    ":*.mp3=01;35:*.mpc=01;35:*.ogg=01;35:*.wav=01;35";
  3056 
  3057 	char    *colorstr;
  3058 	char    *p, *lasts;
  3059 	size_t  color_sz;
  3060 	int	termret;
  3061 	int	i;
  3062 
  3063 	(void) setupterm(NULL, 1, &termret);
  3064 	if (termret != 1)
  3065 		return;
  3066 
  3067 	if ((colorstr = getenv("LS_COLORS")) == NULL)
  3068 		colorstr = default_colorstr;
  3069 
  3070 	/*
  3071 	 * Determine the size of lsc_colors.  color_sz can be > lsc_ncolors
  3072 	 * if there are invalid entries passed in the string (they are ignored)
  3073 	 */
  3074 	color_sz = 1;
  3075 	for (p = strchr(colorstr, ':'); p != NULL && *p != '\0';
  3076 	    p = strchr(++p, ':'))
  3077 		++color_sz;
  3078 
  3079 	lsc_colors = calloc(color_sz, sizeof (ls_color_t));
  3080 	if (lsc_colors == NULL) {
  3081 		free(colorstr);
  3082 		return;
  3083 	}
  3084 
  3085 	for (p = strtok_r(colorstr, ":", &lasts);
  3086 	    p != NULL && lsc_ncolors < color_sz;
  3087 	    p = strtok_r(NULL, ":", &lasts))
  3088 		new_color_entry(p);
  3089 
  3090 	qsort((void *)lsc_colors, lsc_ncolors, sizeof (ls_color_t),
  3091 	    ls_color_compare);
  3092 
  3093 	for (i = 0; i < lsc_ncolors; ++i)
  3094 		if (lsc_colors[i].ftype == LS_ORPHAN) {
  3095 			lsc_orphan = &lsc_colors[i];
  3096 			break;
  3097 		}
  3098 
  3099 	if ((lsc_bold = tigetstr("bold")) == (char *)-1)
  3100 		lsc_bold = NULL;
  3101 
  3102 	if ((lsc_underline = tigetstr("smul")) == (char *)-1)
  3103 		lsc_underline = NULL;
  3104 
  3105 	if ((lsc_blink = tigetstr("blink")) == (char *)-1)
  3106 		lsc_blink = NULL;
  3107 
  3108 	if ((lsc_reverse = tigetstr("rev")) == (char *)-1)
  3109 		lsc_reverse = NULL;
  3110 
  3111 	if ((lsc_concealed = tigetstr("prot")) == (char *)-1)
  3112 		lsc_concealed = NULL;
  3113 
  3114 	if ((lsc_none = tigetstr("sgr0")) == (char *)-1)
  3115 		lsc_none = NULL;
  3116 
  3117 	if ((lsc_setfg = tigetstr("setaf")) == (char *)-1)
  3118 		lsc_setfg = NULL;
  3119 
  3120 	if ((lsc_setbg = tigetstr("setab")) == (char *)-1)
  3121 		lsc_setbg = NULL;
  3122 
  3123 	if (getenv("_LS_COLOR_DEBUG") != NULL) {
  3124 		int i;
  3125 
  3126 		lsc_debug = 1;
  3127 		for (i = 0; i < lsc_ncolors; ++i)
  3128 			dump_color(&lsc_colors[i]);
  3129 	}
  3130 }
  3131 
  3132 /* Free extended system attribute lists */
  3133 
  3134 void
  3135 free_sysattr(struct lbuf *p)
  3136 {
  3137 	int i;
  3138 
  3139 	if (p->exttr != NULL) {
  3140 		for (i = 0; i < sacnt; i++) {
  3141 			if (p->exttr[i].name != NULL)
  3142 				free(p->exttr[i].name);
  3143 		}
  3144 		free(p->exttr);
  3145 	}
  3146 	if (p->extm != NULL) {
  3147 		for (i = 0; i < sacnt; i++) {
  3148 			if (p->extm[i].name != NULL)
  3149 				free(p->extm[i].name);
  3150 		}
  3151 		free(p->extm);
  3152 	}
  3153 }
  3154 
  3155 /* Allocate extended system attribute list */
  3156 
  3157 void *
  3158 xmalloc(size_t size, struct lbuf *p)
  3159 {
  3160 	if ((p = malloc(size)) == NULL) {
  3161 		perror("ls");
  3162 		free_sysattr(p);
  3163 		nvlist_free(response);
  3164 		exit(2);
  3165 	}
  3166 	return (p);
  3167 }
