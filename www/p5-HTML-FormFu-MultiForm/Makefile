# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTML-FormFu-MultiForm
PORTVERSION=	1.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Handle multi-page/stage forms with FormFu

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

xBUILD_DEPENDS=	p5-Clone>=0:devel/p5-Clone \
		p5-Crypt-CBC>=0:security/p5-Crypt-CBC \
		p5-Crypt-DES>=0:security/p5-Crypt-DES \
		p5-HTML-FormFu>=0:www/p5-HTML-FormFu \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Attribute-Chained>=0:devel/p5-MooseX-Attribute-Chained
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-YAML-LibYAML>=0:textproc/p5-YAML-LibYAML

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
