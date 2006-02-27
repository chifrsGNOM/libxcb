/*
 * Copyright (C) 2001-2004 Bart Massey and Jamey Sharp.
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 * 
 * Except as contained in this notice, the names of the authors or their
 * institutions shall not be used in advertising or otherwise to promote the
 * sale, use or other dealings in this Software without prior written
 * authorization from the authors.
 */

#ifndef __XCBEXT_H
#define __XCBEXT_H

#include "xcb.h"

#ifdef __cplusplus
extern "C" {
#endif

/* xcb_ext.c */

struct XCBExtension {
    const char *name;
    int global_id;
};


/* xcb_out.c */

typedef struct {
    size_t count;
    XCBExtension *ext;
    CARD8 opcode;
    BOOL isvoid;
} XCBProtocolRequest;

enum XCBSendRequestFlags {
    XCB_REQUEST_CHECKED = 1 << 0,
    XCB_REQUEST_RAW = 1 << 1
};

int XCBSendRequest(XCBConnection *c, unsigned int *sequence, int flags, struct iovec *vector, const XCBProtocolRequest *request);


/* xcb_in.c */

void *XCBWaitForReply(XCBConnection *c, unsigned int request, XCBGenericError **e);


/* xcb_xid.c */

CARD32 XCBGenerateID(XCBConnection *c);


/* xcb_util.c */

int XCBPopcount(CARD32 mask);

#ifdef __cplusplus
}
#endif

#endif
