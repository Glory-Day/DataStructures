#ifndef __COLORIZER_HPP__
#define __COLORIZER_HPP__

#include <string>

using namespace std;

namespace test::terminal
{
    const string COLOR_PREFIX = "\033[";
    const string COLOR_SUFFIX = "m";
    const string COLOR_RESET  = "\033[0m";

    enum class Foreground
    {
        Black = 0,
        Red,
        Green,
        Yellow,
        Blue,
        Magenta,
        Cyan,
        White,
        Default,
        BrightBlack,
        BrightRed,
        BrightGreen,
        BrightYellow,
        BrightBlue,
        BrightMagenta,
        BrightCyan,
        BrightWhite,
    };

    enum class Background
    {
        Black = 0,
        Red,
        Green,
        Yellow,
        Blue,
        Magenta,
        Cyan,
        White,
        Default,
        BrightBlack,
        BrightRed,
        BrightGreen,
        BrightYellow,
        BrightBlue,
        BrightMagenta,
        BrightCyan,
        BrightWhite,
    };

    enum class Style
    {
        Default = 0,
        Bold,
        Faint,
        Italic,
        Underline
    };

    inline string set_color(Foreground foreground = Foreground::Default, Background background = Background::Default, Style style = Style::Default)
    {
        string foreground_text;
        string background_text;
        string style_text;

        switch (foreground)
        {
            case Foreground::Black:         foreground_text = "30;"; break;
            case Foreground::Red:           foreground_text = "31;"; break;
            case Foreground::Green:         foreground_text = "32;"; break;
            case Foreground::Yellow:        foreground_text = "33;"; break;
            case Foreground::Blue:          foreground_text = "34;"; break;
            case Foreground::Magenta:       foreground_text = "35;"; break;
            case Foreground::Cyan:          foreground_text = "36;"; break;
            case Foreground::White:         foreground_text = "37;"; break;
            case Foreground::Default:       foreground_text = "39;"; break;
            case Foreground::BrightBlack:   foreground_text = "90;"; break;
            case Foreground::BrightRed:     foreground_text = "91;"; break;
            case Foreground::BrightGreen:   foreground_text = "92;"; break;
            case Foreground::BrightYellow:  foreground_text = "93;"; break;
            case Foreground::BrightBlue:    foreground_text = "94;"; break;
            case Foreground::BrightMagenta: foreground_text = "95;"; break;
            case Foreground::BrightCyan:    foreground_text = "96;"; break;
            case Foreground::BrightWhite:   foreground_text = "97;"; break;
        }

        switch (background)
        {
            case Background::Black:         background_text = "40";  break;
            case Background::Red:           background_text = "41";  break;
            case Background::Green:         background_text = "42";  break;
            case Background::Yellow:        background_text = "43";  break;
            case Background::Blue:          background_text = "44";  break;
            case Background::Magenta:       background_text = "45";  break;
            case Background::Cyan:          background_text = "46";  break;
            case Background::White:         background_text = "47";  break;
            case Background::Default:       background_text = "49";  break;
            case Background::BrightBlack:   background_text = "100"; break;
            case Background::BrightRed:     background_text = "101"; break;
            case Background::BrightGreen:   background_text = "102"; break;
            case Background::BrightYellow:  background_text = "103"; break;
            case Background::BrightBlue:    background_text = "104"; break;
            case Background::BrightMagenta: background_text = "105"; break;
            case Background::BrightCyan:    background_text = "106"; break;
            case Background::BrightWhite:   background_text = "107"; break;
        }

        switch (style)
        {
            case Style::Default:   style_text = "0;"; break;
            case Style::Bold:      style_text = "1;"; break;
            case Style::Faint:     style_text = "2;"; break;
            case Style::Italic:    style_text = "3;"; break;
            case Style::Underline: style_text = "4;"; break;
        }

        return COLOR_PREFIX + style_text + foreground_text + background_text + COLOR_SUFFIX;
    }
}

#endif