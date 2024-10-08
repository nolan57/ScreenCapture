#include "ToolBtn.h"
#include "../Font.h"

static int id{ 0 };

ToolBtn::ToolBtn(const char* icon, std::wstring&& tip, bool isDisable, bool selectable, int fontSize, SkColor fontColor, bool isSelected)
{
    //tipInfo.cbSize = sizeof(TOOLINFO);
    //tipInfo.uFlags = TTF_SUBCLASS;
    //tipInfo.hwnd = App::GetWin()->hwnd;
    //tipInfo.hinst = GetModuleHandle(NULL);
    //tipInfo.uId = id;
    //RECT rect{ 0,0,0,0 };
    //tipInfo.rect = rect;
    //tipInfo.lpszText = (LPWSTR)tip.c_str();
    //SendMessage(App::GetWin()->hwndToolTip, TTM_ADDTOOL, 0, (LPARAM)(LPTOOLINFO)&tipInfo);
    //id += 1;
}

ToolBtn::ToolBtn(const int& _id)
{
    id = _id;
    initIconCode(id);
    if (id == 9 || id == 10) {
        isDisable = true;
    }
    if (id >= 9 && id <= 14) {
        selectable = false;
    }
}
ToolBtn::~ToolBtn() {

}

void ToolBtn::Paint(SkCanvas* canvas, SkPaint& paint, float& x, float& y)
{
    if (isSelected && selectable)
    {
        SkRect bgRect = SkRect::MakeXYWH(x + 6, y + 6, ToolBtn::Width - 12, ToolBtn::Height - 12);
        paint.setColor(0xFFE4EEFF);
        canvas->drawRoundRect(bgRect, 6, 6, paint);
        paint.setColor(0xFF0958D9);
    }
    else if (isHover && !isDisable)
    {
        SkRect bgRect = SkRect::MakeXYWH(x + 6, y + 6, ToolBtn::Width - 12, ToolBtn::Height - 12);
        paint.setColor(0xFFEEEEEE);
        canvas->drawRoundRect(bgRect, 6, 6, paint);
        paint.setColor(0xFF1e1e1e);
    }
    else
    {
        if (isDisable) {
            paint.setColor(0xFFa0a0a0);
        }
        else
        {
            paint.setColor(0xFF1e1e1e);
        }
    }
    auto font = Font::GetIcon();
    font->setSize(fontSize);
    if (fontColor != SK_ColorTRANSPARENT) {
        paint.setColor(fontColor);
    }
    if (fontSize == 22) {
        canvas->drawString(iconCode, x + 14, y + ToolBtn::Height / 2 + 8, *font, paint);
    }
    else if (fontSize == 52) {
        canvas->drawString(iconCode, x - 1, y + ToolBtn::Height / 2 + 19, *font, paint);
    }
    else if (fontSize == 82) {
        canvas->drawString(iconCode, x - 16, y + ToolBtn::Height / 2 + 29.5, *font, paint);
    }
    //setToolTip(x, y);
}


void ToolBtn::initIconCode(const int& id)
{
    switch (id)
    {
    case 0: {
        iconCode = (const char*)u8"\ue8e8"; //rect
        break;
    }
    case 1: {
        iconCode = (const char*)u8"\ue6bc"; //ellipse
        break;
    }
    case 2: {
        iconCode = (const char*)u8"\ue603"; //arrow
        break;
    }
    case 3: {
        iconCode = (const char*)u8"\ue776"; //number
        break;
    }
    case 4: {
        iconCode = (const char*)u8"\ue601"; //pen
        break;
    }
    case 5: {
        iconCode = (const char*)u8"\ue69b"; //line
        break;
    }
    case 6: {
        iconCode = (const char*)u8"\ue6ec"; //text
        break;
    }
    case 7: {
        iconCode = (const char*)u8"\ue82e"; //mosaic
        break;
    }
    case 8: {
        iconCode = (const char*)u8"\ue6be"; //eraser
        break;
    }
    case 9: {
        iconCode = (const char*)u8"\ued85"; //undo
        break;
    }
    case 10: {
        iconCode = (const char*)u8"\ued8a"; //redo
        break;
    }
    case 11: {
        iconCode = (const char*)u8"\ue6a3"; //pin
        break;
    }
    case 12: {
        iconCode = (const char*)u8"\ue62f"; //save
        break;
    }
    case 13: {
        iconCode = (const char*)u8"\ue87f"; //copy
        break;
    }
    case 14: {
        iconCode = (const char*)u8"\ue6e7"; //close
        break;
    }
    case 15: {
        iconCode = (const char*)u8"\ue602"; //rect fill
        break;
    }
    case 16: {
        iconCode = (const char*)u8"\ue608"; //dot
        break;
    }
    case 17: {
        iconCode = (const char*)u8"\ue721"; //check
        break;
    }
    case 18: {
        iconCode = (const char*)u8"\ue61d"; //uncheck
        break;
    }
    case 19: {
        iconCode = (const char*)u8"\ue600"; //ellipse Fill
        break;
    }
    case 20: {
        iconCode = (const char*)u8"\ue604"; //arrow Fill
        break;
    }
    case 21: {
        iconCode = (const char*)u8"\ue605"; //num Fill
        break;
    }
    case 22: {
        iconCode = (const char*)u8"\ue607"; //transparent
        break;
    }
    default:
        break;
    }
}

void ToolBtn::setToolTip(const int& x, const int& y)
{
    RECT rect{ .left{x},.top{y},.right{x + (int)ToolBtn::Width},.bottom{y + (int)ToolBtn::Height} };
    tipInfo.rect = rect;
    //SendMessage(App::GetWin()->hwndToolTip, TTM_NEWTOOLRECT, 0, (LPARAM)(LPTOOLINFO)&tipInfo);
}
