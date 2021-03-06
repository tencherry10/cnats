// Copyright 2015 Apcera Inc. All rights reserved.

#ifndef N_WIN_H_
#define N_WIN_H_

#include <winsock2.h>
#include <ws2tcpip.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef WIN32_LEAN_AND_MEAN

#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "Ws2_32.lib")
#pragma warning(disable : 4996)

typedef struct __natsThread
{
    HANDLE  t;
    DWORD   id;

} natsThread;

typedef DWORD               natsThreadLocal;

typedef CRITICAL_SECTION    natsMutex;
typedef CONDITION_VARIABLE  natsCondition;
typedef INIT_ONCE           natsInitOnceType;
typedef SOCKET              natsSock;
typedef int                 natsSockLen;
typedef int                 natsRecvLen;

#define NATS_ONCE_TYPE          INIT_ONCE
#define NATS_ONCE_STATIC_INIT   INIT_ONCE_STATIC_INIT

#define NATS_SOCK_INVALID               (INVALID_SOCKET)
#define NATS_SOCK_CLOSE(s)              closesocket((s))
#define NATS_SOCK_SHUTDOWN(s)           shutdown((s), SD_BOTH)
#define NATS_SOCK_CONNECT_IN_PROGRESS   (WSAEWOULDBLOCK)
#define NATS_SOCK_WOULD_BLOCK           (WSAEWOULDBLOCK)
#define NATS_SOCK_ERROR                 (SOCKET_ERROR)
#define NATS_SOCK_GET_ERROR             WSAGetLastError()

// Windows doesn't have those..
#define snprintf    _snprintf
#define strcasecmp  _stricmp

int
nats_asprintf(char **newStr, const char *fmt, ...);

char*
nats_strcasestr(const char *haystack, const char *needle);

#endif /* N_WIN_H_ */
