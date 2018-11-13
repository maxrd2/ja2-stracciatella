#include "Directories.h"
#include "Font.h"
#include "HImage.h"
#include "VObject.h"
#include "VSurface.h"
#include "WCheck.h"
#include "Font_Control.h"
#include "MemMan.h"
#include "GameRes.h"
#include "GameState.h"


SGPFont gp10PointArial;
SGPFont gp10PointArialBold;
SGPFont gp12PointArial;
SGPFont gp12PointArialFixedFont;
SGPFont gp12PointFont1;
SGPFont gp14PointArial;
SGPFont gp14PointHumanist;
SGPFont gp16PointArial;
SGPFont gpBlockFontNarrow;
SGPFont gpBlockyFont;
SGPFont gpBlockyFont2;
SGPFont gpCompFont;
SGPFont gpLargeFontType1;
SGPFont gpSmallCompFont;
SGPFont gpSmallFontType1;
SGPFont gpTinyFontType1;

SGPFont gpHugeFont;


void InitializeFonts(void)
{
#define M(var, file) ((var) = LoadFontFile((file)))
	M(gp10PointArial,          FONTSDIR "/font10arial.sti");
	M(gp10PointArialBold,      FONTSDIR "/font10arialbold.sti");
	M(gp12PointArial,          FONTSDIR "/font12arial.sti");
	M(gp12PointArialFixedFont, FONTSDIR "/font12arialfixedwidth.sti");
	M(gp12PointFont1,          FONTSDIR "/font12point1.sti");
	M(gp14PointArial,          FONTSDIR "/font14arial.sti");
	M(gp14PointHumanist,       FONTSDIR "/font14humanist.sti");
	M(gp16PointArial,          FONTSDIR "/font16arial.sti");
	M(gpBlockFontNarrow,       FONTSDIR "/blockfontnarrow.sti");
	M(gpBlockyFont,            FONTSDIR "/blockfont.sti");
	M(gpBlockyFont2,           FONTSDIR "/blockfont2.sti");
	M(gpCompFont,              FONTSDIR "/compfont.sti");
	M(gpLargeFontType1,        FONTSDIR "/largefont1.sti");
	M(gpSmallCompFont,         FONTSDIR "/smallcompfont.sti");
	M(gpSmallFontType1,        FONTSDIR "/smallfont1.sti");
	M(gpTinyFontType1,         FONTSDIR "/tinyfont1.sti");

	if(GameState::getInstance()->isEditorMode() && isEnglishVersion())
	{
		M(gpHugeFont, FONTSDIR "/hugefont.sti");
	}
#undef M

	// Set default for font system
	SetFontDestBuffer(FRAME_BUFFER);
}


void ShutdownFonts(void)
{
	UnloadFont(gp10PointArial);
	UnloadFont(gp10PointArialBold);
	UnloadFont(gp12PointArial);
	UnloadFont(gp12PointArialFixedFont);
	UnloadFont(gp12PointFont1);
	UnloadFont(gp14PointArial);
	UnloadFont(gp14PointHumanist);
	UnloadFont(gp16PointArial);
	UnloadFont(gpBlockFontNarrow);
	UnloadFont(gpBlockyFont);
	UnloadFont(gpBlockyFont2);
	UnloadFont(gpCompFont);
	UnloadFont(gpLargeFontType1);
	UnloadFont(gpSmallCompFont);
	UnloadFont(gpSmallFontType1);
	UnloadFont(gpTinyFontType1);

	if(GameState::getInstance()->isEditorMode() && isEnglishVersion())
	{
		UnloadFont(gpHugeFont);
	}
}
