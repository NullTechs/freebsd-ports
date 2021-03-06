# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phonon
PORTVERSION=	4.9.0
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTNAME}-backend-gstreamer/${PORTVERSION}
PKGNAMEPREFIX=	qt5-
PKGNAMESUFFIX=	4-gstreamer
DISTNAME=	${PORTNAME}-backend-gstreamer-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	GStreamer backend for Phonon 4 Qt 5

LICENSE=	LGPL21

WRKSRC=		${WRKDIR}/${DISTNAME:S/-backend//}

USES=		cmake:outsource kde:5 pkgconfig tar:xz
USE_GL=		gl
USE_GNOME=	glib20 libxml2
USE_GSTREAMER1=	yes
USE_KDE=	ecm
USE_QT5=	buildtools_build qmake_build core gui opengl phonon4 widgets \
		x11extras
CMAKE_ARGS=	-DPHONON_BUILD_PHONON4QT5=ON

OPTIONS_DEFINE=	GST_PLUGINS
GST_PLUGINS_DESC=	Install GStreamer plugins
GST_PLUGINS_RUN_DEPENDS=	gstreamer1-plugins-all>=0:multimedia/gstreamer1-plugins-all

.include <bsd.port.mk>
