

#include "common.h"





struct fs_super *superblk;

void zeroize_bitmaparea()
{
	printf("make zero bitmap area on disk");
}

int load_superblk_tomem()
{
}

int flush_any_buffers()
{
	/* should flush buffers 
	* if we are using 
	* any caching
	*/
}


int mk_simplefs()
{

	char *ptr;
	
	
	
	superblk = malloc(sizeof(struct fs_super));
	if(superblk == NULL)
	{
		fprintf(stderr, "malloc failed\n");
		return -1;
	}
	if ((ptr = (char *) malloc(DISK_SIZE)) == NULL) {
		fprintf(stderr, "malloc failed\n");
		return -1;
	}
	superblk->disk_start = ptr;
	superblk->disk_end = superblk->disk_start+DISK_SIZE;

	superblk->disk_num_sectors = DISK_SIZE/512;

	printf("fs_init");
	printf("diskstart = %u",superblk->disk_start);
	
	printf("disk_end = %u",superblk->disk_end);
	printf("disk num sectors = %d\n",superblk->disk_num_sectors);

	/* 1 sector for bootblk: what do we store here?
	 * 1 sector for superblk
	 * remaining 2046 sectors
	 *
	 * datablksize + bitmapareasize +inodeareasize = 2046 sectors
	 * numdatasectors + numdatasectors/8 + inodeareasize = 2046 sectors
	 * (1.125)*(numdatasectors) + inodeareasize = 2046
	 * 
	 * inodeareasize = 32 sectors, (maxnumfiles = 256 if the inodesize = 64
	 * numdatasectors = 1790 sectors
	 * bitmapsize = 223 sectors 
	 *
	 */
	 


	/* create root directory entry
 	 * disk format of the filesystem
         * _________________________________________________________
	 * | bootblk | Superblk | inodes | alloc bitmap| Datablocks|
	 * --------------------------------------------------------
	 * initialise block allocation bitmap
	 */
	
	superblk->superblk_start = superblk->disk_start+1*SECTOR_SIZE;
	superblk->inode_bitmaparea_start = superblk->disk_start+2*SECTOR_SIZE;
	superblk->inodearea_start = superblk->disk_start+3*SECTOR_SIZE;
	superblk->data_bitmaparea_start = superblk->disk_start+35*SECTOR_SIZE;
	superblk->datablkarea_start = superblk->disk_start+258*SECTOR_SIZE;

	
	printf("superblk_start = %u\n",(unsigned int)superblk->superblk_start);
	printf("inodearea_start = %u\n",(unsigned int)superblk->inode_bitmaparea_start);
	printf("inodearea_start = %u\n",(unsigned int)superblk->inodearea_start);
	printf("bitmaparea_start = %u\n",(unsigned int)superblk->data_bitmaparea_start);
	printf("datablkarea_start = %u\n",(unsigned int)superblk->datablkarea_start);
	
	create_root_inode();
	zeroize_bitmaparea();
	
			
}

int create_root_inode()
{
	struct inode *root_inode;
//	create_inode();
	printf("sizeof inode = %d\n", sizeof(struct inode));
	root_inode = inode_create();
	if(root_inode != NULL)
		superblk->root_inode = root_inode;
			
}




int fs_mount()
{
	load_superblk_tomem();
}

int fs_unmount()
{

	flush_any_buffers();
}


int fs_ls()
{

}

int fs_rm(char *name)
{

}



