#ifndef FONT_H
#define FONT_H

#include "Types.h"
#include "VObject.h"


#define DEFAULT_SHADOW		RGB(  0,   0,   0) // 2
#define MILITARY_SHADOW	RGB( 17, 178, 216) // 67
#define NO_SHADOW		0x00000000

// these are bogus! No palette is set yet!
// font foreground color symbols
#define FONT_FCOLOR_WHITE	RGB(255, 255, 255)
#define FONT_FCOLOR_RED	RGB(255,  64,  64)
#define FONT_FCOLOR_NICERED	RGB(205,   0,   0)
#define FONT_FCOLOR_BLUE	RGB(  0,   0, 255)
#define FONT_FCOLOR_GREEN	RGB(  0, 206,   0)
#define FONT_FCOLOR_YELLOW	RGB(255, 215,  63)
#define FONT_FCOLOR_BROWN	RGB(  0, 206,   0) // this ain't right
#define FONT_FCOLOR_ORANGE	RGB(240, 116,  45)
#define FONT_FCOLOR_PURPLE	RGB(255, 193, 193)

extern SGPFont FontDefault;


void SetFontColors(UINT32 uForeground, UINT32 uBackground);
void SetFontForeground(UINT32 uForeground);
void SetFontBackground(UINT32 uBackground);
void SetFontShadow(UINT32 uBackground);

/* Print to the currently selected destination buffer, at the X/Y coordinates
 * specified, using the currently selected font. Other than the X/Y coordinates,
 * the parameters are identical to printf. The resulting string may be no longer
 * than 512 word-characters. */
void gprintf(INT32 x, INT32 y, wchar_t const* fmt, ...);

UINT32 MPrintChar(INT32 x, INT32 y, wchar_t);
void   MPrintBuffer(UINT16* pDestBuf, UINT32 uiDestPitchBYTES, INT32 x, INT32 y, wchar_t const* str);
void   MPrint(INT32 x, INT32 y, wchar_t const* str);
void   mprintf(INT32 x, INT32 y, wchar_t const* fmt, ...);
void   mprintf_buffer(UINT16* pDestBuf, UINT32 uiDestPitchBYTES, INT32 x, INT32 y, wchar_t const* fmt, ...);

/* Sets the destination buffer for printing to and the clipping rectangle. */
void SetFontDestBuffer(SGPVSurface* dst, INT32 x1, INT32 y1, INT32 x2, INT32 y2);

/* Set the destination buffer for printing while using the whole surface. */
void SetFontDestBuffer(SGPVSurface* dst);

/** Replace backbuffer if it is used by the font system. */
void ReplaceFontBackBuffer(SGPVSurface* oldBackbuffer, SGPVSurface* newBackbuffer);

void SetFont(SGPFont);

void SetFontAttributes(SGPFont, const UINT32 foreground, const UINT32 shadow = DEFAULT_SHADOW, const UINT32 background = 0);

SGPFont LoadFontFile(const char* filename);
UINT16  GetFontHeight(SGPFont);
void    InitializeFontManager(void);
void    UnloadFont(SGPFont);

UINT32 GetCharWidth(HVOBJECT SGPFont, wchar_t c);

INT16 StringPixLength(const wchar_t* string, SGPFont);
extern void SaveFontSettings(void);
extern void RestoreFontSettings(void);

void FindFontRightCoordinates( INT16 sLeft, INT16 sTop, INT16 sWidth, INT16 sHeight, const wchar_t* pStr, SGPFont, INT16* psNewX, INT16* psNewY);
void FindFontCenterCoordinates(INT16 sLeft, INT16 sTop, INT16 sWidth, INT16 sHeight, const wchar_t* pStr, SGPFont, INT16* psNewX, INT16* psNewY);

bool IsPrintableChar(wchar_t);

#endif
