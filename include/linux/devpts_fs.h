/* -*- linux-c -*- --------------------------------------------------------- *
 *
 * linux/include/linux/devpts_fs.h
 *
 *  Copyright 1998-2004 H. Peter Anvin -- All Rights Reserved
 *
 * This file is part of the Linux kernel and is made available under
 * the terms of the GNU General Public License, version 2, or at your
 * option, any later version, incorporated herein by reference.
 *
 * ------------------------------------------------------------------------- */

#ifndef _LINUX_DEVPTS_FS_H
#define _LINUX_DEVPTS_FS_H

#include <linux/errno.h>

struct pts_fs_info;

#ifdef CONFIG_UNIX98_PTYS

<<<<<<< HEAD
struct pts_fs_info;

struct pts_fs_info *devpts_acquire(struct file *);
void devpts_release(struct pts_fs_info *);
=======
/* Look up a pts fs info and get a ref to it */
struct pts_fs_info *devpts_get_ref(struct inode *, struct file *);
void devpts_put_ref(struct pts_fs_info *);
>>>>>>> upstream/rpi-4.4.y

int devpts_new_index(struct pts_fs_info *);
void devpts_kill_index(struct pts_fs_info *, int);

/* mknod in devpts */
<<<<<<< HEAD
struct dentry *devpts_pty_new(struct pts_fs_info *, int, void *);
=======
struct inode *devpts_pty_new(struct pts_fs_info *, dev_t, int, void *);
>>>>>>> upstream/rpi-4.4.y
/* get private structure */
void *devpts_get_priv(struct dentry *);
/* unlink */
<<<<<<< HEAD
void devpts_pty_kill(struct dentry *);
=======
void devpts_pty_kill(struct inode *inode);
>>>>>>> upstream/rpi-4.4.y

#endif


#endif /* _LINUX_DEVPTS_FS_H */
