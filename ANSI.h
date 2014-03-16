/*************************************************
 * Definitions for common ANSI escape sequences. *
 *                                               *
 * @author:         William Holltingsworth       *
 * @version:        0.1                          *
 * @since:          2014-02-04                   *
 *                                               *
 *************************************************/

typedef string Color;
typedef string EscapeSequence;


/* Clearing the screen. */
EscapeSequence ansi_clear_screen = "\e[2J";
EscapeSequence ansi_clear_line = "\e[K";

/* Font intensity. */
EscapeSequence ansi_normal = "\e[0m";
EscapeSequence ansi_bold = "\e[1m";

/* Change the foreground color. */
Color ansi_black_fg = "\e[30m";
Color ansi_red_fg = "\e[31m";
Color ansi_green_fg = "\e[32m";
Color ansi_yellow_fg = "\e[33m";
Color ansi_blue_fg = "\e[34m";
Color ansi_magenta_fg = "\e[35m";
Color ansi_cyan_fg = "\e[36m";
Color ansi_white_fg = "\e[37m";

/* Change the background color. */
Color ansi_black_bg = "\e[40m";
Color ansi_red_bg = "\e[41m";
Color ansi_green_bg = "\e[42m";
Color ansi_yellow_bg = "\e[43m";
Color ansi_blue_bg = "\e[44m";
Color ansi_magenta_bg = "\e[45m";
Color ansi_cyan_bg = "\e[46m";
Color ansi_white_bg = "\e[47m";

