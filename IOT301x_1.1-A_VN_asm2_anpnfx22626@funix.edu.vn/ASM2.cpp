#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILENAME "log.txt"   // Ten file log
#define MAX 5000             // Do dai toi da cua chuoi fileStr

char fileStr[MAX];           // Mang chua noi dung toan bo file log
int lineCount = 0;           // Bien dem so dong trong file
char logArr[50][500];        // Mang 2 chieu luu tung dong log

// Khai bao cac ham xu ly
void soBanTinGuiDi();
void soBanTinGuiDenThietBi();
void thoiGianTreLonNhat();
void soCongTac();
void soBanTinGuiLoi();
void thoiGianTreTrungBinh();

// Ham doc noi dung file vao chuoi fileStr
int fileToStr(char *str)
{
    int status;
    FILE *fp = NULL;

    fp = fopen(FILENAME, "r");  // Mo file log.txt de doc

    if (fp == NULL)
    {
        printf("File fdoes not exist\n");
        return -1;  // Tra ve loi neu file khong ton tai
    }

    // Doc noi dung file vao mang str
    status = fread(str, MAX, 1, fp);

    fclose(fp);
    fp = NULL;
    return status;
}

// Tach noi dung fileStr thanh tung dong log luu vao logArr
void splitLogLine(char str[])
{
    char temp[MAX];
    strncpy(temp, str, MAX - 1);  // Sao chep chuoi de xu ly tach dong

    char *line = strtok(temp, "\n");  // Tach tung dong dua theo '\n'

    while (line != NULL)
    {
        strncpy(logArr[lineCount], line, 500);  // Luu dong vao mang logArr
        lineCount++;  // Tang bien dem dong
        line = strtok(NULL, "\n");  // Tiep tuc tach dong ke tiep
    }
}

// Tach dia chi thiet bi tu dong log
void extractSwitchInfo(char line[], char nwk[], int *endPoint)
{
    char *start = strstr(line, "zwave-");
    if (start != NULL)
    {
        sscanf(start, "zwave-%[^:]:4-%d", nwk, endPoint);
    }
}

// Chuyen thoi gian chuoi thanh millisecond
int convertToMilliseconds(char timestamp[])
{
    int hour, min, sec, ms;
    sscanf(timestamp, "2019-10-23%d:%d:%d.%d", &hour, &min, &sec, &ms);
    int totalMs = (((hour * 60 + min) * 60 + sec) * 1000) + ms;
    return totalMs;
}

// Dem so ban tin gui di (cmd = "set")
void soBanTinGuiDi()
{
    printf("===== SO BAN TIN GUI DI =====\n");
    int count = 0;
    char key[50] = "\"cmd\":\"set\"";

    for (int i = 0; i < lineCount; i++)
    {
        if (strstr(logArr[i], key) != NULL)
        {
            printf("%s\n", logArr[i]);
            count++;
        }
    }

    printf("So ban tin gui di: %d\n", count);
}

// Dem so ban tin gui den thiet bi voi dia chi nwk duoc nhap
void soBanTinGuiDenThietBi()
{
    printf("==== SO BAN TIN GUI DEN THIET BI ====");
    int count = 0;
    char key[50] = "\"cmd\":\"set\"";
    char keyNetwork[50];

    do
    {
        printf("\nNhap dia chi nwk cua thiet bi: ");
        scanf("%s", keyNetwork);
        printf("\n");

        for (int i = 0; i < lineCount; i++)
        {
            if (strstr(logArr[i], key) != NULL && strstr(logArr[i], keyNetwork) != NULL)
            {
                printf("%s\n", logArr[i]);
                count++;
            }
        }
    } while (count == 0);

    printf("\nSo ban tin gui di: %d\n", count);
}

// Dem so cong tac khac nhau (theo nwk va endpoint)
void soCongTac()
{
    printf("==== SO CONG TAC ====");
    char key[50] = "\"cmd\":\"set\"";
    char keySwitch[50] = "\"type\":\"switch\"";
    char nwkList[50][50];
    int endpointList[50];

    int count = 0;
    char nwk[50];
    int endPoint;
    int existed;

    printf("\n");
    for (int i = 0; i < lineCount; i++)
    {
        if (strstr(logArr[i], key) != NULL && strstr(logArr[i], keySwitch) != NULL)
        {
            extractSwitchInfo(logArr[i], nwk, &endPoint);

            existed = 0;
            for (int j = 0; j < count; j++)
            {
                if (strcmp(nwkList[j], nwk) == 0 && endpointList[j] == endPoint)
                {
                    existed = 1;
                    break;
                }
            }

            if (!existed)
            {
                strcpy(nwkList[count], nwk);
                endpointList[count] = endPoint;
                count++;
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        printf("Thiet bi %d co dia chi la : NWK - %s, ENDPOINT - %d\n", i + 1, nwkList[i], endpointList[i]);
    }
}

// Dem so ban tin bi loi (gui di nhung khong nhan duoc phan hoi dung reqid)
void soBanTinGuiLoi()
{
    printf("==== SO BAN TIN GUI LOI ====\n");
    int count = 0;

    for (int i = 0; i < lineCount - 1; i += 2)
    {
        char *reqidSet = strstr(logArr[i], "\"reqid\"");
        char *reqidStatus = strstr(logArr[i + 1], "\"reqid\"");

        if (reqidSet && reqidStatus)
        {
            char idSet[10], idStatus[10];

            sscanf(reqidSet, "\"reqid\": \"%[^\"]\"", idSet);
            sscanf(reqidStatus, "\"reqid\": \"%[^\"]\"", idStatus);

            if (strcmp(idSet, idStatus) != 0)
            {
                count++;
            }
        }
        else
        {
            count++;
        }
    }

    printf("\nSo ban tin bi loi: %d\n", count);
}

// Tinh do tre lon nhat va trung binh giua cac cap ban tin hop le (reqid giong nhau)
void thoiGianTreLonNhat()
{
    printf("==== DO TRE BAN TIN ====\n");
    int maxDelay = 0;
    int tbDelay = 0;
    int count = 0;

    for (int i = 0; i < lineCount-1; i += 2)
    {
        char timestamp1[30], timestamp2[30];
        sscanf(logArr[i], "[INFO][%[^]]", timestamp1);
        sscanf(logArr[i + 1], "[INFO][%[^]]", timestamp2);

        int time1 = convertToMilliseconds(timestamp1);
        int time2 = convertToMilliseconds(timestamp2);
        
        char *reqidSet = strstr(logArr[i], "\"reqid\"");
        char *reqidStatus = strstr(logArr[i + 1], "\"reqid\"");

        if (reqidSet && reqidStatus)
        {
            char idSet[10], idStatus[10];
            sscanf(reqidSet, "\"reqid\": \"%[^\"]\"", idSet);
            sscanf(reqidStatus, "\"reqid\": \"%[^\"]\"", idStatus);

            if (strcmp(idSet, idStatus) == 0)
            {
                int delay = time2 - time1;
                tbDelay += delay;
                count++;
                if (delay > maxDelay)
                {
                    maxDelay = delay;
                }
            }
        }
    }

    if (count > 0)
    {
        printf("Do tre trung binh: %d Millisecond\n", tbDelay / count);
        printf("Do tre lon nhat (ms): %d Millisecond\n", maxDelay);
    }
    else
    {
        printf("Khong co ban tin hop le de tinh do tre.\n");
    }
}

// Ham main chinh chuong trinh
int main()
{
    int status = fileToStr(fileStr);  // Doc file vao fileStr

    if (status == 0)
    {
        splitLogLine(fileStr);  // Tach tung dong log

//        for (int i = 0; i < lineCount; i++) {
//            printf("\nLine %d: %s\n", i, logArr[i]);
//        }

        // Goi cac ham xu ly (bo comment ham muon test)
//         soBanTinGuiDi();
//         soBanTinGuiDenThietBi();
//         soCongTac();
//         soBanTinGuiLoi();
         thoiGianTreLonNhat();
    }

    return 0;
}

