#include <iostream>
using std::cout;
using std::endl;

bool gameOver;
const int width = 40;
const int height = 20;
int x, y = 0;
int fruitX = 0;
int fruitY = 0;
int score = 0;

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
    fruitX = rand() % height;
    fruitY = rand() % width;
    // score=0;
}

void draw()
{
    system("cls");

    char head = '0';
    char tail = 'o';
    char fruit = 'F';

    // drawing the top
    for (int i = 0; i < width / 2; i++)
    {
        cout << "# ";
    }
    cout << '\n';

    // int newWidth = 2 * width;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {
                cout << "#";
            }
            else if (j == width - 1)
            {
                cout << "#\n";
            }
            else
            {
                cout << " ";
            }

            // if (j == x && i == y)
            // {
            //     cout << head;
            // }
            // else if (i == fruitX && j == fruitY)
            // {
            //     cout << fruit;
            // }
        }
    }

    // drawing the bottom
    for (int i = 0; i < width / 2; i++)
    {
        cout << "# ";
    }
    cout << '\n';
}

void input()
{
}

void logic()
{
}

int main(int argc, char const *argv[])
{
    // setUp();
    // while (!gameOver)
    // {
    draw();
    //     input();
    //     logic();
    //     // sleep(10);
    // }

    return 0;
}
