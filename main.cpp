#include <iostream>
#include <conio.h>   // console input output
#include <windows.h> // used for the sleep function in order to slow down the snake

using std::cin;
using std::cout;
using std::endl;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y = 0;
int fruitX = 0;
int fruitY = 0;
int score = 0;

int tailX[100] = {};
int tailY[100] = {};
int nTail;

enum eDirection
{
    e_STOP = 0,
    e_LEFT,
    e_RIGHT,
    e_UP,
    e_DOWN
} dir;

char level;
bool easy = true;

void setUp()
{
    gameOver = false;
    dir = e_STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    // score=0;

    cout << "Choose your level:\n";
    cout << "Press E for easy or H for hard\n";

    do
    {
        cin >> level;
        if (level != 'H' && level != 'E')
        {
            cout << "Please enter a correct option\n";
            continue;
        }

        if (level == 'H')
        {
            easy = false;
        }

    } while (level != 'H' && level != 'E');
}

void draw()
{
    system("cls");

    char head = '0';
    char tail = 'o';
    char fruit = 'F';

    // drawing the top
    for (int i = 0; i < width + 2; i++)
    {
        cout << "#";
    }
    cout << '\n';

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // drawing the walls (left)
            if (j == 0)
            {
                cout << "#";
            }

            if (j == x && i == y)
            {
                cout << head;
            }
            else if (i == fruitY && j == fruitX)
            {
                cout << fruit;
            }
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {

                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << tail;
                        print = true;
                    }
                }
                if (!print)
                {
                    cout << " ";
                }
            }

            // drawing the walls (right)
            if (j == width - 1)
            {
                cout << "#";
            }
        }
        cout << '\n';
    }

    // drawing the bottom
    for (int i = 0; i < width + 2; i++)
    {
        cout << "#";
    }
    cout << "\nScore: " << score << '\n';
}

void input()
{
    if (_kbhit()) // if keyboard hit - returns possitive num if is true
    {
        switch (_getch()) // get character
        {
        case 'w':
            dir = e_UP;
            break;
        case 'a':
            dir = e_LEFT;
            break;
        case 'd':
            dir = e_RIGHT;
            break;
        case 's':
            dir = e_DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        default:
            break;
        }
    }
}

void logic()
{

    int prevX = tailX[0];
    int prevY = tailY[0];

    int prev2X = 0;
    int prev2Y = 0;

    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];

        tailX[i] = prevX;
        tailY[i] = prevY;

        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case e_UP:
        --y;
        break;
    case e_DOWN:
        ++y;
        break;
    case e_LEFT:
        --x;
        break;
    case e_RIGHT:
        ++x;
        break;

    default:
        break;
    }

    if (easy)
    {
        if (x >= width)
        {
            x = 0;
        }
        else if (x < 0)
        {
            x = width - 1;
        }

        if (y >= height)
        {
            y = 0;
        }
        else if (y < 0)
        {
            y = height - 1;
        }
    }
    else
    {
        if (x > width || x < 0 || y > height || y < 0)
        {
            gameOver = true;
        }
    }

    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            gameOver = true;
        }
    }

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitY = rand() % width;
        fruitX = rand() % height;

        nTail++;
    }
}

int main()
{
    setUp();
    while (!gameOver)
    {
        draw();
        input();
        logic();
        Sleep(10); // used to slow down the snake
    }
    system("cls");
    cout << "Your score is: " << score << endl;

    return 0;
}
