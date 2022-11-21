#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int out_char_mem;
    char sample, sample_mem, bit_mem, in_byte_mem, current_in_bit, current_out_bit, major_flag, minor_flag, in_check_bit1, in_check_bit2;

    FILE *fi = fopen("input.txt", "rb");
    FILE *fo = fopen("output.txt", "wb");

    //чтение по символу
    while (fread(&in_byte_mem, sizeof(char), 1, fi))
    {
        major_flag = 0, minor_flag = 0;

        //обработка первого байта(выбор шаблона)
        bit_mem = 1;
        sample = 0;
        for (current_in_bit = 7; bit_mem != 0 && current_in_bit > -1; current_in_bit--)
        {
            bit_mem = in_byte_mem & (1 << current_in_bit);
            sample++;
        }
        if (sample > 5 || sample == 2) //проверка на серьёзную ошибку 1 4
            break;
        if (sample == 1)
        {
            current_out_bit = 6;
            sample = 0;
        }
        else
        {
            current_out_bit = (7 - sample) + (sample - 2) * 6;
            sample -= 2;
        }
        sample_mem = sample;

        //чтение битов
        out_char_mem = 0;
        //обработка остатка первого байта
        for (; current_in_bit > -1; current_in_bit--, current_out_bit--)
        {
            out_char_mem += ((in_byte_mem & (1 << current_in_bit)) >> current_in_bit) << current_out_bit;
        }
        //обработка дополнительных байтов
        for (; sample > 0; sample--)
        {
            if (fread(&in_byte_mem, sizeof(char), 1, fi)) //проверка на серьзную ошибку 2
            {
                in_check_bit1 = in_byte_mem & (1 << 7); //проверка на серьёзную ошибку 3
                in_check_bit2 = in_byte_mem & (1 << 6);
                if (in_check_bit1 != 0 && in_check_bit2 == 0)
                {
                    for (current_in_bit = 5; current_in_bit > -1; current_in_bit--, current_out_bit--)
                    {
                        out_char_mem += ((in_byte_mem & (1 << current_in_bit)) >> current_in_bit) << current_out_bit;
                    }
                }
                else
                {
                    major_flag++;
                    break;
                }
            }
            else
            {
                major_flag++;
                break;
            }
        }

        //обработка ошибок
        if (major_flag)
        {
            break;
        }
        //проверка на мягкую ошибку 3
        switch (sample_mem)
        {
        case 1:
            if (out_char_mem < 1 << 7)
            {
                minor_flag++;
            }
            break;
        case 2:
            if (out_char_mem < 1 << 11)
            {
                minor_flag++;
            }
            break;
        case 3:
            if (out_char_mem < 1 << 16)
            {
                minor_flag++;
            }
            break;

        default:
            break;
        }

        if (out_char_mem > 0x10FFFF || (out_char_mem >= 0xD800 && out_char_mem <= 0xDFFF) || minor_flag) //мягкие ошибки 1 2
        {
            out_char_mem = 0xFFFD;
        }

        fwrite(&out_char_mem, sizeof(int), 1, fo);
    }

    fclose(fi);
    fclose(fo);
}