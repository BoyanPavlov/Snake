#include <iostream>
#include <conio.h> // console input output
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

void setUp()
{
    gameOver = false;
    dir = e_STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    // score=0;
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

    if (x > width || x < 0 || y > height || y < 0)
    {
        gameOver = true;
    }

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitY = rand() % width;
        fruitX = rand() % height;

        nTail++;
    }
}

int main(int argc, char const *argv[])
{
    setUp();
    while (!gameOver)
    {
        draw();
        input();
        logic();
        // sleep(10);
    }

    return 0;
}
