/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _RPC_H_RPCGEN
#define _RPC_H_RPCGEN

#include <src/xdr.h>

typedef struct call_body call_body;
typedef struct accepted_reply accepted_reply;
typedef struct rejected_reply rejected_reply;
typedef struct rpc_mismatch_info rpc_mismatch_info;
typedef struct opaque_auth opaque_auth;
typedef struct authsys_parms authsys_parms;
typedef struct rpc_reply_data rpc_reply_data;
typedef struct rpc_msg_body rpc_msg_body;
typedef struct reply_body reply_body;
typedef struct rpc_msg rpc_msg;


enum class auth_flavor {
	AUTH_NONE = 0,
	AUTH_SYS = 1,
	AUTH_SHORT = 2,
	AUTH_DH = 3,
	RPCSEC_GSS = 6,
};

enum class msg_type {
	CALL = 0U,
	REPLY = 1U
};

enum class reply_stat {
	MSG_ACCEPTED = 0U,
	MSG_DENIED = 1U
};

enum class accept_stat {
	SUCCESS = 0U,
	PROG_UNAVAIL = 1U,
	PROG_MISMATCH = 2U,
	PROC_UNAVAIL = 3U,
	GARBAGE_ARGS = 4U,
	SYSTEM_ERR = 5U
};

enum class reject_stat {
	RPC_MISMATCH = 0U,
	AUTH_ERROR = 1U
};

enum class auth_stat {
	AUTH_OK = 0U,
	AUTH_BADCRED = 1U,
	AUTH_REJECTEDCRED = 2U,
	AUTH_BADVERF = 3U,
	AUTH_REJECTEDVERF = 4U,
	AUTH_TOOWEAK = 5U,
	AUTH_INVALIDRESP = 6U,
	AUTH_FAILED = 7U,
	AUTH_KERB_GENERIC = 8U,
	AUTH_TIMEEXPIRE = 9U,
	AUTH_TKT_FILE = 10U,
	AUTH_DECODE = 11U,
	AUTH_NET_ADDR = 12U,
	RPCSEC_GSS_CREDPROBLEM = 13U,
	RPCSEC_GSS_CTXPROBLEM = 14U
};

//typedef enum auth_flavor auth_flavor;
//typedef enum auth_stat auth_stat;
//typedef enum msg_type msg_type;
//typedef enum reply_stat reply_stat;
//typedef enum accept_stat accept_stat;
//typedef enum reject_stat reject_stat;

struct opaque_auth {
  auth_flavor flavor;
  struct {
    u_int body_len;
    char *body_val;
  } body;
};

struct call_body {
	u_int rpcvers;
	u_int prog;
	u_int vers;
	u_int proc;
	opaque_auth cred;
	opaque_auth verf;
};

struct rpc_mismatch_info {
  u_int low;
  u_int high;
};

struct rpc_reply_data {
  accept_stat stat;
  union {
    char results[0];
    rpc_mismatch_info mismatch_info;
  } rpc_reply_data_u;
};

struct accepted_reply {
  opaque_auth verf;
  rpc_reply_data reply_data;
};

struct rejected_reply {
  reject_stat stat;
  union {
    rpc_mismatch_info mismatch_info;
    auth_stat astat;
  } rejected_reply_u;
};

struct reply_body {
	reply_stat stat;
	union {
		accepted_reply areply;
		rejected_reply rreply;
	} reply_body_u;
};

struct rpc_msg_body {
	msg_type mtype;
	union {
		call_body cbody;
		reply_body rbody;
	} rpc_msg_body_u;
};

struct rpc_msg {
	u_int xid;
	rpc_msg_body body;
};

struct authsys_parms {
	u_int stamp;
	char *machinename;
	u_int uid;
	u_int gid;
	struct {
		u_int gids_len;
		u_int *gids_val;
	} gids;
};

/* the xdr functions */
extern  bool_t xdr_auth_flavor (XDR *, auth_flavor*);
extern  bool_t xdr_opaque_auth (XDR *, opaque_auth*);
extern  bool_t xdr_msg_type (XDR *, msg_type*);
extern  bool_t xdr_reply_stat (XDR *, reply_stat*);
extern  bool_t xdr_accept_stat (XDR *, accept_stat*);
extern  bool_t xdr_reject_stat (XDR *, reject_stat*);
extern  bool_t xdr_auth_stat (XDR *, auth_stat*);
extern  bool_t xdr_call_body (XDR *, call_body*);
extern  bool_t xdr_reply_body (XDR *, reply_body*);
extern  bool_t xdr_rpc_mismatch_info (XDR *, rpc_mismatch_info*);
extern  bool_t xdr_rpc_msg_body (XDR *, rpc_msg_body*);
extern  bool_t xdr_rpc_reply_data (XDR *, rpc_reply_data*);
extern  bool_t xdr_rpc_msg (XDR *, rpc_msg*);
extern  bool_t xdr_accepted_reply (XDR *, accepted_reply*);
extern  bool_t xdr_rejected_reply (XDR *, rejected_reply*);
extern  bool_t xdr_authsys_parms (XDR *, authsys_parms*);

#endif /* !_RPC_H_RPCGEN */
