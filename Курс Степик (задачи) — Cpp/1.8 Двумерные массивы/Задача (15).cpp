#include <iostream>
#include <iomanip>
using namespace std;

int main(){
int n, m, c = 1, r = 1;
int x = 1, y = 1;
cin >> n >> m;
int a[102][102];
for (int i = 0; i < n + 2; i++) {
  for (int j = 0; j < m + 2; j++) {
    a[i][j] = 1;
    }
}
for (int i = 1; i < n + 1; i++) {
  for (int j = 1; j < m + 1; j++) {
    a[i][j] = 0;
    }
}
// obrabotka
while (r != n * m + 1){
  if (a[x][y+1] == 0 && a[x-1][y] > 0) {
      c = 1;
  }
  else if ( a[x][y+1] > 0 && a[x+1][y] == 0 ) { 
      c = 2; 
  }
  else if (a[x][y-1] == 0 && a[x+1][y] > 0 ) { 
      c = 3; 
  }
  else if ( a[x-1][y] == 0 && a[x][y-1] > 0 ) { 
      c = 4; 
  }
  if (c == 1) { 
      a[x][y] = r; y++; 
  }
  else if (c == 2) { 
      a[x][y] = r; x++; 
  }
  else if (c == 3) { 
      a[x][y] = r; y--; 
  }
  else if (c == 4) { 
      a[x][y] = r; x--;
  }
r++;
}
// vyvod
for (int i = 1; i < n+1; i++) {
    for (int j = 1; j < m+1; j++) {
    cout << setw(4) << a[i][j];
    }
  cout << endl;
}
return 0;
}




/*
По данным числам n и m заполните двумерный массив размером n×m числами от 1 до n×m по спирали, выходящей из левого верхнего угла и закрученной по часовой стрелке, как показано в примере.
Формат входных данных

Вводятся два числа n и m, не превышающие 100.
Формат выходных данных

Выведите полученный массив, отводя на вывод каждого элемента ровно 4 символа.
*/