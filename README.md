# Apollo 容器源码镜像快照

本仓库的 `src/` 来自远程容器 `apollo_neo_dev_edu_9.1.1` 的 `/opt/apollo/neo/src/`，不是宿主机挂载的 `/apollo_workspace`。该目录是容器中的源码镜像；无法仅凭此证明其与运行中的动态库版本完全一致。

包含源码、配置、模型和测试数据。体积超过约 50 MB 的 7 个文件使用 Git LFS 保存；克隆时需要安装 Git LFS。3 个 GNSS 示例配置的用户名和密码字段已替换为 `REDACTED`。原 `src/tools` 是指向 `/opt/apollo/neo/packages/bazel-extend-tools/latest/src` 的符号链接，其目标见 `SOURCE_LINKS.txt`，目标内容不属于本次源码树快照。

本仓库是文件快照，不包含原 Git 历史，也不包含容器运行时动态库和完整依赖。有关代码及模型的许可见各目录中的原始许可文件。
