#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void spec5(char* recipeFileName, int argRecipeId); /* 実際の処理を行う関数*/

int main(int argc, char* argv[]){
    int argRecipeId;


    if (argc != 2) { /* 引数エラーチェック */
        printf("Usage Error: recipe.exe [File Name] [Recipe ID]");
        exit(EXIT_FAILURE);
    }

    argRecipeId = atoi(argv[2]);
    
    spec5(argv[1], argRecipeId);
}

void spec5(char *recipeFileName, int argRecipeId){
    FILE *recipedataFile;
    char recipedataName[256];
    int numofRecipedata = 3;
    char recipedata[numofRecipedata][256];
    int recipe_id = 0;
    int i;

    if (argRecipeId >= numofRecipedata) {
        printf("ERROR :ArgRecipeID");
        exit(EXIT_FAILURE);
    }


    if((recipedataFile = fopen(recipeFileName, "r")) == NULL){
        printf("file open error\n");
        exit(EXIT_FAILURE);
    }

    // fgets()できなくなるまでループ
    for (i = 0;i < numofRecipedata && 
            fgets(recipedataName, 256, recipedataFile); i++){

        strcpy(recipedata[recipe_id], recipedataName);

        printf("ID:%d recipe_name :%s", recipe_id, recipedata[recipe_id]);
        recipe_id++;
    }

    fclose(recipedataFile);
}
