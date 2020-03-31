#include <fstream>
#include <string>
#include <labyrint.h>
using namespace std;



int main(){
   int labirinth[15][15] = {0};
   int line_nmb = 0;
   int line_len;

   fstream file;
   
   //read the map
   file.open("input.txt",ios::in); 
   if (file.is_open()){
      string line;
      while(getline(file, line)){ 
         for(int i = 0; i < line.length(); i++){
            labirinth[line_nmb][i] = line[i] == '#'? -2: -1; // -2 for walls, -1 for holes
         }
         line_nmb++;
         line_len = line.length();
      }
      file.close();
   }
   
   // find number of enclosures
   int enclosures_nmb = 0;
   int enclosures[10][3];
   for(int i = 0; i < line_nmb; i++){
      for(int j = 0; j < line_len; j++){
         if(labirinth[i][j] == -1){
            enclosures[enclosures_nmb][0] = i;
            enclosures[enclosures_nmb][1] = j;
            enclosures[enclosures_nmb][2] = fill_enclosure(labirinth, line_nmb, line_len, i, j, 0);   
            enclosures_nmb++;
         }  
      }
   }

   // find the largest enclosure
   int largest = 0;
   int l_x, l_y;
   for(int i = 0; i < enclosures_nmb; i++)
      if(enclosures[i][2] > largest){
         l_x = enclosures[i][0];
         l_y = enclosures[i][1];
         largest = enclosures[i][2];
      }

   // mark the largest enclosure
   mark_enclosure(labirinth, line_nmb, line_len, l_x, l_y, 0); 

   // write into output file
   file.open("output.txt",ios::out); 
   if(file.is_open()){
      file << largest << '\n';
      for(int i = 0; i < line_nmb; i++){
         for(int j = 0; j < line_len; j++){
            if(labirinth[i][j] == -2)
               file << '#';
            if(labirinth[i][j] == -3)
               file << '.';
            if(labirinth[i][j] >= 0)
               file << labirinth[i][j];
         }
         file << '\n';
      }
      file.close(); 
   }
}
