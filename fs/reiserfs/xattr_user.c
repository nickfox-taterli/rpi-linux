#include "reiserfs.h"
#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/pagemap.h>
#include <linux/xattr.h>
#include "xattr.h"
#include <linux/uaccess.h>

static int
user_get(const struct xattr_handler *handler, struct dentry *unused,
	 struct inode *inode, const char *name, void *buffer, size_t size)
{
<<<<<<< HEAD
	if (!reiserfs_xattrs_user(inode->i_sb))
		return -EOPNOTSUPP;
	return reiserfs_xattr_get(inode, xattr_full_name(handler, name),
=======
	if (!reiserfs_xattrs_user(dentry->d_sb))
		return -EOPNOTSUPP;
	return reiserfs_xattr_get(d_inode(dentry),
				  xattr_full_name(handler, name),
>>>>>>> upstream/rpi-4.4.y
				  buffer, size);
}

static int
user_set(const struct xattr_handler *handler, struct dentry *unused,
	 struct inode *inode, const char *name, const void *buffer,
	 size_t size, int flags)
{
<<<<<<< HEAD
	if (!reiserfs_xattrs_user(inode->i_sb))
		return -EOPNOTSUPP;
	return reiserfs_xattr_set(inode,
=======
	if (!reiserfs_xattrs_user(dentry->d_sb))
		return -EOPNOTSUPP;
	return reiserfs_xattr_set(d_inode(dentry),
>>>>>>> upstream/rpi-4.4.y
				  xattr_full_name(handler, name),
				  buffer, size, flags);
}

static bool user_list(struct dentry *dentry)
{
	return reiserfs_xattrs_user(dentry->d_sb);
}

const struct xattr_handler reiserfs_xattr_user_handler = {
	.prefix = XATTR_USER_PREFIX,
	.get = user_get,
	.set = user_set,
	.list = user_list,
};
