//LRU
#include<stdio.h>

struct frame {
    int pno;
    int counter;

} frames [5];

int ref_str[30];
int np, n, i, j, currtime;

int pagefound(int pno1) {
    int i;

    for (i = 0; i < n; i++)

        if (frames[i].pno == pno1)
            return i;
    return -1;

}

int get_lru() {
    int min = 0;

    for (i = 0; i < n; i++)

        if (frames[i].counter < frames[min].counter)
            min = i;
    return min;

}

int main() {
    int i, j, pno1, p, page_fault = 0, flag, cnt = 0;;
    float hr, mr;
    printf("\n Enter how many frames: ");
    scanf("%d", & n);
    printf("\n Enter  length of referencestring: ");
    scanf("%d", & np);
    int len = np;
    printf("\n Enter referencestring: ");
    for (i = 0; i < np; i++)
        scanf("%d", & ref_str[i]);

    for (i = 0; i < n; i++) {
        frames[i].pno = -1;
        frames[i].counter = -1;
    }
    printf("\n Page No.\tFrames\t\tPage Fault");
    printf("\n-------------------------------------------------");
    currtime = 1;
    for (p = 0; p < np; p++) {
        flag = 0;
        pno1 = ref_str[p];
        j = pagefound(pno1);
        if (j == -1) {
            page_fault++;

            j = get_lru();

            frames[j].pno = pno1;

            flag = 1;

        }
        frames[j].counter = currtime;
        currtime++;
        printf("\n%5d\t", pno1);
        for (i = 0; i < n; i++)
            printf("  %d ", frames[i]);


        if (flag == 1)
            printf("\t YES");
        else {
            printf("\t NO");
            cnt++;
        }

    }
    printf("\n--------------------------------------------------");
  
    printf("\nNo. of page fault: %d ", page_fault);
    printf("\nNo. of page Hits: %d ", cnt);

   
}


