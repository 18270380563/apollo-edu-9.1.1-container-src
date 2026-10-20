# Apollo 容器源码镜像快照

本仓库的 `src/` 来自远程容器 `apollo_neo_dev_edu_9.1.1` 的 `/opt/apollo/neo/src/`，不是宿主机挂载的 `/apollo_workspace`。该目录是容器中的源码镜像；无法仅凭此证明其与运行中的动态库版本完全一致。

包含源码、配置、模型和测试数据。体积超过约 50 MB 的 7 个文件使用 Git LFS 保存；克隆时需要安装 Git LFS。3 个 GNSS 示例配置的用户名和密码字段已替换为 `REDACTED`。原 `src/tools` 是指向 `/opt/apollo/neo/packages/bazel-extend-tools/latest/src` 的符号链接，其目标见 `SOURCE_LINKS.txt`，目标内容不属于本次源码树快照。

本仓库是文件快照，不包含原 Git 历史，也不包含容器运行时动态库和完整依赖。有关代码及模型的许可见各目录中的原始许可文件。

## 容器其他代码和配置

`container-extra/` 是从同一远程容器补充导出的文本源码、头文件、脚本、构建文件和配置，目录结构对应容器内绝对路径。例如：

- `container-extra/opt/apollo/neo/packages/`：安装包和第三方依赖中的源码、头文件、脚本和配置。
- `container-extra/opt/apollo/neo/include/`、`python/`、`share/`、`bin/` 和 `lib/`：上述目录中可读取的文本代码和配置；可执行文件与动态库等二进制不在此次补充范围。
- `container-extra/apollo/`：容器运行目录中的文本文件；符号链接保存在清单中。
- `container-extra/apollo_workspace/`：容器内可见的工作区源码和车辆配置。该目录绑定宿主机工作区，并非容器独有的文件。

`container-extra/EXTRACTION_MANIFEST.json` 记录扫描目录、符号链接及部分跳过的文件。工作区 `.aem/envroot` 中安装目录与 `/opt/apollo/neo/` 是同一份文件，重复视图未重复导出；`src/` 已有的源码也不因此重复上传。符号链接以清单记录，未在仓库重建。为避免上传凭据和运行数据，排除了常见敏感文件名、日志、运行数据、缓存和 Git 历史，并将发现的 GNSS 用户名和密码字段替换为 `REDACTED`。此次补充按文本文件类型筛选，跳过大于 20 MiB 的文件，不是可直接运行的完整容器备份，也不能保证自动检查覆盖所有敏感信息。实际运行配置、二进制与源码版本仍需核对。
