#include <labyrint.h>

int fill_enclosure(int labirinth[15][15], int n, int m, int x, int y, int cells){
   labirinth[x][y] = -3;
   cells++;
   if((y-1 >= 0 && labirinth[x][y-1] == -1))
      cells = fill_enclosure(labirinth, n, m, x, y-1, cells);

   if((y+1 < m && labirinth[x][y+1] == -1))
      cells = fill_enclosure(labirinth, n, m, x, y+1, cells);

   if((x+1 < n && labirinth[x+1][y] == -1))
      cells = fill_enclosure(labirinth, n, m, x+1, y, cells);

   if((x-1 >= 0 && labirinth[x-1][y] == -1))
      cells = fill_enclosure(labirinth, n, m, x-1, y, cells);

   return cells;
}

int mark_enclosure(int labirinth[15][15], int n, int m, int x, int y, int cells){
   labirinth[x][y] = cells;
   cells++;
   if((y-1 >= 0 && labirinth[x][y-1] == -3))
      cells = mark_enclosure(labirinth, n, m, x, y-1, cells);

   if((y+1 < m && labirinth[x][y+1] == -3))
      cells = mark_enclosure(labirinth, n, m, x, y+1, cells);

   if((x+1 < n && labirinth[x+1][y] == -3))
      cells = mark_enclosure(labirinth, n, m, x+1, y, cells);

   if((x-1 >= 0 && labirinth[x-1][y] == -3))
      cells = mark_enclosure(labirinth, n, m, x-1, y, cells);

   return cells;
}
