# Maintainer: Taylor Allen
pkgname=shortsync-git
_pkgname=shortsync-git
pkgver=1
pkgrel=1
epoch=
pkgdesc="This application makes it easy to keep track of alias, file, and folder shortcuts across multiple applications and shells."
arch=(x86_64 i686)
url="https://github.com/taylo2allen/shortsync.git"
license=('MIT')
groups=()
depends=()
makedepends=('git' 'glibc' 'gcc-libs' 'yaml-cpp')
checkdepends=()
optdepends=('entr')
provides=(shortsync)
conflicts=()
replaces=()
backup=()
options=()
install=
changelog=
source=(git+$url)
noextract=()
md5sums=('SKIP')
validpgpkeys=()

pkgver() {
	cd "${_pkgname}"
	printf "1.r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}

build() {
	cd ${_pkgname}
	make
}

package() {
	cd ${pkgname}
	make install
	# install -CDm755 shortcut-files/* "${pkgdir}/$HOME/.config/${pkgname}/shortcut-files"
	# install -CDm755 config.yaml "${pkgdir}/$HOME/.config/${pkgname}/config.yaml"
	# install -Dm755 bin/${pkgname} "${pkgdir}/usr/local/bin/${pkgname}"
	# install -Dm644 ${pkgname}.1 "${pkgdir}/usr/share/man/man1/${pkgname}.1"
	# install -Dm644 LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
	# install -Dm644 README.org "${pkgdir}/usr/share/doc/${pkgname}/README.org"
}
