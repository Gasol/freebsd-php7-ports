# linwang-ports

SUBDIR+=	archivers
SUBDIR+=	converters
SUBDIR+=	databases
SUBDIR+=	devel
SUBDIR+=	ftp
SUBDIR+=	graphics
SUBDIR+=	lang
SUBDIR+=	mail
SUBDIR+=	math
SUBDIR+=	misc
SUBDIR+=	net
SUBDIR+=	net-mgmt
SUBDIR+=	security
SUBDIR+=	sysutils
SUBDIR+=	textproc
SUBDIR+=	www

PORTSTOP=	yes

.include <bsd.port.subdir.mk>

list-all-origins:
	@for c in ${SUBDIR}; do \
		for p in $$(${MAKE} -C $$c -V SUBDIR); do \
		  echo $$c/$$p; \
		done \
	done

all-origins.txt:
	@${ECHO_MSG} "Generating all-origins.txt"
	@${MAKE} list-all-origins | sort > all-origins.txt
