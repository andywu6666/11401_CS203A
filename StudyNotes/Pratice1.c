//這個程式缺少了:
//1.標頭檔
#include <stdio.h>
#include <stdlib.h>
//2.主函式
int main() {
int *array;
int n = 10;

array = (int *) malloc(n * sizeof(int));
//3.檢查記憶體配置是否成功
if (array == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1; //回傳錯誤碼
}

for(int i = 0; i < n; i++) {
  array[i] = i + 1;
}

for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
}

n = n * 2;

array = (int *) realloc(array, n * sizeof(int));

for (int i = n/2; i < n; i++) {
    array[i] = i + 1;   // initialize new elements
}
//4.釋放記憶體
free(array);

//5.回傳值
return 0;
}