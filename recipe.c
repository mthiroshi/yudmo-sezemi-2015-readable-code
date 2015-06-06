#include<stdio.h>

void spec5();

int main(void){
  spec5();
}

void spec5(){
  FILE *recipedataFile;
  char recipedataName[256];
  int numofRecipedata = 3;
  char recipedata[numofRecipedata][256];
  int recipe_id = 0;

  if((recipedataFile = fopen("recipe-data.txt", "r")) == NULL){
    printf("file open error\n");
    exit(0);
  }

  while(fgets(recipedataName, 256, recipedataFile)){

    //char型配列に文字列を代入する方法を検討中
    recipedata[recipe_id][] = recipedataName;
    printf("%s", recipedata[recipe_id][]);
  }

  fclose(recipedataFile);
}
