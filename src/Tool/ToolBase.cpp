#include <Windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include "ToolBase.h"
#include "../WinMax.h"
#include "../App.h"

ToolBase::ToolBase() :indexHovered{ -1 }, indexSelected{ -1 }
{
}

ToolBase::~ToolBase()
{
}

void ToolBase::OnMouseMove(const int& x, const int& y)
{
    auto win = App::GetWin();
    if (win->state < State::tool)
    {
        return;
    }
    if (!toolRect.contains(x, y))
    {
        if (indexHovered >= 0)
        {
            Btns[indexHovered].isHover = false;
            indexHovered = -1;
            win->Refresh();
        }
        return;
    }
    App::Cursor(IDC_HAND);
    int index = (x - toolRect.left()) / ToolBtn::Width;
    if (index != indexHovered)
    {
        Btns[index].isHover = true;
        if (indexHovered >= 0) {
            Btns[indexHovered].isHover = false;
        }
        indexHovered = index;
        win->Refresh();
    }
    return;
}
