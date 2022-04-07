#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

#define DELAY 50000
#define PLAYER_PAIR    4
#define BALL_PAIR    3
#define NET_PAIR    5
#define PLAYER    ' '
#define BALL    'O'



int main(int argc, char *argv[]){

    int max_rows, max_cols, row_ball, col_ball, res_jugador1, res_jugador2;
    int raqueta_jugador1_row, raqueta_jugador1_col;
    int raqueta_jugador2_row, raqueta_jugador2_col;

    int directionx = -1, directiony = -1, next_x = 0, next_y = 0;

    int final_juego = 5;

    initscr();
    
    keypad(stdscr, true);
    noecho();
    curs_set(FALSE);

    start_color();
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(PLAYER_PAIR, COLOR_RED, COLOR_BLUE);
    init_pair(BALL_PAIR, COLOR_BLACK, COLOR_RED);
    init_pair(NET_PAIR, COLOR_BLACK, COLOR_GREEN);

    clear();
    refresh();

    getmaxyx(stdscr, max_rows, max_cols);
    WINDOW *window = newwin(max_rows, max_cols, 0, 0);
    wbkgd(window, COLOR_PAIR(2));
    box(window, '#', '#');

    
    mvwprintw(window, 5, 45, "BIENVENIDO AL PONG");

    mvwprintw(window, 10, 20, "JUGADOR 1:");
    mvwprintw(window, 12, 20, "W --> MOVERSE HACIA ARRIBA");
    mvwprintw(window, 13, 20, "S --> MOVERSE HACIA ABAJO");

    mvwprintw(window, 10, 60, "JUGADOR 2:");
    mvwprintw(window, 12, 60, "FLECHA HACIA ARRIBA --> MOVERSE HACIA ARRIBA");
    mvwprintw(window, 13, 60, "FLECHA HACIA ABAJO --> MOVERSE HACIA ABAJO");

    mvwprintw(window, 20, 40, "PULSA CUALQUIER TECLA PARA JUGAR");

    wrefresh(window);

    getch();
    nodelay(stdscr, 1);

    row_ball = max_rows/2;
    col_ball = max_cols/2;

    res_jugador1 = 0;
    res_jugador2 = 0;

    raqueta_jugador1_col = 1;
    raqueta_jugador1_row = (max_rows/2) - 4;

    raqueta_jugador2_col = max_cols - 1;
    raqueta_jugador2_row = (max_rows/2) - 4;

    clear();

    while(res_jugador1 != final_juego && res_jugador2 != final_juego){

        clear();

        mvprintw(2, 35, "JUGADOR 1: %i                     JUGADOR 2: %i", res_jugador1, res_jugador2);

        for(int i = 1; i<max_rows; i++){
            attron(COLOR_PAIR(NET_PAIR));
            mvaddch(i, max_cols/2, PLAYER);
            attroff(COLOR_PAIR(NET_PAIR));
            move(i, max_cols/2);
        }

        for(int i = 0; i<8; i++){
            //mvprintw(raqueta_jugador1_row + i, raqueta_jugador1_col, "#");
            //mvprintw(raqueta_jugador2_row + i, raqueta_jugador2_col, "#");
            attron(COLOR_PAIR(PLAYER_PAIR));
            mvaddch(raqueta_jugador1_row + i, raqueta_jugador1_col, PLAYER);
            attroff(COLOR_PAIR(PLAYER_PAIR));
            move(raqueta_jugador1_row + i, raqueta_jugador1_col);

            attron(COLOR_PAIR(PLAYER_PAIR));
            mvaddch(raqueta_jugador2_row + i, raqueta_jugador2_col, PLAYER);
            attroff(COLOR_PAIR(PLAYER_PAIR));
            move(raqueta_jugador2_row + i, raqueta_jugador2_col);
        }

        //mvprintw(row_ball, col_ball, "O");

        attron(COLOR_PAIR(BALL_PAIR));
        mvaddch(row_ball, col_ball, BALL);
        attroff(COLOR_PAIR(BALL_PAIR));
        move(row_ball, col_ball);

        refresh();

        usleep(DELAY);

        if(col_ball == raqueta_jugador1_col && (row_ball < raqueta_jugador1_row || row_ball > raqueta_jugador1_row + 8)){
            res_jugador2++;

            row_ball = max_rows/2;
            col_ball = max_cols/2;
        }

        if(col_ball == raqueta_jugador2_col && (row_ball < raqueta_jugador2_row || row_ball > raqueta_jugador2_row + 8)){
            res_jugador1++;

            row_ball = max_rows/2;
            col_ball = max_cols/2;
        }

        next_x = col_ball + directionx;
 	    next_y = row_ball + directiony;

         if (next_x >= max_cols || next_x < 0) {
 		    directionx*= -1;
 	    } else {
 		    col_ball+= directionx;
 	    }

 	    if (next_y >= max_rows || next_y < 0) {
 		    directiony*= -1;
 	    } else {
 		    row_ball+= directiony;
 	    }

        switch (getch())
        {
        case KEY_UP:
            if(raqueta_jugador2_row > 0){
                raqueta_jugador2_row--;
            }
            break;
        case KEY_DOWN:
            if(raqueta_jugador2_row < max_rows/2 + 7){
                raqueta_jugador2_row++;
            }
            break;
        case 'w':
            if(raqueta_jugador1_row > 0){
                raqueta_jugador1_row--;
            }
            break;
        case 's':
            if(raqueta_jugador1_row < max_rows/2 + 7){
                raqueta_jugador1_row++;
            }
            break;
        case 'p':
            getchar();
            break;
        case 0x1B:
            endwin();
            exit(0); 
            break;
        
        default:
            break;
        }
        
    }

    endwin();
    
     

    return 0;
}