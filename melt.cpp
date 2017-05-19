#include <windows.h>
#include <stdio.h>

int main()
{
    HDC dcDesktop = GetDC(NULL);

    int scrX = GetSystemMetrics(SM_CXSCREEN);
    int scrY = GetSystemMetrics(SM_CYSCREEN);

    printf("%d %d\n", scrX, scrY);

    srand(GetTickCount());

    while (true)
    {
        int x = rand() % scrX;

        printf("%d\n", x);

        for (int y = scrY; y > 0; y--)
        {
            printf("%d\n", y);
            SetPixel(dcDesktop, x, y, GetPixel(dcDesktop, x, y - 3));
            Sleep(1);
        }
    }

    return 0;
}
