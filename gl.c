/**
 * @file gl.c
 *
 * @author Caleb Krcil
 *
 * @date 11/27/2021
 *
 * Assignment: Lab 10/ GOL
 * 
 * Grader - when running the program in the command line for a file put start/ in
 * front of the file name in order to initialize the grid as I have placed the 
 * starts in a folder, also for the edgetype just use the first letter of the
 * type you want
 *
 * @brief calls the functions in life.c and has a loop that will run until the user 
 * wants to exit the program. Also uses get opt for various starting values
 * and configurations.
 *  
 * 
 * @bug when initializing the grid it doesnt wrap around correctly and seg faults
 * if the grid isnt large enough, only an issue on the larger patterns
 * 
 * @todo none
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "unistd.h"
#include "SDL2/SDL.h" 
#include "sdl.h"
#include "life.h"

/**
 * calls the functions in life.c and has a loop that will run until the user 
 * wants to exit the program. Also uses get opt for various starting values
 * and configurations.
 * @param iterator iterates to determine what array to check and display 
 * @param matrix1 one of the two matrices that hold the life data
 * @param matrix2 the second matrix that holds the life data
 * @param edgetype the edge type for the program to use
 * @param width the width of the screen displayed
 * @param height the height of the screen displayed
 * @param sprite_size the size of the sprite
 * @param mwidth the widht of the matrix
 * @param mheight the height of the matrix
 * @param c used for getopt
 * @param file the file used for the starting configuration
 * @param tempx temporary place for the x origin point
 * @param tempy temporary place for the y origin point
 * @param originx the x origin point
 * @param originy the y origin point
 * @param i temporary iterator
 * @param j temporary iterator
 * @param cedgetype temporarily hold the edgetype input
 * @param red red color value
 * @param green green color value
 * @param blue blue color value
 */
int main(int argc, char *argv[])
{
	int iterator = 0;
	unsigned char **matrix1;
	unsigned char **matrix2;
	int edgetype = 3;
	int width = 900;
	int height = 700;
	int sprite_size = 4; /* either 2, 4, 8, or 16 */
	int mwidth = (width / sprite_size);
	int mheight = (height / sprite_size);
	int c;
	char* file;
	file = "start/glider_106.lif";
	char* tempx;
	char* tempy;
	int originx = mheight / 2;
	int originy = mwidth / 2;
	int i;
	int j;
	char cedgetype;
	//int m = -66;
	//int n = -10;
        /* colors are RGB model valid values [0, 255] */
	unsigned char red = 140;
	unsigned char green = 145;
	unsigned char blue = 250;
    struct sdl_info_t sdl_info; /* this is needed to graphically display the game */

	// if (argc == 1) {
	// 	printf("usage: find -w width -h height -e edgetype -r red -g green -b blue -s sprite size\n");
	// 	printf("-f filename -o origin\n");
	// 	exit(EXIT_FAILURE);
	// }
	/* pass a string of options to getopt
         * the colon after a letter signifies that the option expects an argument 
         * leading colon lets you distinguish between invalid option and missing argument cases
         */
	while((c = getopt(argc, argv, ":Hw:h:e:r:g:b:s:f:o:")) != -1)
		switch(c) {
		case 'w':
			width = atoi(optarg);
			break;
		case 'h':
			height = atoi(optarg);
			break;
		case 'e':
			cedgetype = optarg[0];
			switch(cedgetype){
				case 'h':
					edgetype = 1;
					break;
				case 't':
					edgetype = 2;
					break;
				case 'k':
					edgetype = 3;
					break;
				default:
					edgetype = 1;
					break;
			}
			break;
		case 'r':
			if(atoi(optarg) <= 255 && atoi(optarg) >= 0){
				red = atoi(optarg);
			}
			break;
		case 'g':
			if(atoi(optarg) <= 255 && atoi(optarg) >= 0){
				green = atoi(optarg);
			}
			break;
		case 'b':
			if(atoi(optarg) <= 255 && atoi(optarg) >= 0){
				blue = atoi(optarg);
			}
			break;
		case 's':
			if(atoi(optarg) == 2 || atoi(optarg) == 4 || atoi(optarg) == 8 || atoi(optarg) == 16){
				sprite_size = atoi(optarg);
			}
			else{
				sprite_size = 4;
			}
			break;
		case 'f':
			file = malloc(strlen(optarg) + 1);
			strcpy(file, optarg);
			break;
		case 'o':
			tempx = malloc(strlen(optarg) + 1);
			tempy = malloc(strlen(optarg) + 1);
			for(i = 0; optarg[i] != ','; i++){
				tempx[i] = optarg[i];
			}
			for(j = 1; optarg[i + j] != '\0'; j++){
				tempy[j - 1] = optarg[i + j];
			}
			// if(atoi(tempx) < (mheight - 1) && atoi(tempy) < (mwidth - 1)){
			// 	originx = atoi(tempx);
			// 	originy = atoi(tempy);
			// }
			break; 
		case 'H': 	/* help */
			printf("usage: find -w width -h height -r red -g green -b blue -s sprite size\n");
			printf("-f filename -o origin\n");
			printf("w: width of the screen\n");
			printf("h: height of the screen\n");
			printf("r: red color value, between [0,255]\n");
			printf("g: green color value, between [0,255]\n");
			printf("b: blue color value, between [0,255]\n");
			printf("s: sprite size, must be 2, 4, 8, or 16\n");
			printf("f: the name of the file in life 1.06 format\n");
			printf("o: the origin spot for the file, x,y\n");
			exit(EXIT_SUCCESS);
		case ':':
			/* missing option argument */
			/* optopt contains the option */
			/* argv[0] is the programs name */
			/* stderr is 1 of 3 files open for you -- stdin, stdout, stderr. Usually they are mapped to the same location */
			fprintf(stderr, "%s: option '-%c' requires an argument\n", argv[0], optopt);
			exit(EXIT_FAILURE);
		case '?': 	/* getopt default invalid option */
		default:
			printf("illegal option %c - ignored\n", optopt);
			printf("usage: find -w width -h height -r red -g green -b blue -s sprite size\n");
			printf("-f filename -o origin\n");
			break;
				
		}
	mwidth = (width / sprite_size);
	mheight = (height / sprite_size);
	if(atoi(tempx) < (mheight - 1) && atoi(tempy) < (mwidth - 1)){
				originx = atoi(tempx);
				originy = atoi(tempy);
			}
        
        /* set up SDL -- works with SDL2 */
	init_sdl_info(&sdl_info, width, height, sprite_size, red, green, blue);

	/* your life initialization code here */
	matrix1 = init_matrix(mwidth, mheight);
	
	fileset(matrix1, file, mwidth, mheight, originx, originy, edgetype);

	matrix2 = init_matrix(mwidth, mheight);
        /* Main loop: loop forever. */
		sdl_render_life(&sdl_info, matrix1);
	while (1)
	{
		if(iterator % 2 == 0){
			next_gen(matrix1, matrix2, mwidth, mheight, edgetype);
		}
		else{
			next_gen(matrix2, matrix1, mwidth, mheight, edgetype);
		}
		// printf("hey\n");
		// unsigned char **tmp = matrix1;
		// matrix1 = matrix2;
		// matrix2 = tmp;
		// sdl_render_life(&sdl_info, matrix2);
		// next_gen(matrix2, matrix1, width, height, edgetype);
		// sdl_render_life(&sdl_info, matrix1);
		/* change the  modulus value to slow the rendering */
		if (SDL_GetTicks() % 1 == 0){
			if(iterator % 2 == 0){
				sdl_render_life(&sdl_info, matrix2);
			}
			else{
				sdl_render_life(&sdl_info, matrix1);
			}
		}
		// 	//sdl_test(&sdl_info, m, n);

                 /* Poll for events, and handle the ones we care about. 
                  * You can click the X button to close the window
                  */
		SDL_Event event;
		while (SDL_PollEvent(&event)) 
		{
			switch (event.type) 
			{
			case SDL_KEYDOWN:
				break;
			case SDL_KEYUP:
                        /* If escape is pressed, return (and thus, quit) */
				if (event.key.keysym.sym == SDLK_ESCAPE)
					return 0;
				break;
			case SDL_QUIT:
				return(0);
			}
		}
		iterator++;
		if(iterator == 2){
			iterator = 0;
		}
	}
	free_matrix(matrix1, mwidth);
	free_matrix(matrix2, mwidth);
	return 0;
}
