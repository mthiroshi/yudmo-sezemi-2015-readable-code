#include<stdio.h>

void spec4();

int main(void){
  spec4();
}

void spec4(){
  FILE *recipedataFile;
  char recipedata[256];

  if((recipedataFile = fopen("recipe-data.txt", "r")) == NULL){
    printf("file open error\n");
    exit(0);
  }

  while(fgets(recipedata, 256, recipedataFile)){

    printf("%s", recipedata);
  }

  fclose(recipedataFile);
}
