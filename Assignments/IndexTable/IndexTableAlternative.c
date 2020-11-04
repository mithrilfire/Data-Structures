#include <stdio.h>

//index tablosu icin dizi sinirlari.
#define M 2
#define N 15

void ekle(int liste[M][N], int id[], int ind);
void sil(int liste[M][N], int id[], int ind);
void degistir(int liste[M][N], int id[], int ind, int yeniNot);
void yazdir(int liste[M][N], int id[], int tsh);

int main() 
{ 
  
    int indexTable[M][N] = { {18060311, 20060045, 19061091, 20060134, 20060678, 18061086, 20060032, 20060067, 19060456,
        18060245, 20060110, 20060234, 20060141, 20060011, 20060012} ,
        { 40, 50, 75, 90, 40, 75, 50, 60, 60, 75, 40, 90, 60, 50, 60} };

    //Baslangic degeri 0 olursa 4 ve 10 indexli eleman 0 dan daha kucuk oldugu icin kaydirma esnasinda listenin disina atiliyor.
    int id[15] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };

    int i;

    //Tum ogrencileri id dizisine ekle.
    for (i = 0; i < N; i++)
    {
        ekle(indexTable, id, i);
    }

    printf("Index table baslangic degerleri ciktisi\n\n");

    yazdir(indexTable, id, 0);
    sil(indexTable, id, 7);
    degistir(indexTable, id, 5, 100);
    yazdir(indexTable, id, 50);

    return 0; 

} 

void ekle(int liste[M][N], int id[], int ind)
{

    int i;

    for (i = 0; i < N; i++)
    {

        if (liste[1][id[i]] > liste[1][ind] && id[i] >= 0)
        {
            continue;
        }
        else if (liste[1][id[i]] == liste[1][ind] && id[i] >= 0)
        {
            if (liste[0][id[i]] < liste[0][ind])
            {
                continue;
            }
        }

        //Sondan basa dogru gezerek yapilan kaydirma islemi.
        //0 1 2 3 (4) -->  0 1 2 (4) 3 --> 0 1 (4) 2 3 --> 0 (4) 1 2 3 --> (4) 0 1 2 3
        int j;

        for (j = N - 1; j > i; j--)
        {
            id[j] = id[j - 1];
        }

        /*
        * Bastan sona dogru kaydirma islemi; bu islemde kaydirilan eleman bir sonraki elemanin uzerine yazildigi icin,
        * Bir sonraki elemanin yutulmasina sebep oluyor bunu engellemek icin sonraki elemani depolayip sonra uzerine-
        * Yazma islemini yapiyorum. Islem bittigi zaman sonraki elemani yeni islem yapilacak eleman olarak atiyorum.
        *
        int current = id[i];
        int next = 0;
        for (j = i; j < N - 1; j++)
        {
            next = id[j + 1];
            id[j + 1] = next;
            current = next;
        }
        */

        id[i] = ind;
        break;

    }

}

void sil(int liste[M][N], int id[], int ind)
{

    int i = 0, j = 0;

    while (i < N)
    {
        id[i] = id[j];

        //Garbage value yerine, baslangic degeri olarak kullandigim -1 degerini atamak icin ekledim.
        if (j >= N)
        {
            id[i] = -1;
        }

        if (id[j] != ind)
        {
            i++;
        }
        j++;

    }

}

void degistir(int liste[M][N], int id[], int ind, int yeniNot)
{

    liste[1][ind] = yeniNot;

    int order, i;

    //Degistirmek istedigimiz ogrencinin index numarasini kullanarak id listesindeki sirasini buluyorum.
    for (i = 0; i < N; i++)
    {

        if (id[i] == ind)
        {

            order = i;

        }

    }

    while (true)
    {

        //Yukarida aldigim siralar ile id listesinde bir onceki siradaki elemanlarla kiyaslama yapiyorum. 
        //(Bir onceki indexte eleman var ise)
        //Kiyaslama sonucunda onceki eleman yeni deger atanmis elemanimizdan daha kucuk ise yer degistiriyorum,
        //Cunku bu buyukten kucuge dogru siralanmis bir tablo.
        if (order > 0 && liste[1][id[order]] > liste[1][id[order - 1]])
        {

            int temp = 0;

            temp = id[order - 1];
            id[order - 1] = id[order];
            id[order] = temp;

            order = order - 1;

        } // Ayni sekilde bir sonraki eleman ile kiyaslama yapiyorum, sonraki eleman daha buyuk ise yer degistiriyorum.
        else if (order < 14 && liste[1][id[order]] < liste[1][id[order + 1]])
        {

            int temp = 0;

            temp = id[order + 1];
            id[order + 1] = id[order];
            id[order] = temp;

            order = order + 1;
        }
        else // Kiyaslanacak eleman kalmadiysa while dongusunu sona eriyor.
        {
            break;
        }

    }

}

void yazdir(int liste[M][N], int id[], int tsh)
{

    int i, prev = 0;

    printf("\t\tAlt limit notu: %d\n\n",tsh);
    printf("........................................................\n");

    for (i = 0; i < N; i++)
    {

        //-1 degerli (Bos) elemanlari gormezden gelsin
        if (id[i] < 0)
        {
            continue;
        }

        if (liste[1][id[i]] < tsh)
        {
            break;
        }

        prev = i;

    }

    for (i = 0; i <= prev; i++)
    {

        //-1 degerli (Bos) elemanlari Yazdirmasin
        if (id[i] < 0)
        {
            continue;
        }

        printf("Id: %d\t|\tNumara: %d\t|\tNot: %d\n",id[i],liste[0][id[i]],liste[1][id[i]]);
    }

    printf("........................................................\n\n");

}