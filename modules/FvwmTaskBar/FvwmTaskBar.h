/* FvwmTaskBar Module for Fvwm.
 *
 *  Copyright 1994,  Mike Finger (mfinger@mermaid.micro.umn.edu or
 *                               Mike_Finger@atk.com)
 *
 * The author makes not guarantees or warantees, either express or
 * implied.  Feel free to use any contained here for any purpose, as long
 * and this and any other applicible copyrights are kept intact.

 * The functions in this header file that are based on part of the FvwmIdent
 * module for Fvwm are noted by a small copyright atop that function, all others
 * are copyrighted by Mike Finger.  For those functions modified/used, here is
 * the full, original copyright:
 *
 * Copyright 1994, Robert Nation and Nobutaka Suzuki.
 * No guarantees or warantees or anything
 * are provided or implied in any way whatsoever. Use this program at your
 * own risk. Permission to use this program for any purpose is given,
 * as long as the copyright is kept intact. */

#ifndef FVWMTASKBAR_H
#define FVWMTASKBAR_H

#include "config.h"
#include "fvwm/fvwm.h"
#include "libs/vpacket.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xproto.h>
#include <X11/Xatom.h>
#include <X11/Intrinsic.h>
#include <X11/cursorfont.h>

#define F_SWALLOWED      1
#define F_NOT_SWALLOWED  2

#define F_ICONIFIED	(1<<2)


/* Motif  window hints */
typedef struct
{
    CARD32      flags;
    CARD32      functions;
    CARD32      decorations;
    INT32       inputMode;
} PropMotifWmHints;

typedef PropMotifWmHints        PropMwmHints;

/* Motif window hints */
#define MWM_HINTS_FUNCTIONS     (1L << 0)
#define MWM_HINTS_DECORATIONS   (1L << 1)
#define MWM_HINTS_INPUT_MODE    (1L << 2)

/* bit definitions for MwmHints.functions */
#define MWM_FUNC_ALL            (1L << 0)
#define MWM_FUNC_RESIZE         (1L << 1)
#define MWM_FUNC_MOVE           (1L << 2)
#define MWM_FUNC_MINIMIZE       (1L << 3)
#define MWM_FUNC_MAXIMIZE       (1L << 4)
#define MWM_FUNC_CLOSE          (1L << 5)

/* values for MwmHints.input_mode */
#define MWM_INPUT_MODELESS                      0
#define MWM_INPUT_PRIMARY_APPLICATION_MODAL     1
#define MWM_INPUT_SYSTEM_MODAL                  2
#define MWM_INPUT_FULL_APPLICATION_MODAL        3

/* bit definitions for MwmHints.decorations */
#define MWM_DECOR_ALL                 (1L << 0)
#define MWM_DECOR_BORDER              (1L << 1)
#define MWM_DECOR_RESIZEH             (1L << 2)
#define MWM_DECOR_TITLE               (1L << 3)
#define MWM_DECOR_MENU                (1L << 4)
#define MWM_DECOR_MINIMIZE            (1L << 5)
#define MWM_DECOR_MAXIMIZE            (1L << 6)

#define PROP_MOTIF_WM_HINTS_ELEMENTS  4
#define PROP_MWM_HINTS_ELEMENTS       PROP_MOTIF_WM_HINTS_ELEMENTS

/* Alarm Events */
#define NOT_SET        0
#define SHOW_TIP       1
#define HIDE_TASK_BAR  2

/*************************************************************************
  Subroutine Prototypes
**************************************************************************/
extern void EndLessLoop(void);
extern void ReadFvwmPipe(void);
extern void ProcessMessage(unsigned long type,unsigned long *body);
extern void SendFvwmPipe(char *message,unsigned long window);
extern void DeadPipe(int nonsense);
extern void Alarm(int nonsense);
extern void SetAlarm(int event);
extern void ClearAlarm(void);
extern void CheckForTip(int x, int y);
extern void MakeMeWindow(void);
extern void WaitForExpose(void);
extern void RedrawWindow(int force);
extern void StartMeUp(void);
extern int OpenConsole(void);
extern void ConsoleMessage(char *fmt,...);
extern void LoopOnEvents(void);
extern void AdjustWindow(int width, int height);
extern char *makename(char *string,long flags);
extern void ChangeWindowName(char *str);
extern void LinkAction(char *string);
extern void AddToSkipList(char *string);
extern int InSkipList(char *string);
extern void PrintSkipList(void);
extern void FvwmNameMessage(long *body);
extern void SetMwmHints(unsigned int value,
			unsigned int funcs,unsigned int input);
extern void ConstrainSize (XSizeHints *hints, int *widthp, int *heightp);
extern void RevealTaskBar(void);
extern void HideTaskBar(void);
extern void WarpTaskBar(int x);
extern void PurgeConfigEvents(void);

extern void Swallow(unsigned long *body);

#endif
