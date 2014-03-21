/*************************************************
 * Definitions for common ANSI escape sequences. *
 *                                               *
 * @author:         TheFightingMongooses         *
 * @version:        0.1                          *
 * @since:          2014-02-04                   *
 *                                               *
 *************************************************/
namespace ANSI 
{
  typedef string Color;
  typedef string EscapeSequence;


  /* Clearing the screen. */
  EscapeSequence clear_screen = "\e[2J";
  EscapeSequence clear_line = "\e[K";

  /* Font intensity. */
  EscapeSequence normal = "\e[0m";
  EscapeSequence bold = "\e[1m";

  /* Change the foreground color. */
  Color black_fg = "\e[30m";
  Color red_fg = "\e[31m";
  Color green_fg = "\e[32m";
  Color yellow_fg = "\e[33m";
  Color blue_fg = "\e[34m";
  Color magenta_fg = "\e[35m";
  Color cyan_fg = "\e[36m";
  Color white_fg = "\e[37m";

  /* Change the background color. */
  Color black_bg = "\e[40m";
  Color red_bg = "\e[41m";
  Color green_bg = "\e[42m";
  Color yellow_bg = "\e[43m";
  Color blue_bg = "\e[44m";
  Color magenta_bg = "\e[45m";
  Color cyan_bg = "\e[46m";
  Color white_bg = "\e[47m";
}
