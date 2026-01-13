#include <linux/mount.h>
#include <linux/nsproxy.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/skbuff.h>
#include <linux/socket.h>
#include <linux/hash.h>
#include <linux/in.h>
#include <linux/net.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/fdtable.h>
#include <linux/version.h>
#include <net/tcp.h>

// copied_seq
int struct_tcp_sock__copied_seq_offset(void)
{
	return offsetof(typeof(struct tcp_sock), copied_seq);
}

// write_seq
int struct_tcp_sock__write_seq_offset(void)
{
	return offsetof(typeof(struct tcp_sock), write_seq);
}

// snd_nxt
int struct_tcp_sock__snd_nxt_offset(void)
{
	return offsetof(typeof(struct tcp_sock), snd_nxt);
}

// files
int struct_task_struct__files_offset(void)
{
	return offsetof(typeof(struct task_struct), files);
}

// __sk_flags_offset
int struct_sock____sk_flags_offset_offset(void)
{
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 6, 0))
	return offsetof(typeof(struct sock), __sk_flags_offset);
#else
	return offsetof(typeof(struct sock), sk_pacing_shift) - 1;
#endif
}

// fdt
int struct_files_struct_fdt_offset(void)
{
	return offsetof(typeof(struct files_struct), fdt);
}

// private_data
int STRUCT_FILES_PRIVATE_DATA_OFFSET(void)
{
	return offsetof(typeof(struct file), private_data);
}

// f_op
int struct_file_f_op_offset(void)
{
	return offsetof(typeof(struct file), f_op);
}

// read_iter
int struct_file_operations_read_iter_offset(void)
{
	return offsetof(typeof(struct file_operations), read_iter);
}

// f_inode
int struct_file__f_inode_offset(void)
{
	return offsetof(typeof(struct file), f_inode);
}

// f_pos
int struct_file_f_pos_offset(void)
{
	return offsetof(typeof(struct file), f_pos);
}

// i_mode
int struct_inode__i_mode_offset(void)
{
	return offsetof(typeof(struct inode), i_mode);
}

// i_sb
int struct_inode_i_sb_offset(void)
{
	return offsetof(typeof(struct inode), i_sb);
}

// s_dev
int struct_super_block_s_dev_offset(void)
{
	return offsetof(typeof(struct super_block), s_dev);
}

// struct_file_dentry_offset
int struct_file__dentry__sum_offset(void)
{
	return offsetof(typeof(struct file),
			f_path) + offsetof(typeof(struct path), dentry);
}

// dentry_name
int struct_dentry_name__sum__offset(void)
{
	return offsetof(typeof(struct dentry),
			d_name) + offsetof(typeof(struct qstr), name);
}

// d_parent
int struct_dentry__d_parent__offset(void)
{
	return offsetof(typeof(struct dentry), d_parent);
}

// skc_family
int struct_sock_common__skc_family_offset(void)
{
	return offsetof(typeof(struct sock_common), skc_family);
}

// skc_rcv_saddr
int struct_sock_common__skc_rcv_saddr_offset(void)
{
	return offsetof(typeof(struct sock_common), skc_rcv_saddr);
}

// skc_daddr
int struct_sock_common__skc_daddr_offset(void)
{
	return offsetof(typeof(struct sock_common), skc_daddr);
}

// skc_v6_rcv_saddr
int struct_sock_common__skc_v6_rcv_saddr_offset(void)
{
	return offsetof(typeof(struct sock_common), skc_v6_rcv_saddr);
}

// skc_v6_daddr
int struct_sock_common__skc_v6_daddr_offset(void)
{
	return offsetof(typeof(struct sock_common), skc_v6_daddr);
}

// skc_dport
int struct_sock_common__skc_dport_offset(void)
{
	return offsetof(typeof(struct sock_common), skc_dport);
}

// skc_num
int struct_sock_common__skc_num_offset(void)
{
	return offsetof(typeof(struct sock_common), skc_num);
}

// skc_state
int struct_sock_common__skc_state_offset(void)
{
	return offsetof(typeof(struct sock_common), skc_state);
}

// skc_state 
int struct_sock_common__skc_ipv6only_offset(void)
{
	return offsetof(typeof(struct sock_common), skc_state) + 1;
}

//f_path
int struct_file_f_path_offset(void)
{
	return offsetof(typeof(struct file), f_path);
}

// mnt
int struct_path_mnt_offset(void)
{
	return offsetof(typeof(struct path), mnt);
}

// inum
int struct_ns_common_inum_offset(void)
{
	return offsetof(typeof(struct ns_common), inum);
}

// `linux/source/fs/mount.h` does not exist in the `kernel-devel` package.
// mount mnt
//int struct_mount_mnt_offset(void)
//{
//	return offsetof(typeof(struct mount), mnt);
//}

// mnt_ns
//int struct_mount_mnt_ns_offset(void)
//{
//	return offsetof(typeof(struct mount), mnt_ns);
//}

// ns
//int struct_mnt_namespace_ns_offset(void)
//{
//	return offsetof(typeof(struct mnt_namespace), ns);
//}

// mnt_id
//int struct_mount_mnt_id_offset(void)
//{
//	return offsetof(typeof(struct mount), mnt_id);
//}

static int init_skso(void)
{
	return 0;
}

static void exit_skso(void)
{
	return;
}

module_init(init_skso);
module_exit(exit_skso);

MODULE_LICENSE("Proprietary");
