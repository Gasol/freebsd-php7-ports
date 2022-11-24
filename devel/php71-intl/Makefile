# $FreeBSD: head/devel/php71-intl/Makefile 515599 2019-10-25 10:32:31Z tz $

CATEGORIES=	devel

MASTERDIR=	${.CURDIR}/../../lang/php71

PKGNAMESUFFIX=	-intl

USES=		compiler:c++11-lib
USE_CXXSTD=	gnu++11

CPPFLAGS+=	-DU_USING_ICU_NAMESPACE=1

TEST_TARGET=    test

.include "${MASTERDIR}/Makefile"
