/*\file n_nodup_log.h
 * generic log system with no duplicate
 *\author Castagnier Mickael
 *\date 2013-04-15
 */
#ifndef __NO_DUP_LOG_HEADER_GUARD__
#define __NO_DUP_LOG_HEADER_GUARD__

#ifdef __cplusplus
extern "C"
{
#endif

/**\defgroup LOG LOGGING: logging to console, to file, to syslog under *x
   \addtogroup LOG
  @{
*/

#ifdef __linux__
#define _GNU_SOURCE
#endif
#include "n_common.h"
#include "n_log.h"
#include "n_str.h"
#include "n_list.h"
#include "n_hash.h"
#ifdef __linux__
#undef _GNU_SOURCE
#endif
/* init the nodup log internal hash_table */
int init_nodup_log( int max );
/* empty the nodup table */
int empty_nodup_table();
/* end nodup session */
int close_nodup_log();

#define n_nodup_log( __LEVEL__  , ... ) \
   do \
   { \
      _n_nodup_log( __LEVEL__ , __FILE__ , __func__ , __LINE__ , __VA_ARGS__ ); \
   }while( 0 )


#define n_nodup_log_indexed( __LEVEL__  , __PREF__ , ... ) \
   do \
   { \
      _n_nodup_log_indexed( __LEVEL__ , __PREF__ , __FILE__ , __func__ , __LINE__ , __VA_ARGS__ ); \
   }while( 0 )

/* no duplicate logging, single */
void _n_nodup_log( int LEVEL, const char *file, const char *func, int line, const char *format, ... );
/* no duplicate logging, mutliple with index */
void _n_nodup_log_indexed( int LEVEL, const char *prefix, const char *file, const char *func, int line, const char *format, ... );
/* dump the saved duplicate error log hash table in a specific file, human
 * readable */
int dump_nodup_log( char *file );


/*@}*/

#ifdef __cplusplus
}
#endif
#endif
