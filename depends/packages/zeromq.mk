package=zeromq
$(package)_version=4.3.1
$(package)_download_path=https://github.com/zeromq/zeromq4-1/releases/download/v$($(package)_version)/
$(package)_file_name=$(package)-$($(package)_version).tar.gz
$(package)_sha256_hash=bcbabe1e2c7d0eec4ed612e10b94b112dd5f06fcefa994a0c79a45d835cd21eb
$(package)_patches=9114d3957725acd34aa8b8d011585812f3369411.patch 9e6745c12e0b100cd38acecc16ce7db02905e27c.patch

define $(package)_set_vars
  $(package)_config_opts=--without-documentation --disable-shared --without-libsodium --disable-curve
  $(package)_config_opts_linux=--with-pic
  $(package)_cxxflags=-std=c++11
endef

define $(package)_preprocess_cmds
  patch -p1 < $($(package)_patch_dir)/9114d3957725acd34aa8b8d011585812f3369411.patch && \
  patch -p1 < $($(package)_patch_dir)/9e6745c12e0b100cd38acecc16ce7db02905e27c.patch && \
  ./autogen.sh
endef

define $(package)_config_cmds
  $($(package)_autoconf)
endef

define $(package)_build_cmds
  $(MAKE) libzmq.la
endef

define $(package)_stage_cmds
  $(MAKE) DESTDIR=$($(package)_staging_dir) install-libLTLIBRARIES install-includeHEADERS install-pkgconfigDATA
endef

define $(package)_postprocess_cmds
  rm -rf bin share
endef
