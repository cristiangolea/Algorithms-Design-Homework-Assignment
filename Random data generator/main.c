#include <string.h>
#include <time.h>
#include <stdio.h>

void gen_random_string(char *s, const int len)
{
    static const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < len; i++)
    {
        s[i] = alphabet[rand() % (sizeof(alphabet) - 1)];
    }
    s[len] = 0;
}

int gen_random_num(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return("%d", num);
}

int main ()
{
    FILE *outfile;
    outfile = fopen("out.txt","w");

    int n, nr;
    printf("How many books do you want to generate? ");
    scanf("%d", &n);
    char *s=malloc(sizeof(char));

    for (int i=1; i<=n; i++)
    {

        gen_random_string(s,gen_random_num(2,10));
        nr=gen_random_num(2,5);

        fprintf(outfile,"1 ");

        fprintf(outfile,"%s %d ", s, nr);
        for (int j=1; j<=nr; j++)
        {
            gen_random_string(s,gen_random_num(2,10));
            fprintf(outfile,"%s ", s);
            gen_random_string(s,gen_random_num(2,10));
            fprintf(outfile,"%s ", s);
        }
        fprintf(outfile,"\n");
    }
    fprintf(outfile,"5");
    fprintf(outfile,"\n");
    fclose(outfile);
}
