/**
 * @file scrabble.c
 *
 * @author Caleb Krcil
 *
 * @date 4/11/2022
 *
 * Assignment: Homework 4
 *
 * @brief a program that uses binary search to find if a words exists in the 
 * scrabble dictionary. Also cand find the best word to play from random 
 * letters.
 *
 * @bug none
 * 
 * @todo none
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100



struct data_t {
    int nval;
    int max;
    int length;     //length of dictionary
    char **words;   //all the scrabble words.
    int **letters;  //how many of a each letter each word contains
};

int binary(struct data_t *data, char buf[]);
int maxpts(struct data_t *data, char buf[], int pts[], int tilelet[]);

enum {INIT = 1, GROW = 2};

/**
 * Main function, allocates all memory, contains menu system, and finds the
 * amount of letters in each word and their point values. Also calls the binary
 * search and best word functions.
 * @param choice menu choice
 * @param pts array that holds word point values
 * @param pt temporary holder for word point values
 * @param i iterating value
 * @param tilelet array that holds how many of each letter user input has
 * @param fp file-in this case dictionary
 * @param buf temporary user input array
 * @param l holds each character for point and letter determination
 * @param j iterating value
 * @param data struct that holds values for the scrabble dictionary
 */
int main(void){
    int choice;
    int *pts;
    int pt;
    int i = 0;
    int tilelet[27];
    FILE *fp = NULL;
    fp=fopen("scrabble.txt","r");
    char buf[LEN];
    char l;
    int j;
	struct data_t *data = malloc(sizeof(struct data_t));
	data->nval = INIT;
	data->max = INIT;
	data->words = NULL;
    i = 0;
	while (fgets(buf, LEN, fp)) {
		if (data->words == NULL){
			data->words = malloc(sizeof(char**));
            data->letters = malloc(sizeof(int**));
            pts = malloc(sizeof(int));
        }
		else if (data->nval > data->max) {
			data->words = realloc(data->words, GROW * data->max *sizeof(char**));
            data->letters = realloc(data->letters, GROW * data->max *sizeof(int**));
			pts = realloc(pts, GROW * data->max*(sizeof(int)));
            data->max = GROW * data->max;
            
		}
        buf[strcspn(buf, "\n")] = '\0';
		*(data->words + i) = strdup(buf);

        *(data->letters + i) = calloc(27, sizeof(int));
        pt = 0;
        for (j = 0; j < (strlen(buf)); j++){
                l = buf[j];
                switch (l){
                    case 'a':
                        pt+=1;
                        data->letters[i][1]+=1;
                    break;
                    case 'e':
                        pt+=1;
                        data->letters[i][5]+=1;
                    break; 
                    case 'i':
                        pt+=1;
                        data->letters[i][9]+=1;
                    break; 
                    case 'l':
                        pt+=1;
                        data->letters[i][12]+=1;
                    break; 
                    case 'n': 
                        pt+=1;
                        data->letters[i][14]+=1;
                    break;
                    case 'o':
                        pt+=1;
                        data->letters[i][15]+=1;
                    break; 
                    case 'r':
                        pt+=1;
                        data->letters[i][18]+=1;
                    break;
                    case 's': 
                        pt+=1;
                        data->letters[i][19]+=1;
                    break;
                    case 't': 
                        pt+=1;
                        data->letters[i][20]+=1;
                    break;
                    case 'u':
                        pt+=1;
                        data->letters[i][21]+=1;
                    break;
                    case 'd':
                        pt+=2;
                        data->letters[i][4]+=1;
                    break; 
                    case 'g':
                        pt+=2;
                        data->letters[i][7]+=1;
                    break;
                    case 'b':
                        pt+=3;
                        data->letters[i][2]+=1;
                    break; 
                    case 'm':
                        pt+=3;
                        data->letters[i][13]+=1;
                    break; 
                    case 'p':
                        pt+=3;
                        data->letters[i][16]+=1;
                    break;
                    case 'f':
                        pt+=4;
                        data->letters[i][6]+=1;
                    break; 
                    case 'h':
                        pt+=4;
                        data->letters[i][8]+=1;
                    break; 
                    case 'v':
                        pt+=4;
                        data->letters[i][22]+=1;
                    break; 
                    case 'w':
                        pt+=4;
                        data->letters[i][23]+=1;
                    break; 
                    case 'y':
                        pt+=4;
                        data->letters[i][25]+=1;
                    break;
                    case 'k':
                        pt+=5;
                        data->letters[i][11]+=1;
                    break;
                    case 'j':
                        pt+=8;
                        data->letters[i][10]+=1;
                    break; 
                    case 'x':
                        pt+=8;
                        data->letters[i][24]+=1;
                    break;
                    case 'q':
                        pt+=10;
                        data->letters[i][17]+=1;
                    break;  
                    case 'z':
                        pt+=10;
                        data->letters[i][26]+=1;
                    break;
                }
        }
        pts[i] = pt;
		i++;
        data->nval++;		

    }
    
    data->length = i;
        /* overcounted */
        data->nval--;
        /* no frees! this needs to be fixed */
    while(1){
        for(i = 0; i < 27; i++){
            tilelet[i] = 0;
        }
        printf("Enter your choice:\n");
        printf("1) Find if a word is in the scrabble dictionary.\n");
        printf("2) Determine the best play from a set of tiles.\n");
        printf("3) Exit\n");
        fgets(buf, LEN, stdin);
        choice = atoi(buf);
        switch (choice){
            case 1:
            printf("Enter the word you want to search for.\n");
            fgets(buf, LEN, stdin);
            buf[strcspn(buf, "\n")] = '\0';
            binary(data, buf);
            break;
            case 2:
            printf("Enter your tiles:\n");
            fgets(buf, LEN, stdin);
            buf[strcspn(buf, "\n")] = '\0';
            for (j = 0; j < (strlen(buf)); j++){
                l = buf[j];
                switch (l){
                    case 'a':
                        tilelet[1]+=1;
                    break;
                    case 'e':
                        tilelet[5]+=1;
                    break; 
                    case 'i':
                        tilelet[9]+=1;
                    break; 
                    case 'l':
                        tilelet[12]+=1;
                    break; 
                    case 'n': 
                        tilelet[14]+=1;
                    break;
                    case 'o':
                        tilelet[15]+=1;
                    break; 
                    case 'r':
                        tilelet[18]+=1;
                    break;
                    case 's': 
                        tilelet[19]+=1;
                    break;
                    case 't': 
                        tilelet[20]+=1;
                    break;
                    case 'u':
                        tilelet[21]+=1;
                    break;
                    case 'd':
                        tilelet[4]+=1;
                    break; 
                    case 'g':
                        tilelet[7]+=1;
                    break;
                    case 'b':
                        tilelet[2]+=1;
                    break; 
                    case 'm':
                        tilelet[13]+=1;
                    break; 
                    case 'p':
                        tilelet[16]+=1;
                    break;
                    case 'f':
                        tilelet[6]+=1;
                    break; 
                    case 'h':
                        tilelet[8]+=1;
                    break; 
                    case 'v':
                        tilelet[22]+=1;
                    break; 
                    case 'w':
                        tilelet[23]+=1;
                    break; 
                    case 'y':
                        tilelet[25]+=1;
                    break;
                    case 'k':
                        tilelet[11]+=1;
                    break;
                    case 'j':
                        tilelet[10]+=1;
                    break; 
                    case 'x':
                        tilelet[24]+=1;
                    break;
                    case 'q':
                        tilelet[17]+=1;
                    break;  
                    case 'z':
                        tilelet[26]+=1;
                    break;
                }
        }
            maxpts(data, buf, pts, tilelet);
            break;
            case 3:
            for(i = 0; i < data->length; i++){
                free(*(data->words + i));
                free(*(data->letters + i));
            }
            free(data->letters);
            free(data->words);
            free(data);
            free(pts);
            fclose(fp);
            exit(EXIT_SUCCESS);
            break;
        }
    }
    
	return 0;
}

/**
 * Binary search function, performs binary search to determine if a user
 * input word is in the scrabble dictionary.
 * @param last last array value
 * @param first first array value
 * @param middle middle array value
 * @param valid value used to determine if the word is or is not in the 
 * dictionary.
 */
int binary(struct data_t *data, char buf[]){
    int last;
    int first = 0;
    int middle = data->length / 2;
    int valid = 0;
    last = data->length;
    while (first <= last) {
        if (strcmp((buf), *(data->words+middle)) < 0){
            last = middle - 1;
        }
        else if (strcmp((buf), *(data->words+middle)) == 0){
            valid = 1;
            break;
        }
        else{
            first = middle + 1;
        }
        middle = (first + last) / 2;
    }
    if (first > last){
        valid = 0;
    }
    if (valid == 1){
        printf("%s is a valid word\n", buf);
    }
    else{
        printf("%s is not a valid word\n", buf);
    }
    return 0;
}

/**
 * Determines what the best play from a user input set of tiles would be.
 * @param i iterating value
 * @param j iterating value
 * @param most value that holds the value for the highest point word.
 * @param bestword holds the string for the best word 
 * @param all value that helps check if all the letters in a certain word are 
 * in the user input set of tiles.
 */
int maxpts(struct data_t *data, char buf[], int pts[], int tilelet[]){
    int i;
    int j;
    int most = 0;
    char *bestword = NULL;
    int all;
    for(i = 0; i < data->length; i++){
        all = 0;
        for(j = 0; j < 27; j++){
            if((data->letters[i][j] <= tilelet[j])){
                all+=1;
            }
        }
        if((all == 27) && (pts[i] > most)){
            bestword = *(data->words+i);
            most = pts[i];
        }
    }
    if(most != 0){
        printf("The best word is %s worth %d pts\n", bestword, most);
    }
    else{
        printf("No word could be made from the tiles.\n");
    }
    return 0;
}