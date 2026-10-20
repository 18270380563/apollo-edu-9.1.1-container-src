#!/bin/bash

export APOLLO_CONFIG_HOME="${APOLLO_CONFIG_HOME:=$HOME/.apollo}"

function subenv {
    template="${1}"
    target="${2}"
    eval "
cat <<EOF
$(cat ${template})
EOF
" > ${target} 2> /dev/null
}

function unpack_and_install {
  install_prefix="${1:-$APOLLO_CONFIG_HOME}"
  mkdir -pv "${install_prefix}"

  tmp_dir=$(mktemp -d -t apollo-studio-connector-install-pkg-XXXXXXXXXX)
  archive='/apollo/bazel-bin/modules/studio_connector/studio_connector.tar'
  tar -xf "${archive}" -C "${tmp_dir}"

  # clean old files
  rm -rf ${install_prefix}/dreamview/plugins/studio_connector/*.so
  rm -rf ${install_prefix}/dreamview/plugins/studio_connector/common/*.so
  rm -rf ${install_prefix}/dreamview/plugins/studio_connector/proto/*.so
  rm -rf ${install_prefix}/dreamview/plugins/studio_connector/modules/dreamview/proto/*.so

  # install plugin files
  mkdir -pv ${install_prefix}/dreamview/plugins/studio_connector

  conf_files=(
    'studio_connector.dag'
    'studio_connector.conf'
    'studio_connector.launch'
    'studio_connector_plugin_config.pb.txt'
  )
  for conf_file in "${conf_files[@]}"; do
    subenv \
      "${tmp_dir}/studio_connector/package/${conf_file}" \
      "${install_prefix}/dreamview/plugins/studio_connector/${conf_file}"
  done
  # flags for staging environment
  cp -arpv \
    /apollo/modules/studio_connector/testdata/dreamview/plugins/studio_connector/studio_connector.conf \
    ${install_prefix}/dreamview/plugins/studio_connector/studio_connector.conf

  # install libraries
  cp -arpv \
    ${tmp_dir}/studio_connector/*.so \
    ${install_prefix}/dreamview/plugins/studio_connector/
  mkdir -pv ${install_prefix}/dreamview/plugins/studio_connector/common
  cp -arpv \
    ${tmp_dir}/studio_connector/common/*.so \
    ${install_prefix}/dreamview/plugins/studio_connector/common/
  mkdir -pv ${install_prefix}/dreamview/plugins/studio_connector/proto
  cp -arpv \
    ${tmp_dir}/studio_connector/proto/*.so \
    ${install_prefix}/dreamview/plugins/studio_connector/proto/
  mkdir -pv ${install_prefix}/dreamview/plugins/studio_connector/modules/dreamview/proto
  cp -arpv \
    ${tmp_dir}/studio_connector/modules/dreamview/proto/*.so \
    ${install_prefix}/dreamview/plugins/studio_connector/modules/dreamview/proto/
  # chmod 755 ${install_prefix}/dreamview/plugins/studio_connector/libstudio_connector_component.so
  # patchelf \
  #   --force-rpath \
  #   --set-rpath \
  #   '$ORIGIN:/apollo/bazel-bin/_solib_k8' \
  #   ${install_prefix}/dreamview/plugins/studio_connector/libstudio_connector_component.so
  # cp -arpv \
  #   ${tmp_dir}/com_github_openssl_openssl/openssl/lib/*.so \
  #   ${install_prefix}/dreamview/plugins/studio_connector/

  # clean
  rm -rf ${tmp_dir}
}

# 入口方法
function main {
  unpack_and_install
  exit 0
}

main "$@"
