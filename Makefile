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
