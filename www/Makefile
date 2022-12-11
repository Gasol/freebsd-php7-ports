# category www

.for ext in opcache session tidy
SUBDIR+=	php70-$(ext)
SUBDIR+=	php71-$(ext)
SUBDIR+=	php72-$(ext)
SUBDIR+=	php73-$(ext)
.endfor

.for ver in 70 71 72 73
SUBDIR+=	mod_php${ver}
.endfor

.include <bsd.port.subdir.mk>

