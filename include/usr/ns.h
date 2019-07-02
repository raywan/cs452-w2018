#ifndef __NS_H__
#define __NS_H__

#define NS_TID 1
#define NS_NAME_MAX_SIZE 50
#define NS_MAX_ENTRIES 100

#define NS_TYPE_SUCCESS 0
#define NS_TYPE_BAD_REQUEST -404

#define NS_TYPE_REGISTER 10
#define NS_TYPE_REGISTER_BAD_NAME -11
#define NS_TYPE_REGISTER_DUPLICATE -12
#define NS_TYPE_REGISTER_FULL -13

#define NS_TYPE_LOOKUP 20
#define NS_TYPE_LOOKUP_BAD_NAME -21
#define NS_TYPE_LOOKUP_NOT_FOUND -22

typedef struct NS_Req {
  int type;
  char *name;
  int tid;
} NS_Req;

typedef struct NS_Entry {
  int tid;
  char name[NS_NAME_MAX_SIZE + 1];
} NS_Entry;

void ns_task(void);

int RegisterAs(char *name);
int WhoIs(char *name);

#endif
