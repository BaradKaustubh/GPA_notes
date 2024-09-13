#include <iostream>
using namespace std;
// ******************************* SIMPLE STAR PATTERN **************************
int pattern1()
{
      int row;
      cout << "Enter the number of rows:- ";
      cin >> row;
      int column;
      cout << "Enter the number of columns:- ";
      cin >> column;
      //     *********************** WHILE LOOP ******************
      int i = 1;
      while (i <= row)
      {
            int j = 1;
            while (j <= column)
            {
                  cout << "*";
                  j = j + 1;
            }
            cout << endl;
            i = i + 1;
      }
      // ******************** FOR LOOP *********************
      for (int i = 0; i < column; i++)
      {
            for (int j = 0; j < row; j++)
            {
                  cout << "*";
            }
            cout << endl;
      }
      // **************** DO-WHILE LOOP **************
      int i = 1;
      do
      {
            int j = 1;
            do
            {
                  cout << "*";
                  j = j + 1;
            } while (j <= column);
            cout << endl;
            i = i + 1;
      } while (i <= row);
      return 0;
}

// Q. 1 1 1 1 1 1
//    2 2 2 2 2 2
//    3 3 3 3 3 3
//    4 4 4 4 4 4
int pattern2()
{
      int row;
      cout << "Enter the number of rows:- ";
      cin >> row;
      int column;
      cout << "Enter the number of columns:- ";
      cin >> column;
      int i = 1;
      while (i <= row)
      {
            int j = 1;
            while (j <= column)
            {
                  cout << i;
                  j = j + 1;
            }
            cout << endl;
            i = i + 1;
      }
      return 0;
}

/*Q. 1 2 3 4
     1 2 3 4
     1 2 3 4 */
int pattern3()
{
      int row;
      cout << "Enter the number of rows:- ";
      cin >> row;
      int column;
      cout << "Enter the number of columns:- ";
      cin >> column;
      int i = 1;
      while (i <= row)
      {
            int j = 1;
            while (j <= column)
            {
                  cout << j;
                  j = j + 1;
            }
            cout << endl;
            i = i + 1;
      }
      return 0;
}

/*Q. 5 4 3 2 1
     5 4 3 2 1
     5 4 3 2 1
     5 4 3 2 1
     5 4 3 2 1*/
int pattern4()
{
      int row;
      cout << "Enter the number of rows:- ";
      cin >> row;
      int column;
      cout << "Enter the number of columns:- ";
      cin >> column;
      return 0;
}

/* Q. 1  2  3  4
      5  6  7  8
      9  10 11 12*/
int pattern5()
{
      // ************* while loop ***********
      int n;
      cin >> n;
      int i = 1;
      int count = 1;
      while (i <= n)
      {
            int j = 1;
            while (j <= 3)
            {
                  cout << count << " ";
                  count = count + 1;
                  j = j + 1;
            }
            cout << endl;
            i = i + 1;
      }

      //  ************* FOR LOOP **************
      int count = 1, n = 0;
      cout << "Enter the Value of n:- ";
      cin >> n;
      for (int i = 0; i < n; i++)
      {
            for (int j = 0; j < n; j++)
            {
                  cout << count;
                  count += 1;
            }
            cout << endl;
      }
      return 0;
}

/* Q. *
 * *
 * * *
 * * * *
 * * * * *
 * * * * * *       */
int pattern6()
{
      int i = 1;
      while (i <= 7)
      {
            int j = 1;
            while (j <= i)
            {
                  cout << "* ";
                  j = j + 1;
            }
            cout << endl;
            i = i + 1;
      }
      return 0;
}

/* Q.
 * * * * * *
 * * * * *
 * * * *
 * * *
 * *
 *               */
int pattern7()
{
      int i = 1;
      while (i <= 7)
      {
            int j = 7;
            while (j >= i)
            {
                  cout << "* ";
                  j = j - 1;
            }
            cout << endl;
            i = i + 1;
      }
      return 0;
}

/* Q.
 * * * * * *
 * * * * *
 * * * *
 * * *
 * *
 *
 * *
 * * *
 * * * *
 * * * * *
 * * * * * *
 */
int pattern8()
{
      int i = 1;
      while (i <= 7)
      {
            int j = 7;
            while (j >= i)
            {
                  cout << "* ";
                  j = j - 1;
            }
            cout << endl;
            i = i + 1;
      }
      int k = 2;
      while (k <= 7)
      {
            int l = 1;
            while (l <= k)
            {
                  cout << "* ";
                  l = l + 1;
            }
            cout << endl;
            k = k + 1;
      }
      return 0;
}

/*Q. 1
     2 3
     4 5 6;
     7 8 9 10 */
int pattern9()
{
      int count = 1;
      for (int i = 1; i <= 5; i++)
      {
            for (int j = 1; j <= i; j++)
            {
                  cout << "<" << count << "> ";
                  count += 1;
            }
            cout << endl;
      }
      return 0;
}

/*Q. 1
     2 1
     3 2 1
     4 3 2 1
     5 4 3 2 1
     6 5 4 3 2 1
     7 6 5 4 3 2 1 */
int pattern10()
{
      int count = 1;
      for (int i = 1; i <= 5; i++)
      {
            for (int j = 1; j <= i; j++)
            {
                  cout << (i - j + 1) << " ";
                  count += 1;
            }
            cout << endl;
      }
      return 0;
}

/* Q. A A A A A A
      B B B B B B
      C C C C C C
      D D D D D D
      E E E E E E
      F F F F F F   */
int pattern11()
{
      int n, row = 1, col = 1;
      cout << "Enter the value of n:- ";
      cin >> n;
      for (row = 1; row <= n; row++)
      {
            for (col = 1; col <= n; col++)
            {
                  char ch = 'A' + row - 1;
                  cout << ch << " ";
            }
            cout << endl;
      }
      return 0;
}

/* Q. A B C D E F G
      A B C D E F G
      A B C D E F G
      A B C D E F G
      A B C D E F G
      A B C D E F G   */
int pattern12()
{
      int n, row = 1, col = 1;
      cout << "Enter the value of n:- ";
      cin >> n;
      for (row = 1; row <= n; row++)
      {
            for (col = 1; col <= n; col++)
            {
                  char ch = 'A' + col - 1;
                  cout << ch << " ";
            }
            cout << endl;
      }
      return 0;
}

/*  Q.   A
         B C
         D E F
         G H I J  */
int pattern13()
{
      int n, row = 1, col = 1;
      cout << "Enter the value of n:- ";
      cin >> n;
      for (row = 1; row <= n; row++)
      {
            for (col = 1; col <= row; col++)
            {
                  char ch = ('A' + row + col - 2);
                  cout << ch << " ";
            }
            cout << endl;
      }
      return 0;
}

int main() { 
      pattern1();
      pattern2();
      pattern3();
      pattern4();
      pattern5();
      pattern6();
      pattern7();
      pattern8();
      pattern9();
      pattern10();
      pattern11();
      pattern12();
      pattern13();
      return 0; 
      }
