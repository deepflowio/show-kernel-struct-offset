# Show Kernel Struct Offset

用于提取 Linux 内核结构体成员偏移的小工具。

DeepFlow 依赖这些偏移，以支持多版本内核的兼容和正确运行。

## 依赖环境

请确保系统已安装以下工具和包：

- gcc
- make
- objdump
- 当前运行内核对应的内核头文件（kernel-devel）
- 内核调试符号包（kernel-debuginfo），包含 `vmlinux`

## 编译方法

```bash
make
```
会得到如下内容：

```bash
make -C /lib/modules/4.19.17-1.el7.x86_64/build M=/home/jiping/struct-member/show-kernel-struct-offset modules
make[1]: 进入目录“/usr/src/kernels/4.19.17-1.el7.x86_64”
  CC [M]  /home/jiping/struct-member/show-kernel-struct-offset/skso.o
  Building modules, stage 2.
  MODPOST 1 modules
  CC      /home/jiping/struct-member/show-kernel-struct-offset/skso.mod.o
  LD [M]  /home/jiping/struct-member/show-kernel-struct-offset/skso.ko
make[1]: 离开目录“/usr/src/kernels/4.19.17-1.el7.x86_64”
objdump -d skso.ko

skso.ko：     文件格式 elf64-x86-64


Disassembly of section .text:

0000000000000000 <struct_tcp_sock__copied_seq_offset>:
   0:   e8 00 00 00 00          callq  5 <struct_tcp_sock__copied_seq_offset+0x5>
   5:   b8 3c 05 00 00          mov    $0x53c,%eax
   a:   c3                      retq   
   b:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

0000000000000010 <struct_tcp_sock__write_seq_offset>:
  10:   e8 00 00 00 00          callq  15 <struct_tcp_sock__write_seq_offset+0x5>
  15:   b8 ac 06 00 00          mov    $0x6ac,%eax
  1a:   c3                      retq   
  1b:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

0000000000000020 <struct_tcp_sock__snd_nxt_offset>:
  20:   e8 00 00 00 00          callq  25 <struct_tcp_sock__snd_nxt_offset+0x5>
  25:   b8 44 05 00 00          mov    $0x544,%eax
  2a:   c3                      retq   
  2b:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

0000000000000030 <struct_task_struct__files_offset>:
  30:   e8 00 00 00 00          callq  35 <struct_task_struct__files_offset+0x5>
  35:   b8 c8 0a 00 00          mov    $0xac8,%eax
  3a:   c3                      retq   
  3b:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

0000000000000040 <struct_sock____sk_flags_offset_offset>:
  40:   e8 00 00 00 00          callq  45 <struct_sock____sk_flags_offset_offset+0x5>
  45:   b8 f8 01 00 00          mov    $0x1f8,%eax
  4a:   c3                      retq   
  4b:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

0000000000000050 <struct_files_struct_fdt_offset>:
  50:   e8 00 00 00 00          callq  55 <struct_files_struct_fdt_offset+0x5>
  55:   b8 20 00 00 00          mov    $0x20,%eax
  5a:   c3                      retq   
  5b:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

0000000000000060 <STRUCT_FILES_PRIVATE_DATA_OFFSET>:
  60:   e8 00 00 00 00          callq  65 <STRUCT_FILES_PRIVATE_DATA_OFFSET+0x5>
  65:   b8 c8 00 00 00          mov    $0xc8,%eax
  6a:   c3                      retq   
  6b:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

0000000000000070 <struct_file_f_op_offset>:
  70:   e8 00 00 00 00          callq  75 <struct_file_f_op_offset+0x5>
  75:   b8 28 00 00 00          mov    $0x28,%eax
  7a:   c3                      retq   
  7b:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

0000000000000080 <struct_file_operations_read_iter_offset>:
  80:   e8 00 00 00 00          callq  85 <struct_file_operations_read_iter_offset+0x5>
  85:   b8 20 00 00 00          mov    $0x20,%eax
  8a:   c3                      retq   
  8b:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

0000000000000090 <struct_file__f_inode_offset>:
  90:   e8 00 00 00 00          callq  95 <struct_file__f_inode_offset+0x5>
  95:   b8 20 00 00 00          mov    $0x20,%eax
  9a:   c3                      retq   
  9b:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

00000000000000a0 <struct_file_f_pos_offset>:
  a0:   e8 00 00 00 00          callq  a5 <struct_file_f_pos_offset+0x5>
  a5:   b8 68 00 00 00          mov    $0x68,%eax
  aa:   c3                      retq   
  ab:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

00000000000000b0 <struct_inode__i_mode_offset>:
  b0:   e8 00 00 00 00          callq  b5 <struct_inode__i_mode_offset+0x5>
  b5:   31 c0                   xor    %eax,%eax
  b7:   c3                      retq   
  b8:   0f 1f 84 00 00 00 00    nopl   0x0(%rax,%rax,1)
  bf:   00 

00000000000000c0 <struct_inode_i_sb_offset>:
  c0:   e8 00 00 00 00          callq  c5 <struct_inode_i_sb_offset+0x5>
  c5:   b8 28 00 00 00          mov    $0x28,%eax
  ca:   c3                      retq   
  cb:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

00000000000000d0 <struct_super_block_s_dev_offset>:
  d0:   e8 00 00 00 00          callq  d5 <struct_super_block_s_dev_offset+0x5>
  d5:   b8 10 00 00 00          mov    $0x10,%eax
  da:   c3                      retq   
  db:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

00000000000000e0 <struct_file__dentry__sum_offset>:
  e0:   e8 00 00 00 00          callq  e5 <struct_file__dentry__sum_offset+0x5>
  e5:   b8 18 00 00 00          mov    $0x18,%eax
  ea:   c3                      retq   
  eb:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

00000000000000f0 <struct_dentry_name__sum__offset>:
  f0:   e8 00 00 00 00          callq  f5 <struct_dentry_name__sum__offset+0x5>
  f5:   b8 28 00 00 00          mov    $0x28,%eax
  fa:   c3                      retq   
  fb:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

0000000000000100 <struct_dentry__d_parent__offset>:
 100:   e8 00 00 00 00          callq  105 <struct_dentry__d_parent__offset+0x5>
 105:   b8 18 00 00 00          mov    $0x18,%eax
 10a:   c3                      retq   
 10b:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

0000000000000110 <struct_sock_common__skc_family_offset>:
 110:   e8 00 00 00 00          callq  115 <struct_sock_common__skc_family_offset+0x5>
 115:   b8 10 00 00 00          mov    $0x10,%eax
 11a:   c3                      retq   
 11b:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

0000000000000120 <struct_sock_common__skc_rcv_saddr_offset>:
 120:   e8 00 00 00 00          callq  125 <struct_sock_common__skc_rcv_saddr_offset+0x5>
 125:   b8 04 00 00 00          mov    $0x4,%eax
 12a:   c3                      retq   
 12b:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

0000000000000130 <struct_sock_common__skc_daddr_offset>:
 130:   e8 00 00 00 00          callq  135 <struct_sock_common__skc_daddr_offset+0x5>
 135:   31 c0                   xor    %eax,%eax
 137:   c3                      retq   
 138:   0f 1f 84 00 00 00 00    nopl   0x0(%rax,%rax,1)
 13f:   00 

0000000000000140 <struct_sock_common__skc_v6_rcv_saddr_offset>:
 140:   e8 00 00 00 00          callq  145 <struct_sock_common__skc_v6_rcv_saddr_offset+0x5>
 145:   b8 48 00 00 00          mov    $0x48,%eax
 14a:   c3                      retq   
 14b:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

0000000000000150 <struct_sock_common__skc_v6_daddr_offset>:
 150:   e8 00 00 00 00          callq  155 <struct_sock_common__skc_v6_daddr_offset+0x5>
 155:   b8 38 00 00 00          mov    $0x38,%eax
 15a:   c3                      retq   
 15b:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

0000000000000160 <struct_sock_common__skc_dport_offset>:
 160:   e8 00 00 00 00          callq  165 <struct_sock_common__skc_dport_offset+0x5>
 165:   b8 0c 00 00 00          mov    $0xc,%eax
 16a:   c3                      retq   
 16b:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

0000000000000170 <struct_sock_common__skc_num_offset>:
 170:   e8 00 00 00 00          callq  175 <struct_sock_common__skc_num_offset+0x5>
 175:   b8 0e 00 00 00          mov    $0xe,%eax
 17a:   c3                      retq   
 17b:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

0000000000000180 <struct_sock_common__skc_state_offset>:
 180:   e8 00 00 00 00          callq  185 <struct_sock_common__skc_state_offset+0x5>
 185:   b8 12 00 00 00          mov    $0x12,%eax
 18a:   c3                      retq   
 18b:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

0000000000000190 <struct_sock_common__skc_ipv6only_offset>:
 190:   e8 00 00 00 00          callq  195 <struct_sock_common__skc_ipv6only_offset+0x5>
 195:   b8 13 00 00 00          mov    $0x13,%eax
 19a:   c3                      retq   
 19b:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

00000000000001a0 <struct_file_f_path_offset>:
 1a0:   e8 00 00 00 00          callq  1a5 <struct_file_f_path_offset+0x5>
 1a5:   b8 10 00 00 00          mov    $0x10,%eax
 1aa:   c3                      retq   
 1ab:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

00000000000001b0 <struct_path_mnt_offset>:
 1b0:   e8 00 00 00 00          callq  1b5 <struct_path_mnt_offset+0x5>
 1b5:   31 c0                   xor    %eax,%eax
 1b7:   c3                      retq   
 1b8:   0f 1f 84 00 00 00 00    nopl   0x0(%rax,%rax,1)
 1bf:   00 

00000000000001c0 <struct_ns_common_inum_offset>:
 1c0:   e8 00 00 00 00          callq  1c5 <struct_ns_common_inum_offset+0x5>
 1c5:   b8 10 00 00 00          mov    $0x10,%eax
 1ca:   c3                      retq   
 1cb:   0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)

00000000000001d0 <init_module>:
 1d0:   e8 00 00 00 00          callq  1d5 <init_module+0x5>
 1d5:   31 c0                   xor    %eax,%eax
 1d7:   c3                      retq   
 1d8:   0f 1f 84 00 00 00 00    nopl   0x0(%rax,%rax,1)
 1df:   00 

00000000000001e0 <cleanup_module>:
 1e0:   e8 00 00 00 00          callq  1e5 <cleanup_module+0x5>
 1e5:   c3                      retq  
```

## 注意

内核结构体 `struct mount` 和 `struct mnt_namespace` 定义在：`linux/source/fs/mount.h`


但此文件通常不包含在 `kernel-devel` 包中，导致无法直接通过头文件获取结构体成员偏移。

## 解决方案

利用 `kernel-debuginfo` 包中的 `vmlinux` 文件和 `pahole` 工具，通过 DWARF 调试信息提取结构体成员的偏移。

## 示例

以 CentOS / RHEL 7，内核版本 4.19.17 为例，使用如下命令：

```c
pahole -C mount /usr/lib/debug/lib/modules/4.19.17-1.el7.x86_64/vmlinux
struct mount {
    ...
    struct vfsmount            mnt;        /*    32    24 */
    ...
    struct mnt_namespace *     mnt_ns;     /*   224     8 */
    ...
    int                        mnt_id;     /*   284     4 */
};
pahole -C mnt_namespace /usr/lib/debug/lib/modules/4.19.17-1.el7.x86_64/vmlinux
struct mnt_namespace {
    ...
    struct ns_common           ns;         /*     8    24 */
    ...
};
```
通过上面的方式得到 mnt、mnt_ns、mnt_id、ns 的偏移。

## 如果遇到问题

如果遇到问题或你的系统还未支持，请新建 issue，运行 `make` 并将完整输出和 `pahole` 得到的偏移值粘贴到 issue 中。
提交地址：
https://github.com/deepflowio/deepflow/issues
