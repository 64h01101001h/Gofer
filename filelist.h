/* filelist.h
 *
 * Definitions for filelist.c
 */

/* Copyright (c) 2004,2005 Edward W. Lemon III
 *
 *  This file is part of GOFER.
 *
 *  GOFER is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  GOFER is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GOFER, in a file called COPYING; if not, write
 *  to the Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 *  Boston, MA  02111-1307  USA
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct matchzone {
  int first_line;
  int last_line;
  int first_char;
  int first_len;
  int last_char;
  int last_len;
  int cur_line;
  int cur_char;
} matchzone_t;

typedef struct fileresult {
  char *filename;
  char *reducename;
  char *contents;
  int content_length;
  int nzones;
  int maxzones;
  int curzone;
  matchzone_t **matches;
} fileresults_t;

typedef struct filelist {
  int nfiles;
  int maxfiles;
  fileresults_t **files;
  int cur_file;
  int cur_file_seen;
  int cur_match_seen;
} filelist_t;
	
filelist_t *new_filelist(void);
void new_entry(filelist_t *dest,
	       const char *filename, char *contents, int content_length,
	       int first_line, int last_line,
	       int first_char, int first_len,
	       int last_char, int last_len,
	       int *cur_line, int *cur_char);
void filelist_free(filelist_t *fl);

#ifdef __cplusplus
}
#endif

/* Local Variables:  */
/* mode:C */
/* c-file-style:"gnu" */
/* end: */
