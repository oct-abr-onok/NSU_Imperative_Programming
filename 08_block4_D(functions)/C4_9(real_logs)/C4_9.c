#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Vidio_s
{
    int totalFrames;
    double totalDecodeFrames;
    double actualPlaybackTime;
    double minDecode, avgDecode, maxDecode;
} Vidio;

void skipLine(void)
{
    char mem;
    mem = getchar();
    while (mem != '\n')
    {
        mem = getchar();
    }
}

int main(void)
{
    char command[300] = {0}, start[300] = "   0.000.000: Decoded first frame",
         end[300] = "   0.000.000: Video ended: no more frames",
         opened[300] = "  14.461.970: Opened file",
         frame1[300] = "  14.461.970: Packet decoded in ",
         frame2[300] = "  14.461.970: Converted to RGBA in ",
         fileName[300],
         mem;
    int line = 0, flag = 0, cm_flag;
    double startTime, currTime, decodeTime, timemem;
    long long intmem;
    Vidio vidio;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (!flag)
    {
        line++;
        for (int i = 0; i < 100; i++) //чтение строки
        {
            if (scanf("%c", &command[i]) < 1) //конец файла
                flag++;
            if (command[i] == '\n')
            {
                for (; i < 100; i++)
                {
                    command[i] = 0;
                }
                break;
            }
        }

        cm_flag = 0; //Имя файла
        for (int i = 13; i < 25; i++)
        {
            if (command[i] != opened[i])
            {
                cm_flag++;
            }
        }
        if (!cm_flag)
        {
            sscanf(&command[26], "%s", fileName);
            continue;
        }

        cm_flag = 0; //Начало обработки видео
        for (int i = 13; i < 33; i++)
        {
            if (command[i] != start[i])
            {
                cm_flag++;
            }
        }
        if (!cm_flag)
        {
            //printf("%d\n", line); //ДЛЯ СЕБЯ
            startTime = 0;
            startTime += (double)(command[2] - 48) * 10000;
            startTime += (double)(command[3] - 48) * 1000;
            startTime += (double)(command[5] - 48) * 100;
            startTime += (double)(command[6] - 48) * 10;
            startTime += (double)(command[7] - 48) * 1;
            startTime += (double)(command[9] - 48) * 0.1;
            startTime += (double)(command[10] - 48) * 0.01;
            startTime += (double)(command[11] - 48) * 0.001;

            vidio.totalFrames = 0;
            vidio.maxDecode = 0;
            vidio.minDecode = 1000;
            vidio.totalDecodeFrames = 0;
            continue;
        }

        cm_flag = 0; //считывание кадра 1
        for (int i = 13; i < 28; i++)
        {
            if (command[i] != frame1[i])
            {
                cm_flag++;
            }
        }
        if (!cm_flag)
        {
            sscanf(&command[32], "%lf", &decodeTime);
            continue;
        }

        cm_flag = 0; //считывание кадра 2
        for (int i = 13; i < 28; i++)
        {
            if (command[i] != frame2[i])
            {
                cm_flag++;
            }
        }
        if (!cm_flag)
        {
            sscanf(&command[34], "%lf", &timemem);
            decodeTime += timemem;
            if (decodeTime < vidio.minDecode)
            {
                vidio.minDecode = decodeTime;
            }
            if (decodeTime > vidio.maxDecode)
            {
                vidio.maxDecode = decodeTime;
            }
            vidio.totalDecodeFrames += decodeTime;
            vidio.totalFrames += 1;
            continue;
        }

        cm_flag = 0; //Конец обработки видео
        for (int i = 13; i < 33; i++)
        {
            if (command[i] != end[i])
            {
                cm_flag++;
            }
        }
        if (!cm_flag)
        {
            currTime = 0;
            currTime += (double)(command[2] - 48) * 10000;
            currTime += (double)(command[3] - 48) * 1000;
            currTime += (double)(command[5] - 48) * 100;
            currTime += (double)(command[6] - 48) * 10;
            currTime += (double)(command[7] - 48) * 1;
            currTime += (double)(command[9] - 48) * 0.1;
            currTime += (double)(command[10] - 48) * 0.01;
            currTime += (double)(command[11] - 48) * 0.001;

            vidio.actualPlaybackTime = currTime - startTime;
            if (vidio.actualPlaybackTime < 0)
            {
                vidio.actualPlaybackTime += 100000;
            }
            vidio.avgDecode = vidio.totalDecodeFrames / vidio.totalFrames;
            printf("Video %c%s%c:\n\tTotal frames: %d\n\tTotal decode time: %0.3lf ms\n\tActual playback time: %0.3lf ms\n\tMin/avg/max decode time: %0.3lf/%0.3lf/%0.3lf ms\n\n", 34, fileName, 34, vidio.totalFrames, vidio.totalDecodeFrames, vidio.actualPlaybackTime, vidio.minDecode, vidio.avgDecode, vidio.maxDecode);
            vidio.totalFrames = 0;
            vidio.maxDecode = 0;
            vidio.minDecode = 1000;
            vidio.totalDecodeFrames = 0;
            continue;
        }
    }

    return 0;
}